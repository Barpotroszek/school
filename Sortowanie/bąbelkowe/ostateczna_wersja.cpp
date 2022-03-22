#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

const int
    LEN = 30,       // długość tablicy
    MAX_VALUE = 30; // maksymalna wartość wyrazu

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
        e = 0; // licznik obrotów pętli

    cout << "\n";
    // gMax -> górna granica, maksymalny index, do tej pozycji będą sprawdzane liczby
    for(int gMax=LEN-1; gMax >= 0; gMax--)
    {
        cout << "Etap " << e++ << ":\n";
        p = -1; // bo jesli będzie nieujemne, to może wskazywać jakieś pole z tablicy

        // pętla wykonuje się n-1 razy, gdzie n = ilością wyrazów w tablicy
        for (int k = 0; k < gMax; k++)
        {
            cout << " k=" << k << "  ->  ";
            if (tab[k] > tab[k + 1]) // jeżeli lewy wyraz ma większą wartość od prawego
            {
                swap(tab[k], tab[k + 1]); // zamień te wartości miejscami
                p = k;
            }
            wypisz(tab);
        }
        cout << "  result: ";
        wypisz(tab);
        cout << "\n\n";
        if(p<0) break; // jeśli nie będzie żadnej zmiany -> przerwij program
    }
    cout << "\n\nEfekt koncowy:\n";
    wypisz(tab);
}