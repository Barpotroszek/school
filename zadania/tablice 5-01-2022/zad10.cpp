/* Zadanie 10
Napisz funkcje, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n oraz n-elementową tablicę tab o elementach typu int i:
    a) zwraca największą wartość przechowywaną w tablicy tab,
    b) zwraca najmniejszą wartość przechowywaną w tablicy tab,
    c) zwraca indeks elementu tablicy tab o największej wartości,
    d) zwraca indeks elementu tablicy tab o najmniejszej wartości,
    e) zwraca największą spośród wartości bezwzględnych elementów przechowywanych w tablicy tab,
    f) zwraca indeks elementu tablicy tab o największej wartości bezwzględnej.  
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int len = 20;

void fill(int table[len])
{
    for (int a = 0; a < len; a++)
        table[a] = rand() % 100 -50;
}

void display(int tab[len])
{
    cout << "   Tab1: ";
    for (int a = 0; a < len; a++)
        cout << tab[a] << ", ";
    cout << "\n";
}

int pkt_a(int n, int tab[len])
{
    //m -> przechowyje najwiekszą wartosc
    int m = tab[0]; // awaryjnie
    for (int i = 1; i < n; i++)
        if (tab[i] > m)
            m = tab[i];
    return m;
}

int pkt_b(int n, int tab[len])
{
    int m = tab[0]; // najmniejsza wartosc z tabelki
    for (int i = 1; i < n; i++)
        if (tab[i] < m)
            m = tab[i];
    return m;
}

int pkt_c(int n, int tab[len])
{
    //indeks największej wartości
    int m = tab[0]; // największa wartosc z tabelki
    int id = 0;     //indeks tej wartosci w tabeli
    for (int i = 1; i < n; i++)
        if (tab[i] > m){
            m = tab[i];
            id = i;
            }
    return id;
}

int pkt_d(int n, int tab[len])
{
    //indeks najmniejszej wartości
    int m = tab[0]; // najmniejsza wartosc z tabelki
    int id = 0;     //indeks tej wartosci w tabeli
    for (int i = 1; i < n; i++)
        if (tab[i] < m){
            m = tab[i];
            id = i;
            }
    return id;
}

int mod(int a){
    //tworzenie modułu
    //cout << " Modul " << a << " -> " << (a<0 ? -1*a : a) << "\n";
    return (a<0 ? -1*a : a);
}

int pkt_e(int n, int tab[len])
{
    int m = mod(tab[0]);
    for (int i = 1; i < n; i++)
        if (mod(tab[i]) > m)
            m = mod(tab[i]);
    return m;
}

int pkt_f(int n, int tab[len])
{
    //indeks najmniejszej wartości
    int m = mod(tab[0]); // najmniejsza wartosc z tabelki
    int id = 0;     //indeks tej wartosci w tabeli
    for (int i = 1; i < n; i++)
        if (mod(tab[i]) > m){
            m = mod(tab[i]);
            id = i;
            }
    return id;
}

int main()
{
    srand(time(0));
    int tab[len];
    fill(tab);
    display(tab);
    cout << "a) " << pkt_a(len, tab) << "\n";
    cout << "b) " << pkt_b(len, tab) << "\n";
    cout << "c) " << pkt_c(len, tab) << "\n";
    cout << "d) " << pkt_d(len, tab) << "\n";
    cout << "e) " << pkt_e(len, tab) << "\n";
    cout << "f) " << pkt_f(len, tab) << "\n";
    return 0;
}