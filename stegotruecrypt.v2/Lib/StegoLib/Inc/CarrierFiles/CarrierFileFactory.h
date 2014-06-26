//
//  CarrierFileFactory.h
//  StegoFS
//
//  Created by matok on 4/11/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef __StegoFS__CarrierFileFactory__
#define __StegoFS__CarrierFileFactory__

#include <iostream>
#include "CarrierFiles/CarrierFile.h"
#include "Logging/logger.h"

class CarrierFileFactory
{
public:
    static CarrierFile* createCarrierFile(string basePath, string relativePath);
};

#endif /* defined(__StegoFS__CarrierFileFactory__) */
