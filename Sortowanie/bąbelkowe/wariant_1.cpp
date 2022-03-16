#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <math.h>
using namespace std;

const int
    LEN = 10,       // długość tablicy
    MAX_VALUE = 10; // maksymalna wartość wyrazu

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
    int tablica[LEN]; // tablica z liczbami
    zapisz(tablica);
    cout << "Przed sortowaniem:\n";
    wypisz(tablica);

    int p,     // pozycja gdzie została dokonana ostatnia zamiania
        e = 0; // licznik obrotów pętli
        
    cout << "\n";
    do
    {
        p = -1;                              // żeby nie wpaśc w nieskończoną pętlę
        
        // pętla wykonuje się n-1 razy, gdzie n = ilością wyrazów w tablicy
        for (int k = 0; k < LEN-1; k++)        // k - kursor
            if (tablica[k] > tablica[k + 1]) // jeżeli lewy wyraz ma większą wartość od lewego
            {
                swap(tablica[k], tablica[k + 1]); // zamień te wartości miejscami
                p = k;
            }
        e++;
        cout << " Etap " << e << ":  ";
        wypisz(tablica);
    } while (p >= 0);
    cout << "\n\nEfekt koncowy:\n";
    wypisz(tablica);
}