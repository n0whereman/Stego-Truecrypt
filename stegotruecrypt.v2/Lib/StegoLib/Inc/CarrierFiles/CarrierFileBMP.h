//
//  CarrierFileBMP.h
//  StegoFS
//
//  Created by matok on 1/6/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__CarrierFileBMP__
#define __StegoFS__CarrierFileBMP__

#include <iostream>
#include <string>
#include <stdint.h>
#include "CarrierFiles/CarrierFile.h"
#include "Logging/logger.h"

using namespace std;

class CarrierFileBMP : CarrierFile {
    
public:
    CarrierFileBMP(string basePath, string relativePath, EncoderPtr embedder);

    int loadFile();
    int saveFile();

    
private:
    uint32 _bmpOffset;
    uint64 _bmpSize;
};

#endif /* defined(__StegoFS__CarrierFileBMP__) */
