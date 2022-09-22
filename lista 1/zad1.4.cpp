#include <iostream>

using namespace std;

int main()
{
    cout << "\x1b[41m *   * " << "\x1b[40m   " << "\x1b[46m ***** " << endl;
    cout << "\x1b[41m *  *  " << "\x1b[40m   " << "\x1b[46m *   * " << endl;
    cout << "\x1b[41m * *   " << "\x1b[40m   " << "\x1b[46m *   * " << endl;
    cout << "\x1b[41m **    " << "\x1b[40m   " << "\x1b[46m ***** " << endl;
    cout << "\x1b[41m * *   " << "\x1b[40m   " << "\x1b[46m *     " << endl;
    cout << "\x1b[41m *  *  " << "\x1b[40m   " << "\x1b[46m *     " << endl;
    cout << "\x1b[41m *   * " << "\x1b[40m   " << "\x1b[46m *     " << endl;

    return 0;
}