/* ZADANIE 2
Napisz program wczytujący ciąg liczb całkowitych do tablicy.
a)	Wypisz na ekranie kolejno wszystkie liczby z tablic, które są parzyste.
b)	Wypisz na ekranie kolejno wszystkie liczby z tablicy, które dzielą się przez 3.
c)	Wypisz na ekranie kolejno wszystkie liczby z tablicy, które mają wszystkie cyfry parzyste.
d)	Wypisz na ekranie kolejno wszystkie liczby z tablicy, których suma cyfr wynosi 8.
e)	Wypisz na ekranie kolejno wszystkie liczby z tablicy, których indeksy są parzyste.
Zastosuj funkcje.
*/

#include <iostream>

using namespace std;
const int size = 20;

void save_to_table(int table[size])
{
    cout << "Wpisuj liczby mniejsze od 100!\n";
    for (int a = 0; a < size; a++)
    {
        cout << "Podaj liczbe nr." << a << ": ";
        cin >> table[a];
    }
}

void pkt_a(int table[size])
{
    cout << "\n\na) liczby parzyste:\n\t";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        if (l % 2 == 0)
            cout << l << ", ";
    }
}

void pkt_b(int table[size])
{
    cout << "\n\nb) podzielne przez 3:\n\t";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        if (l % 3 == 0)
            cout << l << ", ";
    }
}

void pkt_c(int table[size])
{
    cout << "\n\nc) wszystkie cyfry parzyste:\n\t";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        int d = l / 10; //liczba dziesiątek
        int j = l % 10; //liczba jedności
        if (d % 2 == 0 && j % 2 == 0)
            cout << l << ", ";
    }
}

void pkt_d(int table[size])
{
    //biore tu pod uwagę, że może to być 1-cyfrowa liczba
    cout << "\n\nd) liczby, ktorych suma cyfr wynosi 8:\n\t";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        int d = l / 10; //liczba dziesiątek
        int j = l % 10; //liczba jedności
        if (d + j == 8)
            cout << l << ", ";
    }
}

void pkt_e(int table[size])
{
    cout << "\n\ne) liczby, ktorych indeksy sa parzyste:\n\t";
    for (int a = 0; a < size; a++)
    {
        if (a % 2 == 0)
            cout << table[a] << ",";
    }
}

int main()
{
    cout << "Start programu\n";
    cout << "--------------------\n\n";
    int table[size];
    save_to_table(table);
    pkt_a(table);
    pkt_b(table);
    pkt_c(table);
    pkt_d(table);
    pkt_e(table);
}