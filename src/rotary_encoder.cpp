#include "rotary_encoder.h"

namespace mbed
{
namespace lib_ygdstmidn
{

mbed::lib_ygdstmidn::rotary_encoder::rotary_encoder(PinName pinA, PinName pinB, PinName pinZ)
{
    read_encode_z  =new DigitalIn(pinZ);
    wa_encode_pinA  =new InterruptIn(pinA);
    wa_encode_pinB  =new InterruptIn(pinB);

    read_encode_z->mode(ROTARY_ENCODER_DEFAULT_PIN_Z_PINMODE);

    wa_encode_pinA->rise(callback(this, &rotary_encoder::encode));//割り込み
    wa_encode_pinA->fall(callback(this, &rotary_encoder::encode));
    wa_encode_pinA->mode(ROTARY_ENCODER_DEFAULT_PIN_A_PINMODE);

    wa_encode_pinB->rise(callback(this, &rotary_encoder::encode));
    wa_encode_pinB->fall(callback(this, &rotary_encoder::encode));
    wa_encode_pinB->mode(ROTARY_ENCODER_DEFAULT_PIN_B_PINMODE);
}

mbed::lib_ygdstmidn::rotary_encoder::rotary_encoder(PinName pinA, PinName pinB)
{
    read_encode_z  =nullptr;
    wa_encode_pinA  =new InterruptIn(pinA);
    wa_encode_pinB  =new InterruptIn(pinB);

    // read_encode_z->mode(ROTARY_ENCODER_DEFAULT_PIN_Z_PINMODE);

    wa_encode_pinA->rise(callback(this, &rotary_encoder::encode));//割り込み
    wa_encode_pinA->fall(callback(this, &rotary_encoder::encode));
    wa_encode_pinA->mode(ROTARY_ENCODER_DEFAULT_PIN_A_PINMODE);

    wa_encode_pinB->rise(callback(this, &rotary_encoder::encode));
    wa_encode_pinB->fall(callback(this, &rotary_encoder::encode));
    wa_encode_pinB->mode(ROTARY_ENCODER_DEFAULT_PIN_B_PINMODE);
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

int mbed::lib_ygdstmidn::rotary_encoder::get_count()const
{
    return encode_count;
}

void mbed::lib_ygdstmidn::rotary_encoder::set_pinmode(PinMode pinA, PinMode pinB, PinMode pinZ)
{
    wa_encode_pinA->mode(pinA);
    wa_encode_pinB->mode(pinB);
    if (read_encode_z!=nullptr)
    {
        read_encode_z->mode(pinZ);
    }
}

void rotary_encoder::set_ppr(uint set_ppr_uint)
{
    ppr=set_ppr_uint;
}

double rotary_encoder::get_angle()
{
    return (double)encode_count*360.0/ppr;
}

double rotary_encoder::get_angle_radian()
{
    return (double)encode_count/ppr*2.0*M_PI;
}

}//namespace lib_ygdstmidn
}//namespace mbed