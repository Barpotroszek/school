#include <iostream>

using namespace std;

int euklides(int a, int b)
{
    int r = a % b;
    a = b;
    b = r;
    if (b == 0)
        return a;
    return euklides(a, b);
}

int main()
{
    int a, b;
    cout << "Podaj dwie liczby: ";
    cin >> a >> b;
    cout << "NWD(" << a << ", " << b << ") wynosi: " << euklides(a, b);
}