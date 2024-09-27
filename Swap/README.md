# 値の交換
変数 `a`と`b`の値を交換するためには，直接交換することはできない。

## 一時変数を使う

```
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
```

## 排他的論理和で値交換
一時変数を使うことなく値を交換できる。

```
void swap(int *x, int *y)
{
    *y ^= *x;
    *x ^= *y;
    *y ^= *x;
}
```
