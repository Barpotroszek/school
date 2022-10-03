#include <iostream>
#include <iomanip>
#include <stdlib.h>
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
    int tab[LEN]; // tablica z liczbami
    zapisz(tab);

    cout << "Przed sortowaniem:\n";
    wypisz(tab);

    int p,     // pozycja gdzie została dokonana ostatnia zamiania
        e = 0, // licznik obrotów pętli
        gMax;  // górna granica, maksymalny index, do tej pozycji będą sprawdzane liczby

    cout << "\n";
    gMax = LEN;
    do
    {
        cout << "Etap " << e++ << ":\n";
        p = -1; // żeby nie wpaśc w nieskończoną pętlę

        // pętla wykonuje się n-1 razy, gdzie n = ilością wyrazów w tablicy
        for (int k = 0; k < gMax - 1; k++)
        {
            cout << " k=" << k << "  ->  ";
            if (tab[k] > tab[k + 1]) // jeżeli lewy wyraz ma większą wartość od prawego
            {
                swap(tab[k], tab[k + 1]); // zamień te wartości miejscami
                p = k;
            }
            wypisz(tab);
        }
        gMax--;
        cout << "  result: ";
        wypisz(tab);
        cout << "\n\n";
    } while (p >= 0);
    cout << "\n\nEfekt koncowy:\n";
    wypisz(tab);
}
