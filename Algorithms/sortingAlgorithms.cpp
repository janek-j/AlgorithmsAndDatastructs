#include <iostream>


template<typename T>
void printTab(T tab[], const int size) {
    for(int i = 0; i < size; i++) {
        std::cout << tab[i] << std::endl;
    }
}

template<typename T>
void bubbleSort(T tab[], const int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(tab[j] > tab[j+1]) {
                T temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

template<typename T>
void insertionSort(T tab[], const int size) {
    for(int i = 1; i < size; i++) {
        T key = tab[i];
        int j = i - 1;
        while(j >= 0 && tab[j] > key) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = key;

    }
}


int main() {
    const int n = 20;
    int tab[n];
    for(int i = 0; i < n; i++) {
        tab[i] = rand() % 30;
        std::cout << tab[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    insertionSort(tab, n);
    printTab(tab, n);
    return 0;
}