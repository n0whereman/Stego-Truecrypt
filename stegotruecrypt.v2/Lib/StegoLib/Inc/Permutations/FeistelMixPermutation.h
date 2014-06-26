//
//  FeistelMixPermutation.h
//  StegoFS
//
//  Created by matok on 4/15/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__FeistelMixPermutation__
#define __StegoFS__FeistelMixPermutation__

#include "Permutations/Permutation.h"

class FeistelMixPermutation : public Permutation {
    
public:
	FeistelMixPermutation();
    ~FeistelMixPermutation();
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

    _uint8 _leftBits; // mY changed to 8-bit
    _uint64 _leftMod;

    _uint64 _rightMask;
    _uint8 _rightBits; // mY changed to 8-bit
};

#endif /* defined(__StegoFS__FeistelMixPermutation__) */
