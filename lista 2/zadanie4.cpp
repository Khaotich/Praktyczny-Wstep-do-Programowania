#include <iostream>

using namespace std;

int main(){

    cout << "\t-5\t-4\t-3\t-2\t-1\t0\t1\t2\t3\t4\t5" <<endl;
    for(int x=-5; x<=5; x++)
    {
        cout << x << "\t";

        for(int y=-5; y<=5 ;y++)
        {
            if(y==-5)
            {
              cout << x*y;
            }
            else
            {
                cout << "\t" << x*y;
            }
        }
        cout << endl;
    }

    return 0;
}