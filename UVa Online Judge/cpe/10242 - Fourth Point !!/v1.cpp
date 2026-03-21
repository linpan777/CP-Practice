#include <iostream>
#include <iomanip>
using namespace std;

// 識別四個點中哪一個重複，分離成 A、B（另外兩個點）、C（重複點）
void judge(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3,
			 double &x4, double &y4, double &xA, double &yA, double &xB, double &yB, 
			 double &xC, double &yC); 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double xA, yA, xB, yB, xC, yC;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		judge(x1, y1, x2, y2, x3, y3, x4, y4, xA, yA, xB, yB, xC, yC);
		// 平行四邊形性質：第四點 = A + B - C
		cout << setprecision(3) << fixed << xB + xA - xC << ' ' << yB + yA - yC << '\n';
	}
}

// 識別四個點中哪一個重複，分離成 A、B（另外兩個點）、C（重複點）
void judge(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3,
			 double &x4, double &y4, double &xA, double &yA, double &xB, double &yB, 
			 double &xC, double &yC)
{
	// 根據四個點中的重複點，識別出 A、B、C 三個角色
	if(x1 == x3 && y1 == y3)  // 點 1 和點 3 重複
	{
		xC = x1; yC = y1;
		xA = x2; yA = y2;
		xB = x4; yB = y4;
	}
	else if(x1 == x4 && y1 == y4)  // 點 1 和點 4 重複
	{
		xC = x1; yC = y1;
		xA = x2; yA = y2;
		xB = x3; yB = y3;
	}
	else if(x2 == x3 && y2 == y3)  // 點 2 和點 3 重複
	{
		xC = x2; yC = y2;
		xA = x1; yA = y1;
		xB = x4; yB = y4;
	}
	else if(x2 == x4 && y2 == y4)  // 點 2 和點 4 重複
	{
		xC = x2; yC = y2;
		xA = x1; yA = y1;
		xB = x3; yB = y3;
	}
}
