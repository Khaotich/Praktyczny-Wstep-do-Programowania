#include <iostream>
#include <fstream>

using namespace std;

const int width = 500, height = 500;
int r, g, b, temp=0;

int main()
{
    ofstream img ("picture.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if(temp == 0) r++;
            else if(temp == 1) g++;
            else
            {
                g++;
                temp = 0;
            }
            temp++;

            img << r << " " << g << " " << b << endl;
        }
    }
    img.close();
    
    return 0;
}
