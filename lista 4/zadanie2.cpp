#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    ofstream data;
    data.open("zad2.dat");
    srand( time( NULL ) );
    float suma;
    int liczby;
    for(int i=10; i<=5000; i++)
    {
        suma = 0;
        liczby = 0;
        
        for(int j=0; j<=i; j++)
        {
            float l = (double) rand()/RAND_MAX;
            suma += l;
            liczby ++;
        }
        data << i << " " << suma/liczby << endl;
    }

    data.close();
    return 0;
}