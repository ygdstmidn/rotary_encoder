#include "rotary_encoder.h"

mbed::lib_ygdstmidn::rotary_encoder::rotary_encoder(PinName pinA, PinName pinB, PinName switchpin)
{
    read_encode_sw  =new DigitalIn(switchpin);
    wa_encode_pinA  =new InterruptIn(pinA);
    wa_encode_pinB  =new InterruptIn(pinB);

    read_encode_sw->mode(PullUp);

    wa_encode_pinA->rise(callback(this, &rotary_encoder::encode));//割り込み
    wa_encode_pinA->fall(callback(this, &rotary_encoder::encode));
    wa_encode_pinA->mode(PullUp);

    wa_encode_pinB->rise(callback(this, &rotary_encoder::encode));
    wa_encode_pinB->fall(callback(this, &rotary_encoder::encode));
    wa_encode_pinB->mode(PullUp);
}

mbed::lib_ygdstmidn::rotary_encoder::~rotary_encoder()
{
}

void mbed::lib_ygdstmidn::rotary_encoder::encode()
{
    static int last_state1 = 0;
    int sig1_A = *wa_encode_pinA;
    int sig1_B = *wa_encode_pinB;
    int8_t state1 = sig1_A | (sig1_B << 1);
    int8_t sum1 = state1 | last_state1<<2;
    if (last_state1 != state1)
    {
        encode_count+=encode_table[sum1];
        last_state1=state1;
    }
}

int mbed::lib_ygdstmidn::rotary_encoder::get_count()
{
    return encode_count;
}