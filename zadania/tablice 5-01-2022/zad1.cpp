/*   ZADANIE 1
Napisz program wczytujący ciąg liczb rzeczywistych do tablicy . 
a)	Każdą element tablicy należy podnieść do kwadratu, a następnie wypisać na ekran. 
b)	Każdą element tablicy należy podnieść do trzeciej potęgi, a następnie wypisać na ekran. 
c)	Każdą element tablicy należy pomnożyć przez dwa. Tak otrzymane liczby należy wypisać na ekran.
d)	Wypisz na ekranie kolejno wszystkie liczby z tablicy, które należą do przedziału [4;15].
Zastosuj funkcje.
*/

#include <iostream>

using namespace std;
const int size = 20;

void save_to_table(int table[size])
{
    for (int a = 0; a < size; a++)
    {
        cout << "Podaj liczbe nr." << a << ": ";
        cin >> table[a];
    }
}

void pkt_a(int table[size])
{
    cout << "a) Podnoszenie do kwadratu:\n";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        cout << l << " -> " << l * l << "\n";
    }
}

void pkt_b(int table[size])
{

    cout << "b) Podnoszenie do szescianu:\n";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        cout << l << " -> " << l * l * l << "\n";
    }
}

void pkt_c(int table[size])
{

    cout << "c) pomnozone przez 2:\n";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        cout << l << " -> " << l * 2 << "\n";
    }
}

void pkt_d(int table[size])
{
    cout << "\nd) wypisywanie wszystkich liczb, ktore sa w przedziale [4,15]:\n";
    for (int a = 0; a < size; a++)
    {
        int l = table[a];
        cout << l << " -> ";
        if (4 < l && l < 15)
            cout << "w przedziale\n";
        else
            cout << "poza przedzialem\n";
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
    return 0;
}