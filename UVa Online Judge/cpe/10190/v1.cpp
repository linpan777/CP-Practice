#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int first, second, temp;

    while(cin >> first >> second)
    {
        if(second == 1)//忽略second 1
        {
            cout << "Boring!\n";
            continue;
        }

        temp = second;
        while(temp < first)
        temp *= second;
        if(temp != first)
        {
            cout << "Boring!\n";
            continue;
        }

        temp = first;
        while(temp != 1)
        {
            cout << temp << ' ';
            temp /= second;
        }
        cout << "1\n";
    }
}