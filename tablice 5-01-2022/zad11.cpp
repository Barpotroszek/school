/* ZADANIE 11
    Napisz program, który w zadeklarowanej tablicy dwuwymiarowej 10×2 umieszcza w pierwszej kolumnie liczby od 0 do 9, 
w drugiej kwadraty tych liczb. Program powinien obliczać sumę elementów znajdujących się w pierwszej kolumnie oraz 
sumę liczb z kolumny drugiej i wypisać te wartości na ekranie. Zastosuj funkcje.
*/

#include <iostream>

using namespace std;

void fill(int table[10][2])
{
    for (int a = 0; a <= 9; a++)
    {
        table[a][0] = a;
        table[a][1] = a * a;
    }
}

void display(int tab[10][2])
{
    cout << "   Tab1: ";
    for (int a = 0; a < 10; a++)
        cout << tab[a][0] << ", " << tab[a][1]<<";\t";
    cout << "\n\n";
}

void funkcja(int tab[10][2]){
    int suma1=0;
    int suma2=0;
    for(int a=0; a<10; a++){
        suma1 += tab[a][0];
        suma2 += tab[a][1];
    }
    cout << "Suma z pierwszej kolumny: " << suma1 << "\n";
    cout << "Suma z drugiej kolumny: " << suma2 << "\n";
}

int main(){
    int tab[10][2];
    fill(tab);
    display(tab);
    funkcja(tab);
    return 0;
}
