# 11321 - Sort! Sort!! and Sort!!!

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2296)

## 邏輯:
```text
main:
1. while(cin T, dividend & T,dividend != 0)
2. vector<int> modulo
3. for(0 -> T-1)
4.      cin temp 
5.      modulo.push_back(temp)
6. sort( , , mycmp)
7. cout
```
```text
mycmp:
餘數大小比較
1. a % dividend < b % dividend -> true
2. a % dividend > b % dividend -> false
積偶比較
3. a % 2 != 0 && b % 2 == 0 -> true
4. a % 2 == 0 && b % 2 != 0 -> false
同積 -> 大小於比較
5. a > b -> true
6. a < b -> false
同偶 ->大小於比較
7. a < b -> true
8. a > b -> false 
```

## 重點學習:
### sort()
- 引入`<algorithm>`
- 語法：sort(起點, 終點)
> [!Note]
> 注意： 它的範圍是「左閉右開」區間 [起點, 終點)，也就是包含起點，但不包含終點。
```C++
vector<int> vec = {4, 1, 3, 2};
sort(vec.begin(), vec.end()); 
// 結果：1, 2, 3, 4
```
```C++
int arr[5] = {5, 2, 4, 1, 3};
int n = 5;
sort(arr, arr + n); // 起點是 arr[0]，終點是 arr[n] 的下一個位置
```

- 靈魂重點，排序自定義
當題目不只要求「由小到大」時，就要自己寫一個 bool 函式來教編譯器怎麼排
```C++
int main()
{
    int arr[5] = {5, 2, 4, 1, 3};
    sort( arr, arr + 5, cmp)
}
bool cmp(int a, int b) {
    return a > b; // 如果 a 比較大，a 就排前面 -> 達成由大到小
}
//最終排序`5 4 3 2 1`
```