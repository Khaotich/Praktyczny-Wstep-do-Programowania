#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    ofstream data;
    data.open("wynik.dat");

    for(float x=0.0; x<=6.28; x+=0.01)
    {
        cout << x << "\t" << cos(x) << "\t" << pow(cos(x),2) << endl;
        data << x << "\t" << cos(x) << "\t" << pow(cos(x),2) << endl;
    }
    data.close();
    return 0;
}