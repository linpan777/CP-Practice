# 00272 - TEX Quotes

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=208&mosmsg=Submission+received+with+ID+31019966#google_vignette)

## Introduction:
The core of this problem is "string replacement." We need to read multiple lines of text and replace the double quotes (") with the specific format required by the problem. The replacement rule alternates: the first `"` -> `` ` ` ``, and the second `"` -> `''`. All other characters are output exactly as they are.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是「字串替換」，讀取多行文字，將雙引號 " 替換成題目要求的專屬格式，規則為交替進行：遇到的第一個 `"` -> `` ` ` ``，第二個 `"` -> `''`，其餘所有字元則照原樣輸出。
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `sentence` | Stores entire line of string data read by `getline` during each iteration |
| `check` | A boolean variable acting as a state toggle. It records whether the currently encountered double quote is an "opening" quote (0) or a "closing" quote (1). |

### version 1 - 邏輯:
```text
1. bool check = 0
2. while(getline(cin, sentence)) // Read line by line until EOF
3.      for(0 -> sentence.size() - 1) // Traverse each character
4.          if(sentence[i] == '"') // Check if it's a double quote
5.              if(check == 0)
6.                  cout ``
7.                  check = 1
8.              else
9.                  cout ''
10.                 check = 0
11.             continue
12.         cout sentence[i] // Output normal characters
13.     cout '\n' // Restore the newline character consumed by getline
```
<details>
<summary><head>點擊查看中文版</head></summary>
```text
1. 初始化 check = 0 (代表預期遇到的是開頭引號)
2. while(getline(cin, sentence)) //使用 getline 讀取直到 EOF
3.      for(0 -> sentence.size() - 1) //遍歷這行字串 sentence 中的每一個字元
4.          if(sentence[i] == '"') //如果當前字元是 '"'
5.              if (check == 0) // 如果是左引號
6.                  輸出 "``"
7.                  更新 check = 1 (切換狀態)
8.              else            // 如果是右引號
9.                  輸出 "''"
10.                 更新 check = 0 (切換狀態)
11.             continue // 處理完引號，跳過後續步驟，直接進入下一次迴圈
12.         輸出 sentence[i] //如果不是引號，就正常印出原本的字元
13.     輸出 '\n' 換行 //因為 getline 會把換行符號吃掉，輸出時需手動補回
```
```text

</details>

## Complexity:
### Time Complexity: $O(N)$
> Where $N$ is the total number of characters in the input data.

### Space Complexity: $O(L)$
> Where $L$ is the length of the longest line in the input data.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: $O(N)$
> $N$ 為輸入資料的總字元數。

### Space Complexity: $O(L)$
> $L$ 為輸入資料中「最長一行」的長度
</details>

> [!Note]
> 1. 用for(char c: sentence)感覺會更好，但我好懶得改，就先這樣