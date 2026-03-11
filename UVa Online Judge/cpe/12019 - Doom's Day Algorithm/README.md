# 12019 - Doom's Day Algorithm

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=3170)

## 簡介:
要求計算給定 2011 年的特定日期（月、日），判斷該天是星期幾。
1. 2011 年是平年，可以使用內建的 C 時間函式庫直接轉換。<br>
2. 或是利用「每月天數陣列」計算總天數後，以同餘運算（模運算）推導出星期。

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `month` | The target month |
| `date` | The target date |
| `wday` | An array to store the names of the days of the week |
| `time_info` | <sub>Used in `V1`</sub> A `tm` struct to store date information and automatically calculate the weekday via `mktime` |
| `month_a` | <sub>Used in `V2`</sub> An array storing the number of days in each month for a non-leap year |
| `day` | <sub>Used in `V2`</sub> Accumulates the total number of days passed in the previous months |
> via = 通過
> accumulates = 累積

### version 1 - 邏輯:
```text
1. cin >> T
2. while(T--)
3.      cin month, date
4.      Initialize tm time_info(0)
5.      time_info.tm_year = 2011 - 1900 // Years since 1900
6.      time_info.tm_mon = month - 1 // Months are 0-indexed (0-11)
7.      time_info.tm_mday = date
8.      mktime(&time_info) // Automatically computes the weekday (tm_wday)
9.      cout wday[time_info.tm_wday]
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀入 T (測資數量)
2. while迴圈 (執行 T 次)
3.      讀入 month, date
4.      初始化 tm time_info 為 0
5.      設定 time_info 的年份為 2011 - 1900 (距離 1900 年的年數)
6.      設定 time_info 的月份為 month - 1 (月份從 0 開始算)
7.      設定 time_info 的日期為 date
8.      呼叫 mktime(&time_info) 自動計算星期幾並存入 tm_wday
9.      輸出 wday[time_info.tm_wday]
```
```text
string wday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
```
</details>

### version 2 - 邏輯:
```text
1. cin >> T
2. while(T--)
3.      cin >> month >> date
4.      Initialize day = 0
5.      for(i = 0 -> month - 1) // Accumulate days of previous months
6.          day += month_a[i]
7.      cout wday[(day + date) % 7] << '\n'
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀入 T
2. while迴圈 (執行 T 次)
3.      讀入 month 和 date
4.      初始化 day = 0
5.      for迴圈 (i 從 0 跑到 month - 1) // 累加目標月份之前的所有天數
6.          day += month_a[i]
7.      輸出 wday[(day + date) % 7] 並換行
```
```text
string wday[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
int month_a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```
</details>