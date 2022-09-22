#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

char p1='n',p2='n',p3='n',p4='n',p5='n',p6='n',p7='n',p8='n',p9='n';
bool game = true;
int gracz = 0; //  0 komputer / 1 użytkownik
string pole1 = "A1", pole2 = "B1", pole3 = "C3", pole4 = "A2",
pole5 = "B2", pole6 = "C2", pole7 = "A3", pole8 = "B3", pole9 = "C3";

void move();
void check();
void win();
void draw();
bool trast();
bool trast_c();
void swicher();

void swicher()
{
    if(gracz == 0) gracz=1;
    else gracz=0;
}

bool trast(string x)
{
    if(x==pole1 && p1=='n')
    {
        return true;
    }
    else if(x==pole2 && p2=='n')
    {
        return true;
    }
    else if(x==pole3 && p3=='n')
    {
        return true;
    }
    else if(x==pole4 && p4=='n')
    {
        return true;
    }
    else if(x==pole5 && p5=='n')
    {
        return true;
    }
    else if(x==pole6 && p6=='n')
    {
        return true;
    }
    else if(x==pole7 && p7=='n')
    {
        return true;
    }
    else if(x==pole8 && p8=='n')
    {
        return true;
    }
    else if(x==pole9 && p9=='n')
    {
        return true;
    }
    else return false;
}

bool trast_c(int x)
{
    if(x==1 && p1=='n')
    {
        return true;
    }
    else if(x==2 && p2=='n')
    {
        return true;
    }
    else if(x==3 && p3=='n')
    {
        return true;
    }
    else if(x==4 && p4=='n')
    {
        return true;
    }
    else if(x==5 && p5=='n')
    {
        return true;
    }
    else if(x==6 && p6=='n')
    {
        return true;
    }
    else if(x==7 && p7=='n')
    {
        return true;
    }
    else if(x==8 && p8=='n')
    {
        return true;
    }
    else if(x==9 && p9=='n')
    {
        return true;
    }
    else return false;
}

void move()
{
    if(gracz==0)
    {
        srand(time(NULL));
        int liczba = 1 + rand() % (9-2);
        cout << liczba;
        while(trast_c(liczba)==false)
        {
            liczba = 1 + rand() % (9-2);
        }
        if(liczba == 1) p1='O';
        if(liczba == 2) p2='O';
        if(liczba == 3) p3='O';
        if(liczba == 4) p4='O';
        if(liczba == 5) p5='O';
        if(liczba == 6) p6='O';
        if(liczba == 7) p7='O';
        if(liczba == 8) p8='O';
        if(liczba == 9) p9='O';
    }
    else
    {
        string wybor = "";
        cout << endl;
        cout << "Komputer wykonał ruch" << endl;
        cout << "Proszę wybrać pole z pustych: ";
        cin >> wybor;
        while(trast(wybor)==false)
        {
            cout << "Wybrano złe pole, proszę ponownie wprowadzić pole: ";
            cin >> wybor;
        }
        if(wybor == pole1) p1='X';
        if(wybor == pole2) p2='X';
        if(wybor == pole3) p3='X';
        if(wybor == pole4) p4='X';
        if(wybor == pole5) p5='X';
        if(wybor == pole6) p6='X';
        if(wybor == pole7) p7='X';
        if(wybor == pole8) p8='X';
        if(wybor == pole9) p9='X';
    }
}

void check()
{
    if ((p1==p2 && p2==p3 && p1!='n') ||
        (p4==p5 && p5==p6 && p4!='n') ||
        (p7==p8 && p8==p9 && p7!='n') ||
        (p1==p4 && p4==p7 && p1!='n') ||
        (p2==p5 && p5==p8 && p2!='n') ||
        (p3==p6 && p6==p9 && p3!='n') ||
        (p1==p5 && p5==p9 && p1!='n') ||
        (p3==p5 && p5==p7 && p3!='n'))
        {
            game = false;
            win();
        }
}

