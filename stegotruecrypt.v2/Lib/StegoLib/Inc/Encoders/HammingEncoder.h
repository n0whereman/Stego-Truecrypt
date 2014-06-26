//
//  HammingEncoder.h
//  StegoFS
//
//  Created by matok on 3/21/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__HammingEncoder__
#define __StegoFS__HammingEncoder__

#include "Encoders/Encoder.h"

#define ENCODER_HAMMING_CODE_NAME_DEF "Hamming"

class HammingEncoder : public Encoder {
    
public:
    HammingEncoder();
    HammingEncoder(_uint32 parityBits);

    int embed(_uint8 *codeword, const _uint8 *data);
    int extract(const _uint8 *codeword, _uint8 *data);

    void setArgByName(const string &arg, const string &val);

    static const string getName();
    const string getNameInstance() const;
    static shared_ptr<Encoder> getNew();
    shared_ptr<Encoder> getNewInstance();

    static int getParityBitsMin();
    static int getParityBitsMax();

private:
    void init(_uint32 parityBits);
    _uint64 computeH(const _uint8 *buffer);
    void swapBitInCodeword(_uint8 *buffer, int bitIn);
    void writeBitsToBuffer(_uint64 value, int offset, _uint8 *buffer);
    _uint64 readBitsFromBuffer(const _uint8 *buffer, int offset, int length);
    
    int _parityBits;
    int _totalBits;
    
    _uint32 _codewordsInBlock;
    _uint32 _codewordBufferSize;

    static const _uint32 ENCODER_HAMMING_PARITY_BITS_MIN = 3;
    static const _uint32 ENCODER_HAMMING_PARITY_BITS_MAX = 8;
    static const string ENCODER_HAMMING_CODE_NAME;    
    // default block size
    static const _uint32 ENCODER_HAMMING_DEFAULT_PARITY_BITS = 5;
};

#endif /* defined(__StegoFS__HammingEncoder__) */
