#include <iostream>
#include <climits>
using namespace std;

int main()
{
    char wybor = 'T';

    while(wybor!='N')
    {
        int dzialanie;
        float liczba1, liczba2;
        cout << "Podaj działanie: " << endl;
        cout << "0 dodawanie" << endl;
        cout << "1 odejmowanie" << endl;
        
        while(!(cin>>dzialanie))
        {   
            cout << "Podaj liczbę!" << endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        cout << "OK" << endl;

        cout << "Podaj pierwszą liczbę: ";
        while(!(cin>>liczba1))
        {   
            cout << "Podaj liczbę!" << endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        cout << "OK" << endl;
        
        cout << "Podaj drugą liczbę: ";
        while(!(cin>>liczba2))
        {   
            cout << "Podaj liczbę!" << endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        cout << "OK" << endl;


        if(dzialanie==0)
        {
            cout << "Twój wynik dodawania to: " << liczba1 + liczba2 << endl;
        }
        else if(dzialanie==1)
        {
            cout << "Twój wynik odejmowania to: " << liczba1 - liczba2 << endl; 
        }
        else
        {
            cout << "Wybrano złą opcję" << endl;
        }

        cout << "Chcesz spróbować jeszcze raz? (T/N)" << endl;
        cin >> wybor;
        
    }

    return 0;
}