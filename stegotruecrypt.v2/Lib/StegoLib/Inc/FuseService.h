#include <QtCore/QtGlobal>

#ifndef Q_OS_WIN

#include "Logging/log.h"
#include "VirtualStorage/VirtualStorage.h"

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

static struct fuse_operations stegofs_ops;

class FuseService {

public:
	FuseService();
	~FuseService();
	FuseService(VirtualStorage *vs, const char *mp);

    static FuseServiceDelegate*     delegate;
    static VirtualStorage*        	virtualStorage;
    static uint64           		capacity;
    static bool                     fuseMounted;
    static const char*              virtualFileName;

    static QString                  mountPoint;

    static QProcess*                childProcess;

    static pid_t                    fuseProcPid;
	//static struct fuse_operations stegofs_ops;

    static int init(VirtualStorage *virtualStorage);
    static int mountFuse(const char* mountPoint);
    static int unmountFuse(const char* mountPoint);
    //static int mountFuse(QString mountPoint);
    //static int unmountFuse(QString mountPoint);

};

#endif
