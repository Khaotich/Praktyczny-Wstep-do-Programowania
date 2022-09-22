#include <iostream>
using namespace std;

int main()
{
    int i;
    unsigned long long silnia = 1;
    
    cout << "Wprowadź N: ";
    cin >> i;

    for(int j=1; j<=i;j++)
    {
        silnia*=j;
        cout << silnia << endl;
    }

    //Maksymalne N=12, później wychodzimy po za zakres int.
    //Maksymalne N=20, później wychodzimy po za zakres unsigned long long.

    return 0;
}