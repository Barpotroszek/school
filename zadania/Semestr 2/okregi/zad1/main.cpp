#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("okregi.txt");
    float x,y,r;
    int cwiartka1=0, cwiartka2=0, cwiartka3=0, cwiartka4=0, niecalkowicie=0;
    for(int i=0; i<2000; i++)
    {
        plik >>x>>y>>r;
        if(fabs(x) > r && fabs(y)>r)
        {
            if(x>0 && y>0) cwiartka1++;
            if(x<0 && y>0) cwiartka2++;
            if(x<0 && y<0) cwiartka3++;
            if(x>0 && y<0) cwiartka4++;
        }
        niecalkowicie++;
    }


    cout << cwiartka1 << " " << cwiartka2  << " " << cwiartka3 << " "  << cwiartka4 << " "  <<
         2000 - cwiartka1 - cwiartka2 - cwiartka3 - cwiartka4;
    return 0;
}
