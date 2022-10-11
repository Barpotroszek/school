#include <iostream>
#include <fstream>

using namespace std;
ifstream dane;

int NWD(int a, int b)
{
    do
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    while(a!=b);
    return a;
}

int suma_cyfr(int liczba){
    int suma=0;
    //  cout << "Suma " << liczba
    do{
        suma += liczba%10;
        liczba = liczba/10;
    }while(liczba!=0);

   //cout << ": " << suma << endl;
   return suma;
}


int main()
{
    int liczba1, liczba2, pkt_a=0, pkt_b=0, pkt_c=0;
    dane.open("PARY_LICZB.TXT");
    if(!dane.good())
    {
        cout << "Problem z otwarciem pliku";
        return 1;
    }
    for(int i=0; i<1000; i++)
    {
        dane >> liczba1 >> liczba2;

        //podpunkt a
        if(liczba1%liczba2 == 0 || liczba2%liczba1==0)
            pkt_a++;

            //podpunkt b
        if(NWD(liczba1, liczba2)==1)
            pkt_b++;

        if(suma_cyfr(liczba1) == suma_cyfr(liczba2)){
            //cout << "l1:" << liczba1 << " l2:" <<liczba2 << endl;
            pkt_c++;

    };};
    cout << "odpowiedz do pkt a: " << pkt_a;
    cout << "\nodpowiedz do pkt b: " << pkt_b;
    cout << "\nodpowiedz do pkt c: " << pkt_c;


    dane.close();
    return 0;
}
