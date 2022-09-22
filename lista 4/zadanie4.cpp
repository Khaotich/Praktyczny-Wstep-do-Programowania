#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    char wybor = 'T';
    int kolejka = 0;

    while(wybor!='N')
    {
        int wylosowana_liczba =(rand() % (100 + 20*kolejka) ) + 1;
        int strzal = 0;
        int tura = 0;

        cout << "Wymyśliłem sobie pewną liczbę z zakresu 1-"<< 100+20*kolejka << ", zgadniesz która to?" << endl;
        while(strzal != wylosowana_liczba)
        {
            cout << "Podaj liczbę: ";
            cin >> strzal;
            tura++;

            if(strzal>wylosowana_liczba)
            {
                cout << "Podana liczba jest za duża" << endl;
            }
            else if (strzal<wylosowana_liczba)
            {
                cout << "Podana liczba jest za mała" << endl;
            }

            kolejka++;
        }
        
        if(strzal==wylosowana_liczba)
        {
            cout << "Gratulacje udało Ci się odgadnąć liczbę, ta liczba to: " << wylosowana_liczba << endl;
            cout << "Udało Ci się odgadnąć w " << tura << " turze." << endl;
        }

        cout << "Chcesz spróbować jeszcze raz? (T/N)" << endl;
        cin >> wybor;
        
    }

    return 0;
}