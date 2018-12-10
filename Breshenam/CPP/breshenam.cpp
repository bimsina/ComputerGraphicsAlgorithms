#include<stdio.h>
#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
void breshenam(float x1,float y1,float x2,float y2){
		int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"");
		float x,y,dx,dy,p;
		int i;
		x = x1; y = y1;
	dx = x2 - x1;
	dy = y2 - y1;

	float m =(y2-y1)/(x2-x1);
	if(m<1){
		p = 2 * dy - dx;
		for(i = 0 ;i< dx ; i++){
			if(p<0) {
				x = x + 1;
				p = p + 2*dy;
			}else{
				x = x + 1;
				y = y +1;
				p = p + 2*dy - 2*dx;
			}
			putpixel(x,y,255);
		}
	}else{
		p = 2 * dx - dy;
		for(i = 0 ;i< dy ; i++){
			if(p<0) {
				y = y + 1;
				p = p + 2*dx;
			}else{
				x = x + 1;
				y = y +1;
				p = p + 2*dx - 2*dy;
			}
			putpixel(x,y,255);
		}
	}
	getch();
}


int main()
{
	float x1,x2,y1,y2;
	// Input points
		cout<<"Enter the first point (x1,y1) : ";
		cin>>x1;
		cin>>y1;
		cout<<"Enter the second point (x2,y2) : ";
		cin>>x2;
		cin>>y2;

	breshenam(x1,y1,x2,y2);
	return 0;
}
