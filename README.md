# このライブラリについて
ロータリーエンコーダを使うためのライブラリです．
namespaceはmbed::lib_ygdstmidnです．ヘッダファイル内でusingしています．

# 使い方

## 初期化
`rotary_encoder rorikonname(pinA,pinB,pinZ);`
`rotary_encoder rorikonname(pinA,pinB);`
ロータリーエンコーダの値を読み取るためのインスタンスを作成します
初期化の際にプログラム上でPULLUPするので，他でプルアップする必要はありません

パラメーター:
pinA – ロータリーエンコーダのAチャンネル
pinB – ロータリーエンコーダのBチャンネル
pinZ – ロータリーエンコーダのZチャンネル,INDEXチャンネル(省略可)

## ロータリーエンコーダの値を読み取る
`val = rorikonname.get_count();`
ロータリーエンコーダの変位を返します．
int型の値が返ってきます．

戻り値:
ロータリーエンコーダの変位(int)