#include <iostream>
#include <fstream>

using namespace std;
ofstream wynik;
ifstream dane;

string szyfruj(string text, int k) {
    string output;
    char temp;
    k %= 26;
    for (int a = 0; a < text.length(); a++) {
        // Szyfrowanie tekstu
        temp = text[a];
        int val = temp % 65;
        val += k;
        output += (char)(val % 26 + 65);
    }
    return output;
};

int main()
{
    cout << "Otwieranie i tworzenie plikow... ";

    dane.open("dane_6_1.txt");
    wynik.open("wynik_6_1.txt");
    if (!(dane.is_open() && wynik.is_open()))
    {
        cout << "Coœ posz³o nie tak...";
        return 1;
    }
    cout << " Pliki zostaly otwarte!\n Szyfrowanie...\n";
    string text;
    int i=0;
    while (i < 100)
    {
        dane >> text; // odczyt danych z pliku
        i++;
        wynik << szyfruj(text, 107) << '\n';
    }
    dane.close();
    wynik.close();
    cout << "Program skonczyl prace\n";
    return 0;
}
