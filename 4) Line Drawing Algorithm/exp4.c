#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int X1,X2,Y1,Y2;
int Round(float a)
{
    return(int)(a+0.5);
}

void draw(int X1,int Y1,int X2,int Y2)
{
    glBegin(GL_POINTS);
    int dx=X2-X1,dy=Y2-Y1,steps,i;
    if(abs(dx)>abs(dy))
    {
        steps=abs(dx);
    }
    else
    {
        steps=abs(dy);
    }
    float xinc=dx/(float)steps,yinc=dy/(float)steps,x=X1,y=Y1;
    glVertex2i(Round(x),Round(y));
    for(i=0;i<steps;i++)
    {
        x=x+xinc;
        y=y+yinc;
        glVertex2i(Round(x),Round(y));
    }
    glEnd();
    glFlush();
}
void line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw(X1,Y1,X2,Y1);
    draw(X2,Y1,X2,Y2);
    draw(X2,Y2,X1,Y2);
    draw(X1,Y2,X1,Y1);
    draw((X1+X2)/2,Y1,X2,(Y1+Y2)/2);
    draw(X2,(Y1+Y2)/2,(X1+X2)/2,Y2);
    draw((X1+X2)/2,Y2,X1,(Y1+Y2)/2);
    draw(X1,(Y1+Y2)/2,(X1+X2)/2,Y1);
    draw((3*X1+X2)/4,(3*Y1+Y2)/4,(3*X2+X1)/4,(3*Y1+Y2)/4);
    draw((3*X2+X1)/4,(3*Y1+Y2)/4,(3*X2+X1)/4,(3*Y2+Y1)/4);
    draw((3*X2+X1)/4,(3*Y2+Y1)/4,(3*X1+X2)/4,(3*Y2+Y1)/4);
    draw((3*X1+X2)/4,(3*Y2+Y1)/4,(3*X1+X2)/4,(3*Y1+Y2)/4);
}

int main(int argc,char **argv)
{
    printf("\n Enter first point: ");
    scanf("%d%d",&X1,&Y1);
    printf("\n Enter second point: ");
    scanf("%d%d",&X2,&Y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("point");
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
    glutDisplayFunc(line);
    glutMainLoop();
    return 0;
}
/*
OUTPUT:
Enter first point: 200 200
Enter second point: 400 400 
<Image is displayed as uploaded in previous directory>*/
