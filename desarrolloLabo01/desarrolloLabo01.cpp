#include <iostream>
#include <vector>

class Elemento {
public:
    int atributo1;
    int atributo2;
};

// Función para imprimir la lista de elementos
void imprimirLista(const std::vector<Elemento>& lista) {
    for (const Elemento& elem : lista) {
        std::cout << "Atributo1: " << elem.atributo1 << ", Atributo2: " << elem.atributo2 << std::endl;
    }
    std::cout << std::endl;
}

// Implementación de Selection Sort
void selectionSort(std::vector<Elemento>& lista, bool ascending, bool sortByAtributo1) {
    int n = lista.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && sortByAtributo1 ? lista[j].atributo1 : lista[j].atributo2) <
                (ascending && sortByAtributo1 ? lista[minIndex].atributo1 : lista[minIndex].atributo2)) {
                minIndex = j;
            }
        }
        
        std::swap(lista[i], lista[minIndex]);
    }
}

// Implementación de Bubble Sort
void bubbleSort(std::vector<Elemento>& lista, bool ascending, bool sortByAtributo1) {
    int n = lista.size();
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && sortByAtributo1 ? lista[j].atributo1 : lista[j].atributo2) >
                (ascending && sortByAtributo1 ? lista[j + 1].atributo1 : lista[j + 1].atributo2)) {
                std::swap(lista[j], lista[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<Elemento> elementos = {
        {25, 80},
        {18, 95},
        {32, 60},
        {22, 75},
        {30, 65},
        {28, 85},
        {20, 70}
    };

    std::cout << "Lista original:" << std::endl;
    imprimirLista(elementos);

    // Ordenamiento con Selection Sort en base a atributo1 de forma ascendente
    selectionSort(elementos, true, true);
    std::cout << "Lista ordenada con Selection Sort por atributo1 (ascendente):" << std::endl;
    imprimirLista(elementos);

    // Ordenamiento con Bubble Sort en base a atributo2 de forma descendente
    bubbleSort(elementos, false, false);
    std::cout << "Lista ordenada con Bubble Sort por atributo2 (descendente):" << std::endl;
    imprimirLista(elementos);

    return 0;
}
