/*  ZADANIE 7
Napisz funkcję, która otrzymuje cztery argumenty: dodatnią liczbę całkowitą n oraz trzy n-elementowe tablice tab1, tab2 i tab3 o elementach typu int, i:
a)	przypisuje elementom tablicy tab3 sumę odpowiadających im elementów tablic tab1 i tab2 (do komórki tablicy tab3 o indeksie i powinna trafić suma elementów tab1[i] i tab2[i]),
b)	przypisuje elementom tablicy tab3 większy spośród odpowiadających im elementów tablic tab1 i tab2 (do komórki tablicy tab3 o indeksie i powinien trafić większy spośród elementów tab1[i] i tab2[i]),
c)	przypisuje zawartość tablicy tab1 do tablicy tab2, zawartość tablicy tab2 do tablicy tab3 oraz zawartość tablicy tab3 do tablicy tab1.
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

void zeros(int table[len])
{
    for (int a = 0; a < len; a++)
        table[a] = 0;
}

void display(int tab1[len], int tab2[len], int tab3[len])
{
    cout << "   Tab1: ";
    for (int a = 0; a < len; a++)
        cout << tab1[a] << ", ";
    cout << "\n   Tab2: ";
    for (int a = 0; a < len; a++)
        cout << tab2[a] << ", ";
    cout << "\n   Tab3: ";
    for (int a = 0; a < len; a++)
        cout << tab3[a] << ", ";
    cout << "\n";
}

void pkt_a(int tab1[len], int tab2[len], int tab3[len])
{
    for (int a = 0; a < len; a++)
        tab3[a] = tab1[a] + tab2[a];
}

void pkt_b(int tab1[len], int tab2[len], int tab3[len])
{
    for (int a = 0; a < len; a++)
    {
        if (tab1[a] > tab2[a])
            tab3[a] = tab1[a];
        else
            tab3[a] = tab2[a];
    }
}

void pkt_c(int tab1[len], int tab2[len], int tab3[len])
{
    for (int a = 0; a < len; a++)
    {
        int temp = tab1[a];
        tab1[a] = tab2[a];
        tab2[a] = tab3[a];
        tab3[a] = temp;
    }
}

int main()
{
    srand(time(NULL));
    int tab1[len], tab2[len], tab3[len];
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

    cout << "\nPunkt c:\n";
    pkt_c(tab1, tab2, tab3);
    display(tab1, tab2, tab3); 
    return 0;
}