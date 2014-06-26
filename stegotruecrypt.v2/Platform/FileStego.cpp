#include "Platform/FileStego.h"
#include "Platform/File.h"
#include "Fuse/FuseService.h"
#include <iostream>
#include <fcntl.h>	// UNIX!!! (open)
#include <sys/types.h>  // UNIX!!! (open)
#include <sys/stat.h>   // UNIX!!! (open)
//#include <wx/string.h>
//#include <wx/file.h>

#ifdef TC_UNIX
#endif

namespace TrueCrypt
{
	#if 0
#	define TC_TRACE_FILE_OPERATIONS

	static void TraceFileOperation (int fileHandle, FilePath filePath, bool write, uint64 length, int64 position = -1)
	{
		string path = filePath;
		if (path.empty() || path.find ("truecrypt_aux_mnt") != string::npos)
			return;

		stringstream s;
		s << path << ": " << (write ? "W " : "R ") << (position == -1 ? lseek (fileHandle, 0, SEEK_CUR) : position) << " (" << length << ")";
		SystemLog::WriteError (s.str());
	}
    #endif

    FileStego::FileStego() {
    	FuseMount = false;
    	FuseUnmount = false;
    	CurrentPos = unique_ptr<uint64>(new uint64());
    }

   

	void FileStego::Close ()
	{
		//SystemLog::WriteError("Filestego::Close was called on " + string (Path));
        if(FuseUnmount && string(FuseMountPoint).size()) {
        	//SystemLog::WriteError("FUSEEEEEEEEEE UNMOUNTEDDD!!!! " + string (FuseMountPoint));
        	FuseService::unmountFuse(string(FuseMountPoint).c_str());
        }
        FileIsOpen = false;		
		Manager->saveVirtualStorage();
		

		
	}

    void FileStego::SetFuse(bool Mount, bool Unmount) {
    	FuseMount = Mount;
        FuseUnmount = Unmount;
    }


	void FileStego::Delete ()
	{
		throw SystemException (SRC_POS, L"Delete");
	}


	void FileStego::Flush () const
	{
		//throw SystemException (SRC_POS, L"Flush");
		if_debug (ValidateState());
		throw_sys_sub_if (Manager->saveVirtualStorage() != 0, wstring (Path));
	}

	uint32 FileStego::GetDeviceSectorSize () const
	{
		throw SystemException (SRC_POS, L"GetDeviceSectorSizeStego");
	}

	void FileStego::ReadCompleteBuffer (const BufferPtr &buffer) const {
		throw SystemException (SRC_POS, L"ReadCompleteBufferStego");
	}

	uint64 FileStego::GetPartitionDeviceStartOffset () const
	{
		throw SystemException (SRC_POS, L"GetPartitionDeviceStartOffsetStego");
	}

	uint64 FileStego::Length () const
	{
		return virtualStorage->getUsableCapacity();
		
	}


	void FileStego::Open (const FilePath &path, FileOpenMode mode, FileShareMode shareMode, FileOpenFlags flags)
	{
		try {
		  virtualStorage = VirtualStorage::getNewInstance("MixedFeistel"); //HARDCODED PERMUTATION, SEC.CONSTRAINTS, pravdepodobne bude nutne premiestnit
	      Manager->loadVirtualStorage(virtualStorage);
		} catch (std::exception &e) {
			SystemLog::WriteError("FileStego::Open: failed to load VirtalStorage");
			throw SystemException (SRC_POS, L"FileStego::loadVirtualStorage");
		}
        
        try{
         	 	//wxString name("/tmp/blabla3.stego/virtualdisc.iso");
               // wxFile tmpFile = tmpFile.Create(name,false,wxFile::write)
         	 	Path = FilesystemPath("/tmp/blabla3.stego/virtualdisc.iso");
         	 	FuseMountPoint = FilesystemPath("/tmp/blabla3.stego");				
					
        }
        catch (std::exception &e) {
			SystemLog::WriteError("FileStego::Open: failed create temporary PATH");
			throw SystemException (SRC_POS, L"FileStego::loadVirtualStorage");
		}
        
		if(FuseMount && string(FuseMountPoint).size()) {
          FuseService fs = FuseService(virtualStorage,Manager,string(FuseMountPoint).c_str());
		}
		mFileOpenFlags = flags;
		FileIsOpen = true;
	}

	uint64 FileStego::Read (const BufferPtr &buffer) const
	{
		int err = virtualStorage->read(*CurrentPos, buffer.Size(), buffer.Get());
		if(err == 0) {
         		*CurrentPos = *CurrentPos + buffer.Size();
		} else 
			throw SystemException (SRC_POS, L"FileStego::Read failed");
		//SystemLog::WriteError("FileStego::Read bytes="+std::to_string(buffer.Size()));
		return buffer.Size();
	}

	uint64 FileStego::ReadAt (const BufferPtr &buffer, uint64 position) const
	{
		int err = virtualStorage->read(position, buffer.Size(), buffer.Get());
		if(err) 
			throw SystemException (SRC_POS, L"FileStego::ReadAt failed");
		return buffer.Size();
	}

	void FileStego::SeekAt (uint64 position) const
	{
		throw_sys_sub_if (position < 0, wstring (Path));
		*CurrentPos = position;
		cerr << "SeekAt current position je " << *CurrentPos << endl;

	}

	void FileStego::SeekEnd (int offset) const
	{
		
		throw_sys_sub_if (offset > 0,wstring (Path));
		SeekAt (Length() - 1 + offset);	
	}

	void FileStego::Write (const ConstBufferPtr &buffer) const
	{
		if_debug(ValidateState());
		int err = virtualStorage->write(*CurrentPos, buffer.Size(), buffer.Get());
		if(err == 0) {
         		*CurrentPos = *CurrentPos + buffer.Size();
		} else 
			throw SystemException (SRC_POS, "FileStego::Write: failed; CurrentPos=" + std::to_string(*CurrentPos) + ", Size=" + std::to_string(buffer.Size()));
		
	}
	
	void FileStego::WriteAt (const ConstBufferPtr &buffer, uint64 position) const
	{
		throw SystemException (SRC_POS, L"Write");
	}

	void FileStego::SetManager (shared_ptr<CarrierFilesManager> _manager) 
	{
		this->Manager = _manager;
	}

	void FileStego::ValidateState () const 
	{
		if ((virtualStorage == nullptr) || (Manager == nullptr))
			throw NotInitialized (SRC_POS);
	}

}
