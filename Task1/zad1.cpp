#include <iostream>

//Jan Jochymczyk
//dopisane funkcje purge oraz duplicate.

using namespace std;

typedef int elementtype, position ;
const int maxlength = 40;
struct List {
    elementtype elements[maxlength];
    int last; //indeks ostatniego elementu listy
};

position END(List l) {
    return l.last + 1;
}

position First(List l) {
    return 0;
}

position Next(position p,List l) {
    return p + 1;
}

position Previous(position p,List l) {
    return p - 1;
}

position Locate(elementtype x, List l) {
    //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    for(int i = 0; i <= l.last; ++i) {
        if(l.elements[i] == x) {
            return i;
        }
    }
    return END(l);
}

elementtype Retrieve(position p, List l) {
    return l.elements[p];
}

bool Insert(int x, position p, List &l) {
    if (p < 0 || p > l.last + 1 || l.last == maxlength - 1) {
        return false; // warunek poprawnosci pozycji.
    }
    for (int i = l.last; i >= p; --i) {
        l.elements[i + 1] = l.elements[i];
    }
    l.elements[p] = x;
    ++l.last; //1 el. wiecej, wiec index ostatniego elementu zwiekszam o 1.

    return true;
}

bool Delete(position p, List &l) {
    if (p < 0 || p > l.last) {
        return false; // warunek blednego podania indeksu.
    }
    for (int i = p; i < l.last; ++i) {
        l.elements[i] = l.elements[i + 1];
    }
    --l.last;
    return true;
}

void print(List l)
{
    position i=First(l);
    while (i!=END(l))
    {
        printf ("  %d,", Retrieve(i,l));
        i=Next(i,l);
    }
    printf("\n");

}

void Duplicate(List &l) {
    position i = First(l);

    while (i != END(l)) {
        elementtype elementToDuplicate = Retrieve(i, l);
        Insert(elementToDuplicate, Next(i, l), l); // wstawia duplikat za podanym elementem.
        i = Next(Next(i, l), l); // Przesuń pozycje na nastepna pozycje.
    }
}

void Purge(List &l) { //usuwamy duplikaty.
    position i = First(l);
    while (i != END(l)) {
        position j = Next(i, l);
        while (j != END(l)) {
            if (Retrieve(i, l) == Retrieve(j, l)) {
                Delete(j, l); // usuwa powtorzenie
            } else {
                j = Next(j, l); //przechodzi do nastepnego elementu
            }
        }
        i = Next(i, l); // przechodzi do nastepnego elementu
    }
}

void initiateTask1() {
    List l;
    l.last = -1;
    Insert(100, First(l), l);
    print(l);

    for (int i = 0; i < 3; i++) {
        Insert(i, First(l), l);
    }
    print(l);

    Insert(20, Previous(END(l), l), l);
    Insert(15, Next(Locate(100, l), l), l);
    print(l);

    Duplicate(l); //testy podane w zadaniu.
    print(l); //sprawdzam czy dziala - dziala.

    Purge(l); //testy podane w zadania
    print(l); //sprawdzczam czy dziala - dziala.
}

int main(int args, char* argv[]) {
    initiateTask1();
    return 0;
}