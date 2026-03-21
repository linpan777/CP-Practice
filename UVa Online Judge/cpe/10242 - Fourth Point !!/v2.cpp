#include <iostream>
#include <iomanip>
using namespace std;

// 使用結構體表示二維座標上的點
struct Point{
	double x;
	double y;
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	Point a;
	Point b;
	Point c;
	Point d;
	Point samePoint;
	while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y)
	{
		// 計算四個點的座標和
		// 利用平行四邊形性質：第四點 = B + (A - C) = (a+b+c+d) - 3*C
		double sumX = a.x + b.x + c.x + d.x;
		double sumY = a.y + b.y + c.y + d.y;
		
		// 找出重複的點（作為平行四邊形的中心點 C）
		if(a.x == c.x && a.y == c.y)
		{
			samePoint.x = a.x;
			samePoint.y = a.y;
		}
		else if(a.x == d.x && a.y == d.y)
		{
			samePoint.x = a.x;
			samePoint.y = a.y;
		}
		else if(b.x == c.x && b.y == c.y)
		{
			samePoint.x = b.x;
			samePoint.y = b.y;
		}
		else if(b.x == d.x && b.y == d.y)
		{
			samePoint.x = b.x;
			samePoint.y = b.y;
		}

		// 利用座標和直接計算第四點：sumX - 3*C.x 就是答案
		cout << setprecision(3) << fixed << sumX - 3*samePoint.x << ' ' << sumY - 3*samePoint.y << '\n';
	}
}