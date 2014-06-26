//
//  AffinePermutation.h
//  StegoFS
//
//  Created by matok on 3/22/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__AffinePermutation__
#define __StegoFS__AffinePermutation__

#include "Permutations/Permutation.h"

class AffinePermutation : public Permutation {

public:
    int init(_uint64 requestedSize, _uint8* keyHash);
    int permute(_uint64 *position) const;
    _uint64 getSizeUsingParams(_uint64 requestedSize, _uint8 *keyHash);

    const string getNameInstance() const;
    static const string getName();
    virtual shared_ptr<Permutation> getNewInstance();
    static shared_ptr<Permutation> getNew();

private:
    _uint64 getSizeUsingParams(_uint64 requestedSize, _uint8 *keyHash, bool overwriteMembers);
    _uint64 _keyParamA;
    _uint64 _keyParamB;
};


#endif /* defined(__StegoFS__AffinePermutation__) */
