#include <iostream>
#include <fstream>

using namespace std;
ofstream wynik;
ifstream dane;

bool sprawdz_szyfrogram(string slowo, string szyfrogram) {
    if (slowo.length() != szyfrogram.length())   return false;
    int k = (int)slowo[0] - (int)szyfrogram[0];
    if (k < 0) k += 26;
    int roznica;
    for (int i = 1; i < slowo.length(); i++)
    {
        roznica = (int)slowo[i] - (int)szyfrogram[i];
        if (roznica < 0) roznica += 26;
        // cout << slowo << ", " << szyfrogram;
        // cout << ";  Roznica: " << roznica << endl;
        if (roznica != k) {
            cout << slowo << ", " << szyfrogram << '\n';

            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Otwieranie i tworzenie plików... ";

    dane.open("dane_6_3.txt");
    wynik.open("wynik_6_3.txt");
    if (!(dane.is_open() && wynik.is_open()))
    {
        cout << "Coœ posz³o nie tak...";
        return 1;
    }
    cout << " Pliki zostaly otwarte!\n Odczyt pliku\n\n";
    string tekst, szyfrogram;


    for (int i = 0; i < 3000; i++) {
        dane >> tekst >> szyfrogram;
        bool jest_ok = sprawdz_szyfrogram(tekst, szyfrogram);
        if (jest_ok)
            wynik << tekst << '\n';
    }
    dane.close();
    wynik.close();
    cout << "\n\nProgram skonczyl prace\n";
    return 0;
}
