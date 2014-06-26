//
//  CarrierFile.h
//  StegoFS
//
//  Created by matok on 1/6/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__CarrierFile__
#define __StegoFS__CarrierFile__

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <errno.h>
#include <typeinfo>
#include "Utils/Config.h"
#include "Utils/Types.h"
#include "Logging/logger.h"
#include "Encoders/EncoderFactory.h"
#include "Permutations/PermutationFactory.h"
#include "Permutations/Permutation.h"
#include "VirtualStorage/VirtualStorage.h"

using namespace std;

/**
 * The CarrierFile class.
 *
 * Abstract base class CarrierFile (cannot be instantiated)
 * Provides an interface for CarrierFiles subclasses
 */
class CarrierFile {
        
public:
    CarrierFile();
    CarrierFile(string basePath, string relativePath, EncoderPtr encoder);
    virtual ~CarrierFile();
    
    _uint64 getCapacity();
    _uint64 getRawCapacity();

    _uint32 getBlockCount();
    string getBasePath();
    string getAbsolutePath();
    string getRelativePath();
    struct stat getStat();
    
    void setPermutation(PermutationPtr permutation);
    void unsetPermutation();
    void setEncoder(EncoderPtr encoder);
    void unsetEncoder();
    _uint64 getCapacityUsingEncoder(EncoderPtr encoder);

    virtual bool isFileLoaded();
    virtual int loadFile() = 0;
    virtual int saveFile() = 0;
    virtual void unloadFile();
    virtual int closeFile();

    int setSubkey(_uint8* subkey);
    int addToVirtualStorage(VirtualStoragePtr storage, _uint64 offset, _uint64 bytesUsed);
        
    int getPermKeyHash(_uint8 *hash);
    
    bool operator< (const CarrierFile& val) const;

    static bool compareByPointers(CarrierFile* a, CarrierFile* b);

    static string normalizePath(string path);

protected:
    FILE* openFile();
    int setDatesBack();
    
    void setBitInBufferPermuted(_uint64 index);
    _uint8 getBitInBufferPermuted(_uint64 index);
    int initTemporaryBuffer();
    int destroyTemporaryBuffer();

    int extractBufferUsingEncoder();
    int embedBufferUsingEncoder();


    _uint8* _buffer;

    string _basePath;
    string _relativePath;
    FILE* _file;

    _uint32 _codewordBlockSize;
    _uint32 _dataBlockSize;
    _uint32 _blockCount;
    _uint64 _capacity;
    _uint64 _rawCapacity;
    _uint64 _fileSize;

    _uint32 _blocksUsed;

    _uint64 _virtualStorageOffset;

    bool _fileLoaded;
    struct stat _stat;

    _uint8 _subkey[SFS_KEY_HASH_LENGTH];

    EncoderPtr _encoder;
    PermutationPtr _permutation;
    VirtualStoragePtr _virtualStorage;
};

#endif /* defined(__StegoFS__CarrierFile__) */
