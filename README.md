# このライブラリについて
ロータリーエンコーダを使うためのライブラリです．<br>
namespaceはmbed::lib_ygdstmidnです．ヘッダファイル内でusingしています．

# 使い方

## rotary_encoder_config.hについて

rotary_encoder_config.hの内容はクラスに適用されます．<br>
よって，インスタンスごとに違う内容を設定したいときは，インスタンスごとで設定しなければなりません．

### DEFAULT_PINMODE
```rotary_encoder_config.h
#define ROTARY_ENCODER_DEFAULT_PIN_A_PINMODE       PullUp
#define ROTARY_ENCODER_DEFAULT_PIN_B_PINMODE       PullUp
#define ROTARY_ENCODER_DEFAULT_PIN_Z_PINMODE       PullUp
```
開発ボードのプルアップ抵抗をonにするか，offにするかを選択します．<br>
開発ボードにそのまま接続するときはPullUp，プルアップ抵抗を入れているときはPullNoneにすると良いと思います．

### PPR
```rotary_encoder_config.h
#define ROTARY_ENCODER_DEFAULT_PPR                 400
```
ロータリーエンコーダのPPR(Pulses Per Revolution)，1回転当たりのパルス数を設定します．分解能ともいうそうです．

## プログラム

↓一覧です．
```c++
//rotary_encoderクラス
rotary_encoder(PinName pinA,PinName pinB,PinName pinZ);
int get_count()const;
void set_pinmode(PinMode pinA,PinMode pinB,PinMode pinZ);
void set_ppr(uint set_ppr_uint);
double get_angle()const;
double get_angle_radian()const;
void set_teeth(uint set_teeth_uint);
uint get_teeth()const;
//rotary_encoder_gearクラス
rotary_encoder_gear(rotary_encoder *rotary_encoder_address);
rotary_encoder_gear(rotary_encoder_gear *rotary_encoder_gear_address);
void set_teeth(uint set_teeth_uint);
uint get_teeth()const;
double get_angle()const;
double get_angle_radian()const;
```

rotary_encoderという名前のクラスがあるので，ロータリーエンコーダ一つ一つごとにrotary_encoderのインスタンスを作成してください．<br>
ロータリーエンコーダにつながっているギアがある場合，そのギアごとにrotary_encoder_gearのインスタンスを作成してください．<br>

### rotary_encoderクラス

#### 初期化
```c++
rotary_encoder name(pinA,pinB,pinZ);
```
```c++
rotary_encoder name(pinA,pinB);
```
ロータリーエンコーダの値を読み取るためのインスタンスを作成します

パラメーター:<br>
pinA – ロータリーエンコーダのAチャンネル<br>
pinB – ロータリーエンコーダのBチャンネル<br>
pinZ – ロータリーエンコーダのZチャンネル,INDEXチャンネル(省略可)<br>

#### ロータリーエンコーダの値を読み取る
```c++
val = name.get_count();
```
ロータリーエンコーダの変位を返します．<br>
int型の値が返ってきます．

戻り値:<br>
ロータリーエンコーダの変位(int)

#### ピンのmodeを変える
```c++
name.set_pinmode(pinA_mode,pinB_mode,pinZ_mode);
```
それぞれのピンごとにmodeを設定します．<br>
PullUp, PullDown, PullNone, OpenDrain

パラメーター:<br>
pinA_mode – Aチャンネルのmode<br>
pinB_mode – Bチャンネルのmode<br>
pinZ_mode – Zチャンネルのmode<br>

注:<br>
Zチャンネルを設定していない場合，modeは設定されません．<br>

#### ロータリーエンコーダのPPRを変える
```c++
name.set_ppr(ppr);
```
ロータリーエンコーダのPPRを設定します．

パラメーター:<br>
ppr – 設定したいPPR<br>

#### ロータリーエンコーダの角度を取得する
```c++
val = name.get_angle();
```
ロータリーエンコーダの角度を返します(度数法)．

戻り値:<br>
ロータリーエンコーダの角度(double)

#### ロータリーエンコーダの角度を弧度法で取得する
```c++
val = name.get_angle_radian();
```
ロータリーエンコーダの角度を返します(弧度法)．

戻り値:<br>
ロータリーエンコーダの角度(double)

#### ロータリーエンコーダについているギアの歯数を設定する
```c++
name.set_teeth(teeth);
```
ロータリーエンコーダについているギアの歯数を設定します．

パラメーター:<br>
teeth – 設定したい歯数

#### 設定されているギアの歯数を取得する
```c++
val = name.get_teeth();
```
設定されているギアの歯数を返します．

戻り値:<br>
設定されているギアの歯数

### rotary_encoder_gearクラス

#### 初期化
```c++
rotary_encoder_gear gearname(*rotary_encoder_address);
```
ロータリーエンコーダにくっつけるギアのインスタンスを作成します．

パラメーター:<br>
rotary_encoder_address – くっつけるロータリーエンコーダのアドレス

```c++
rotary_encoder_gear gearname(*rotary_encoder_gear_address);
```
ギアにくっつけるギアのインスタンスを作成します．<br>

パラメーター:<br>
rotary_encoder_gear_address – くっつけるギアのアドレス

#### ギアの歯数を設定する
```c++
gearname.set_teeth(teeth);
```
ギアの歯数を設定します．

パラメーター:<br>
teeth – 設定したい歯数

#### 設定されているギアの歯数を取得する
```c++
val = gearname.get_teeth();
```
設定されているギアの歯数を返します．

戻り値:<br>
設定されているギアの歯数

#### ギアの角度を取得する
```c++
val = gearname.get_angle();
```
ギアの角度を返します(度数法)．

戻り値:<br>
ギアの角度(double)

#### ギアの角度を弧度法で取得する
```c++
val = gearname.get_angle_radian();
```
ギアの角度を返します(弧度法)．

戻り値:<br>
ギアの角度(double)