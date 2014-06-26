//
//  Encoder.h
//  StegoFS
//
//  Created by matok on 3/21/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__Encoder__
#define __StegoFS__Encoder__

#include <memory>
#include <string>

#include "Utils/Types.h"

using namespace std;

class Encoder {

public:
    Encoder();
    virtual ~Encoder();
    virtual int embed(_uint8* codeword, const _uint8* data) = 0;
    virtual int extract(const _uint8* codeword, _uint8* data) = 0;

    virtual _uint32 getDataBlockSize();
    virtual _uint32 getCodewordBlockSize();
    virtual void setArgByName(const string &arg, const string &val) = 0;

    virtual const string getNameInstance() const = 0;
    static const string getName();
    virtual shared_ptr<Encoder> getNewInstance() = 0;
    static shared_ptr<Encoder> getNew();

protected:
    _uint32 _codewordBlockSize;
    _uint32 _dataBlockSize;
};


#endif /* defined(__StegoFS__Encoder__) */
