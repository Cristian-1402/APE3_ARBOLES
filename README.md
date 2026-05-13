# Práctica de Estructuras de Datos: Árboles

El objetivo de este repositorio es proporcionarles un entorno práctico donde puedan aplicar los conceptos teóricos vistos en clase relacionados con árboles N-arios, árboles binarios, recorridos y transformaciones.

## Objetivos de Aprendizaje

Al completar estos ejercicios, serán capaces de:
1. Comprender y manipular la estructura básica de nodos con múltiples hijos y nodos binarios.
2. Implementar la lógica de inserción en un Árbol Binario de Búsqueda (BST).
3. Utilizar la recursividad para calcular métricas estructurales, como la profundidad máxima.
4. Extraer datos mediante recorridos estándar (In-Order).
5. Modificar la estructura subyacente de los punteros para transformar un árbol.

## Estructura del Repositorio

El repositorio contiene 5 ejercicios, cada uno implementado en C++ y Java:

1. Ejercicio 1: Árboles Básicos (Conteo de nodos en árboles N-arios).
2. Ejercicio 2: Árbol Binario (Inserción en BST).
3. Ejercicio 3: Árbol Binario (Cálculo de profundidad máxima).
4. Ejercicio 4: Recorridos (Implementación de In-Order).
5. Ejercicio 5: Transformación (Inversión o árbol espejo).

## Instrucciones para el Desarrollo

1. Dentro de cada archivo encontrarán la estructura básica de las clases (o structs) y la definición de un método específico que deben completar. 
2. Localicen el comentario `TODO: Implementa tu lógica aquí`. Esa es la única sección del código que necesitan modificar.
3. No es necesario modificar el método `main`. Este método ya contiene la construcción de un árbol de prueba y las impresiones necesarias para validar que su algoritmo funciona correctamente.
4. Su objetivo es lograr que, al ejecutar el código, los resultados calculados coincidan con los resultados esperados impresos en la consola.

## Implementaciones Completas

### Ejercicio 1: Conteo de Nodos en Árboles N-arios

Un árbol N-ario es aquél donde cada nodo puede tener múltiples hijos (no limitado a 2 como en árboles binarios).

**Java - Ejercicio1_Basico.java:**
```java
class NodoN {
    public int valor;
    public List<NodoN> hijos;
    
    public NodoN(int valor) {
        this.valor = valor;
        this.hijos = new ArrayList<>();
    }
    
    public NodoN(int valor, List<NodoN> hijos) {
        this.valor = valor;
        this.hijos = hijos;
    }
}

public class Ejercicio1_Basico {
    public static int contarNodos(NodoN raiz) {
        // Caso base: si el nodo es null, no hay nada que contar
        if (raiz == null) return 0;
        
        // Empezamos contando el nodo actual (1)
        int total = 1;
        
        // Recorremos cada hijo y sumamos recursivamente sus nodos
        for (NodoN hijo : raiz.hijos) {
            total += contarNodos(hijo);
        }
        return total;
    }

    public static void main(String[] args) {
        // Construimos el árbol:
        //        1
        //      / | \
        //     2  3  4
        //    / \
        //   5   6
        NodoN n5 = new NodoN(5);
        NodoN n6 = new NodoN(6);
        NodoN n2 = new NodoN(2, Arrays.asList(n5, n6));
        NodoN n3 = new NodoN(3);
        NodoN n4 = new NodoN(4);
        NodoN raiz = new NodoN(1, Arrays.asList(n2, n3, n4));
        
        System.out.println("--- Prueba Ejercicio 1 ---");
        System.out.println("Nodos esperados: 6");
        System.out.println("Nodos calculados: " + contarNodos(raiz));
    }
}
```
**C++ - Ejercicio1_Basico.cpp:**
```c++
#include <iostream>
#include <vector>
using namespace std;

struct NodoN {
    int valor;
    vector<NodoN*> hijos;
    NodoN(int v) : valor(v) {}
};

int contarNodos(NodoN* raiz) {
    // Caso base: si el nodo es null, no hay nada que contar
    if (raiz == nullptr) return 0;
    
    // Empezamos contando el nodo actual (1)
    int total = 1;
    
    // Recorremos cada hijo y sumamos recursivamente sus nodos
    for (NodoN* hijo : raiz->hijos) {
        total += contarNodos(hijo);
    }
    return total;
}

int main() {
    // Construimos el árbol
    NodoN* n5 = new NodoN(5);
    NodoN* n6 = new NodoN(6);
    NodoN* n2 = new NodoN(2);
    n2->hijos.push_back(n5);
    n2->hijos.push_back(n6);
    NodoN* n3 = new NodoN(3);
    NodoN* n4 = new NodoN(4);
    NodoN* raiz = new NodoN(1);
    raiz->hijos.push_back(n2);
    raiz->hijos.push_back(n3);
    raiz->hijos.push_back(n4);

    cout << "--- Prueba Ejercicio 1 ---" << endl;
    cout << "Nodos esperados: 6" << endl;
    cout << "Nodos calculados: " << contarNodos(raiz) << endl;
    
    return 0;
}
```
### **Ejercicio 2: Inserción en Árbol Binario de Búsqueda (BST)**
Un BST es un árbol binario donde cada nodo tiene como máximo 2 hijos, y cumple: valores menores van a la izquierda, mayores o iguales a la derecha.

