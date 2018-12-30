#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void shear(float *x,float *y,float sx,float sy)
{
    float xTemp = *x;
    *x = *x + sx * (*y);
    *y = *y + sy * xTemp;
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
        cout<<"Enter the scaling factors (sx,sy): ";
        cin >> sx >> sy;

        int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");

        line(x1,y1,x2,y2);
        line(x2,y2,x3,y3);
        line(x3,y3,x4,y4);
        line(x4,y4,x1,y1);

        shear(&x1,&y1,sx,sy);
        shear(&x2,&y2,sx,sy);
        shear(&x3,&y3,sx,sy);
        shear(&x4,&y4,sx,sy);



        line(x1,y1,x2,y2);
        line(x2,y2,x3,y3);
        line(x3,y3,x4,y4);
        line(x4,y4,x1,y1);


        getch();
		closegraph();

		return 0;
}
