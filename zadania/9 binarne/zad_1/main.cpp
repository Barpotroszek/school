#include <iostream>
#include <fstream>

using namespace std;

bool zad_1(string liczba)
{
    int w_lenght = size(liczba),
        half = w_lenght/2;

    for(int i=0; i<half; i++)
    {
        if(liczba[i]!=liczba[half+i])
        {
            //cout << "failed on: " << i << "\n ->    " <<liczba[i] << " i " << liczba[half+1];
            return false;
        }
    }
    return true;
}

double potega(int a, int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    int l=a;
    for(int i=1; i<b; i++)
    {
        l=l*a;
    }
    return l;
}

bool zad_2(string liczba)
{
    char nic;
    int segmenty = size(liczba)/4,
        wart, // Wartoœæ danego segmentu
        p=0;

    for(int segm=0; segm < segmenty; segm++)
    {
        wart =0;
        for(int i=0; i<4; i++)
        {
            if(liczba[4*segm+i] == '1')
            {
                p=potega(2, 3-i);
                wart += p;
                // cout << "=>"<<p ;
            }
        }
        if(wart > 9)
        {
            //cout << "wychodze...\n";
            return true;
        };
    }
    cout << '\n';
    return false;
}


int zad_3(string liczba)
{
    int wart=0, p;
    //cout << liczba;

    //cout << endl;
    for(int i=size(liczba); i>0; i--)
    {

        if(liczba[i-1] == '1')
        {
            p=potega(2, size(liczba)-i);
            wart += p;
            if(wart>=65535) return 0;
        }
    }
    return wart;
}


int main()
{
    ifstream plik;
    string dane, najdluzszy, bin_3;
    int max_dlugosc=0,
        licznik_1=0,
        licznik_2=0,
        min_2=99999999999,
        dec_3=0,
        temp;

    plik.open("binarne.txt");
    //cout << "Otwarto? ";
    if( plik.bad())
    {
        cout << "Coœ posz³o nie tak przy otwieraniu pliku...";
        return 1;
    }
    cout << '\t';
    while(!plik.eof())
    {
        char nic;
        plik >> dane;

        if(zad_1(dane)){
            licznik_1++;
/*
            cout << "Liczba dwucykliczna:\t" << dane;
            cout << "\n dlugosc: " << size(dane);
            cout << "\n\n";
            */
            if(size(dane) >> max_dlugosc){
                max_dlugosc = size(dane);
                najdluzszy = dane;
            }
        }

        if(zad_2(dane))
        {
            if(size(dane)<min_2)
            min_2 = size(dane);
            licznik_2++;
        }


        temp = zad_3(dane);
        if(temp > dec_3)
        {
            dec_3 = temp;
            bin_3 =dane;
        }
    }
    cout << "\n\n\nzad 1\n-----------------------------------\n";
    cout << "Ilosc liczb dwucyklicznych: " << licznik_1;
    cout << "\nNajdluzszy ciag: " << najdluzszy;
    cout << "\njego dlugosc: " << max_dlugosc;

    cout << "\n\n\nzad 2\n-----------------------------------\n";
    cout << "liczba niepoprawnych napisow: " << licznik_2;
    cout << "\ndlugosc najkrotszego wyrazu: " << min_2;


    cout << "\n\n\nzad 3\n-----------------------------------\n";
    cout << "binarnie: " << bin_3;
    cout << "\ndecymalnie: " << dec_3;
    return 0;
}
