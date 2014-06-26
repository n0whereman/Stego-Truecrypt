/*
 Copyright (c) 2008-2009 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Stego_File
#define TC_HEADER_Stego_File
#include "File.h"
#include "PlatformBase.h"
#include "Buffer.h"
#include "FileManagement/CarrierFilesManager.h"
#include "VirtualStorage/VirtualStorage.h"
#include "FilesystemPath.h"
#include "SystemException.h"


namespace TrueCrypt
{
	class FileStego : public File
	{
	public:		

		shared_ptr<CarrierFilesManager> Manager;
		shared_ptr<VirtualStorage> virtualStorage;
		
		FileStego();
		virtual ~FileStego () {};
	
		virtual void Open (const FilePath &path, FileOpenMode mode = OpenRead, FileShareMode shareMode = ShareReadWrite, FileOpenFlags flags = FlagsNone); 
		virtual void Close ();
		//static void Copy (const FilePath &sourcePath, const FilePath &destinationPath, bool preserveTimestamps = true);
		virtual void Delete ();
		virtual void Flush () const;
		virtual uint32 GetDeviceSectorSize () const;
		static size_t GetOptimalReadSize () { return OptimalReadSize; }
		static size_t GetOptimalWriteSize ()  { return OptimalWriteSize; }
		virtual uint64 GetPartitionDeviceStartOffset () const;
		bool IsOpen () const { return FileIsOpen; }
	    FilePath GetPath () const;
		virtual uint64 Length () const;
		// /10/31/2013 - virtual Open 
		virtual uint64 Read (const BufferPtr &buffer) const;
		virtual void ReadCompleteBuffer (const BufferPtr &buffer) const;
		virtual uint64 ReadAt (const BufferPtr &buffer, uint64 position) const;
		virtual void SeekAt (uint64 position) const;
		virtual void SeekEnd (int ofset) const;
		virtual void Write (const ConstBufferPtr &buffer) const;
		virtual void Write (const ConstBufferPtr &buffer, size_t length) const { Write (buffer.GetRange (0, length)); }
		virtual void WriteAt (const ConstBufferPtr &buffer, uint64 position) const;
		virtual void ValidateState() const;
		
        void SetFuse(bool Mount, bool Unmount);
		
		void SetManager (shared_ptr<CarrierFilesManager> _manager);

	private:
		FileStego (const FileStego &);
		FileStego &operator= (const FileStego &);
		unique_ptr<uint64> CurrentPos;
		static const size_t OptimalReadSize = 256 * 1024;
		static const size_t OptimalWriteSize = 256 * 1024;
        bool FuseMount = false;
		bool FuseUnmount = false;
	    FilePath FuseMountPoint;
		
   };
}

#endif // TC_HEADER_Stego_File
