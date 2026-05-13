#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

void inOrderAux(Nodo* nodo, vector<int>& resultado) {
    // Caso base: si el nodo es null, no hacemos nada
    if (nodo == nullptr) return;
    
    // PASO 1: Recorrer todo el subárbol izquierdo
    inOrderAux(nodo->izquierdo, resultado);
    
    // PASO 2: Visitar el nodo actual (agregar su valor)
    resultado.push_back(nodo->valor);
    
    // PASO 3: Recorrer todo el subárbol derecho
    inOrderAux(nodo->derecho, resultado);
}

vector<int> recorridoInOrder(Nodo* raiz) {
    vector<int> resultado;
    inOrderAux(raiz, resultado);
    return resultado;
}

int main() {
    Nodo* raiz = new Nodo(4);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(6);
    raiz->izquierdo->izquierdo = new Nodo(1);
    raiz->izquierdo->derecho = new Nodo(3);
    raiz->derecho->izquierdo = new Nodo(5);
    raiz->derecho->derecho = new Nodo(7);

    vector<int> res = recorridoInOrder(raiz);
    
    cout << "--- Prueba Ejercicio 4 ---" << endl;
    cout << "Resultado esperado: 1 2 3 4 5 6 7 " << endl;
    cout << "Tu resultado:       ";
    for(int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}