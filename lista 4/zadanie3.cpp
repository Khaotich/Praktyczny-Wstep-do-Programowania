#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand( time( NULL ) );
    char wybor = 'T';

    while(wybor!='N')
    {
        int wylosowana_liczba =( std::rand() % 100 ) + 1;
        int strzal = 0;
        int proby = 0;

        cout << "Wymyśliłem sobie pewną liczbę z zakresu 1-100, zgadniesz która to?" << endl;
        while(strzal != wylosowana_liczba)
        {
            cout << "Podaj liczbę: ";
            cin >> strzal;

            if(strzal>wylosowana_liczba)
            {
                cout << "Podana liczba jest za duża" << endl;
            }
            else if (strzal<wylosowana_liczba)
            {
                cout << "Podana liczba jest za mała" << endl;
            }
            proby++;
            
        }
        
        if(strzal==wylosowana_liczba)
        {
            cout << "Gratulacje udało Ci się odgadnąć liczbę, ta liczba to: " << wylosowana_liczba << ", udało Ci się to w "<< proby << " próbie." << endl;
        }

        cout << "Chcesz spróbować jeszcze raz? (T/N)" << endl;
        cin >> wybor;
        
    }

    return 0;
}