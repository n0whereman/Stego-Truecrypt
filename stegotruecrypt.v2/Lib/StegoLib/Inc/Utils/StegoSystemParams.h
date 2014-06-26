#ifndef STEGOSYSTEMPARAMS_H
#define STEGOSYSTEMPARAMS_H

#include "Permutations/PermutationFactory.h"
#include "Encoders/EncoderFactory.h"
#include "FileManagement/CarrierFilesManager.h"

class StegoSystemParams
{

public:
    StegoSystemParams();
    ~StegoSystemParams();
    void destroyContent();
    static vector<StegoSystemParams*> getConfigurations(CarrierFilesManager* manager, uint8* keyHash, uint64 minimalCapacity);

    PermutationPtr permutation;
    EncoderPtr encoder;
    uint64 capacity;
};

#endif // STEGOSYSTEMPARAMS_H