**Java - Ejercicio2_Binario.java:**
```java
class Nodo {
    int valor;
    Nodo izquierdo, derecho;
    Nodo(int valor) { this.valor = valor; }
}

public class Ejercicio2_Binario {
    public static Nodo insertar(Nodo raiz, int valor) {
        // Caso base: si llegamos a un lugar vacío, creamos el nodo aquí
        if (raiz == null) {
            return new Nodo(valor);
        }
        
        // Si el valor es menor, va al subárbol izquierdo
        if (valor < raiz.valor) {
            raiz.izquierdo = insertar(raiz.izquierdo, valor);
        } 
        // Si es mayor o igual, va al subárbol derecho
        else {
            raiz.derecho = insertar(raiz.derecho, valor);
        }
        
        return raiz;
    }

    public static void main(String[] args) {
        Nodo raiz = new Nodo(10);
        
        // Insertamos valores
        insertar(raiz, 5);
        insertar(raiz, 15);
        insertar(raiz, 3);
        
        System.out.println("--- Prueba Ejercicio 2 ---");
        System.out.println("Raiz (Esperado 10): " + raiz.valor);
        
        String izq = (raiz.izquierdo != null) ? String.valueOf(raiz.izquierdo.valor) : "null";
        System.out.println("Hijo Izquierdo de Raiz (Esperado 5): " + izq);
        
        String der = (raiz.derecho != null) ? String.valueOf(raiz.derecho.valor) : "null";
        System.out.println("Hijo Derecho de Raiz (Esperado 15): " + der);
        
        String izqIzq = (raiz.izquierdo != null && raiz.izquierdo.izquierdo != null) ? String.valueOf(raiz.izquierdo.izquierdo.valor) : "null";
        System.out.println("Hijo Izquierdo del 5 (Esperado 3): " + izqIzq);
    }
}
```
### **C++ - Ejercicio2_Binario.cpp:**
```c++
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* insertar(Nodo* raiz, int valor) {
    // Caso base: si llegamos a un lugar vacío, creamos el nodo aquí
    if (raiz == nullptr) {
        return new Nodo(valor);
    }
    
    // Si el valor es menor, va al subárbol izquierdo
    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } 
    // Si es mayor o igual, va al subárbol derecho
    else {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    
    return raiz;
}

int main() {
    Nodo* raiz = new Nodo(10);
    
    insertar(raiz, 5);
    insertar(raiz, 15);
    insertar(raiz, 3);
    
    cout << "--- Prueba Ejercicio 2 ---" << endl;
    cout << "Raiz (Esperado 10): " << raiz->valor << endl;
    
    if(raiz->izquierdo) cout << "Hijo Izquierdo (Esperado 5): " << raiz->izquierdo->valor << endl;
    else cout << "Hijo Izquierdo: null" << endl;
    
    if(raiz->derecho) cout << "Hijo Derecho (Esperado 15): " << raiz->derecho->valor << endl;
    else cout << "Hijo Derecho: null" << endl;
    
    if(raiz->izquierdo && raiz->izquierdo->izquierdo) 
        cout << "Hijo Izq del 5 (Esperado 3): " << raiz->izquierdo->izquierdo->valor << endl;
    else cout << "Hijo Izq del 5: null" << endl;

    return 0;
}
```
**Ejercicio 3: Cálculo de Altura/Profundidad Máxima**
La altura de un árbol es la distancia máxima desde la raíz hasta cualquier hoja.

