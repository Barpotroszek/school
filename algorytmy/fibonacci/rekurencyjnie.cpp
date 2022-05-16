#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    int val = fibonacci(n-1) + fibonacci(n-2);
    // cout << "\nf(" << n << ") = " << val;
    return val;
}

int main()
{
    int amount;
    cout << "Podaj ktora liczbe ciagu mam pokazac: ";
    cin >> amount;
    cout << "Odp: " << fibonacci(amount);
}