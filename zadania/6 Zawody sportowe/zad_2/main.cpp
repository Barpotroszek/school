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
    int minim, nr_min, maxim=0, nr_max, t;
    dane >> minim;
    for(int i=1; i<310; i++){
        dane >> t;
        if(t<minim){
                nr_min = i;
            minim = t;
    }
        else if(t > maxim){
            nr_max = i;
            maxim = t;
        }
    }
    cout << "minimum: " << minim << "cm, wynik nr: " << nr_min+1 << endl;
    cout << "maximum: " << maxim << "cm, wynik nr: " << nr_max+1 << endl;
    return 0;
}
