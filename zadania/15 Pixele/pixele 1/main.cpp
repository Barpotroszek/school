#include <iostream>
#include <fstream>
#include<math.h>

using namespace std;
ifstream plik;

int pkt_2(int tab[200][320])
{
    int odp=0;
    for(int y=0; y<200; y++)
    {
        for(int x=0; x<160; x++)
        {
            if(tab[y][x] != tab[y][319-x])
            {
                //cout << "\nLinia nr: " << y;
                odp++;
                break;
            }
        }
    }
    return odp;
}


int pkt_3(int tab[200][320])
{

    int odp=0;
    for(int y=0; y<200; y++)
    {
        for(int x=0; x<320; x++)
        {
            if(
                    (x!=0 && abs(tab[y][x]-tab[y][x-1]) > 128) ||
                    (x!=199 && abs(tab[y][x]-tab[y][x+1]) > 128) ||
                    (y!=0 && abs(tab[y][x]-tab[y-1][x]) > 128) ||
                    (y!=199 && abs(tab[y][x]-tab[y+1][x]) > 128)
               )
                //cout << "line: " << y<<"; " << tab[y][x] << tab[y][x+1] << '\n';
                odp++;
        }
    }
    return odp;
};


int pkt_4(int tab[200][320])
{
    int odp=0;

    for(int x=0; x<320; x++)
    {
        int temp=1;
        for(int y=0; y<199; y++)
        {
            if(tab[y][x] == tab[y+1][x]){
                temp++;
                // if(w)
                     // cout << temp << ". " << tab[y][x] << '\n';
            }if(tab[y][x] != tab[y+1][x]){
                if(temp > odp)
                    odp = temp;
                temp = 1;
            }
        }
    }
    return odp;
}

int main()
{
    plik.open("dane.txt");
    if(!plik.good())
    {
        cout << "Cos poszlo nie tak...";
        return 0;
    }

    int tab[200][320];
    int minim=255, maxim=0, curr, a=0, b=0;
    while(a<200)
    {
        while(b<320)
        {
            plik >> curr;
            tab[a][b] = curr;
            //cout << curr << endl;
            if(curr < minim)
                minim = curr;
            if(curr > maxim)
                maxim = curr;
            b++;
        };
        b=0;
        a++;
    };


    cout << "\n\n\nzad 1\n najciemniejsza: " << minim << "\n najjasniejsza: " << maxim;
    cout << "\n\nzad 2\n -> " << pkt_2(tab);
    cout << "\n\nzad 3\n -> " << pkt_3(tab);
    cout << "\n\nzad 4\n -> " << pkt_4(tab);
    plik.close();
    return 0;
}
