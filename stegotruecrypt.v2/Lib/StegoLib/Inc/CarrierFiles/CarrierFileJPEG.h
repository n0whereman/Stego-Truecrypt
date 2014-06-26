//
//  CarrierFileJPEG.h
//  StegoFS
//
//  Created by matok on 1/9/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__CarrierFileJPEG__
#define __StegoFS__CarrierFileJPEG__

#include <iostream>
#include <string>
#include <stdint.h>
#include <jpeglib.h>
#include <jerror.h>
#include "Logging/logger.h"
#include "CarrierFiles/CarrierFile.h"

using namespace std;

class CarrierFileJPEG : CarrierFile {

private:
	int computeCapacity();
    
public:
    CarrierFileJPEG(string basePath, string relativePath, EncoderPtr encoder);

    int loadFile();
    int saveFile();

    int getHistogram();
    
};

#endif /* defined(__StegoFS__CarrierFileJPEG__) */
