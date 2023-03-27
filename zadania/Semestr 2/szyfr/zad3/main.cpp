#include <iostream>
#include <fstream>

using namespace std;

string deszyfruj(string txt, int klucz[50])
{
    char temp;
    for(int i=50; i>0; i--)
        swap(txt[klucz[(i-1)%6]-1], txt[i-1]);
    return txt;
}

int main()
{
    ifstream plik;
    ofstream wynik;
    string tekst;
    int A[6] = {6,2,4,1,5,3};
    plik.open("szyfr3.txt");
    wynik.open("wyniki_szyfr3.txt");

    plik >> tekst;
    wynik << deszyfruj(tekst, A)<<endl;

    return 0;
}
