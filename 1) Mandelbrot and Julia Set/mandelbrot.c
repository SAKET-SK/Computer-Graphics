#include <GL/gl.h> 
#include <GL/glut.h> 
#include <stdio.h> 
/* *defining a RGB struct to color the pixel */ 
struct Type_rgb
{ 
    float r; 
    float g; 
    float b; 
};
/* * pixel variable contain the value of the color pixel in the picture. * pattern is a predefine set of color for a particular value. */ 
struct Type_rgb pixels[841*1440], pattern[999];
/* * function mandelbrotset find where the number is in mandelbrotset or not and also assign a color to that coordinate with that iteration pattern. */ 
void mandelbrotset() 
{ 
    float x0, y0, x, y, xtemp; 
    int iteration, max_iteration, loc=0; printf("\nstart"); 
    for(y0 = -1; y0 < 1.1; y0 = y0 + 0.0025) 
    {
            for(x0 = -2.5; x0 < 1.1; x0 = x0 + 0.0025)
            { 
                x = 0; y = 0; 
                iteration = 0; 
                max_iteration = 1000;
                while(((x*x) + (y*y) < (2*2)) && iteration < max_iteration)
                { 
                    xtemp = (x*x) - (y*y) + x0; y = (2*x*y) + y0; x = xtemp; iteration = iteration + 1; 
                } 
                if(iteration >= 999)
                { 
                /* * setting color pixel to Mandelbrot set coordinate *to black. */ 
                     pixels[loc].r = 0; pixels[loc].g = 0; pixels[loc].b = 0; 
                }
                else
                { /* * setting color pixel to the reset of the coordinate by the * pattern of no of iteration before bailout. */
                    pixels[loc].r = pattern[iteration].r; 
                    pixels[loc].g = pattern[iteration].g; 
                    pixels[loc].b = pattern[iteration].b;
                }
                loc = loc + 1;
            }
        }
        void Init( ) 
        { 
            glViewport(0, 0, 1440, 841); 
            glMatrixMode(GL_MODELVIEW); 
            glLoadIdentity( ); 
            glMatrixMode(GL_PROJECTION); 
            glLoadIdentity( ); 
            gluOrtho2D(0, 1440, 0, 841); 
            int i; 
            float r, g, b;
            /* * Initializing all the pixels to white. */
            for(i = 0; i < 841*1440; i++)
            {
                pixels[i].r = 1;
                pixels[i].g = 1; 
                pixels[i].b = 1; 
            } 
            i = 0;
            /* * Initializing all the pattern color till 9*9*9 */
            for(r = 0.1; r <= 0.9; r= r+0.1) 
                for(g = 0.1; g <= 0.9; g = g+0.1) 
                    for(b = 0.1; b <= 0.9; b = b+0.1)
                        { 
                            pattern[i].r = b; 
                            pattern[i].g = r; 
                            pattern[i].b = g; 
                            i++; 
                        }
                        /* * Initializing the rest of the pattern as 9*9*9 is 729. * and we need up to 999 pattern as the loop bailout * condition is 1000. */
                        for( ; i <= 999; i++)
                        { 
                            pattern[i].r = 1; 
                            pattern[i].g = 1; 
                            pattern[i].b = 1;
                        }
                        mandelbrotset(); 
                   }
                   void onDisplay() 
                   { 
                        /** Clearing the initial buffer */
                       glClearColor(1, 1, 1, 0); 
                       glClear(GL_COLOR_BUFFER_BIT);
                       /* * Draw the complete Mandelbrot set picture. */
                       glDrawPixels(1440, 841, GL_RGB, GL_FLOAT, pixels);
                       glutSwapBuffers(); 
                   }
       }
                   int main(int argc, char** argv) 
                   { 
                        /* * Here basic Opengl initialization. */ 
                        glutInit(&argc, argv); 
                        glutInitWindowSize (1440, 841); 
                        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
                        glutInitWindowPosition (100, 100); 
                        glutCreateWindow ("Mandelbrotset by SKR"); 
                        Init (); /* * connecting the Display function */
                        glutDisplayFunc(onDisplay); /* * starting the activities */ 
                        glutMainLoop(); 
                        return 0; 
                    }
