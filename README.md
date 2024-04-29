# このライブラリについて
ロータリーエンコーダを使うためのライブラリです．
namespaceはmbed::lib_ygdstmidnです．ヘッダファイル内でusingしています．

# 使い方

## rotary_encoder_config.hについて

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
```

### 初期化
`rotary_encoder rorikonname(pinA,pinB,pinZ);`
`rotary_encoder rorikonname(pinA,pinB);`
ロータリーエンコーダの値を読み取るためのインスタンスを作成します

パラメーター:
pinA – ロータリーエンコーダのAチャンネル
pinB – ロータリーエンコーダのBチャンネル
pinZ – ロータリーエンコーダのZチャンネル,INDEXチャンネル(省略可)

### ロータリーエンコーダの値を読み取る
`val = rorikonname.get_count();`
ロータリーエンコーダの変位を返します．
int型の値が返ってきます．

戻り値:
ロータリーエンコーダの変位(int)