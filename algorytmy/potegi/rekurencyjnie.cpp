#include <iostream>

using namespace std;

int potega(int &liczba, int wykladnik)
{
    if (wykladnik == 0)
        return 1;
    return potega(liczba, wykladnik - 1) * liczba;
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
