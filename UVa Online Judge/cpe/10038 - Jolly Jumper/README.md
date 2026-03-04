# 10038 - Jolly Jumper

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979)

## Thinking

### variable reference
| variable | meaning |
| :--- | :--- |
| `n` | The total number of integers in the current sequence |
| `jolly` | A boolean flag initialized to true, used to track whether the sequence is a Jolly Jumper |
| `number[]` | A boolean array initialized to false, used as a checklist to mark which absolute differences have appeared |
| `first` | Stores the previously read integer, used to calculate the absolute difference with the current integer |
| `second` | Stores the current integer being read in the loop |

### 邏輯:
```text
1. input n
2. bool jolly = true, bool number[3000] = false;
3. input first
4. for(1 -> n - 1)
5.      cin second
6.      number[abs(first - second)] = true
7.      first = second
8. for(1 -> n - 1)
9.      if(number[i] == false), jolly = false, break
10.     else, continue
11. if(jolly) cout Jolly
12. else cout Not Jolly
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 輸入 n
2. 設定bool jolly = true，以及bool number[3000] = {false}
3. 輸入第一個數字，存入 first
4. 執行迴圈 (執行 n - 1 次)：
5.      輸入下一個數字，存入 second
6.      將陣列 number[abs(first - second)] 的位置標記為 true
7.      將 second 的值交給 first
8. 執行迴圈 i (從 1 到 n - 1)：
9.      如果 number[i] 等於 false，則 jolly = false 並跳出迴圈 (break)
10.     否則，繼續下一圈 (continue)
11. 如果 jolly 為 true，輸出 "Jolly"
12. 否則，輸出 "Not jolly"
```
</details>