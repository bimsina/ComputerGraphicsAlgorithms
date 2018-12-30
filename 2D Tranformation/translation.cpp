#include<iostream>
#include<graphics.h>
using namespace std;

void translate(float *x,float *y,float tx,float ty)
{
    *x = *x + tx;
    *y = *y + ty;
}
int main()
{
        float x1, y1, x2, y2,tx,ty;
		cout << "Enter the first point (x1,y1) : ";
		cin >> x1 >> y1;
        cout << "Enter the first point (x2,y2) : ";
		cin >> x2 >> y2;
        cout<<"Enter the translation factor (tx,ty):";
        cin >> tx >> ty;

        int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");

        line(x1,y1,x2,y2);
		translate(&x1, &y1, tx, ty);
        translate(&x2, &y2, tx, ty);
        line(x1,y1,x2,y2);

        getch();
        closegraph();

		return 0;
}
