#ifndef INCLUDE_ROTARY_ENCODER_H
#define INCLUDE_ROTARY_ENCODER_H

#include "mbed.h"

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

    DigitalIn *read_encode_z;

    InterruptIn *wa_encode_pinA;
    InterruptIn *wa_encode_pinB;

    void encode();
public:
    /**
     * @brief ロータリーエンコーダの値を読み取るためのインスタンスを作成します
     * @brief 初期化の際にプログラム上でPULLUPするので，他でプルアップする必要はありません
     * @param pinA ロータリーエンコーダのAチャンネル
     * @param pinB ロータリーエンコーダのBチャンネル
     * @param pinZ ロータリーエンコーダのZチャンネル,INDEXチャンネル
    */
    rotary_encoder(PinName pinA,PinName pinB,PinName pinZ);

    /**
     * ロータリーエンコーダの値を読み取るためのインスタンスを作成します
     * 初期化の際にプログラム上でPULLUPするので，他でプルアップする必要はありません
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
};

}//namespace lib_ygdstmidn
}//namespace mbed

using namespace mbed::lib_ygdstmidn;

#endif