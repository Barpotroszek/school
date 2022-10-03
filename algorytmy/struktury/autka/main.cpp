#include <iostream>

using namespace std;

struct samochod{
    string marka;
    int rok;
    string producent;
};

int main()
{
    int suma=0;
    samochod auta[3];
    for(int i=0; i<3; i++){
        cout << "\nAuto nr " << i << ".\n  Podaj marke auta: ";
        cin >> auta[i].marka;
        cout << "  Jego rok produkcji: ";
        cin >> auta[i].rok;
        cout << "  Producent:";
        cin >> auta[i].producent;
        suma += auta[i].rok;
    }
    for(int i=0; i<3; i++)
        cout << "\n\nAuto nr " << i<<"\n  Marka: " << auta[i].marka
        << "  Jego rok produkcji: "<< auta[i].rok << "  Producent: "  << auta[i].producent;

    cout << "\n\nSredni rok produkcji: " << ((float)suma)/3;
    return 0;
}
