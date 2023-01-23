#include <iostream>

using namespace std;

const int N = 20;
int licznik=0;

void strzalka(int x, int y){
    licznik++;
    cout << "-> X: " << x <<", Y: " << y << ",\n";
}

void rysuj(int x)
{
    if(2*x<=N){
        strzalka(x, 2*x);
        rysuj(2*x);
    }
    if(2*x+1 <= N){
        strzalka(x, x*2+1);
        rysuj(2*x+1);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    rysuj(1);
    cout << "\n\nLICZNIK: " << licznik;
    return 0;
}
