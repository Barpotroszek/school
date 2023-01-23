#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void podpkt_1(string dane)
{
    int odp = 0;
    for(int i=0; i<9999; i++)
        if(dane[i]!=dane[i+1]) odp++;

    cout << "1.1) " << odp << endl;
}

void podpkt_2(string dane)
{

    cout << "1.2) ";
    int teamA = 0, teamB =0;
    for(int i=0; i<9999; i++)
    {
        char sign = dane[i];
        if(sign == 'A') teamA++;
        else teamB++;
        //cout << teamA << ":" <<teamB << endl;

        if( (teamA - teamB >= 3) || (teamB - teamA >=3))
        {
            if(teamA >= 1000)
            {
                cout << "A " << teamA<<":"<<teamB<<endl;
                return;
            }
            if(teamB >= 1000)
            {
                cout << "B " << teamA<<":"<<teamB <<endl;
                return;
            }
        }
    }
}

void podpkt_3(string dane)
{
    int passa=1, passaA=0, passaB=0, max_passa=0;
    string team_max;

    for(int i=0; i<9999; i++)
    {
        if(dane[i]!=dane[i+1])
        {

            if(passa >= 10)
            {
                char sign = dane[i];
                if(sign == 'A')
                    passaA++;
                else
                    passaB++;

                if(passa > max_passa)
                {
                    max_passa = passa;
                    team_max = dane[i];
                }
            }
            passa=1;
        }
        else
            passa++;
    }

    cout << "1.3) " << passaA+passaB << " " <<team_max<< " " << max_passa <<endl;
}


int main()
{
    ifstream plik;
    plik.open("mecz.txt");

    string dane="";
    plik >> dane;
    podpkt_1(dane);
    podpkt_2(dane);
    podpkt_3(dane);
    return 0;
}
