# Algorytm Euklidesa(wyznaczanie NWD)
>  __Opis działania:__   
Najprostsza wersja algorytmu rozpoczyna się od wybrania dwóch liczb naturalnych, dla których należy wyznaczyć *największy wspólny dzielnik*. Następnie z tych dwóch liczb tworzymy nową parę: pierwszą z liczb jest liczba mniejsza, natomiast drugą jest różnica liczby większej i mniejszej. Proces ten jest powtarzany aż obie liczby będą sobie równe – wartość tych liczb to największy wspólny dzielnik wszystkich par liczb wcześniej wyznaczonych. Wadą tej wersji algorytmu jest duża liczba operacji odejmowania, które należy wykonać w przypadku, gdy różnica pomiędzy liczbami z pary jest znacząca.   
Operacja odejmowania mniejszej liczby od większej może zostać zastąpiona przez wyznaczanie reszty z dzielenia. W tej wersji nowa para liczb składa się z mniejszej liczby oraz reszty z dzielenia większej przez mniejszą. Algorytm kończy się w momencie, w którym jedna z liczb jest równa zero – druga jest wtedy największym wspólnym dzielnikiem.

> __Algorytm__:  Algorytm wykorzystujący funkcję modulo to druga równoważna implementacja algorytmu Euklidesa. Poniżej przedstawiono wersję obliczania NWD liczb a i b wykorzystującą operację reszty z dzielenia (modulo):
>- oblicz c jako resztę z dzielenia a przez b
>- zastąp a liczbą b, następnie b liczbą c
>- jeżeli wartość b wynosi 0, to a jest szukaną wartością NWD, w przeciwnym wypadku przejdź do kroku 1