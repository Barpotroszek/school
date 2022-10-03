#include <iostream>

using namespace std;

bool is_anagram(string word1, string word2) {
    int a = word1.size(), b=word2.size();
    if(a!=b) return false;
    int licz[127];
    for(int i=0; i<a; i++)licz[word1[i]]++; //zliczam litery pierwszego wyrazu;
    for(int i=0; i<a; i++)licz[word2[i]]--;
    for(int i=0; i<a; i++) // jesli bêdzie jakaœ wartoœc rozna od zera, to znaczy, ¿e
                           // w drugim wyrazie jest wiecej/mniej danej litery;
    if(licz[i]!= 0){
        //cout << (char)i << ": " << licz[i];
        //! DO NAPRAWY
        return false;
    }
    return true;
};

int main()
{
    string word1, word2;
    cout << "podaj 2 wyrazy: "; cin >> word1 >> word2;
    cout << "wyraz " << word1 << " i " << word2;
    if(!is_anagram(word1, word2)) cout << " NIE";
    cout << " jest anagramem";
    return 0;
    return 0;
}
