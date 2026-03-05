# 10812 - Beat the Spread!

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870)

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | Number of test cases |
| `total` | Sum of the two final scores |
| `difference` | Absolute difference between the two final scores |
| `a` | The higher score |
| `b` | The lower score |

### 邏輯:
```text
1. input T
2. while(T--)
3.      input total, difference
4.      if total < difference OR (total + difference) is odd:
5.          cout "impossible"
6.      else:
7.          a = (total + difference) / 2
8.          b = a - difference
9.          cout a << " " << b
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 輸入 T (測資數量)
2. 迴圈執行 T 次
3.      輸入 total (總和), difference (差值)
4.      如果 總和小於差值 或 (總和 + 差值) 無法被 2 整除:
5.          輸出 "impossible"
6.      否則:
7.          計算大數: a = (total + difference) / 2
8.          計算小數: b = a - difference
9.          輸出 a 與 b (a 一定大於等於 b)
```
</details>