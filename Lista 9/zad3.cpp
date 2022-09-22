#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int x = 500, y = 500;

int main()
{
    for (int t = 0; t < 500; t++)
    {
        ofstream ofs("images/p" + to_string(t) +".ppm", ios_base::out | ios_base::binary);
        ofs << "P6" << endl << x << ' ' << y << endl << "255" << endl;

        for (int j = 0; j < y; ++j)
            for (int i = 0; i < x; ++i)
            {
                if ((i+1)*(j+1) <= t*t)
                {
                    ofs << (char)(i % 256) << (char)(j % 256) << (char)((i * j) % 256);
                }
                else
                {
                    ofs << 0 << ' ' << 0 << ' ' << 0;
                }
            }
        ofs.close();
    }
    return 0;
}