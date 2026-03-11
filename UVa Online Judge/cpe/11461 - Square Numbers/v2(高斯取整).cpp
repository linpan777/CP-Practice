#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int first, last;
    
    while(cin >> first >> last)
    {
        if(first == 0 && last == 0)
            return 0;
        
        int count = (int)sqrt(last) - (int)sqrt(first - 1);
        
        cout << count << '\n';
    }
}