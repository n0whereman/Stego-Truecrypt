#ifndef VIRTUALSTORAGE_H
#define VIRTUALSTORAGE_H

#ifndef __SHARED_PTR_VIRTUALSTORAGE__
#define __SHARED_PTR_VIRTUALSTORAGE__
#include <memory>
class VirtualStorage;
typedef std::shared_ptr<VirtualStorage> VirtualStoragePtr;
#endif // __SHARED_PTR_VIRTUALSTORAGE__

#include "Utils/Types.h"
#include "Permutations/PermutationFactory.h"


/**
 * Main storage buffer that utilizes global permutation in readByte/writeByte ops
 *
 * [ STORAGE (len: usable capacity) | CHECKSUM/HASH (len: hash length) ]
*/


class VirtualStorage final
{
private:
    VirtualStorage();
    void init();

public:
    ~VirtualStorage();

    static VirtualStoragePtr getNewInstance();
    static VirtualStoragePtr getNewInstance(string permutation);

    // Initialization of the VirtualStorage depends on permutation
    void setPermutation(PermutationPtr permutation);
    void unsetPermutation();
    void applyPermutation(_uint64 requestedSize, const unique_ptr<_uint8[]> &keyHash);

    // Accessed by CarrierFile during save/load operation
    int writeByte(_uint64 position, _uint8 value);
    int readByte(_uint64 position, _uint8* value);

    // Accessed by main I/O layer (Fuse, VirtualDisc driver..)
    int read(_uint64 offset, _uint32 length, _uint8* buffer);
    int write(_uint64 offset, _uint32 length, const _uint8* buffer);

    _uint64 getRawCapacity();
    _uint64 getUsableCapacity();

    int randomizeBuffer();
    int clearBuffer();
    int fillBuffer(_uint8 value);

    bool isValidChecksum();
    int writeChecksum();

private:
    PermutationPtr _globalPermutation;
    bool   _isSetGlobalPermutation;
    _uint64 _rawCapacity;                // raw capacity (hash + storage)
    _uint64 _usableCapacity;             // usable capacity (storage only)
    std::unique_ptr<_uint8[]> _data;
};

#endif // VIRTUALSTORAGE_H
