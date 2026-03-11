# 11461 - Square Numbers

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2456)

## 簡介：
要求計算給定區間 `[first, last] 內包含了多少個「完全平方數」`

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- | 
| `first` | The starting number of the range |
| `last` | The ending number of the range |
| `count` | Stores the total number of perfect squares within the range |
| `number`| <sub>Used in `V1`</sub> Stores the truncated square root to verify if i is a perfect square |

### version 1 - 邏輯:
```text
1. cin first, last
2. Initialize count //Avoid affecting the next test case
3. if first, last == 0; return 0
4. for(first -> last)
5.      number = sqrt(i) //Effectively convert the square root to an integer
6.      if(number*number == i)
7.          count++
8. cout count
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀入 first, last
2. 初始化 count //避免重覆到下一個測資
3. 如果 first 和 last 皆為 0; 結束程式 (return 0)
4. for迴圈 (從 first 跑到 last)
5.      number = sqrt(i) //有效讓平方根變為整數
6.      如果 (number * number == i)
7.          count 加 1
8. 輸出 count
```
</details>

### version 2 - 邏輯:
```text
1. cin >> first >> last
2. if(first == 0 && last == 0); return 0
3. count = (int)sqrt(last) - (int)sqrt(first - 1) //
4. cout count << '\n'
```
>Core (Math Formula O(1)):
>1. Calculate the number of perfect squares from 1 to last -> (int)sqrt(last)
>2. Calculate the number of perfect squares from 1 to first - 1 -> (int)sqrt(first - 1)
>3. count = (int)sqrt(last) - (int)sqrt(first - 1)

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀入 first 和 last
2. 如果 first 和 last 皆為 0; 結束程式 (return 0)
3. count = (int)sqrt(last) - (int)sqrt(first - 1) // 利用公式直接算出區間內的平方數數量
4. 輸出 count 並換行
```
> 核心 (數學公式 O(1)):
> 1. 計算從 1 到 last 之間的完全平方數數量 -> (int)sqrt(last)
> 2. 計算從 1 到 first - 1 之間的完全平方數數量 -> (int)sqrt(first - 1)
> 3. count = (int)sqrt(last) - (int)sqrt(first - 1)
</details>