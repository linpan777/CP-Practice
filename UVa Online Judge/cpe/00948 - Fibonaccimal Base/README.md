# UVa 00948 - Fibonaccimal Base

## Problem Description
Brief description of the problem -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=889)

## Learning Objectives
1. <ruby>Greedy Algorithm<rt>*貪心演算法*</rt></ruby>
2. <ruby>Precomputation<rt>*建表預處理*</rt></ruby>
3. Zeckendorf's theorem (齊肯多夫定理：任何正整數都能表示為若干不連續費氏數之和)

## Thinking
### variable reference
| variable | meaning |
| :--- | :--- |
| `fib[]` | Array to store the precomputed Fibonacci sequence |
| `T` | The number of test cases |
| `n` | The target positive integer to be converted |

> [!IMPORTANT]
> 費氏數列成長極快，第 39 項即超過一億 ($10^8$)，因此陣列開到 45 已經非常足夠，無須開到過大的記憶體空間。

### Algorithm logic
```text
main：
1. Initialize fib[0] = 1, fib[1] = 2
2. for i from 2 to 44:  // Precomputation
3.      fib[i] = fib[i-1] + fib[i-2]
4. 
5. Read T
6. while (T-- > 0):
7.      Read n
8.      Print "n = "
9.      
10.     Find index i where fib[i] is the largest number <= n
11.     for j from i down to 0:
12.         if (n >= fib[j])
13.             n = n - fib[j]
14.             Print '1'
15.         else
16.             Print '0'
17.     Print " (fib)\n"
```
<details>
<summary> <head>點擊查看中文版<head> </summary>

```text
1. 初始化陣列 fib[0] = 1, fib[1] = 2
2. 迴圈 i 從 2 跑到 44： // 建表預處理，不要在測資迴圈內重複算
3.      fib[i] = fib[i-1] + fib[i-2]
4. 
5. 讀取測資數量 T
6. 當 (T > 0) 時：
7.      讀取目標數字 n
8.      提早印出 "n = "
9.      
10.     尋找小於等於 n 的最大費氏數所在的索引值 i
11.     迴圈 j 從 i 倒著跑到 0： // 從最大的費氏數開始往下檢查 (Greedy)
12.         如果 (n >= fib[j])：
13.             n 扣除 fib[j]
14.             印出 '1'
15.         否則：
16.             印出 '0'
17.     印出 " (fib)\n"
```
</details>

## Challenges
1. Unnecessary Hardcoding <sub>Overcomplicating base cases</sub>
2. Redundant Calculation <sub>Calculating Fibonacci sequence inside the while loop for every test case</sub>

## New code struct
<details>
<summary> <head>click to open<head> </summary>

```C++
#include<iostream>
using namespace std;

int fib[45] = { 1, 2 };

int main()
{
    for (int i{ 2 }; i < 45; i++)//fib數列建立(1 2固定，剩下讓code自己加)
        fib[i] = fib[i - 1] + fib[i - 2];

    int T;//測資數量
    cin >> T;
    while (T--)
    {
        int n;//輸入數字
        cin >> n;
        cout << n << " = ";//提早印出n =

        int i{ 0 };
        while (n >= fib[i])//找出n在fib數列中小於等於n的最大index
            i++;

        for (int j{ i - 1 }; j >= 0; j--)//從最大index開始往下檢查(需從i - 1開始才是<=n的max number)
            if (fib[j] > n)
                cout << 0;
            else
            {
                n -= fib[j];
                cout << 1;
            }

        cout << " (fib)\n";
    }
}
```
</details>

[source code](v2(更好).cpp)

## Optimization Points:
1. <ruby>Precomputation<rt>建表預處理</rt></ruby>
Moved the Fibonacci calculation outside the test case loop. Precomputing it globally allows for $O(1)$, reduces time complexity.
2. Removed unnecessary hardcoding:
Removed special cases for `n == 1` and `n == 2`. Relying purely on the core greedy logic makes the code much cleaner.
3. Array Size Optimization
Reduced the array size from `fib[501]` to `fib[45]` based on the constraint ($N < 10^8$) to save memory space.

## Complexity Analysis
- Time complexity： $O(T + 45)$
- Space complexity： $O(45)$