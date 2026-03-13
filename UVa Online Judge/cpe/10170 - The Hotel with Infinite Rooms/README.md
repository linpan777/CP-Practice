# 10170 - The Hotel with Infinite Rooms

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111)

## Introduction:
The core of this problem is "simulation" or "sequence progression." Given an initial group size S, that group stays for S days. The next group has S+1 members and stays for S+1 days. We need to find the group size on a specific day D. We can simulate this by continuously subtracting the current group size from the target day until the remaining day is less than or equal to 0.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是「模擬」或「數列推導」。給定初始團體人數 S，他們會住 S 天，下一組人數為 S+1，會住 S+1 天。我們需要找出第 D 天時飯店內的團體人數。可以透過不斷將目標天數減去當前人數，直到天數小於等於 0，此時的人數即為解答。
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `people` | The size of the current group staying in the hotel |
| `day` | The remaining days to reach the target day |

## 邏輯:
```text
1. while cin people, day // Read inputs until EOF
2.      while(day != 0) // Autually it's unless, use true is OK
3.          day -= people // Subtract current group size from remaining days
4.          if(day <= 0) // Reached or passed the target day
5.              break
6.          else
7.              people++ // Move to the next group
8.      cout people
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. while cin people, day // 讀取初始人數與目標天數直到 EOF
2.      while(day != 0) //其實沒用，直接用 true 也可以
3.          day -= people // 將目標天數減去當前這組人住的天數
4.          if(day <= 0) // 如果天數扣完 <= 0，代表已經到了要求的天數
5.              break
6.          else
7.              people++ // 換下一組人 (人數加 1)
8.      cout people
```
</details>

## Complexity
### Time Complexity: $O(\sqrt{D})$
> Where $D$ is the target day
### Space Complexity: $O(1)$
> Only a few standard variables `people, day` are used, which takes constant memory space regardless of the input size

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: $O(\sqrt{D})$
> $D$ 為目標天數
### Space Complexity: $O(1)$
> 只需要使用幾個基本變數 (people, day) 來計算，無論輸入的數字多大，佔用的記憶體空間都是固定的常數
</details>