#ifndef INCLUDE_ROTARY_ENCODER_H
#define INCLUDE_ROTARY_ENCODER_H

#include "mbed.h".
#include "rotary_encoder_config.h"

namespace mbed
{
namespace lib_ygdstmidn
{

const int encode_table[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

class rotary_encoder
{
private:
    int encode_count=0;
    uint ppr=RORIKON_DEFAULT_PPR;

    DigitalIn *read_encode_z;

    InterruptIn *wa_encode_pinA;
    InterruptIn *wa_encode_pinB;

    void encode();
public:
    /**
     * ロータリーエンコーダの値を読み取るためのインスタンスを作成します
     * @param pinA ロータリーエンコーダのAチャンネル
     * @param pinB ロータリーエンコーダのBチャンネル
     * @param pinZ ロータリーエンコーダのZチャンネル,INDEXチャンネル
    */
    rotary_encoder(PinName pinA,PinName pinB,PinName pinZ);

    /**
     * ロータリーエンコーダの値を読み取るためのインスタンスを作成します
     * @param pinA ロータリーエンコーダのAチャンネル
     * @param pinB ロータリーエンコーダのBチャンネル
    */
    rotary_encoder(PinName pinA,PinName pinB);
    ~rotary_encoder();

    /**
     * ロータリーエンコーダの変位を返します．
     * @return ロータリーエンコーダの変位(int)
    */
    int get_count()const;

    /**
     * それぞれのピンごとにmodeを設定します．
     * PullUp, PullDown, PullNone, OpenDrain
     * @param pinA Aチャンネルのmode
     * @param pinB Bチャンネルのmode
     * @param pinZ Zチャンネルのmode
     * @note Zチャンネルを設定していない場合，modeは設定されません．
    */
    void set_pinmode(PinMode pinA,PinMode pinB,PinMode pinZ);

    /**
     * ロータリーエンコーダのPPRを設定します．
     * @param set_ppr_uint 設定したいPPR
    */
    void set_ppr(uint set_ppr_uint);
};

}//namespace lib_ygdstmidn
}//namespace mbed

using namespace mbed::lib_ygdstmidn;

#endif