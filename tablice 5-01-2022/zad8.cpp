/*  ZADANIE 8
Napisz funkcję, która otrzymuje cztery argumenty: dodatnią liczbę całkowitą n, n-elementowe tablice tab1 i tab2 oraz 2 · n-elementową tablicę tab3 o elementach typu double.
a)	Funkcja powinna przepisywać zawartość tablic tab1 i tab2 do tablicy tab3 w taki sposób, że na początku tablicy tab3 powinny się znaleźć elementy tablicy tab1, a po nich elementy tablicy tab2.
b)	Funkcja powinna przepisywać zawartość tablic tab1 i tab2 do tablicy tab3 w taki sposób, że w komórkach tablicy tab3 o nieparzystych indeksach powinny się znaleźć elementy tablicy tab1, a w komórkach tablicy tab3 o parzystych indeksach elementy tablicy tab2.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int len = 6;

void fill(int table[len])
{
    for (int a = 0; a < len; a++)
        table[a] = rand() % 100;
}

void zeros(double table[len * 2])
{
    for (int a = 0; a < len*2; a++)
        table[a] = 0;
}

void display(int tab1[len], int tab2[len], double tab3[len*2])
{
    cout << "   Tab1: ";
    for (int a = 0; a < len; a++)
        cout << tab1[a] << ", ";
    cout << "\n   Tab2: ";
    for (int a = 0; a < len; a++)
        cout << tab2[a] << ", ";
    cout << "\n   Tab3: ";
    for (int a = 0; a < len*2; a++)
        cout << tab3[a] << ", ";
    cout << "\n";
}

void pkt_a(int tab1[len], int tab2[len], double tab3[len])
{
    for (int a = 0; a < len; a++)
        tab3[a] = (double)tab1[a];
    for (int a = 0; a < len; a++)
        tab3[a + len] = (double)tab2[a];
}

void pkt_b(int tab1[len], int tab2[len], double tab3[len])
{
    for (int a = 0; a < 2 * len; a++)
        if (a % 2 == 0)
            tab3[a] = (double)tab2[a / 2];
        else
            tab3[a] = (double)tab1[a / 2];
}

int main()
{
    int tab1[len], tab2[len];
    double tab3[2 * len];
    fill(tab1);
    fill(tab2);
    zeros(tab3);

    cout << "Wartosci poczatkowe:\n";
    display(tab1, tab2, tab3);

    cout << "\nPunkt a:\n";
    pkt_a(tab1, tab2, tab3);
    display(tab1, tab2, tab3);

    cout << "\nPunkt b:\n";
    pkt_b(tab1, tab2, tab3);
    display(tab1, tab2, tab3);
    return 0;
}