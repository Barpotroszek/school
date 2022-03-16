#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <math.h>
using namespace std;

const int
    LEN = 10,       // długość tablicy
    MAX_VALUE = 16; // maksymalna wartość wyrazu

void zapisz(int tab[LEN])
{
    srand(time(NULL));
    for (int i = 0; i < LEN; i++)
        tab[i] = rand() % MAX_VALUE + 1;
}

void wypisz(int tab[LEN])
{
    srand(time(NULL));
    for (int i = 0; i < LEN; i++)
        cout << tab[i] << ", ";
    cout << "\n";
}

int main()
{
    // int tablica[LEN]; // tablica z liczbami
    int tablica[LEN] = {3, 13, 14, 14, 9, 8, 11, 15, 12, 6};
    zapisz(tablica);

    cout << "Przed sortowaniem:\n";
    wypisz(tablica);

    int p,     // pozycja gdzie została dokonana ostatnia zamiania
        e = 0, // licznik obrotów pętli
        gMax;  // górna granica, maksymalny index, do tej pozycji będą sprawdzane liczby

    cout << "\n";
    gMax = LEN;
    do
    {
        cout <<"Etap " << e++ <<":\n";
        p = -1; // żeby nie wpaśc w nieskończoną pętlę

        // pętla wykonuje się n-1 razy, gdzie n = ilością wyrazów w tablicy
        for (int k = 0; k < gMax - 1; k++)
        {
            cout << " k=" << k << "  ->  ";
            if (tablica[k] > tablica[k + 1]) // jeżeli lewy wyraz ma większą wartość od lewego
            {
                swap(tablica[k], tablica[k + 1]); // zamień te wartości miejscami
                p = k;
            }
            wypisz(tablica);
        }
        gMax--;
        cout << "  result: ";
        wypisz(tablica);  cout << "\n\n";
    } while (p >= 0);
    cout << "\n\nEfekt koncowy:\n";
    wypisz(tablica);
}