### **Java - Ejercicio3_Binario2.java:**
```java
public class Ejercicio3_Binario2 {
    public static int calcularAltura(Nodo raiz) {
        // Caso base: árbol vacío tiene altura 0
        if (raiz == null) return 0;
        
        // Calculamos altura de ambos subárboles recursivamente
        int alturaIzq = calcularAltura(raiz.izquierdo);
        int alturaDer = calcularAltura(raiz.derecho);
        
        // La altura actual es 1 + la mayor de las dos alturas de los hijos
        return 1 + Math.max(alturaIzq, alturaDer);
    }

    public static void main(String[] args) {
        //        1
        //         \
        //          2
        //         /
        //        3
        Nodo raiz = new Nodo(1);
        raiz.derecho = new Nodo(2);
        raiz.derecho.izquierdo = new Nodo(3);
        
        System.out.println("--- Prueba Ejercicio 3 ---");
        System.out.println("Altura esperada: 3");
        System.out.println("Altura calculada: " + calcularAltura(raiz));
        System.out.println("Altura de árbol nulo (esperado 0): " + calcularAltura(null));
    }
}
```
**C++ - Ejercicio3_Binario.cpp:**
```c++
#include <iostream>
#include <algorithm>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

int calcularAltura(Nodo* raiz) {
    // Caso base: árbol vacío tiene altura 0
    if (raiz == nullptr) return 0;
    
    // Calculamos altura de ambos subárboles recursivamente
    int alturaIzq = calcularAltura(raiz->izquierdo);
    int alturaDer = calcularAltura(raiz->derecho);
    
    // La altura actual es 1 + la mayor de las dos alturas de los hijos
    return 1 + max(alturaIzq, alturaDer);
}

int main() {
    Nodo* raiz = new Nodo(1);
    raiz->derecho = new Nodo(2);
    raiz->derecho->izquierdo = new Nodo(3);
    
    cout << "--- Prueba Ejercicio 3 ---" << endl;
    cout << "Altura esperada: 3" << endl;
    cout << "Altura calculada: " << calcularAltura(raiz) << endl;
    cout << "Altura de arbol nulo (esperado 0): " << calcularAltura(nullptr) << endl;

    return 0;
}
```
**Ejercicio 4: Recorrido In-Order**
El recorrido In-Order visita los nodos en el orden: izquierda -> raíz -> derecha. En un BST, esto produce los valores en orden ascendente.

