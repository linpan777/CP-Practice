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