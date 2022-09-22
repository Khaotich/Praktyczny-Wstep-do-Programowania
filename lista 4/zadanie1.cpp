#include <iostream>
#include <climits>

using namespace std;

void a()
{
    cout << "Hello World" << endl;
}

void b(float x)
{
    cout << x << endl;
}

void c(int a, int b)
{
    cout << a+b << endl;
}

int d(int x, float y, float z)
{
    return x*y*z;
}

int e(int * d, int z)
{
    int iloczyn = 1;
    for(int i=0; i<z; i++)
    {
        iloczyn = iloczyn * d[i];
    }
    return iloczyn;
}

int main()
{
    int tab[7] = {1,2,3,4,5,6,7};
    
    char wybor = 'T';

    while(wybor!='N')
    {
        int dzialanie;
        cout << "Podaj funkcję: " << endl;
        cout << "0 A" << endl;
        cout << "1 B" << endl;
        cout << "2 C" << endl;
        cout << "3 D" << endl;
        cout << "4 E" << endl;
        
        while(!(cin>>dzialanie))
        {   
            cout << "Podaj liczbę!" << endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        cout << "OK" << endl;

        

        if(dzialanie==0)
        {
            a();
        }
        else if(dzialanie==1)
        {
            float x = 0;
            cout << "Wprowadź liczbę: " << endl;
            cin >> x;
            b(x);
        }
        else if(dzialanie==2)
        {
            int x = 0;
            int y = 0;
            cout << "Wprowadź pierwszą liczbę: " << endl;
            cin >> x;
            cout << "Wprowadź drugą liczbę: " << endl;
            cin >> y;
            c(x,y);
        }
        else if(dzialanie==3)
        {
            int x = 0;
            float y = 0;
            float z = 0;
            cout << "Wprowadź pierwszą liczbę: " << endl;
            cin >> x;
            cout << "Wprowadź drugą liczbę: " << endl;
            cin >> y;
            cout << "Wprowadź trzecią liczbę: " << endl;
            cin >> z;
            cout << d(x,y,z) << endl;
        }
        else if(dzialanie==4)
        {
            cout << e(tab,7) << endl;;
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