# 10093 - An Easy Problem!

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1034&mosmsg=Submission+received+with+ID+31009847)

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `number_sy` | Store input string |
| `temp` | The converted integer value of the current character |
| `max` | The maximum character value found in the string <sub>determines the starting base</sub> |
| `total` | The sum of all character values in the string |
| `value` | A boolean flag to check if a valid base was successfully found |

> converted = 已轉換的

## 邏輯:
```text
1. while input number_sy:
2.      Initialize max = 0, total = 0, value = false.
3.      For each character in number_sy:
4.          Convert character to integer temp (0-9 -> 0-9, A-Z -> 10-35, a-z -> 36-61).
5.          Update max to keep track of the largest character value.
6.          total += temp
7.      if max == 0 (e.g., input is "0"):
8.          print 2 (the smallest possible base) and continue.
9.      For n from (max + 1) to 62:
10.         if total % (n - 1) == 0:
11.             print n
12.             value = true
13.             break
14.     if value is false:
15.         print "such number is impossible!"
```

<details>
<summary><head>點擊查看中文版</head><summary>

```text
1. 當持續輸入字串 number_sy:
2.      初始化 max = 0, total = 0, value = false。
3.      字串中的每一個字元:
4.          字元轉換對應temp (0-9 -> 0-9, A-Z -> 10-35, a-z -> 36-61)。
5.          更新 max 以記錄字串中出現過的最大數值 <sub>用來決定猜測的起點</sub>
6.          total += temp <sub>將數值加入總積分</sub>
7.      如果 max == 0 <sub>例如輸入全為 "0"</sub>:
8.          輸出min進位制2, continue
9.      使用迴圈讓 n 從 (max + 1) 測試到 62:
10.         如果 total % (n - 1) == 0 <sub>總積分能被進位制減一整除</sub>:
11.             輸出找到的最小進位制 n。
12.             將 value 設為 true, break。
13.     如果迴圈跑完 value 依然是 false:
14.         cout "such number is impossible!"
```
</details>