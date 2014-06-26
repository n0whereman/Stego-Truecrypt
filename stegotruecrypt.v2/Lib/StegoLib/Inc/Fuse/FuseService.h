#include <QtCore/QtGlobal>

#ifndef Q_OS_WIN

#include "Logging/log.h"
#include "VirtualStorage/VirtualStorage.h"
#include "FileManagement/CarrierFilesManager.h"

#include <QtCore/QString>
#include <QtCore/QProcess>

#include "Fuse/FuseServiceDelegate.h"

#define _FILE_OFFSET_BITS 64
#define FUSE_USE_VERSION 26

#ifdef Q_OS_MAC
    #include <osxfuse/fuse.h>
#else
    #include <fuse.h>
#endif

#include <memory>

static struct fuse_operations stegofs_ops;

class FuseService {

public:
	FuseService();
	~FuseService();
	FuseService(shared_ptr<VirtualStorage> vs, shared_ptr<CarrierFilesManager> fm, const char *mp);

    static FuseServiceDelegate*     delegate;
    static shared_ptr<VirtualStorage>        	virtualStorage;
    static shared_ptr<CarrierFilesManager>	filesManager;
    static _uint64           		capacity;
    static bool                     fuseMounted;
    static const char*              virtualFileName;

    static QString                  mountPoint;

    static QProcess*                childProcess;

    static pid_t                    fuseProcPid;
	//static struct fuse_operations stegofs_ops;

    static int init(shared_ptr<VirtualStorage> virtualStorage, shared_ptr<CarrierFilesManager> fm);
    static int mountFuse(const char* mountPoint);
    static int unmountFuse(const char* mountPoint);
    //static int mountFuse(QString mountPoint);
    //static int unmountFuse(QString mountPoint);

};

#endif
