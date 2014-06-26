//
//  FeistelNetPermutation.h
//  StegoFS
//
//  Created by matok on 4/15/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__FeistelNumPermutation__
#define __StegoFS__FeistelNumPermutation__

#include "Permutations/Permutation.h"

class FeistelNumPermutation : public Permutation {
    
public:
    FeistelNumPermutation();
    ~FeistelNumPermutation();
    int init(_uint64 requestedSize, _uint8* keyHash);
    int permute(_uint64 *position) const;
    bool checkPermutation();
    _uint64 getSizeUsingParams(_uint64 requestedSize, _uint8 *keyHash);

    const string getNameInstance() const;
    static const string getName();
    virtual shared_ptr<Permutation> getNewInstance();
    static shared_ptr<Permutation> getNew();
    
private:

    void leftRound(_uint64 *left, _uint64 *right);
    void rightRound(_uint64 *left, _uint64 *right);

    _uint32 *_hash;

    _uint32 _modulus;

    _uint32 _leftBits;
    _uint64 _leftMod;

    _uint64 _rightMask;
    _uint64 _rightBits;
};

#endif /* defined(__StegoFS__FeistelNumPermutation__) */
