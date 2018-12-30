#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void translate(float *x,float *y,float tx,float ty)
{
    *x = *x + tx;
    *y = *y + ty;
}

void rotation(float *x,float *y,float theta)
{
    theta = (3.1415 / 180 ) * theta;
    float xTemp = *x;
    *x = *x * cos(theta) - *y * sin(theta);
    *y = xTemp * sin(theta) + *y * cos(theta) ;
}
int main()
{
        float x1, y1, x2, y2,xc,yc,theta;
		cout << "Enter the first point (x1,y1) : ";
		cin >> x1 >> y1;
        cout << "Enter the second point (x2,y2) : ";
		cin >> x2 >> y2;
		cout << "Enter the arbitrary rotation center (xc,yc) : ";
		cin >> xc >> yc;
        cout<<"Enter the rotation angle in degree(theta): ";
        cin >> theta;

        int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");

        line(x1,y1,x2,y2);
        translate(&x1,&y1,-xc,-yc);
        translate(&x2,&y2,-xc,-yc);
		rotation(&x1, &y1, theta);
        rotation(&x2, &y2, theta);
        translate(&x1,&y1,xc,yc);
        translate(&x2,&y2,xc,yc);
        line(x1,y1,x2,y2);

        getch();
		closegraph();

		return 0;
}
