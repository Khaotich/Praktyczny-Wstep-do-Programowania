#include <iostream>

using namespace std;

int main()
{
    //1
    for(int i=0; i<=7; i++)
    {
        cout << "\x1b[107m \x1b[0m";
    }

    cout << endl;
    //2
    for(int i=0; i<=7; i++)
    {
        if(i>0 && i<7) 
        {
            cout << "\x1b[105m \x1b[0m";
        }
        else 
        {
            cout << "\x1b[107m \x1b[0m";
        }
    }

    cout << endl;
    //3
    for(int i=0; i<=7; i++)
    {
        if(i>1 && i<6) 
        {
            cout << "\x1b[102m \x1b[0m";
        }
        else if(i==1 || i==6)
        {
            cout << "\x1b[105m \x1b[0m";
        }
        else 
        {
            cout << "\x1b[107m \x1b[0m";
        }
    }

    cout << endl;
    //4
    for(int i=0; i<=7; i++)
    {
        if(i==0 || i==7) 
        {
            cout << "\x1b[107m \x1b[0m";
        }
        else if(i==1 || i==6)
        {
            cout << "\x1b[105m \x1b[0m";
        }
        else if(i==2 || i==5)
        {
            cout << "\x1b[102m \x1b[0m";
        }
        else if(i==3 || i==4)
        {
           cout << "\x1b[103m \x1b[0m"; 
        }
    }

    cout << endl;
    //4
    for(int i=0; i<=7; i++)
    {
        if(i==0 || i==7) 
        {
            cout << "\x1b[107m \x1b[0m";
        }
        else if(i==1 || i==6)
        {
            cout << "\x1b[105m \x1b[0m";
        }
        else if(i==2 || i==5)
        {
            cout << "\x1b[102m \x1b[0m";
        }
        else if(i==3 || i==4)
        {
           cout << "\x1b[103m \x1b[0m"; 
        }
    }

    cout << endl;
    //3
    for(int i=0; i<=7; i++)
    {
        if(i>1 && i<6) 
        {
            cout << "\x1b[102m \x1b[0m";
        }
        else if(i==1 || i==6)
        {
            cout << "\x1b[105m \x1b[0m";
        }
        else 
        {
            cout << "\x1b[107m \x1b[0m";
        }
    }

    cout << endl;
    //2
    for(int i=0; i<=7; i++)
    {
        if(i>0 && i<7) 
        {
            cout << "\x1b[105m \x1b[0m";
        }
        else 
        {
            cout << "\x1b[107m \x1b[0m";
        }
    }

    cout << endl;
    //1
    for(int i=0; i<=7; i++)
    {
        cout << "\x1b[107m \x1b[0m";
    }
    
    return 0;
}