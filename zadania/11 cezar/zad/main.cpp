#include <iostream>
#include <fstream>

using namespace std;

ifstream dane;
ifstream klucze;
ofstream wynik;

string szyfruj(string wyraz, string klucz){
    string tablica="";
    //cout << "\nWyraz: " << wyraz << '\n';
    for(int i=0; i<wyraz.length(); i++){
        int l = (int)wyraz[i];
        //cout << l << "->";
        int k = ((int)klucz[i%klucz.length()])%64;
        l += k;
        if(l>90)
            l-=26;
        tablica += (char)l;
        //cout << "("<<l<<")"<<(char)l << '\n';
    }
    return tablica;
}

string deszyfruj(string szyfrogram, string klucz){
    string tablica="";
    for(int i=0; i<szyfrogram.length(); i++){
        int l = (int)szyfrogram[i];
        int k = ((int)klucz[i%klucz.length()])%64;

        cout << l << "->";
        l -= k;
        if(l<65)
            l+=26;
        tablica += (char)l;
        cout << "("<<l<<")"<<(char)l << '\n';
    }
    return tablica;
}

int main()
{
    dane.open("tj.txt");
    klucze.open("klucze1.txt");
    wynik.open("wynik4a.txt");
    if(dane.bad()||klucze.bad()||wynik.bad()){
        cout << "Cos poszlo nie tak przy otwieraniu...";
        return 1;
    }
    do{
        string wyraz, klucz, szyfrogram;
        dane >> wyraz;
        klucze >> klucz;

        //cout << "w:" << klucz;
        szyfrogram = szyfruj(wyraz, klucz);
        wynik << szyfrogram << '\n';
    }
    while(!dane.eof());
    dane.close();
    klucze.close();
    wynik.close();
    cout << "Zrobione A; \n";

    dane.open("sz.txt");
    klucze.open("klucze2.txt");
    wynik.open("wynik4b.txt");

    if(dane.bad()||klucze.bad()||wynik.bad()){
        cout << "Cos poszlo nie tak przy otwieraniu...";
        return 1;
    }

    do{
        string wyraz, klucz, szyfrogram;
        dane >> szyfrogram;
        klucze >> klucz;

        cout << "w:" << szyfrogram;
        wyraz = deszyfruj(szyfrogram, klucz);
        cout << " -> " << wyraz << '\n';
        wynik << wyraz << '\n';
    }while(!dane.eof());

    dane.close();
    klucze.close();
    wynik.close();
    cout << "Zrobione B; \n";
    return 0;
}
