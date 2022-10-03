#include <iostream>

using namespace std;

int main()
{
    char tab[40];
    char *wsk;

    cout << "Podaj tekst: ";
    cin.getline(tab, 40);
    wsk = tab;
    int ile=0;
    while(*wsk!='\0'){
        ile++;
        wsk++; // przesuwamy wskaŸnik na kolejny element z tablicy
    }
    cout << "Podany tekst ma " << ile << " znakow";
    return 0;
}
