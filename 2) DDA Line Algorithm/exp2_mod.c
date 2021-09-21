//Program for BOUNDARY FILLING of a polygon
//SAKET.S.KHOPKAR    SI072
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>

int n,input[2][10];
int x,y;
int X1,Y1,X2,Y2;
float b_col[3],f_col[3];

int round_value(float v)
{
	return (int)(v+0.5);
}


void lineDDA(int X1,int Y1,int X2,int Y2)
{
	glBegin(GL_POINTS);
	
	int dx=X2 - X1;
	int dy=Y2 - Y1;
	int steps,i;          
	float xIncrement,yIncrement,x=X1,y=Y1;
	
	steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	/*if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);    */
		
	xIncrement=dx /(float) steps;
	yIncrement=dy /(float) steps;
	glBegin(GL_POINTS);
	glVertex2i(round_value(x),round_value(y));
	//glEnd();
	
	for(i=0;i<steps;i++)
	{ 
		x += xIncrement;
		y += yIncrement;
		//glBegin(GL_POINTS);
		glVertex2i(round_value(x),round_value(y));
	}
	glEnd();
	glFlush();
}

void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(f_col[0],f_col[1],f_col[2]);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

void boundary(int x,int y,float f_col[],float b_col[])
{
	float col[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,col);
	if(col[0]!=b_col[0]||col[1]!=b_col[1]||col[2]!=b_col[2] && col[0]!=f_col[0]||col[1]!=f_col[1]||col[2]!=f_col[2])
	{
		glColor3f(f_col[0],f_col[1],f_col[2]);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
		
		boundary(x+1,y,f_col,b_col);
		boundary(x-1,y,f_col,b_col);
		boundary(x,y+1,f_col,b_col);
		boundary(x,y-1,f_col,b_col);
	}
}

void p_fill()
{
	int i,j;
	for(i=0,j=1;i<n-1;i++,j++)
	{
		lineDDA(input[0][i],input[1][i],input[0][j],input[1][j]);
	}
	lineDDA(input[0][i],input[1][i],input[0][0],input[1][0]);
	boundary(x,y,b_col,f_col);
}

int main(int argc,char** argv)
{
	int i;
	printf("Enter inside point x,y:- ");
	scanf("%d %d",&x,&y);
	printf("Enter boundary color eg:(0 1 1):- ");
	for(i=0;i<3;i++)
	{
		scanf("%f",&b_col[i]);
	}
	printf("Enter fill color:- eg:(1 0 0):- ");
	for(i=0;i<3;i++)
	{
		scanf("%f",&f_col[i]);
	}
	
	printf("Enter no.of vertices : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the value of X : ");
		scanf("%d",&input[0][i]);
		printf("Enter the value of Y : ");
		scanf("%d",&input[1][i]);
	}
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Polygon Fill");
	init();
	
	glutDisplayFunc(p_fill);
	glutMainLoop();
	
	return 0;
}
