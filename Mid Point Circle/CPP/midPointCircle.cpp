#include<graphics.h>
#include<iostream>
#include<conio.h>
using namespace std;
void midPointCircle(int centreX, int centerY, int r){
    int x = 0;
    int y = r;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    float p = (5/4) - r;
    do{
        if(p<0){
            x += 1;
            p = p + 2*x + 1;
        }
        if(p>0){
            x += 1;
            y -= 1;
            p = p + 2*x + 1 - 2*(y-1);
        }
        cout<<x + centreX;
        cout<<" ";
        cout<<y + centerY;
        cout<<"\n";
        putpixel(x+centreX , y + centerY , WHITE);
        putpixel(y+centreX , x + centerY , WHITE);
        putpixel(x+centreX , -y + centerY , WHITE);
        putpixel(y+centreX , -x + centerY , WHITE);
        putpixel(-y+centreX , -x + centerY , WHITE);
        putpixel(-x+centreX , -y + centerY , WHITE);
        putpixel(-x+centreX , y + centerY , WHITE);
        putpixel(-y+centreX , x + centerY , WHITE);
    }while(x <= y);
    getch();
    closegraph();

}
int main(){
    int x,y,r;
    cout<<"Enter the center of the circle (x,y) : ";
    cin>>x;
    cin>>y;
    cout<<"Enter the radius : ";
    cin>>r;
    midPointCircle(x,y,r);
    return 0;
}
