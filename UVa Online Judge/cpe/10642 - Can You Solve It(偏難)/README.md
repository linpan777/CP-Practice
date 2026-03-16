# 10642 - Can You Solve It?

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1583&mosmsg=Submission+received+with+ID+31003568)

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `x1, y1` | Coordinates of the source circle |
| `x2, y2` | Coordinates of the destination circle |
| `sum1, sum2` | The layer number ($x + y$) for the source and destination |
| `answer1, answer2` | The total steps from the origin $(0,0)$ to the respective coordinates |
<sub>layer = 層數</sub>

### 邏輯:
```text
Logic:
1. input T
2. while(T--)
3.      input x1, y1, x2, y2
4.      sum1 = x1 + y1, sum2 = x2 + y2
5.      long long answer1 = sum1 * (sum1 + 1) / 2
6.      long long answer2 = sum2 * (sum2 + 1) / 2
7.      answer2 += (x2 - answer1 - x1)
8.      cout "Case " << time << ": " << answer2
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
邏輯:
1. 輸入 T (測資數量)
2. 迴圈執行 T 次
3.      輸入 x1, y1 (起點), x2, y2 (終點)
4.      計算所在層數: sum1 = x1 + y1, sum2 = x2 + y2
5.      算起點絕對距離: long long answer1 = sum1 * (sum1 + 1) / 2
6.      算終點絕對距離: long long answer2 = sum2 * (sum2 + 1) / 2
7.      計算總步數: answer2 += (x2 - answer1 - x1)
8.      輸出 Case 編號與答案 answer2
```
</details>