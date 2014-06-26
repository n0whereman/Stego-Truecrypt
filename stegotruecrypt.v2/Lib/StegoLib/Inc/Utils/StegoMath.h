//
//  StegoMath.h
//  StegoFS
//
//  Created by matok on 3/23/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__StegoMath__
#define __StegoFS__StegoMath__

#include <string>
#include "Utils/Types.h"

using namespace std;

class StegoMath {

public:
    static _uint64 gcd(_uint64 a, _uint64 b);
    static _uint64 lcm(_uint64 a, _uint64 b);
    //static bool MillerRabin(_uint64 p, int iteration);
    static bool MillerRabin(_uint64 p);
    static void printHexBuffer(_uint8 *buffer, int length);
    static string hexBufferToStr(_uint8 *buffer, int length);
    static _uint64 closestSmallerPrime(_uint64 number);
    static _uint64 modulo(_uint64 a, _uint64 b, _uint64 c);
    //static long long mulmod(long long a,long long b,long long c);
    //static inline _uint64_t mulmod(_uint64_t a, _uint64_t b, _uint64_t m);
    static _uint64 mulmod(_uint64 a, _uint64 b, _uint64 m);
    static _uint8 log2(_uint64 number);
    static _uint8 popcount(_uint64 x);
    
};


#endif /* defined(__StegoFS__StegoMath__) */
