#include <iostream>
#include <fstream>

using namespace std;

string szyfruj(string txt, int klucz[50])
{
    char temp;
    for(int i=0; i<50; i++)
        swap(txt[i], txt[klucz[i%15]-1]);
    return txt;
}

int main()
{
    ifstream plik;
    ofstream wynik;
    string tekst;
    int klucz[50];
    plik.open("szyfr2.txt");
    wynik.open("wyniki_szyfr2.txt");

    plik >> tekst;
    for(int i=0; i<15; i++)
        plik >> klucz[i];
    wynik << szyfruj(tekst, klucz)<<endl;


    return 0;
}
