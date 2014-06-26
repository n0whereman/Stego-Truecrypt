//
//  CarrierFilesManager.h
//  StegoFS
//
//  Created by matok on 1/6/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__CarrierFilesManager__
#define __StegoFS__CarrierFilesManager__

#include <iostream>
#include <vector>
#include "CarrierFiles/CarrierFile.h"
#include "VirtualStorage/VirtualStorage.h"
#include "Encoders/EncoderFactory.h"
#include "Logging/logger.h"

#include <QtCore/QtCore>

#include <QtCore/QObject>
#include <QtCore/QThreadPool>

#include "FileManagement/CarrierFilesManagerDelegate.h"

//#include <boost/filesystem/path.hpp>
//#include <boost/filesystem/operations.hpp>
//#include <boost/progress.hpp>

//namespace fs = boost::filesystem;
/*
enum StegoLoadingStage {
    CountingCapacity = 0,
    LoadingFiles = 1,
    SavingFiles = 2
};

typedef void (*ProgressCallbackFunction)(int progress, int max, StegoLoadingStage stage);
*/
class CarrierFilesManager : public QObject {
        
    Q_OBJECT

public:
    explicit CarrierFilesManager(QObject *parent = 0);
    ~CarrierFilesManager();
    int loadDirectory(const char* directory);
    void closeAllFiles();
    void saveAllFiles(); 
       
    _uint64 getCapacity();
    _uint64 getRawCapacity();

    _uint64 getCapacityUsingEncoder(EncoderPtr encoder);

    void applyEncoder();
    void setEncoder(EncoderPtr encoder);
    void unsetEncoder();
    void setEncoderArgByName(const string &param, const string &val);

    void setPassword(const char* password);

    bool loadVirtualStorage(VirtualStoragePtr storage);
    int saveVirtualStorage();

    int getPermKeyHash(_uint8* hash);
    
    void setDelegate(CarrierFilesManagerDelegate *delegate);


private:
    void init();
    
    void addFileAtPath(string path);
    int countFilesInDir(const QString& sDir);
    int loadFilesInDir(const QString& sDir);

    int generateMasterKey();
    int deriveSubkeys();

    QString _basePath;

    QThreadPool _loadingThreadPool;

    QMutex _fileListMutex;
    QMutex _loadingProgressMutex;

    std::vector<CarrierFile*> _carrierFiles;
    _uint64 _capacity;

    _uint64 _filesInDirectory;
    _uint64 _loadingProgress;

    _uint8 _passwordHash[SFS_KEY_HASH_LENGTH];
    _uint8 _masterKey[SFS_KEY_HASH_LENGTH];

    CarrierFilesManagerDelegate* _delegate;
    VirtualStoragePtr _virtualStorage;

    // TODO using of encoder in doc
    // 1. setEncoder (isActiveEnc = false)
    // 2. setEncoderArgs (isActiveEnc = false)
    // 3. applyEncoder (only after applyEnc isActiveEnc = true)
    // 4. ...
    // 5. unsetEncoder (isActiveEnc = false)
    EncoderPtr _encoder;
    bool _isActiveEncoder;

public slots:
    void on_fileInitFinished();
    void on_fileLoadFinished();
};


#endif /* defined(__StegoFS__CarrierFilesManager__) */
