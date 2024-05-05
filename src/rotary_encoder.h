#ifndef INCLUDE_ROTARY_ENCODER_H
#define INCLUDE_ROTARY_ENCODER_H

#include "mbed.h".
#include "rotary_encoder_config.h"

#ifndef M_PI//M_PIが定義されていないならば定義
#define M_PI		3.14159265358979323846
#endif//M_PI
#ifndef _SYS_TYPES_H//uintが定義されていないならば定義
typedef	unsigned int	uint;		/* System V compatibility */
#endif//_SYS_TYPES_H

namespace mbed
{
namespace lib_ygdstmidn
{

const int encode_table[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

class rotary_encoder
{
private:

    int encode_count=0;
    uint gear_teeth=1;
    uint ppr=ROTARY_ENCODER_DEFAULT_PPR;

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

    /**
     * ロータリーエンコーダの角度を返します(度数法)．
     * @return ロータリーエンコーダの角度(double)
    */
    double get_angle();

    /**
     * ロータリーエンコーダの角度を返します(弧度法)．
     * @return ロータリーエンコーダの角度(double)
    */
    double get_angle_radian();

    /**
     * ロータリーエンコーダについているギアの歯数を設定します．
     * @param set_teeth_uint 設定したい歯数
    */
    void set_teeth(uint set_teeth_uint);

    /**
     * 設定されているギアの歯数を返します．
     * @return 設定されているギアの歯数
    */
    uint get_teeth();

};//class rotary_encoder

class rotary_encoder_gear
{
private:

    uint rotary_encoder_teeth;
    uint gear_teeth=1;

    rotary_encoder *rotary_encoder_ins;
    rotary_encoder_gear *gear_ins;

public:

    /**
     * ロータリーエンコーダにくっつけるギアのインスタンスを作成します．
     * @param rotary_encoder_address くっつけるロータリーエンコーダのアドレス
    */
    rotary_encoder_gear(rotary_encoder *rotary_encoder_address);

    /**
     * ギアにくっつけるギアのインスタンスを作成します．
     * @param rotary_encoder_gear_address くっつけるギアのアドレス
    */
    rotary_encoder_gear(rotary_encoder_gear *rotary_encoder_gear_address);

    ~rotary_encoder_gear();

    /**
     * ギアの歯数を設定します．
     * @param set_teeth_uint 設定したい歯数
    */
    void set_teeth(uint set_teeth_uint);

    /**
     * 設定されているギアの歯数を返します．
     * @return 設定されているギアの歯数
    */
    uint get_teeth();
};

}//namespace lib_ygdstmidn
}//namespace mbed

using namespace mbed::lib_ygdstmidn;

#endif//INCLUDE_ROTARY_ENCODER_H