void win()
{
    if(gracz==0)
    {
        cout << "Wygrał komputer, może uda Ci się następnym razem." << endl;
    }
    else
    {
        cout << "Wygrałeś w pięknym stylu. Gratulacje." << endl;
    }

}

void draw()
{
    //czyścimy konsolę
    cout << "\033[H\033[J";
    // góra nad napisem
    for(int j=0; j<4; j++)
    {
        if(j==2) 
        {
            for(int x=0; x<15; x++) cout << "\u001b[46m ";
            cout << "\u001b[32mGra kółko i krzyżyk";
            for(int x=0; x<15; x++) cout << "\u001b[46m ";
        }
        else
            for(int i=0; i<49; i++)
            {
                cout << "\u001b[46m ";
            }
        cout << "\u001b[0m" << endl;
    }
    
    //napis
    for(int i=0; i<49; i++)
    {
        if(i==11) cout << "\u001b[31mA";
        else if(i==24) cout << "\u001b[31mB";
        else if(i==37) cout << "\u001b[31mC";
        else cout << "\u001b[46m ";
    }
    cout << "\u001b[0m" << endl;

    //1 rząd pól
    for(int j=0; j<11; j++)
    {
        for(int i=0; i<49; i++)
        {
            if(i==5 && j==5) cout << "\u001b[31m1";
            else if((i==11 || i==24 || i==37) && j==5)
            {
                if(i==11)
                {   
                    if(p1=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p1);
                }
                if(i==24)
                {   
                    if(p2=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p2);
                }
                if(i==37)
                {   
                    if(p3=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p3);
                }
            } 
            else if((i>5 && i<17)||(i>18 && i<30)||(i>31 && i<43)) cout << "\u001b[47m ";
            else cout << "\u001b[46m ";
        }
        cout << "\u001b[0m" << endl;
    }

    //przerwa między 1 a 2 rzędem
    for(int i=0; i<49; i++)
    {
        cout << "\u001b[46m ";
    }
    cout << "\u001b[0m" << endl;

    //2 rząd pól
    for(int j=0; j<11; j++)
    {
        for(int i=0; i<49; i++)
        {
            if(i==5 && j==5) cout << "\u001b[31m2";
            else if((i==11 || i==24 || i==37) && j==5)
            {
                if(i==11)
                {   
                    if(p4=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p4);
                }
                if(i==24)
                {   
                    if(p5=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p5);
                }
                if(i==37)
                {   
                    if(p6=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p6);
                }
            }
            else if((i>5 && i<17)||(i>18 && i<30)||(i>31 && i<43)) cout << "\u001b[47m ";
            else cout << "\u001b[46m ";
        }
        cout << "\u001b[0m" << endl;
    }

    //przerwa między 2 a 3 rzędem
    for(int i=0; i<49; i++)
    {
        cout << "\u001b[46m ";
    }
    cout << "\u001b[0m" << endl;

    //3 rząd pól
    for(int j=0; j<11; j++)
    {
        for(int i=0; i<49; i++)
        {
            if(i==5 && j==5) cout << "\u001b[31m3";
            else if((i==11 || i==24 || i==37) && j==5)
            {
                if(i==11)
                {   
                    if(p7=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p7);
                }
                if(i==24)
                {   
                    if(p8=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p8);
                }
                if(i==37)
                {   
                    if(p9=='n') cout << "\u001b[31m ";
                    else cout << "\u001b[31m" + string(1, p9);
                }
            }
            else if((i>5 && i<17)||(i>18 && i<30)||(i>31 && i<43)) cout << "\u001b[47m ";
            else cout << "\u001b[46m ";
        }
        cout << "\u001b[0m" << endl;
    }

    // dół pod planszą
    for(int i=0; i<4; i++)
    {
        for(int i=0; i<49; i++)
        {
            cout << "\u001b[46m ";
        }
        cout << "\u001b[0m" << endl;
    }
}

int main()
{
    while(game)
    {
        move();
        draw(); 
        check();
        swicher();
    }
    return 0;
}
