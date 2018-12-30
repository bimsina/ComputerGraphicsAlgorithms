#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void translate(float *x,float *y,float tx,float ty)
{
    *x = *x + tx;
    *y = *y + ty;
}

void scale(float *x,float *y,float sx,float sy)
{
    *x = *x * sx;
    *y = *y * sy;
}
int main()
{
        float x1, y1, x2, y2,x3,y3,x4,y4,xc,yc,sx,sy;
		cout << "Enter the first point (x1,y1) : ";
		cin >> x1 >> y1;
        cout << "Enter the second point (x2,y2) : ";
		cin >> x2 >> y2;
		cout << "Enter the third point (x3,y3) : ";
		cin >> x3 >> y3;
        cout << "Enter the fourth point (x4,y4) : ";
		cin >> x4 >> y4;
		cout << "Enter the arbitrary rotation center (xc,yc) : ";
		cin >> xc >> yc;
        cout<<"Enter the scaling factors (sx,sy): ";
        cin >> sx >> sy;

        int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");

        line(x1,y1,x2,y2);
        line(x2,y2,x3,y3);
        line(x3,y3,x4,y4);
        line(x4,y4,x1,y1);

        translate(&x1,&y1,-xc,-yc);
        translate(&x2,&y2,-xc,-yc);
        translate(&x1,&y1,-xc,-yc);
        translate(&x2,&y2,-xc,-yc);

		scale(&x1, &y1, sx,sy);
        scale(&x2, &y2, sx,sy);
        scale(&x3, &y3, sx,sy);
        scale(&x4, &y4, sx,sy);

        translate(&x1,&y1,xc,yc);
        translate(&x2,&y2,xc,yc);
        translate(&x1,&y1,xc,yc);
        translate(&x2,&y2,xc,yc);

        line(x1,y1,x2,y2);
        line(x2,y2,x3,y3);
        line(x3,y3,x4,y4);
        line(x4,y4,x1,y1);


        getch();
		closegraph();

		return 0;
}
