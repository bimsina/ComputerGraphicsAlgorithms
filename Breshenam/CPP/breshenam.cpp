#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<graphics.h>
using namespace std;

void slopelessthan1(int x1,int y1,int x2,int y2){
	int dx = x2-x1;
	int dy = y2-y1;
	int yi = 1;
	if (dy<0){
		yi = -1;
		dy = -dy;
	}
	int D = 2*dy-dx;
	int y = y1;

	for (int x=x1;x<=x2;x++){
        cout<<x;
        cout<<" ";
        cout<<y;
        cout<<"\n";
		putpixel(x,y,WHITE);
		if(D>0){
			y=y+yi;
			D = D-2*dx;
		}
		D = D+2*dy;
	}

}

void slopegreaterthan1(int x1,int y1,int x2,int y2){
	int dx = x2-x1;
	int dy = y2-y1;
	int xi = 1;
	if(dx<0){
		xi = -1;
		dx = -dx;
	}
	int D = 2*dx-dy;
	int x = x1;
	for (int y=y1;y<=y2;y++){
        cout<<x;
        cout<<" ";
        cout<<y;
        cout<<"\n";
		putpixel(x,y,WHITE);
		if(D>0){
			x = x+xi;
			D = D-2*dy;
		}
		D = D+2*dx;
	}
}


void pltline(int x1,int y1,int x2,int y2){
	if(abs(y2-y1)<abs(x2-x1))
		if(x1>x2)
			slopelessthan1(x2,y2,x1,y1);
		else
			slopelessthan1(x1,y1,x2,y2);
	else
		if(y1>y2)
			slopegreaterthan1(x2,y2,x1,y1);
		else
			slopegreaterthan1(x1,y1,x2,y2);
}

int main(){
    //Define points
        int x1,y1,x2,y2;
        // Input points
        cout<<"Enter the first point (x1,y1) : ";
        cin>>x1;
        cin>>y1;
        cout<<"Enter the second point (x2,y2) : ";
        cin>>x2;
        cin>>y2;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"");
	//int x1=10,x2=50,y1=100,y2=60;
	pltline(x1,y1,x2,y2);
	getchar();
	closegraph();
	return 0;

}
