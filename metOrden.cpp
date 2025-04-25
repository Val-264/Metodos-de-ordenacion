// Metodos de ordenacion 

#include <iostream>
#include <time.h>    // Mejor usar <ctime> en lugar de <time.h>
#include <stdlib.h>   // Mejor usar <cstdlib> en lugar of <stdlib.h>
using namespace std;

// Prototipos
void menu();
void crearVector(int *vec, int tam);
void pedirTam();
void liberarEsp(int *vec);

// Variable global para el vector (alternativa: pasar como parámetro)
int *vectorGlobal = nullptr;
int tamanoGlobal = 0;

int main() {
    srand(time(nullptr)); // nullptr es mejor que NULL en C++
    menu();
    if(vectorGlobal != nullptr) {
        liberarEsp(vectorGlobal);
    }
    return 0;
}

void menu() {
    int opc = 0;
    do {
        cout<<"SELECCIONA UN METODO:\n";
        cout<<"SELECCION...............1\n";
        cout<<"INSERCCION..............2\n";
        cout<<"BURBUJA.................3\n";
        cout<<"COMBSORT................4\n";
        cout<<"COCKTAILSORT............5\n";
        cout<<"COUNTINGSORT............6\n";
        cout<<"BINSORT.................7\n";
        cout<<"SHELL...................8\n";
        cout<<"SHAKERSORT..............9\n";
        cout<<"GNOME SORT..............10\n";
        cout<<"MERGESORT...............11\n";
        cout<<"RADIXSORT...............12\n";
        cout<<"QUICKSORT...............13\n";
        cout<<"Pedir tamano del vector.14\n";
        cout<<"Liberar espacio en memoria.15\n";
        cout<<"Salir...................16\n";
		cout<<"Elije una opcion: ";
        cin >> opc;
        
        switch(opc) {
            case 14: 
                pedirTam(); 
                break;
            case 15: 
                if(vectorGlobal != nullptr) {
                    liberarEsp(vectorGlobal);
                    vectorGlobal = nullptr;
                    tamanoGlobal = 0;
                    cout << "Memoria liberada.\n";
                } else {
                    cout << "No hay vector creado.\n";
                }
                break;
            case 16: 
                cout << "Saliendo...\n";
                break;
            default:
                if(vectorGlobal == nullptr && opc >=1 && opc <=13) {
                    cout << "Primero debe crear un vector (opción 14)\n";
                } else if(opc >=1 && opc <=13) {
                    cout << "Ejecutando algoritmo de ordenamiento " << opc << "\n";
                    // Aquí iría la llamada a los algoritmos de ordenamiento
                }
                break;
        }
    } while(opc != 16);
}

void pedirTam() {
    if(vectorGlobal != nullptr) {
        liberarEsp(vectorGlobal);
    }
    
    int tam = 0;
    cout << "Tamano del arreglo: ";
    cin >> tam;
    while(tam <= 0) {
        cout << "El tamaño debe ser positivo. Intente nuevamente: ";
        cin >> tam;     
    }
    
    vectorGlobal = new int[tam];
    tamanoGlobal = tam;
    crearVector(vectorGlobal, tam);
}

void crearVector(int *vec, int tam) {
    cout << "Vector generado:\n";
    for(int i = 0; i < tam; i++) {
        vec[i] = rand() % 2001;
        cout << vec[i] << "\t";
        if((i+1) % 5 == 0) cout << "\n"; // Formato de 5 columnas
    }
    cout << "\n";
}

void liberarEsp(int *vec) {
    delete[] vec;
}