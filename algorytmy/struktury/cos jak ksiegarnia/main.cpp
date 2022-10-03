#include <iostream>
#include <fstream>

using namespace std;
ifstream dane("dane.txt");

struct ksiazka {
    string tytul;
    string autor;
    float cena;
    int naklad;
};

int main()
{
    string data;
    ksiazka biblioteka[4];
    for(int i=0; i<4; i++){
        while(biblioteka[i].tytul == "")
            getline(dane, biblioteka[i].tytul);
        getline(dane, biblioteka[i].autor);
        dane >> biblioteka[i].cena;
        dane >> biblioteka[i].naklad;
    }


    for(int i=0; i<4; i++){
        cout << "\ntytul: " << biblioteka[i].tytul << "\n";
        cout << "autor: " << biblioteka[i].autor << "\n";
        cout << "cena: " << biblioteka[i].cena << "\n";
        cout << "naklad: " << biblioteka[i].naklad << "\n";
    }return 0;
}
