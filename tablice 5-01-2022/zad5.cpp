/*  ZADANIE 5
Napisz funkcję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n oraz n-elementową tablicę tab o elementach typu int i zwraca jako wartość:
a) średnią arytmetyczną elementów tablicy tab.
b) sumę elementów tablicy tab,
c) sumę kwadratów elementów tablicy tab.
*/
#include <iostream>
using namespace std;

const int len = 6;

void fill(int table[len])
{
    for (int a = 0; a < len; a++)
        table[a] = a;
}

float pkt_a(int n, int tab[len])
{
    int suma = 0;
    for (int a = 0; a < n; a++)
        suma += tab[a];
    return suma/n;
}

int pkt_b(int n, int tab[len])
{
    int wynik = 0;
    for (int a = 0; a < n; a++)
        wynik += tab[a];
    return wynik;
}

double pkt_c(int n, int tab[len])
{
    int wynik=0;
    for (int a = 0; a < n; a++){
        wynik += tab[a]*tab[a];
        }
    return wynik;
}

int main()
{
    int table[len];
    fill(table); //tego nie było w poleceniu
    cout << "Punkt a: "<< pkt_a(len, table) << "\n";
    cout << "Punkt b: "<< pkt_b(len, table) << "\n";
    cout << "Punkt c: "<< pkt_c(len, table) << "\n";
    return 0;
}