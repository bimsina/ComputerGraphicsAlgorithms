#include<stdio.h>
#include<iostream>
#include<graphics.h>
using namespace std;

void DDA(int x1, int y1, int x2,int y2) {
     //Initialise graphics
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");

    //calculate dx & dy
	int dx = x2 - x1;
	int dy = x2 - x1;

	// calculate steps required for generating pixels
	int steps;
	if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

	// calculate increment in x & y for each steps
	float xInc = dx / (float) steps;
	float yInc = dy / (float) steps;

	// Put pixel for each step
	float X = x1;
	float Y = y1;
	for (int i = 0; i <= steps; i++)
	{
		putpixel (X,Y,WHITE);
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
      DDA(x1,y1,x2,y2);
      return 0;
}
