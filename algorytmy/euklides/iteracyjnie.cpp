#include <iostream>

using namespace std;

int euklides(int a, int b)
{
    int r;
    do{
        r=a%b;
        a=b;
        b=r;
    }while(b!=0);
    return a;
}

int main()
{
    int a,b;
    cout << "Podaj dwie liczby: ";
    cin >> a >> b;
    cout << "NWD("<< a<<", "<< b << ") wynosi: " << euklides(a, b);
}