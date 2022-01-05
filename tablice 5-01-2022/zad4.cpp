/*  ZADANIE 4
Napisz funkcję, która otrzymuje dwa argumenty: nieujemną liczbę całkowitą n oraz n-elementową tablicę tab elementów typu int i:
a)	nadaje wartość zero wszystkim elementom tablicy tab,
b)	zapisuje do kolejnych elementów tablicy wartości równe ich indeksom (do komórki o indeksie i funkcja ma zapisywać wartość i),
c)	podwaja wartość wszystkich elementów w tablicy tab,
d)	wpisz do  co drugiego elementu tablicy wartość ujemną.
e)	do wszystkich komórek tablicy tab wstawia wartości bezwzględne ich pierwotnych wartości.
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

void funkcja(int nieujemna, int tab[n]){
    //punkt a
    for (int a = 0; a < n; a++){
        tab[a] = 0;
    }
    cout << "\nPunkt a: ";
    display(tab);

    for (int a = 0; a < n; a++)
        tab[a] = a;
    cout << "\nPunkt b: ";
    display(tab);

    for (int a = 0; a < n; a++)
        tab[a] = a*2;

    cout<<"\nPunkt c: ";
    display(tab);

    for (int a = 0; a < n; a++)
        if(a%2==1)
            tab[a]=-7;
    cout << "\npunkt d: ";
    display(tab);

    for (int a = 0; a < n; a++)
        tab[a] = abs(tab[a]);
    cout << "\nPunkt e: ";
    display(tab);
}

int main(){
    int tab[n];
    funkcja(n, tab);
}