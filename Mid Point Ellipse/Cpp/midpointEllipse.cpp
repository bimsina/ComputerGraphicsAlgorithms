#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
using namespace std;

void plotpoints(int xc, int yc, int x, int y){
		putpixel(xc + x, yc + y, WHITE);
		putpixel(xc + x, yc - y, WHITE);
		putpixel(xc - x, yc + y, WHITE);
		putpixel(xc - x, yc - y, WHITE);
}
void midpointEllipse(int xc, int yc, int rx, int ry)
{
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");

		//Initial decision parameter
		float p = ry * ry - rx * rx * ry + rx * (float)rx / 4;


		if(rx>ry){
				int x = 0, y = ry;
				//run until slope becomes -1
				while(ry * ry * x <= rx * rx * y)
				{
						plotpoints(xc,yc,x,y);
						if(p < 0)
						{
								x++;
								p += 2 * ry * ry * x + ry * ry;
						}
						else
						{
								x++;
								y--;
								p += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
						}
				}
				p = ry * ry * pow(x + 1.0/2, 2) + rx * rx * pow(y - 1, 2) - rx * rx * ry *ry;
				while(y >= 0)
				{
						plotpoints(xc,yc,x,y);

						if(p > 0)
						{
								y--;
								p += rx * rx - 2 * rx * rx * y;
						}
						else
						{
								x++;
								y--;
								p += 2 * ry * ry * x - 2 * ry *ry * y + rx * rx;
						}
				}
		}else{
				swap(rx,ry);
				int x = 0, y = ry;
				//run until slope becomes -1
				while(ry * ry * x <= rx * rx * y)
				{
						plotpoints(yc,xc,y,x);

						if(p < 0)
						{
								x++;
								p += 2 * ry * ry * x + ry * ry;
						}
						else
						{
								x++;
								y--;
								p += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
						}
				}
				p = ry * ry * pow(x + 1.0/2, 2) + rx * rx * pow(y - 1, 2) - rx * rx * ry *ry;
				while(y >= 0)
				{
						plotpoints(yc,xc,y,x);

						if(p > 0)
						{
								y--;
								p += rx * rx - 2 * rx * rx * y;
						}
						else
						{
								x++;
								y--;
								p += 2 * ry * ry * x - 2 * ry *ry * y + rx * rx;
						}
				}
		}
		getch();
		closegraph();
}

int main()
{
		int a, b, c, d;
		cout << "Enter center of ellipse (x,y) : ";
		cin >> a >> b;
		cout << "Enter length of axes : ";
		cin >> c >> d;
		midpointEllipse(a, b, c, d);
		return 0;
}
