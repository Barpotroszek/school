#include <iostream>

using namespace std;

bool przynaleznosc(float xa, float ya, float xb, float yb, float x, float y)
{
    /** Funkcja sprawdza czy punkt nalezy do prostej */
    float d = xb*y+xa*yb+x*ya-xa*y-xb*ya-x*yb;
    if(d==0 && x>=min(xa,xb) && x<=max(xa,xb)
            && y>=min(ya,yb) && y<=max(ya,yb))
        return true;
    return false;
}

int main()
{
    float xA, xB, yA, yB, x,y;
    cout << "!!!! ODDZIELAJ WSZYSTKO SPACJA !!!!\n";
    cout << "Podaj wspolrzedne A:";
    cin >> xA >> yA;
    cout << "Podaj wspolrzedne B:";
    cin >> xB >> yB;
    cout << "Podaj wspolrzedne C:";
    cin >> x >> y;
    cout << "\n\nPunkt C ";
    if(!przynaleznosc(xA, yA, xB, yB, x,y)) cout << "NIE ";
    cout << "nalezy do odcinka AB;";
    return 0;
}
