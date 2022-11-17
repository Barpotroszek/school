#include <iostream>

using namespace std;

int main()
{
    string S = " NKI_ATE_USGACYOKZZ_YYSJTCWEKI_SAEMTRLE_P";
    int k = 10, //ilosc elementow w kolumnie
        n = S.length(), //ilosc znakow w tekscie
        w = n/k, //ilosc elementow w wierszu
        ob = 0; //obecny wiersz

    //cout << "W: " << w << '\n';
    char tablica[w][k] = {};
    for(int i=1; i<=n; i++)
    {
        int temp = i-1; //pomocnicza

        float r = (float)temp/w - temp/w; //liczba po przecinku
        if(r==0 && temp!=0)
        {
            cout << '\n';
            ob++;
        }

        tablica[temp/w][temp%w] = (char)S[i];
        cout << "  (" << temp/w<<", "<< temp%w<<")  ";
        cout <<  tablica[temp/w][temp%w];
    };

    ob=0;
    int c=0, i=1;
    string T =" ";
    while(ob<w)
    {
        while(c<k){
            //cout << tablica[c][ob];
            T += tablica[c][ob];
            c++;
            i++;
        }
        ob++;
        while(c>0){
            c--;
            //cout << tablica[c][ob];
            T += tablica[c][ob];
            i++;
        };
        ob++;
    };

    cout << "\n\nHaslo: ";
    cout << T;
    return 0;
}
