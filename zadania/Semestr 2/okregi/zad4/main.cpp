#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool czy_styczne(float x1, float y1, float r1, float x2, float y2, float r2){
    float dystans = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    if(fabs(r1-r2)<= dystans && dystans <= r1+r2 )
        return true;
    return false;
}

int main()
{
    ifstream plik;
    plik.open("okregi.txt");
    float x[1000],y[1000],r[1000];
    float temp[3] = {};
    int licznik=0, lancuch=1, max_lancuch=0;
    for(int j=0; j<1000; j++)
    {
        plik >>x[j]>>y[j]>>r[j];
            if(czy_styczne(x[j-1], y[j-1], r[j-1], x[j], y[j], r[j]))
                lancuch++;
            else{
                if(lancuch > 1)
                    cout << lancuch << " ";
                if(max_lancuch < lancuch)
                    max_lancuch = lancuch;
                lancuch=1;
                licznik++;
            }


    }
    if(lancuch > 1)
        cout << lancuch << " ";
    cout << "\nmax_lancuch: " << max_lancuch;

    return 0;
}
