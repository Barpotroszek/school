#include <iostream>

using namespace std;

double f(double x){
    return x*x+x+2;
}

double Pole(int a, int b, int n){
    double x = (b-a)/(double)n;
    double S = 0.0; // zeby podkreslic, ze to liczby rzeczywiste
    double srodek = a+(b-a)/(n*2.0);
    for(int i=0; i<n; i++){
        S += f(srodek)*x;
        srodek += x;
    };
    return S;
}

int main()
{

    int a,b,n;
    cout << "a="; cin >> a; // poczatek przedzialu
    cout << "b="; cin >> b; // wysokosc wzgledna funkcji
    cout << "podaj liczbe prostokatow: "; cin >> n; // ilosc prostokatow, na ktore zostanie podzielona figura
    if(a<b) cout << "To nie jest przedzial :<";
    else cout << "Pole figury: " << Pole(a,b,n);
    return 0;
}
