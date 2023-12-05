#include <iostream>

// implementacja listy wskaznikowej.

typedef int  elementtype;

struct celltype {
    elementtype element;
    celltype * next;
};

typedef celltype  *position;

class Lista
{
protected :
    position l; //wskaźnik do głowy listy
public:
    Lista();    //konstruktor
    ~Lista();  //destruktor

    void Insert(elementtype x, position p);
    void Delete(position p);
    elementtype Retrieve(position p);
    position Locate(elementtype x);
    position First();
    position Next(position p);
    position Previous(position p);
    position END();
};

Lista::Lista() {
    l = new celltype();
    l -> next = nullptr;
}

Lista::~Lista() {
    position current = l;
    position nextNode;

    // Traverse the list and delete each node
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    // Make sure to set the head pointer to null after deleting all nodes
    l = nullptr;
}

position Lista::First() {
    return l;
}

position Lista::END() {
    position tmp;
    tmp = l;
    while(tmp -> next != nullptr) {
        tmp = tmp -> next;
    }
    return tmp;
}

position Lista::Next(position p) {
    if(p != nullptr) {
        return p -> next;
    }
    return nullptr;
}

position Lista::Previous(position p) {
    if (p != nullptr && p != l) {
        position current = l;
        while (current != nullptr && current -> next != nullptr && current -> next != p) {
            current = current -> next;
        }
        return current;
    } else {
        // Handle error or return a special value to indicate an error
        return nullptr;
    }
}

position Lista::Locate(elementtype x) {
    position current = l;
    while(current != nullptr && current -> next != nullptr) {
        if(current -> next -> element == x) {
            return current;
        }
        current = current -> next;
    }
}

void Lista::Insert(elementtype x, position p) {
    position newNode = new celltype; // Create a new node
    newNode->element = x;
    newNode->next = p->next;
    p->next = newNode;
}

void Lista::Delete(position p) {
    if (p != nullptr && p->next != nullptr) {
        position temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
}

elementtype Lista::Retrieve(position p) {
    if (p != nullptr && p->next != nullptr) {
        return p->next->element;
    } else {
        return -1; //gdy nie ma, to zwroci -1
    }
}

void initaiteTask2() {
    Lista lista;

    // Wstaw 5 na początek
    lista.Insert(5, lista.First());

    // Wypisz pierwszy element
    std::cout << "Pierwszy element: " << lista.Retrieve(lista.First()) << std::endl;

    // Wstaw 2 na początek
    lista.Insert(2, lista.First());

    // Wypisz pierwszy element
    std::cout << "Pierwszy element: " << lista.Retrieve(lista.First()) << std::endl;

    // Wypisz drugi element
    std::cout << "Drugi element: " << lista.Retrieve(lista.Next(lista.First())) << std::endl;

    // Wstaw 1 za pierwszym elementem
    lista.Insert(1, lista.Next(lista.First()));

    // Wypisz listę
    position current = lista.First();
    while (current != nullptr && current->next != nullptr) {
        std::cout << current->next->element << " ";
        current = lista.Next(current);
    }
    std::cout << std::endl;

    // Wstaw 100 na koniec listy
    lista.Insert(100, lista.END());

    // Wypisz listę
    current = lista.First();
    while (current != nullptr && current->next != nullptr) {
        std::cout << current->next->element << " ";
        current = lista.Next(current);
    }
    std::cout << std::endl;

    // Usuń element przed wartością 100
    position positionBefore100 = lista.Locate(100);
    if (positionBefore100 != nullptr) {
        lista.Delete(positionBefore100);
    }

    // Wypisz listę
    current = lista.First();
    while (current != nullptr && current->next != nullptr) {
        std::cout << current->next->element << " ";
        current = lista.Next(current);
    }
    std::cout << std::endl;

    // Koniec listy
    position endPosition = lista.END();
    std::cout << "Koniec listy: " << lista.Retrieve(endPosition) << std::endl;
}

int main(int args, char* argv[]) {
   initaiteTask2();
}

