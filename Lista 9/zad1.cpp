#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>


using namespace std;

const int width = 500, height = 500;
int r, g, b, random;

int main()
{
    srand(time(NULL));
    ofstream img ("picture.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            random = rand()%256;
            r = random;
            random = rand()%256;
            g = random;
            random = rand()%256;
            b = random;

            img << r << " " << g << " " << b << endl;
        }
    }
    img.close();    

    return 0;
}
