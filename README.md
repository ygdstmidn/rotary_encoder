# このライブラリについて
ロータリーエンコーダを使うためのライブラリです．
namespaceはmbed::lib_ygdstmidnです．ヘッダファイル内でusingしています．

# 使い方

## rotary_encoder_config.hについて

rotary_encoder_config.hの内容はクラスに適用されます．
よって，インスタンスごとに違う内容を設定したいときは，インスタンスごとで設定しなければなりません．

### DEFAULT_PINMODE
```rotary_encoder_config.h
#define DEFAULT_PIN_A_PINMODE       PullUp
#define DEFAULT_PIN_B_PINMODE       PullUp
#define DEFAULT_PIN_Z_PINMODE       PullUp
```
開発ボードのプルアップ抵抗をonにするか，offにするかを選択します．
開発ボードにそのまま接続するときはPullUp，プルアップ抵抗を入れているときはPullNoneにすると良いと思います．

## プログラム

↓一覧です．
```c++
rotary_encoder(PinName pinA,PinName pinB,PinName pinZ);
int get_count()const;
void set_pinmode(PinMode pinA,PinMode pinB,PinMode pinZ);
```

### 初期化
`rotary_encoder rorikonname(pinA,pinB,pinZ);`<br>
`rotary_encoder rorikonname(pinA,pinB);`<br>
ロータリーエンコーダの値を読み取るためのインスタンスを作成します

パラメーター:<br>
pinA – ロータリーエンコーダのAチャンネル<br>
pinB – ロータリーエンコーダのBチャンネル<br>
pinZ – ロータリーエンコーダのZチャンネル,INDEXチャンネル(省略可)<br>

### ロータリーエンコーダの値を読み取る
`val = rorikonname.get_count();`
ロータリーエンコーダの変位を返します．<br>
int型の値が返ってきます．

戻り値:<br>
ロータリーエンコーダの変位(int)

### ピンのmodeを変える
`void set_pinmode(PinMode pinA,PinMode pinB,PinMode pinZ);`
それぞれのピンごとにmodeを設定します．<br>
PullUp, PullDown, PullNone, OpenDrain

パラメーター:<br>
pinA – Aチャンネルのmode<br>
pinB – Bチャンネルのmode<br>
pinZ – Zチャンネルのmode<br>

注:<br>
Zチャンネルを設定していない場合，modeは設定されません．<br>