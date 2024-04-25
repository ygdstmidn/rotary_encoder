#include "rotary_encoder.h"

mbed::lib_ygdstmidn::rotary_encoder::rotary_encoder::rotary_encoder(PinName pinA, PinName pinB,PinName switchpin)
{
    read_encode_pinA=new DigitalIn(pinA);
    read_encode_pinB=new DigitalIn(pinB);
    read_encode_sw  =new DigitalIn(switchpin);
    wa_encode_pinA  =new InterruptIn(pinA);
    wa_encode_pinB  =new InterruptIn(pinB);
}

mbed::lib_ygdstmidn::rotary_encoder::rotary_encoder::~rotary_encoder()
{
}
