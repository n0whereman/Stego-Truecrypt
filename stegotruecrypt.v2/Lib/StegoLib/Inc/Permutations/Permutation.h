//
//  Permutation.h
//  StegoFS
//
//  Created by matok on 3/22/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__Permutation__
#define __StegoFS__Permutation__

#include <string>
#include <memory>
#include "Utils/Types.h"

using namespace std;

class Permutation {
    
public:
    Permutation();
    virtual ~Permutation();
    virtual int init(_uint64 requestedSize, _uint8 *keyHash);
    virtual int permute(_uint64* position) const;
    virtual _uint64 getSize() const;
    virtual _uint64 getSizeUsingParams(_uint64 requestedSize, _uint8 *keyHash);
    bool isValid() const;

    virtual const string getNameInstance() const;
    static const string getName();
    virtual shared_ptr<Permutation> getNewInstance();
    static shared_ptr<Permutation> getNew();

protected:
    _uint64 _size;
};

#endif /* defined(__StegoFS__Permutation__) */
