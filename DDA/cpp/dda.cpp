#include<stdio.h>
#include<iostream>
#include<graphics.h>
using namespace std;

void DDA(int x1, int y1, int x2,int y2) {
    //calculate dx & dy
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int xCenter=250,yCenter=250;

	// calculate steps required for generating pixels
	int steps;
	float xstep,ystep;
	if(dx > dy)
            steps = dx;
    else
            steps = dy;
    if (x1>x2)
        xstep=(-steps);
    else
        xstep=steps;
    if (y1>y2)
        ystep=(-steps);
    else
        ystep=steps;

	// calculate increment in x & y for each steps
	float xInc = dx / (float) xstep;
	float yInc = dy / (float) ystep;
	cout<<xInc<<yInc<<endl;

	// Put pixel for each step
	float X = x1;
	float Y = y1;
	for (int i = 0; i <= steps; i++)
	{
		putpixel (X+xCenter,Y+yCenter,WHITE);
		X += xInc;
		Y += yInc;
		delay(50);
    }
    getch();
    closegraph();

}

int main() {
        //Define points
        int x1,y1,x2,y2;
        // Input points
        cout<<"Enter the first point (x1,y1) : ";
        cin>>x1;
        cin>>y1;
        cout<<"Enter the second point (x2,y2) : ";
        cin>>x2;
        cin>>y2;

        //Initialize graphics
        int gd = DETECT, gm;
        initgraph (&gd, &gm, "");
        DDA(x1,y1,x2,y2);
        return 0;
}
