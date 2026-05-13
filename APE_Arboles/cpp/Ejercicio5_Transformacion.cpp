#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* invertir(Nodo* raiz) {
    // Caso base: árbol vacío o llegamos a una hoja
    if (raiz == nullptr) return nullptr;
    
    // PASO 1: Invertir recursivamente los subárboles
    Nodo* tempIzq = invertir(raiz->izquierdo);
    Nodo* tempDer = invertir(raiz->derecho);
    
    // PASO 2: Intercambiar los hijos (crear el espejo)
    raiz->izquierdo = tempDer;
    raiz->derecho = tempIzq;
    
    return raiz;
}

int main() {
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);

    cout << "--- Prueba Ejercicio 5 ---" << endl;
    cout << "Antes de invertir:" << endl;
    cout << "Hijo Izq: " << raiz->izquierdo->valor << " | Hijo Der: " << raiz->derecho->valor << endl;
    
    invertir(raiz);
    
    cout << "\nDespues de invertir (Esperado: Izq 3 | Der 2):" << endl;
    
    if(raiz->izquierdo) cout << "Hijo Izq: " << raiz->izquierdo->valor;
    else cout << "Hijo Izq: null";
    
    cout << " | ";
    
    if(raiz->derecho) cout << "Hijo Der: " << raiz->derecho->valor << endl;
    else cout << "Hijo Der: null" << endl;

    return 0;
}