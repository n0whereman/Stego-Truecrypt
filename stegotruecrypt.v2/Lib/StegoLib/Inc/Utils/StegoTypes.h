//
//  StegoTypes.h
//  StegoFS
//
//  Created by matok on 4/7/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef StegoFS_StegoTypes_h
#define StegoFS_StegoTypes_h

#include <QtCore/QtGlobal>

#ifndef Q_WS_WIN

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;

typedef char int8;
typedef short int16;
typedef int int32;
typedef long int64;

#else

#include <inttypes.h>
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

#endif




#endif
