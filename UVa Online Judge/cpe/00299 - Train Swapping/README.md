# UVa 00299 - Train Swapping

## Problem Description
Brief description of the problem -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=235)

## Learning Objectives
1. Learn and implement <ruby>Bubble Sort<rt><i>(氣泡排序法)</i></rt></ruby>.
2. Understand the concept of "<ruby>Inversions" <rt><i>(逆序數對)</i></rt><ruby> in an array.
3. 

## Thinking
### variable reference
| 變數 | 意義 |
| :--- | :--- |
| `T` | input: number of test cases (測資數量) |
| `C` | input: length of the train / number of carriages (車廂數量) |
| `carriages` | vector to store the current order of carriages |
| `times` | core variable to count the total number of swaps |
| `temp` | to put carriage number in vector |

### Algorithm logic
```text
1. input T
2. while loop (T--)
3.      input C
4.      for loop (0 -> C) to input carriages sequence
5.      for loop (i: 0 -> C - 1)
6.          for loop (j: 0 -> C - 1)
7.              if (carriages[j] > carriages[j + 1])
8.                  swap(carriages[j], carriages[j + 1])
9.                  times++
10.     output times
```

## Challenges
1. First version, my core code is already quite close to Bubble Sort, but I restart the check from the beginning every time a swap occurs, which makes the time complexity unstable.

## New code struct
<details>
<summary> <head>click to open V2 (AC Code)</head> </summary>

```C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        vector<int> carriages; // 優化：宣告在迴圈內，每次測資自動重置，省去 clear()
        int C, temp, times{ 0 }; // times 也要放在這裡，每次測資重置為 0
        cin >> C;
        
        for(int i{0}; i < C; i++)
        {
            cin >> temp;
            carriages.push_back(temp);
        }

        // core code：氣泡排序法 (Bubble Sort)
        for(int i{0}; i < C - 1; i++)
        {
            for (int j{ 0 }; j < C - 1; j++) // 可優化為 j < C - 1 - i
            {
                if (carriages[j] > carriages[j + 1])
                {
                    swap(carriages[j], carriages[j + 1]);
                    times++;
                }
            }
        }
        cout << "Optimal train swapping takes " << times << " swaps.\n";
    }
}
```

</details>

[source code](v2(更好-氣泡演算法).cpp)

## Optimization Points:
1. Since v1 performs a back-track every time it encounters a swap, the time complexity remains unstable. The v2 algorithm effectively stabilizes the time complexity at $T \times C^2$.
2. For the best optimization, please refer to v3, effectively reducing the time complexity to  $O(T \cdot C \log C)$
the only place to modify：
<details>
```C++
for (int j{ 0 }; j < C - 1 - i; j++)
```
</details>

## Complexity Analysis
- Time complexity:  $O(T \cdot C \log C)$
- Space complexity: $O(C)$

## Note


[New] 遇到多筆測資 (Test Cases) 時，優先考慮把變數跟陣列宣告在 while 迴圈裡面，讓它們自動重生，可以避免很多忘記歸零的低級失誤