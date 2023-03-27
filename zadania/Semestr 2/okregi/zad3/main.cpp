#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("okregi.txt");
    float x,y,r;
    float okregi[2000][3];
    float temp[3] = {};
    int pary=0;
    for(int j=0; j<2000; j++)
    {
        plik >>x>>y>>r;
        if(j!=0)
            for(int i=0; i<j; i++)
            {
                if(okregi[i][2] == r)
                {
                    if(okregi[i][0] == y && okregi[i][1] == -x) pary++;
                    if(okregi[i][0] == -y && okregi[i][1]== x) pary++;

                }
            }
        okregi[j][0] = x;
        okregi[j][1] = y;
        okregi[j][2] = r;
    }
    cout << "odp: " << pary;
    return 0;
}
