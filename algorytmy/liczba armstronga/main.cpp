#include <iostream>

using namespace std;


int potega(int a, int b){
    int wynik = a;
    if(b==0) return 1;
    for(int i=1; i<b; i++)wynik*=a;
    return wynik;
}

bool armstrong(int n)
{
    int kopia=n, //żeby przypadkiem nie zniszczyć tamtej liczby 
        p=0, // licznik dziesiatek danej liczby
        wynik=0; //zmienna przechowujaca sume wszystkich cyfr podniesionych do potegi p
    while(kopia > 0){ // zliczanie ile liczb ma liczba
        kopia = kopia/10;
        p++;
    }
    // cout << "\nma " << p << "cyfry\n";
    kopia = n;
    for(int i=0; i<p; i++){
        int a=kopia%10; // tymczasowa zmienna przechowujaca cyfry odpowiednie
        kopia = kopia/10;
        // cout << "\n potega : " << potega(a,p);
        wynik += potega(a,p);
    }
    // cout << "suma: " << wynik;
    return wynik == n;
}

int main()
{
    int a;
    cout << "Podaj liczbe: ";
    cin >> a;
    cout << "Liczba ";
    if (!armstrong(a))
        cout << "nie ";
    cout << "jest narcystyczna";
}