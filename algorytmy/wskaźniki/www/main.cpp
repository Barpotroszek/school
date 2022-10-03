#include <iostream>

using namespace std;

void zmien(int *wsk){
    *wsk=*wsk+10;
}

int main()
{
    int a =3;
    int *wsk;
    wsk=&a;
    cout << "a=" << a<<endl;
    zmien(wsk);
    cout << "a=" << a<<endl;
    return 0;
}
