#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    /* ----- UZUPELNIANIE SITA ----- */

const int N=1000000;
bool SITO[N];
    SITO[1]=false;
    for(int i=2; i<N; i++)
    {
        SITO[i]=true;
    }

    for(int i=2; i<=N/2; i++)
    {
        if(SITO[i]==true)
        {
            int j=i*2;
            while(j<=N)
            {
                SITO[j] = false;
                j = j+i;
            }
        }
    }
    /* ----- PRACA Z PLIKIEM ----- */

    int liczba, wynik3_2=0;
    ifstream plik;
    plik.open("liczby.txt");


    int max_rozkladow=0, max_rozkladana,
        min_rozkladow=200, min_rozkladana,
        rozklad;

    for(int i=0; i<100; i++)
    {
        plik >> liczba;
        if(SITO[liczba-1])
        {
            wynik3_2++;
        }


    }
    cout << "\n3.2) " << wynik3_2;




    return 0;

}
