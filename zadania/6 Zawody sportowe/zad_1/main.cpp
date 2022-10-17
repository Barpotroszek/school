#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream dane;
    dane.open("dziennik.txt");
    if(!dane.good()){
        cout << "Problem z otwarciem pliku...";
        return 1;
    }
    int poprzednie=0, obecne, strike=0, licznik=0;
    for(int i=0; i<310; i++){
        dane >> obecne;
        cout << i << ". " << obecne;
        if(obecne > poprzednie){
            strike++;
            cout << " -> wieksze!";
        }

        else if(obecne <= poprzednie){
            if(strike >3) {licznik++;
            cout << "\n--------------\nzwieksz licznik\n--------------\n";
            };
            strike =1;
        }
        cout << "\n  strike: " << strike << endl << endl;
        poprzednie = obecne;
    }
    cout << "Odp a:"<<licznik;
    return 0;
}