### **Java - RecorridoInOrder.java:**
```java
import java.util.ArrayList;
import java.util.List;

public class RecorridoInOrder {
    public static void inOrderAux(Nodo nodo, List<Integer> resultado) {
        // Caso base: si el nodo es null, no hacemos nada
        if (nodo == null) return;
        
        // PASO 1: Recorrer todo el subárbol izquierdo
        inOrderAux(nodo.izquierdo, resultado);
        
        // PASO 2: Visitar el nodo actual (agregar su valor)
        resultado.add(nodo.valor);
        
        // PASO 3: Recorrer todo el subárbol derecho
        inOrderAux(nodo.derecho, resultado);
    }

    public static List<Integer> recorridoInOrder(Nodo raiz) {
        List<Integer> resultado = new ArrayList<>();
        inOrderAux(raiz, resultado);
        return resultado;
    }

    public static void main(String[] args) {
        //        4
        //      /   \
        //     2     6
        //    / \   / \
        //   1   3 5   7
        Nodo raiz = new Nodo(4);
        raiz.izquierdo = new Nodo(2);
        raiz.derecho = new Nodo(6);
        raiz.izquierdo.izquierdo = new Nodo(1);
        raiz.izquierdo.derecho = new Nodo(3);
        raiz.derecho.izquierdo = new Nodo(5);
        raiz.derecho.derecho = new Nodo(7);

        System.out.println("--- Prueba Ejercicio 4 ---");
        System.out.println("Resultado esperado: [1, 2, 3, 4, 5, 6, 7]");
        System.out.println("Tu resultado:       " + recorridoInOrder(raiz));
    }
}
```
### **C++ - Ejercicio4_Recorridos.cpp:**
```c++
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
```
**Ejercicio 5: Transformación - Árbol Espejo (Invertido)**
Invierte la estructura del árbol intercambiando los punteros izquierdo y derecho de cada nodo.

### **Java - Ejercicio5_Transformacion.java:**
```java
public class Ejercicio5_Transformacion {
    public static Nodo invertir(Nodo raiz) {
        // Caso base: árbol vacío o llegamos a una hoja
        if (raiz == null) return null;
        
        // PASO 1: Invertir recursivamente los subárboles
        Nodo tempIzq = invertir(raiz.izquierdo);
        Nodo tempDer = invertir(raiz.derecho);
        
        // PASO 2: Intercambiar los hijos (crear el espejo)
        raiz.izquierdo = tempDer;
        raiz.derecho = tempIzq;
        
        return raiz;
    }

    public static void main(String[] args) {
        //        1                 1
        //      /   \    -->      /   \
        //     2     3           3     2
        Nodo raiz = new Nodo(1);
        raiz.izquierdo = new Nodo(2);
        raiz.derecho = new Nodo(3);

        System.out.println("--- Prueba Ejercicio 5 ---");
        System.out.println("Antes de invertir:");
        System.out.println("Hijo Izq: " + raiz.izquierdo.valor + " | Hijo Der: " + raiz.derecho.valor);
        
        invertir(raiz);
        
        System.out.println("\nDespues de invertir (Esperado: Izq 3 | Der 2):");
        String izq = (raiz.izquierdo != null) ? String.valueOf(raiz.izquierdo.valor) : "null";
        String der = (raiz.derecho != null) ? String.valueOf(raiz.derecho.valor) : "null";
        
        System.out.println("Hijo Izq: " + izq + " | Hijo Der: " + der);
    }
}
```
### **C++ - Ejercicio5_Transformacion.cpp:**
```c++
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
```
**Conceptos Clave**
Recursividad: Técnica fundamental en la mayoría de operaciones con árboles.

Caso Base: Condición de salida de la recursión (generalmente cuando el nodo es nulo).

Caso Recursivo: Cómo se reduce el problema hacia el caso base.

Recorridos: Diferentes formas de visitar los nodos (In-Order, Pre-Order, Post-Order).

Árboles Binarios de Búsqueda: Estructura ordenada que permite búsquedas eficientes.

**Cómo Compilar y Ejecutar**
```
Java:
cd APE_Arboles/java
javac Ejercicio1_Basico.java
java Ejercicio1_Basico
```
```
C++:
cd APE_Arboles/cpp
g++ -o Ejercicio1 Ejercicio1_Basico.cpp
./Ejercicio1
```
