#include <iostream>

using namespace std;

int readMass()
{
    int masa;
    cout << "Podaj swoją masę w kg: ";
    cin >> masa;
    return masa;
}

float readHeight()
{
    float wysokosc;
    cout << "Podaj swój wzrost w metrach: ";
    cin >> wysokosc;
    return wysokosc;
}

float BMI(float x, int y)
{
    return (y/(x*x));
}

void BMIprint(float x)
{
    if(x<16) cout << "Masz niedowagę w skali wygłodzenia" << ", Twoje BMI wynosi " << x << endl;
    else if(x>=16 && x<17) cout << "Masz niedowagę w skali wychudzenia" << ", Twoje BMI wynosi " << x << endl;
    else if(x>=17 && x<18.5) cout << "Masz niedowagę" << ", Twoje BMI wynosi " << x << endl;
    else if(x>=18.5 && x<25) cout << "Masz idealną wagę" << ", Twoje BMI wynosi " << x << endl;
    else if(x>=25 && x<30) cout << "Masz idealną nadwagę" << ", Twoje BMI wynosi " << x << endl;
    else if(x>=30 && x<35) cout << "Masz otyłość I stopnia" << ", Twoje BMI wynosi " << x << endl;
    else if(x>=35 && x<40) cout << "Masz otyłość II stopnia" << ", Twoje BMI wynosi " << x << endl;
    else if(x>40) cout << "Masz otyłość III stopnia" << ", Twoje BMI wynosi " << x << endl;
}

int main()
{
    BMIprint( BMI( readHeight(), readMass() ) );
    
    return 0;
}
