#include <iostream>

using namespace std;

int main()
{
    int i=13, j=16;
    int *wsk,*wsk1;
    wsk=&i;
    cout<<"wskaznik wskazuje na i= "<<*wsk<<endl;
    cout<<"wartosc wskaznika= "<<wsk<<endl;
    wsk=&j;
    cout<<"wskaznik wskazuje na j= "<<*wsk<<endl;
    cout<<"wartosc wskaznika= "<<wsk<<endl;
    wsk1=&j;
    i=*wsk+*wsk1;
    cout<<"i= "<<i;

    return 0;
}
