## rimeの使い方
[rime 1.0 documentation](http://nya3jp.github.io/rime/)

# コイン集めゲーム
## 問題概要
プレーヤーを動かしマップ上のコインを全て集めるゲームを行います．
コインを全て集めるのに必要なコストの最小値を求めましょう．

高さ$H$，幅$W$の大きさのマップが与えられます．
また，マップ上にコインは$N$枚置いてあリます．

あなたはゲームの開始時に，マップ上の好きな箇所にプレーヤーを置くことができます．
プレーヤーは上下左右の4方向にのみ移動することができます．

マップの情報は次のように与えられます．
```
3 4
1141
5123
1##1
```

最初の1行はマップの高さと幅を表します．
続く数字はH行W列のマップを表現しています．

数字はその箇所に移動するのに，プレーヤーが必要とするコストを表します．
例えば，現在（2, 3）の箇所，つまり数字2の箇所にいるとします．

- 箇所（2，2）へ移動するにはコスト1が掛かります，
- 箇所（1，3）へ移動するにはコスト4が掛かります，
- 箇所（2，4）へ移動するにはコスト3が掛かります．

また，（2，3）の箇所から（1，1）の箇所へ移動する場合は，
最低でもコスト3が掛かります．

'#'は移動不可能な箇所を表します．
この箇所にはどの方向からも移動できません．
ただし，すでにその箇所にいる場合，他の箇所へ移動することができます．

マップにはコインが$N$枚置いてあります．
一つの箇所には高々1つのコインが置いてあります．
どこに置いてあるかは次のように与えられます．
```
4
1 1
1 4
2 3
3 1
```
最初の1行はいくつのコインが置いてあるか，つまり$N$を表します．
続くN行は，どの箇所にコインが置いてあるかを表します．
この例の場合，（1, 1）， （1, 4）， （3, 1）， （2, 2）の箇所にコインが置いてあります．

つまり，コインは次のように置いてあります．
```
@..@
..@.
@...
```

## 入力
入力は次のように与えられます
```
H W
line_1
line_2
...
line_i
...
line_H
N
x_1 y_1
x_2 y_2
...
x_i y_i
...
x_N y_N
```
$H$はマップの高さを，$W$はマップの幅を表します．
続く$H$行はマップを表す文字列です．
line_iは[1, 9]の数値，もしくは'#'で構成される長さWの文字列です．
$N$はコインの枚数を表します．
続く$N$行がコインが置いてある場所を表します．

## 出力
コインが全て集められる場合にはその最小のコストを1行に出力してください．
ただし，どうやっても全てを集められない場合は-1を出力してください．

## 制約
入力は以下の制約を満たします．

- 1 <= H, W <= 30
- 1 <= N <= 14
- 1 <= x_i <= H
- 1 <= y_i <= W

## 入力例1
```
3 3
111
1#1
111
3
1 1
1 3
3 3
```

## 出力例1
```
4
```
始めに箇所（1, 1）にプレーヤーを置きます．
その後（1，2），（1，3），（2，3），（3，3）と移動することで，
コスト4で全てのコインを集めることができます．
開始時にプレーヤーを置く際にコストはかかりません．注意してください．

## 入力例2
```
3 4
1141
5123
1##1
4
1 1
1 4
2 3
3 1
```

## 出力例2
```
14
```

## 入力例3
```
2 3
##1
1#1
2
2 1
2 2
```

## 出力例3
```
1
```

## 入力例4
```
2 3
##1
1#1
3
2 1
2 3
1 1
```

## 出力例4
```
-1
```
どうやっても全てのコインを集めることはできません．
