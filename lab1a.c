#include<stdio.h>
#include<graphics.h>

int absval(int a,int b)
{
    return a-b>0 ? a-b : b-a;
}

void dda(int x1,int y1,int x2,int y2)
{
    int dx = absval(x2,x1);
    int dy = absval(y2,y1);
    int steps = dx>dy ? dx : dy;

    float inx = dx / (float) steps;
    float iny = dy / (float) steps;

    float x = x1;
    float y = y1;

    for(int i=0 ; i<=steps ; i++)
    {
        putpixel(x,y,YELLOW);
        x+=inx;
        y+=iny;
        delay(100);
    }
}

void main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    //printf("enter x1,y1,x2,y2\n");
    //int x1,y1,x2,y2;
    //scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    dda(1,1,10,10);
}