/*  ZADANIE 6
Napisz funkcję, która otrzymuje trzy argumenty: dodatnią liczbę całkowitą n oraz dwie n-elementowe tablice tab1, tab2 o elementach typu int i:
a)	przepisuje zawartość tablicy tab1 do tablicy tab2,
b)	przepisuje zawartość tablicy tab1 do tablicy tab2 w odwrotnej kolejności (czyli element tab1[0] ma zostać zapisany do komórki tablicy tab2 o indeksie n − 1).
*/

#include <iostream>
using namespace std;

const int len = 5;

void fill(int table[len])
{
    for (int a = 0; a < len; a++)
        table[a] = a;
}

void display(int tab1[len], int tab2[len])
{
    cout << "   Tab1: ";
    for (int a = 0; a < len; a++)
        cout << tab1[a] << ", ";
    cout << "\n   Tab2: ";
    for (int a = 0; a < len; a++)
        cout << tab2[a] << ", ";
    cout << "\n";
}

void pkt_a(int tab1[len], int tab2[len]){
    for (int a = 0; a < len; a++)
        tab2[a] = tab1[a];
}

void pkt_b(int tab1[len], int tab2[len]){
    for (int a = 0; a < len; a++)
        tab2[a] = tab1[len-a-1];
}

int main(){
    int tab1[len], tab2[len];
    fill(tab1);
    cout << "\nNa start:\n";
    display(tab1, tab2); //wywala dziwne rzeczy przy tab2, bo nie zdefiniowano jej wartości
    cout << "\nPunkt a:\n";
    pkt_a(tab1, tab2);
    display(tab1, tab2);
    cout << "\nPunkt b:\n";
    pkt_b(tab1, tab2);
    display(tab1, tab2);
    return 0;
}