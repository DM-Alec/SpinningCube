#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float a, b, c, x, xp, y, yp, z, zz;
float cubewidth = 10;
int width = 160
int height = 44;
float zbuffer[width * height];
char buffer[width * height];
int backASCIIcode = ' ';
int distfromCam = 60;
float incrementSpeed = 0.6;
float K1 = 40;
int idx;

float calculateX (int i, int j, int k) {
    return j * sin(a) * sin(b) * cos(c) - k * cos(a) * sin(b) * cos (c) + 
            j * cos(a) * sin(c) * + k * sin(a) * sin(c) + i * cos(b) * cos(c)
            }

float calculateY(int i, int j, int k) {
  return j * cos(a) * cos(c) + k * sin(a) * cos(c) - 
         j * sin(a) * sin(b) * sin(c) + k * cos(a) * sin(b) * sin(c) -
         i * cos(b) * sin(c);
}

float calculateZ(int i, int j, int k) {
  return k * cos(a) * cos(b) - j * sin(a) * cos(b) + i * sin(b);
}

void calculateSurface(float cubeX, float cubeY, float CubeZ, int ch){
    x = calculateX(cubeX, cubeY, cubeZ):
    y = calculateY(cubeX, cubeY, cubeZ):
    z = calculateZ(cubeX, cubeY, cubeZ) + distfromCam;
    zz = 1/z;
    xp = (int)(width/2 + K1 * zz * x * 2);
    yp = (int)(width/2 + K1 * zz * y)
    
    idx = xp + yp * width;
    if ( idx >= 0 && idx < width * height){
            if (zz > zbuffer[idx]){
                    zbuffer[idx] = zz;
                    buffer[idx] = ch;
                    }
            }
    }

int main () {
    printf("\x1b[2J");
    while(1){
            memset(buffer, backASCIIcode, width * height);
            memset(zbuffer, 0, width * height * 4);
            cubeWidth = 20;
            horizontalOffset = -2 * cubeWidth;
            for(float cubeX = - cubewidth; cubeX < cubewidth; cubeX += incrementSpeed) {
                    for(float cubeY = - cubewidth; cubeY < cubewidth; cubeY += incrementSpeed) {
                            
                        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
                        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
                        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
                        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
                        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
                        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
                    }
                    
                    print("\x1b[H");
                    for ( int k = 0; k < width * height; k++){
                            putchar(k % width ? buffer[k] : 10);
                            }
                    
                    a += 0.005;
                    b += 0.005;
            }
    
    return 0;

    }
