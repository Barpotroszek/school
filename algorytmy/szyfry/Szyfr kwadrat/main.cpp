#include <iostream>
#include <math.h>

using namespace std;

int len;

void szyfruj(string txt){
    len = txt.size();
    int m = 1; //dlugosc boku kwadratu
    while(m*m<len) m++; //wyliczanie boku kwadratu
    char t[m][m];
    for(int k=0; k<m; k++)
        for(int w=0; w<m; w++)
            t[k][w] = txt[k*m+w];

    for(int k=0; k<m; k++)
        for(int w=0; w<m; w++)
            cout << t[w][k];
}

int main()
{
    string tekst;
    cout << "Podaj jakis tekst(bez spacji): ";
    cin >> tekst;
    szyfruj(tekst);
    return 0;
}
