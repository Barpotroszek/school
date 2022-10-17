#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream dane;
    dane.open("dziennik.txt");
    if(!dane.good())
    {
        cout << "Problem z otwarciem pliku...";
        return 1;
    }
    int s_pocz, s_dlugosc=0, s_roznica;
    int poprzednie=0, obecne, seria=0;

    for(int i=0; i<309; i++)
    {
        dane >> obecne;

        if(obecne > poprzednie)
        {
            seria++;
        }

        else if(obecne <= poprzednie)
        {
            cout << i << ". seria: " << seria << "\n";
            if(seria > s_dlugosc)
            {
                s_roznica = poprzednie - s_pocz;
                    s_dlugosc = seria;
            };
            s_pocz=obecne;
            seria =1;
        }
        poprzednie = obecne;


    }
    cout << "dlugosc: " << s_dlugosc << endl;
    // cout << "s_pocz: " << s_pocz << endl;
    cout << "roznica: " << s_roznica << endl;
    return 0;
}
