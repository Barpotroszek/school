#include <iostream>

using namespace std;

void szyfruj(char tekst[], int &key)
{
    int idx=0;
    int klucz = key%26; //bo jest 26 liter
    while(tekst[idx] != '\0')  // dopóki nie ma koñca tekstu
    {
        tekst[idx] = (char)((int)tekst[idx]+klucz);
        if((int)tekst[idx] > 122)
            tekst[idx] = (char)((int)tekst[idx]-26);
        idx++;
    }
}

void deszyfruj(char tekst[], int &key)
{
    int idx=0;
    int klucz = key%26; //bo jest 26 liter
    while(tekst[idx] != '\0')  // dopóki nie ma koñca tekstu
    {
        tekst[idx] = (char)((int)tekst[idx]-klucz);
        if((int)tekst[idx] <97)
            tekst[idx] = (char)((int)tekst[idx]+26);
        idx++;
    }
}

int main()
{
    char tekst[50];
    int key;
    cout << "Podaj slowo/tekst do zaszyfrowania(bez spacji): ";
    cin >> tekst;
    cout << "podaj klucz(3 dla Cezara): ";
    cin >> key;
    szyfruj(tekst, key);
    cout << "zaszyfrowany: " << tekst << '\n';
    deszyfruj(tekst, key);
    cout << "odszyfrowany: " << tekst;
    return 0;
}
