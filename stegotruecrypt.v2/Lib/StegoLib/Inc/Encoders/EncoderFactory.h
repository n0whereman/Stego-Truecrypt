#ifndef ENCODERFACTORY_H
#define ENCODERFACTORY_H

#ifndef __SHARED_PTR_ENCODER__
#define __SHARED_PTR_ENCODER__
#include <memory>
class Encoder;
typedef std::shared_ptr<Encoder> EncoderPtr;
#endif // __SHARED_PTR_ENCODER__

#include <vector>
using namespace std;

// no inheritance from this class
class EncoderFactory final
{
private:
    EncoderFactory();
public:
    // get vector of all encoders (each encoder with all possible settings)
    static vector<EncoderPtr> getAllEncoders();
    // get vector of all encoders (each encoder once with default settings)
    static vector<EncoderPtr> getEncoders();
    // get names of all encoders supported by this library
    static vector<string> getEncoderNames();
    // get instance of encoder based on the his code name
    static EncoderPtr getEncoderByName(const string &name);
    // set encoder param by name
    static void setEncoderArgByName(EncoderPtr encoder, const string &param, const string &val);
    // get instance of the default encoder
    static EncoderPtr getDefaultEncoder();
};

#endif // ENCODERFACTORY_H
