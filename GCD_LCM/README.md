# 最大公約数と最小公倍数
## 最大公約数（Greatest Common Divisor）
最大公約数とは与えられた複数の整数の共通の約数のうち最大なもの。例えば2つの整数 $`A, B`$ の最大公約数は， $`A=ag, B=bg`$が存在するような最大の整数 $`g`$ である。

### ユークリッドの互除法
ユークリッドの互除法は，2つの整数の最大公約数を求めるアルゴリズム。2つの正の整数 $`A, B`$ （ただし$` A \geqq B`$）について， $`A`$ を $`B`$ で割ったときの剰余を $`r`$ とすると，$`A`$ と $`B`$ の最大公約数$`g`$ は，$`B`$と$`r`$の最大公約数に等しい。ここで$`g`$ を使って，$`A=ag, B=bg`$であるから，以下の式が成り立つ。

```math
A - B = g (a - b)
```

つまり，$` A, B, A - B `$は最大公約数$`g`$を持つ。ここから$`A`$と$`B`$の最大公約数は，$`B`$と$`A-B`$の最大公約数は等しい。さらに$`A`$と$`B`$の最大公約数は，$`B`$と$`A-2B`$の最大公約数は等しく，$`A`$と$`B`$の最大公約数は，$`B`$と$`A-3B`$の最大公約数は等しい。これを繰り返すと，$`A`$と$`B`$の最大公約数は，$`B`$と$`A-qB`$の最大公約数は等しい。ここで，$`A`$を$`B`$で割ったときの余りを$`r`$とすると，

```math
A = qB + r
```
が成り立ち，これを変形すると，
```math
r = A - qB
```
従って，$`A`$と$`B`$の最大公約数は，$`B`$と$`r`$（$`A`$と$`B`$の剰余）の最大公約数は等しい。

## 最小公倍数（Least Common Multiple）
最小公倍数とは与えられた複数の整数の共通の倍数のうち最小なもの。

### 最大公約数と最小公倍数の関係
2つの整数 $`A, B`$ の最大公約数を$` g `$，最小公倍数を$` l `$とすると以下の関係がある。

```math
A B = g l
```

従って，最大公約数を$` g `$を使って最小公倍数を$` l `$は以下のように求めることができる。
```math
l = \frac{AB}{g}
```

