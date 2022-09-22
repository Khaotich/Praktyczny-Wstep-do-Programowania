#include <iostream>

using namespace std;

int main()
{
    cout << "\x1b[41m" "K" "\x1b[41m" << "\x1b[42m" "a" "\x1b[42m" 
    << "\x1b[43m" "r" "\x1b[43m" << "\x1b[44m" "o" "\x1b[44m" 
    << "\x1b[45m" "l" "\x1b[45m" << "\x1b[0m" " " "\x1b[0m"  
    << "\x1b[46m" "P" "\x1b[46m" << "\x1b[47m" "i" "\x1b[47m" 
    << "\x1b[48m" "c" "\x1b[48m" << "\x1b[41m" "h" "\x1b[41m" 
    << "\x1b[42m" "s" "\x1b[42m" << "\x1b[43m" "k" "\x1b[43m" 
    << "\x1b[44m" "i" "\x1b[44m" << endl;
    return 0;
}