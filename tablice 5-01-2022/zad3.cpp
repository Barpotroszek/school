/* ZADANIE 3
Napisz program wypełniający tablicę n liczb t[0] ... t[n-1] wartościami:
a) od 0 do n-1
b) od 7 do n+6
c) ciągiem 4, 8, 12, 16, ...
d) ciągiem 1, 2, 4, 8, 16, ...
e) 2,3,4,....,n+1
Zastosuj funkcje.
*/

#include <iostream>

using namespace std;
const int n = 5;

void display(int table[n])
{
    for (int a = 0; a < n; a++)
        cout << table[a] << ", ";
    cout << "\n";
}

void pkt_a(int table[n])
{
    cout << "pkt_a:\n\t";
    for (int a = 0; a < n; a++)
        table[a] = a;
    display(table);
}

void pkt_b(int table[n])
{
    cout << "pkt_b:\n\t";
    for (int a = 0; a < n; a++)
        table[a] = a+7;
    display(table);
}

void pkt_c(int table[n])
{
    cout << "pkt_c:\n\t";
    for (int a = 0; a < n; a++)
        table[a] = (a + 1) * 4;
    display(table);
}

void pkt_d(int table[n])
{
    cout << "pkt_d:\n\t";
    int zmienna=1;
    for (int a = 0; a < n; a++)
    {
        table[a] = zmienna;
        zmienna = zmienna * 2;
    }
    display(table);
}

void pkt_e(int table[n])
{
    cout << "pkt_e:\n\t";
    for (int a = 0; a < n; a++)
        table[a] = a+2;
    display(table);
}

int main()
{
    int table[n];
    pkt_a(table);
    pkt_b(table);
    pkt_c(table);
    pkt_d(table);
    pkt_e(table);
}