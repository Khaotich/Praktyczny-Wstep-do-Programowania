#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

long genFibonacci(int n) 
{
   long fibo[n+2]; 
   fibo[0] = 0;
   fibo[1] = 1;
   
   for (int i = 2; i <= n; i++) {
      fibo[i] = fibo[i-1] + fibo[i-2]; 
   }
   return fibo[n];
}

int main()
{
	
    ofstream data;
    data.open("wynik.dat");
    int n;
	
	cout<<"Podaj nr wyrazu ciągu: ";
	cin>>n;
	
	for(int i=0; i<=n; i++)
    {
        data << i << " " << genFibonacci(i) << endl;
    }
	
    data.close();
	return 0;
}