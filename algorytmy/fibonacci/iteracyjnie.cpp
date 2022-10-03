#include <iostream>

using namespace std;

void fibonacci(int n)
{
    /**
     * w -> f(n), wynik
     * p -> f(n-1), poprzednia
     */
    int w=0, p=0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) w = 0;
        else if (i == 1) w = 1;
        else{
            w = p + w;
            p = w-p; // wcześniejsza od "poprzedniej"
        }
        cout << "\nf(" << i << ") = " << w;
    }
}

int main()
{
    int amount;
    cout << "Podaj ile mam pokazac liczb: ";
    cin >> amount;
    fibonacci(amount);
}