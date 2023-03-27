#include <iostream>
#include <fstream>

using namespace std;

string szyfruj(string txt, int klucz[50]){
    char temp;
    for(int i=0; i<50; i++)
        swap(txt[i], txt[klucz[i]-1]);
    return txt;
}

int main()
{
    ifstream plik;
    ofstream wynik;
    string tekst[6];
    int klucz[50];
    plik.open("szyfr1.txt");
    wynik.open("wyniki_szyfr1.txt");

    for(int i=0; i<6; i++)
        plik >> tekst[i];
    for(int i=0; i<50; i++)
        plik >> klucz[i];
    for(int i=0; i<6; i++)
        wynik << szyfruj(tekst[i], klucz)<<endl;


    return 0;
}
