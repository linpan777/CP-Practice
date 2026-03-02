# UVa 10008 - What's Cryptanalysis?

## Problem Description
Brief description of the problem -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949)

## Learning Objectives
1. Character <ruby>Manipulation<rt>*操縱*</rt></ruby> & ASCII concept
2. A-Z match 0-25 and used in array to store
3. Implicit Sorting (利用迴圈特性達成特定排序條件)
4. Input Buffer Handling (`cin.ignore()`)

## Thinking
### variable reference
| variable | meaning |
| :--- | :--- |
| `character[]` | Array to store the frequency of each alphabet letter (A-Z) |
| `T` | The number of text lines to read |
| `sentences` | String buffer to store each line of input |
| `max` | The highest frequency count among all letters |

### Algorithm logic
```text
main:
1. cin T  T
2. cin.ignore()
3. max = 0, character[26] = {0}
4. while (T-- > 0):
5.      getline(cin, sentences)
6.      for(char c: sentences):
7.          if(isalpha(c)):
8.              c = toupper(c)
9.              character[c - 'A']++
10.             if character[c - 'A'] > max: max = character[c - 'A']
11.
12. for i from max down to 1:
13.     for j from 0 to 25:
14.         if character[j] == i:
15.             Print (char)(j + 'A') and character[j]
```
<details>
<summary> <head>點擊查看中文版<head> </summary>
```text
1. 讀取行數 T
2. 清除輸入緩衝區中殘留的換行字元 (cin.ignore)
3. 初始化最高頻率 max = 0，以及計數陣列 character[26] = {0}
4. 當 (T > 0) 時：
5.      使用 getline 讀取一整行到 sentences
6.      對 sentences 中的每個字元 c 進行檢查：
7.          如果 c 是英文字母：
8.              將 c 統一轉換為大寫
9.              對應的陣列位置 character[c - 'A'] 計數 + 1
10.             如果該字母的次數 > max，更新 max
11.
12. 迴圈 i 從 max 倒著跑到 1： // 處理次數由大到小
13.     迴圈 j 從 0 跑到 25：   // 處理字母由 A 到 Z (次數相同時的內建排序)
14.         如果 character[j] 等於當前的次數 i：
15.             印出對應的字母與次數
```
</details>

## Challenges
### 1. Input Buffer Trap:
Forgetting `cin.ignore()` after `cin >> T`, causing getline to read an empty line.
### 2. ASCII Code Memorization:
Confusing decimal values 65 and 97, and forgetting >= or <= boundaries.
### 3. Array Size Miscalculation:
Initializing character[34] instead of 26.
### 4. Loop Condition Error:
Writing i < 0 instead of i > 0 for the reverse loop.
### 5. Output Formatting Offset:
Accidentally adding + 65 again <sub>`j + 65`</sub> to the output count value.

## New code struct (v2)
<details>
<summary> <head>click to open<head> </summary>

```C++
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int character[26] = {};

int main()
{
	int T;
	cin >> T;

	cin.ignore();
	string sentences = {};
	int max{ 0 };
	while (T--)
	{
		getline(cin, sentences);
		for (char c : sentences)
		{
            if(isalpha(c))
            	c = toupper(c);
            else
                continue;
			character[c - 65]++;//ACSII code碼記錯
			if (max < character[c - 65])
				max = character[c - 65];
		}
	}
	for (int i{ max }; i > 0; i--)//本來寫i < 0
		for (int j{ 0 }; j < 26; j++)
			if (character[j] == i)
				cout << static_cast<char>(j + 65)
				<< ' '
				<< character[j]//原本又+65
				<< '\n';
}
```
</details>

[source code](v2(更好).cpp)

## Optimization Points:
### 1. Standard Library Utilization `<cctype>`:
Replaced <ruby>manual<rt>手動</rt></ruby> ASCII range checks with `isalpha()` and `toupper()`. This simplifies the code and prevents mistakes caused by manually typing ASCII boundaries.

### 2. Array Size Optimization:
Reduced the frequency array from character[34] to character[26], exactly matching the 26 letters of the English alphabet to save memory and reduce loop iterations.

### 3. ASCII code Alert (Future Improvement):
Although V2 is much cleaner, it still uses the ASCII code 65. In the future, replacing 65 with 'A' will completely eliminate the need to memorize ASCII decimal values!<sub>對金魚腦忘記ASCII code的友善</sub>

## Complexity Analysis
- Time complexity: $O(N + K \times 26)$<br>
$N$ is the total characters read, $K$ is the maximum frequency `max`. The double loop relies on maximum frequency rather than total elements.
- Space complexity： $O(1)$

> [!Note]
> 下次用混用cin, getline時要記得`cin.ignore()`
> 不用背ASCII code，直接減'char'就好
> 要注意大小寫間有相隔一些符號
> 我覺得那個max超棒，有效計算迴圈數！！！