# UVa 00490 - Rotating Sentences

## Problem Description
Brief description of the problen -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=431)


## Learning Objectives
1. <ruby>Matrix<rt>*矩陣*</rt></ruby> Rotation Logic
2. Boundary & <ruby>Padding<rt>*補位*</rt></ruby> Handling

## Thinking
### variable reference
| variable | meaning |
| :--- | :--- |
| `sentences[]` | Two-dimensional string to store every lines |
| `line` | horizontally read data (Rows) |
| `max_row` | vertical read data (the max column) |

~~這邊行列不小心搞混了~~
> [!IMPORTANT]
> 列 = row``horizontally``<br>
> 行 = column``vertical``

### Algorithm logic
```text
main：
1. Initialize line_count = 0, max_len = 0
2. while (read input into sentences[line_count])
3.      if (sentences[line_count].size() > max_len)
4.          max_len = sentences[line_count].size()
5.      line_count++
6. 
7. for i from 0 to max_len - 1:
8.      for j from line_count - 1 down to 0:
9.          if (sentences[j].size() <= i) 
10.             print ' '
11.         else 
12.             print sentences[j][i]
13.     print '\n'
```
<details>
<summary> <head>點擊查看中文版<head> </summary>

```text
1. 初始化 總行數 (line_count) = 0, 最大長度 (max_len) = 0
2. 當 (成功讀取一行輸入 到 sentences[總行數]) 時：
3.      如果 (當前句子的長度 > 最大長度)
4.          更新 最大長度 = 當前句子的長度
5.      總行數 + 1
6. 
7. 迴圈 i 從 0 跑到 (最大長度 - 1)：         // 外層迴圈：負責印出每一列 (對應原字串的字元位置)
8.      迴圈 j 從 (總行數 - 1) 倒著跑到 0：   // 內層迴圈：負責從最後一句話往前讀取 (對應原字串的行數)
9.          如果 (sentences[j] 的長度 <= i)： // 代表這句話不夠長，該位置已經沒有字元了
10.             印出 空白鍵 (' ')            // 補位，維持矩陣形狀
11.         否則：
12.             印出 sentences[j][i]        // 印出對應的字元
13.     印出 換行 ('\n')                     // 這一列印完了，換下一列
```

</details>

## Challenges
1. Index Mix-up <sub>Row vs. Column</sub>
2. Space <ruby>padding<rt>填充</rt></ruby> for <ruby>insufficient<rt>*不足的*</rt><ruby> length

## New code struct
<details>
<summary> <head>click to open<head> </summary>

```C++
#include<iostream>
#include<string>
using namespace std;

string sentences[101] = {};

int main()

{
    ios::sync_with_stdio(0), cin.tie(0);

    int row{0}, max_colum{0};
    while(getline(cin, sentences[++row]))//一口氣讀入每一列，直到EOF，並且紀錄max字數
        if(max_colum < sentences[row].size())
            max_colum = sentences[row].size();

    for(int i{0}; i < max_colum; i++)
    {
        for(int j{row - 1}; j >= 1; j--)//row - 1是因為row最後會因為eof多加1，變成空行
            if(sentences[j].size() - 1 < i)//判斷如果該列字數不夠，就補空格
                cout << ' ';
            else
                cout << sentences[j][i];//如果字數夠，就照正常輸出旋轉後的矩陣
        cout << '\n';
    }
}
```

</details>

[source code](v2(更好).cpp)

## <ruby>Optimization<rt>*優化*</rt></ruby> Points:
1. Removed wrong variable name

## Complexity Analysis
- Time complexity： $O(N \times M)$
- Space complexity： $O(N \times M)$

> [!Note]
> 1. 我真的好討厭行列問題，每次腦子都脹痛
> 2. 明天我將學習矩陣轉移！！！