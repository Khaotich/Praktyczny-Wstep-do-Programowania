#include <iostream>

using namespace std;

int main()
{
    for(int i=0; i<=255; i++)
    {
        cout << "\x1b[" << i << "m Cześć! \x1b[0m" << endl;
        cout << i << endl;
    }
    return 0;
}