# 4章 式と演算子
## サンプルコード
| セクション | ファイル名 | 内容 |
| ---      | ---      | ---       |
| 4.1 式のしくみを知る | [Sample1.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample1.c) | 式の値を出力する|
| 4.1 | [Sample2.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample2.c) | 変数の値をつかう|
| 4.1 | [Sample3.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample3.c) | たし算プログラム|
| 4.2 演算子の種類 | [Sample4.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample4.c) | いろいろな演算子 |
| 4.2 | [Sample5.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample5.c) | 前置・後置インクリメント演算子を使う |
| 4.2 | [Sample6.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample6.c) | 複合的な代入演算子を使う |
| 4.2 | [Sample7.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample7.c) | sizeof演算子を使う |
| 4.4 型変換 | [Sample8.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample8.c) | 大きなサイズの型に代入 |
| 4.4 | [Sample9.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample9.c) | 小さなサイズの型に代入 |
| 4.4 | [Sample10.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample10.c) | 異なる型の演算 |
| 4.4 | [Sample11.c](https://github.com/202408pythonciot/C_lang/blob/main/Lesson_04/Sample/Sample11.c) | 同じ型の演算 |

## 演算子
| 優先順位 | 記号 | 演算子名 | 書式 | 式の値(評価結果) |
| ---      | ---       | ---       | ---       | ---       |
| 4 (左) | * | 乗算 | `a * b` | $` a \times b `$ |
| 4 (左) | / | 除算 | `a / b` | $` a \div b `$ |
| 4 (左) | % | 剰余 | `a % b` | $`a`$を$`b`$で割った余り  |
| 5 (左) | + | 加算 | `a + b` | $` a + b `$ |
| 5 (左) | - | 減算 | `a - b` | $` a - b `$ |
| 6 (左) | << | 左シフト | `a << b` | $`a`$を左に$`b`$ビットシフトした値 |
| 6 (左) | >> | 右シフト | `a >> b` | $`a`$を右に$`b`$ビットシフトした値 |
| 7 (左) | < | 小なり | `a < b` | $`a < b`$なら$`1`$，そうでなければ$`0`$ |
| 7 (左) | <= | 以下 | `a <= b` | $`a <= b`$なら$`1`$，そうでなければ$`0`$ |
| 7 (左) | >= | 以上 | `a >= b` | $`a >= b`$なら$`1`$，そうでなければ$`0`$ |
| 7 (左) | > | 大なり | `a > b` | $`a > b`$なら$`1`$，そうでなければ$`0`$ |

