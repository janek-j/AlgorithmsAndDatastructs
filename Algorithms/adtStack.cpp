#include <iostream>

using namespace std;

const int maxlength = 20;
typedef int elementtype;
typedef int position;

class Stack {
protected:
    int S[maxlength];
    position Top; //szczyt stosu.
public:
    Stack();
    void push(elementtype x);
    void pop();
    bool empty();
    elementtype topElem();
    void makeNull();
};

Stack::Stack() { Top = -1; }
void Stack::makeNull() { Top = -1; }

void Stack::push(elementtype x) {
    if( Top < maxlength -1 ) {
        Top++;
        S[Top] = x;
    }
}

void Stack::pop() {
    if(Top >= 0) {
        Top--;
    }
}

bool Stack::empty() {
    return ( Top== -1); //Empty
}

//Odwrotna notacja polska - algorytm,
//implementacja stosu tablicowego

elementtype Stack::topElem() {
    if(!empty()) {
        return S[Top];
    } else {
        throw runtime_error("Stack jest pusty.");
    }

}

void initiateTask3(){
    Stack s;

    cout << "Empty: " << s.empty() << endl;
    s.push(5);
    cout << "Top element: " << s.topElem() << endl;
    cout << "Empty: " << s.empty() << endl;
    s.pop();
    cout << "Empty after pop: " << s.empty() << endl;
    s.push(2);
    s.push(3);
    cout << "Top element: " << s.topElem() << endl;
    s.makeNull();
    cout << "Empty after makeNull: " << s.empty() << endl;
    //przechodzi testy. standard: c++2b
}


int main(int args, char* argv[]) {
    initiateTask3();
    return 0;
}

