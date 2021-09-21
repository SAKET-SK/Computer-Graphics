//Program for drawing a polygon using DDA LINE ALGORITHM
//SAKET.S.KHOPKAR    SI072
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>

void lineDDA(int x1,int y1,int x2,int y2)
{
	glColor3f(1.0,0.0,0.0);
	
	int dx=x2 - x1,dy=y2 - y1,steps,k;          
	float xIncrement,yIncrement,x=x1,y=y1;
	
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
		
	xIncrement=dx / steps;
	yIncrement=dy / steps;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	
	for(k=0;k<steps;k++)
	{ 
		x += xIncrement;
		y += yIncrement;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}
	
	glFlush();
}

void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}
int main(int argc,char** argv)
{
	int x[5],y[5],n,i;
	
	printf("Enter no.of vertices : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the value of X : ");
		scanf("%d",&x[i]);
		printf("Enter the value of Y : ");
		scanf("%d",&y[i]);
	}
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Polygon Algo");
	init();
	
	for(i=0;i<n-1;i++)
	{
		lineDDA(x[i],y[i],x[i+1],y[i+1]);
    }
    	
	lineDDA(x[0],y[0],x[i],y[i]);
	glutMainLoop();
	
	return 0;
}
