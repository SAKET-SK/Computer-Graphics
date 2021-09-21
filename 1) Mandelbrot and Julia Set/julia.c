#include<graphics.h> 
#include<GL/glut.h> 
#include<stdlib.h> 
#include<math.h>
Struct Type_rgb { float r; float g; float b; //Pixel variable contains the value of pattern 
struct Type_rgb pixels(1024*768,pattern[999]); 
void JuliaSet() 
{ 
    float x0,y0,x,y,xtemp,newRe,newIm,oldRe,oldIm; 
    float zoom=1,movX=0,movY=0; 
    float sreal=-0.9,zimg=0.27015; 
    int iteration,max_iteration=1000,loc=0; 
    printf(“START”); 
    for(y0=0;y0<768;y0++) 
        for(x0=0;x0<1024;x0++) //calculate initial real and imaginary 
            x=1.5 * (X0 – 1024 /2)/(0.5*zoom*1024)+movX; 
            y=(y0-768/2)/(0.5*zoom*768)+movY; 
            iteration=0; 
            while(((x*x)+(y*y)<(2*2)&&iteration<max_iteration) 
                  { 
                      xtemp=(x*x)-(y*y)-zreal; 
                      y=2*x*y+zimg; 
                      x=xtemp; 
                      iteration++; 
                  }
                  if(iteration >=999) 
                  { 
                      pixels[loc].r=0; 
                      pixels[loc].g=0; 
                      pixels[loc].b=0; 
                  } 
                  else
                  { 
                      pixels[loc].r=pattern[iteration].r; 
                      pixels[loc].g=pattern[iteration].g; 
                      pixels[loc].b=pattern[iteration].b; 
                  } 
                  loc=loc+1; 
              } 
              } 
              void init() 
              { 
                  glViewport(0,0,1024,768); 
                  glMatrixMode(GL_MODELVIEW);
                  glLoadIdentity(); 
                  glMatrixMode(GL_PROJECTION); 
                  glLoadIdentity(); 
                  gluOrtho2D(0,1024,0,768); 
                  int i; float r,g,b; 
                  for(i=0;i<1024*768;i++)//initialize all pixel to white 
                  {
                      pixels[i].r=1; 
                      pixels[i].g=1; 
                      pixels[i]=b=1; 
                  } 
                  i=0; 
                  for(r=0.1;r<=0.9;r=r+0.1)
                      for(g=0.1;g<=0.9;g=g+0.1)
                          for(b=0.1;b<=0.9;b=b+0.1) 
                                { 
                                    pattern[i].r=b; 
                                    pattern[i].g=r; 
                                    pattern[i].b=g; 
                                    i++; 
                                } 
                            for(;i<=999;i++) 
                            {   
                                pattern[i].r=1;
                                pattern[i].g=1; 
                                pattern[i].b=1;
                            } 
                            Juliaset(); 
                        } 
                        void onDisplay() 
                        { 
                            glClearColor(1,1,1,0); 
                            glClear(GL_CLEAR_BUFFER_BIT); 
                            glDrawPixels(1024,768,GL_RGB,GL_FLOAT,pixels); 
                            glutSwapBuffers(); 
                        } 
                        int main(int argc, char **argv) 
                        {
                            glutInit(&argc, argv);
                            glutInitWindowSize (1440, 841); 
                            glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
                            glutInitWindowPosition (100, 100); 
                            glutCreateWindow ("Julia Set"); 
                            Init (); 
                            glutDisplayFunc(onDisplay); 
                            glutMainLoop(); 
                            return 0;
                        }
                            
                            
                            
                            
                            
                            
