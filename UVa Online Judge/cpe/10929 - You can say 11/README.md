# 10929 - You can say 11

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870)

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `number` | Stores the large input integer as a string |
| `temp1` | The sum of digits at odd positions |
| `temp2` | The sum of digits at even positions |

### 邏輯:
```text
Core:
1. int temp1 = 0, temp2 = 0
2. for(i = size - 1 -> 0, i -= 2) 
   temp1 += number[i] - '0' (Sum of odd-positioned digits)
3. for(i = size - 2 -> 0, i -= 2) 
   temp2 += number[i] - '0' (Sum of even-positioned digits)
4. if(abs(temp1 - temp2) % 11 == 0) -> true (is a multiple of 11)
5. else -> false (is not a multiple of 11)
```
```text
Main (Outer I/O Control):
1. while(cin >> number)
2. if(number == "0") -> return 0 (Terminate if string is exactly "0")
3. Execute Core logic
4. cout formatted string based on Core result
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
核心 (11 的倍數判斷):
1. temp1 = 0, temp2 = 0
2. 從字串的「最後一位」開始，每次往前跳 2 格 (收集奇數位的數字)，加總到 temp1
3. 從字串的「倒數第二位」開始，每次往前跳 2 格 (收集偶數位的數字)，加總到 temp2
4. 計算 絕對值(temp1 - temp2) 
5. 如果算出來的差值可以被 11 整除 (餘數為 0)：
        判定：是 11 的倍數
6. 否則：
        判定：不是 11 的倍數

Main (輸入與流程控制):
1. 當 (持續讀入測資字串到 number)
2.      如果 number 剛好等於 "0"，直接結束程式
3.      把 number 丟進 Core 邏輯去算
4.      依照算出來的結果，印出 is / is not a multiple of 11.
```
</details>

> [!Note]
> 不能用`number[0] == '0'`，不嚴謹
> 使用`number == "0"`<sub>*雙引號*</sub>