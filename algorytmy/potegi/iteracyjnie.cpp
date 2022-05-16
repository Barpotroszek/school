#include <iostream>

using namespace std;

int potega(int &liczba, int &wykladnik)
{
    int wynik = liczba;
    for (int a = wykladnik; a > 1; a--)
    {
        wynik = wynik * liczba;
    }
    return wynik;
}

int main()
{
    int n, wykladnik;
    n = 2;
    cout << "Podaj wykladnik: ";
    cin >> wykladnik;
    cout << n << " do " << wykladnik << " = " << potega(n, wykladnik) << endl;
    return 0;
}
