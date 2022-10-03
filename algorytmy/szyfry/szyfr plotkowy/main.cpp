#include <iostream>

using namespace std;

int main()
{
    string haslo;
    int wys, poz, a,b;
    cout << "podaj haslo: ";
    cin >> haslo;
    cout << "Podaj wysokosc plotka: ";
    cin >> wys;
    cout << haslo << endl;
    for(int w=0; w< wys; w++){
        cout << haslo[w];
        a=2*(wys-1)-2*w; // skok
        b=2*w; //luka miêdzy s¹siednimi
        poz = w;
        while((poz+a)<haslo.size() && (poz+b)<haslo.size()){
            if(a>0 && poz+a<haslo.size()) cout << haslo[poz+a];
            if(a>0) poz+=a;
            if(b>0 && poz+b<haslo.size()) cout << haslo[poz+b];
            if(b>0) poz+=b;
        }
    }
    return 0;
}
