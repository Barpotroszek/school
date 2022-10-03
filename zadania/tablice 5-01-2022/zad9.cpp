/* ZADANIE 9
Napisz funkcję, która otrzymuje cztery argumenty: dodatnią liczbę całkowitą n oraz trzy n-elementowe tablice tab1, tab2 i tab3 o elementach 
typu int i zamienia zawartości komórek otrzymanych w argumentach tablic w następujący sposób:
    a) dla dowolnego i komórka tab1[i] powinna zawierać największą spośród pierwotnych wartości komórek tab1[i], tab2[i] oraz tab3[i],
    b) dla dowolnego i komórka tab2[i] powinna zawierać drugą co do wielkości spośród pierwotnych wartości komórek tab1[i], tab2[i] oraz tab3[i],
    c) dla dowolnego i komórka tab3[i] powinna zawierać najmniejszą
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

void funkcja(int tab1[len], int tab2[len], int tab3[len])
{
    int a, b, c;
    for (int i = 0; i < len; i++)
    {
        a = tab1[i];
        b = tab2[i];
        c = tab3[i];

        //łapanie największej
        if (a > b && a > c)
            tab1[i] = a;
        else if (b > a && b > c)
            tab1[i] = b;
        else if (c > b && a < c)
            tab1[i] = c;

        //łapanie średniej
        if ((a > b && b > c) || (a < b && b < c))
            tab2[i] = b;
        else if ((b > a && a > c) || (b < a && a < c))
            tab2[i] = a;
        else if ((a < c && c < b) || (a > c && c > b))
            tab2[i] = c;

        //łapanie najmniejszej
        if (a < b && a < c)
            tab3[i] = a;
        else if (b < a && b < c)
            tab3[i] = b;
        else if (c < b && c < a)
            tab3[i] = c;
    }
}

int main(){
    int tab1[len], tab2[len], tab3[len];
    fill(tab1);
    fill(tab2);
    fill(tab3);
    display(tab1, tab2, tab3);
    cout << "\n";
    funkcja(tab1, tab2, tab3);
    display(tab1, tab2, tab3);
}