#ifndef INCLUDE_ROTARY_ENCODER_H
#define INCLUDE_ROTARY_ENCODER_H

#include "mbed.h"

void a();

namespace mbed
{
namespace lib_ygdstmidn
{

class rotary_encoder
{
// private:
public:
    const int encode_table[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
    int encode_count=0;

    DigitalIn *read_encode_sw;

    InterruptIn *wa_encode_pinA;
    InterruptIn *wa_encode_pinB;

    void encode();
public:
    rotary_encoder(PinName pinA,PinName pinB,PinName switchpin);
    ~rotary_encoder();

    int get_count();
};

}//namespace lib_ygdstmidn
}//namespace mbed

using namespace mbed::lib_ygdstmidn;

#endif