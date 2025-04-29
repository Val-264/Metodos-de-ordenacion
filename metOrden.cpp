// Metodos de ordenacion 
//

#include <iostream>
#include <time.h>    // Mejor usar <ctime> en lugar de <time.h>
#include <stdlib.h>   // Mejor usar <cstdlib> en lugar of <stdlib.h>
#include <chrono>    // libreria para medir el tiempo que tarda en ejecutarse

using namespace std;

// Prototipos
void menu();
void crearVector(int *vecG, int *vecC, int tam);
void pedirTam();
void liberarEsp(int *vecG, int *vecC);
void restaurarVecGlobal(int *vecG, int *vecC);
void seleccion(int *vec); 
void insercion(int *vec);
void burbuja(int *vec); 
void combsort(int *vec); 
void cocktailsort(int *vec); 
void countingsort(int *vec); 
void binsort(int *vec); 
void shell(int *vec); 
void shakesort(int *vec); 
void gnomesort(int *vec); 
void mergesort(int *vec); 
void radixsort(int *vec); 
void quicksort(int *vec);
void mostrarVec(int *vec);

// Variable global para el vector (alternativa: pasar como parámetro)
int *vectorGlobal = nullptr;
int *vectorCopia = nullptr;
int tamanoGlobal = 0;

int main() {
    srand(time(nullptr)); // nullptr es mejor que NULL en C++
    menu();
    if(vectorGlobal != nullptr) {
        liberarEsp(vectorGlobal, vectorCopia);
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
                    liberarEsp(vectorGlobal, vectorCopia);
					          // Incializar variables //
                    vectorGlobal = nullptr; 
				          	vectorCopia = nullptr;
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
                    cout << "Primero debe crear un vector (opcion 14)\n";
                } else if(opc >=1 && opc <=13) {
                    cout << "Ejecutando algoritmo de ordenamiento " << opc << "\n";
                    
                    switch(opc){
                    	case 1: restaurarVecGlobal(vectorGlobal, vectorCopia);
								seleccion(vectorGlobal); break;
								 
                    	case 2: restaurarVecGlobal(vectorGlobal, vectorCopia);					
								insercion(vectorGlobal); break;
								
                    	case 3: restaurarVecGlobal(vectorGlobal, vectorCopia);														
								burbuja(vectorGlobal); break;
								
                    	case 4:	restaurarVecGlobal(vectorGlobal, vectorCopia);												
								combsort(vectorGlobal); break;
								
                    	case 5: restaurarVecGlobal(vectorGlobal, vectorCopia);						                    	
								cocktailsort(vectorGlobal); break;
                    	
                    	case 6: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								countingsort(vectorGlobal); break;
                    	
						case 7: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								binsort(vectorGlobal); break;
                    	
						case 8: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								shell(vectorGlobal); break;
                    	
						case 9: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								shakesort(vectorGlobal); break;
                    	
						case 10: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								 gnomesort(vectorGlobal); break;
                    	
						case 11: 
						restaurarVecGlobal(vectorGlobal, vectorCopia);
        				{
            				auto start = chrono::high_resolution_clock::now();				// Marca el tiempo de inicio antes de ejecutar el algoritmo de ordenación
           					mergesort(vectorGlobal);										// Llama al algoritmo de ordenación 'mergesort' para ordenar el vector
            				auto end = chrono::high_resolution_clock::now();				// Marca el tiempo de finalización después de que el algoritmo termine
            				chrono::duration<double, milli> duration = end - start;	 		// Calcula la duración en milisegundos entre el tiempo de inicio y el de fin
            				cout << "Tiempo de ejecucion: " << duration.count() << " ms\n";	// Imprime el tiempo que tardó el algoritmo en ordenar el vector en milisegundos
        				}
        				break;
                    	
						case 12: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								 radixsort(vectorGlobal); break;
                    	
						case 13: restaurarVecGlobal(vectorGlobal, vectorCopia);											
								 quicksort(vectorGlobal); break;
					}

                }
                break;
        }
    } while(opc != 16);
}

void pedirTam() {
    if(vectorGlobal != nullptr) {
        liberarEsp(vectorGlobal, vectorCopia);
    }
    
    int tam = 0;
    cout << "Tamano del vector: ";
    cin >> tam;
    while(tam <= 0) {
        cout << "El tamano debe ser positivo. Intente nuevamente: ";
        cin >> tam;     
    }
    
    vectorGlobal = new int[tam];
    vectorCopia = new int[tam];
    tamanoGlobal = tam;
    crearVector(vectorGlobal, vectorCopia, tam);
}

void crearVector(int *vecG, int *vecC, int tam) {
    cout << "Vector generado:\n";
    for(int i = 0; i < tam; i++) {
        vecG[i] = rand() % 2001;
        cout << vecG[i] << "\t";
        if((i+1) % 5 == 0) cout << "\n"; // Formato de 5 columnas
    }
    
    // Hacer la copia del vector 
    for (int i=0; i < tam; i++) {
    	vecC[i] = vecG[i];
	}
    cout << "\n";
}

void liberarEsp(int *vecG, int *vecC) {
    delete[] vecG;
    delete[] vecC;
}

void restaurarVecGlobal(int *vecG, int *vecC) {
	for(int i = 0; i < tamanoGlobal; i++) {
		vecG[i] = vecC[i];
	}
}

//Seleccion
void seleccion(int *vec) {
	int menor, aux;
	for(int i = 0; i < tamanoGlobal-1; i++){
		menor=i;
		for(int j = i+1; j < tamanoGlobal; j++){
			if(vec[j] < vec[menor]){
				menor = j;
			}
		}
		if(menor != i){
			aux = vec[i];
			vec[i] = vec[menor];
			vec[menor] = aux;
		}
	}
	
	// Mostrar vector ordenado
	mostrarVec(vec);
	cout<<"\n";
}

// Insercion
void insercion(int *vec) {
	int j = 0;
	for(int i = 0; i < tamanoGlobal; i++){
		int tem = vec[i];
		j = i-1;
		while(j >= 0 && tem < vec[j]){
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1]=tem;
	}

	// Mostrar vector ordenado
	mostrarVec(vec);
	cout << "\n";
}

//burbuja
void burbuja(int *vec) {
	int aux = 0;
	for(int i = 0; i < tamanoGlobal; i++){
		for(int j = 0; j < tamanoGlobal-1; j++){
			if(vec[j+1] < vec[j]){
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}	
		}
	}

	// Mostrar vector ordenado
	mostrarVec(vec);
	cout << "\n";		
} 

void combsort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

void cocktailsort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

void countingsort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
}

void binsort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

//Sell
void shell(int *vec) {
	int j, temp;
	int inc = tamanoGlobal/2;
	while(inc>0){
		for(int i = inc; i < tamanoGlobal; i++){
			j=i;
			temp=vec[i];
			while((j >= inc) && (vec[j-inc] > temp)){
				vec[j] = vec[j-inc];
				j = j-inc;
			}
			vec[j] = temp;
		}
		inc/= 2;
	}	

	// Mostrar vector ordenado
	mostrarVec(vec);
	cout << "\n";	
}

//Shakesort
void shakesort(int *vec) {
	bool swapped = true;
	int start = 0;
	int end = tamanoGlobal - 1;

	while (swapped) {
		swapped = false;

		// Recorrer de izquierda a derecha
		for (int i = start; i < end; ++i) {
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				swapped = true;
			}
		}

		// Si no hubo intercambio, el vector ya está ordenado
		if (!swapped)
			break;

		// Decrementar el extremo derecho
		--end;

		swapped = false;

		// Recorrer de derecha a izquierda
		for (int i = end - 1; i >= start; --i) {
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				swapped = true;
			}
		}

		// Incrementar el extremo izquierdo
		++start;
	}

	// Mostrar vector ordenado
	mostrarVec(vec);
	cout << "\n";
} 

// GnomeSort
void gnomesort(int *vec) {
	int index = 0;
	while (index < tamanoGlobal) {
		if (index == 0 || vec[index] >= vec[index - 1]) {
			index++;
		} else {
			swap(vec[index], vec[index - 1]);
			index--;
		}
	}
	// Mostrar vector ordenado
	mostrarVec(vec);
	cout << "\n";
} 

// MergeSort
// Función para fusionar dos subarreglos ordenados
void merge(int *vec, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;   // Tamaño del primer subarreglo
    int n2 = fin - medio;          // Tamaño del segundo subarreglo

    // Crear arreglos temporales
    int *L = new int[n1];
    int *R = new int[n2];

    // Copiar los datos a los arreglos temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = vec[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[medio + 1 + j];

    // Combinar los arreglos L[] y R[] en vec[]
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si quedan
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si quedan
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Función auxiliar recursiva de mergesort
void mergeSortAux(int *vec, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        mergeSortAux(vec, inicio, medio);      // Ordena la primera mitad
        mergeSortAux(vec, medio + 1, fin);      // Ordena la segunda mitad
        merge(vec, inicio, medio, fin);         // Fusiona las dos mitades
    }
}

// Función principal llamada desde el main
void mergesort(int *vec) {
    mergeSortAux(vec, 0, tamanoGlobal - 1);     // Llama a la función auxiliar
    mostrarVec(vec);                            // Muestra el vector ordenado
    cout << "\n";
}

// RadixSort
// Función para obtener el valor máximo en el arreglo
int getMax(int *vec) {
    int mx = vec[0];
    for (int i = 1; i < tamanoGlobal; i++)
        if (vec[i] > mx)
            mx = vec[i];
    return mx;
}

// Función para realizar un counting sort basado en el dígito exp
void countSort(int *vec, int exp) {
    int *output = new int[tamanoGlobal];    // Arreglo temporal
    int count[10] = {0};                    // Cuenta para cada dígito (0-9)

    // Contar las ocurrencias de cada dígito
    for (int i = 0; i < tamanoGlobal; i++)
        count[(vec[i] / exp) % 10]++;

    // Cambiar count[i] para que contenga las posiciones reales
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir el arreglo de salida
    for (int i = tamanoGlobal - 1; i >= 0; i--) {
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        count[(vec[i] / exp) % 10]--;
    }

    // Copiar el arreglo de salida al arreglo original
    for (int i = 0; i < tamanoGlobal; i++)
        vec[i] = output[i];

    delete[] output;
}

// Función principal de radix sort
void radixsort(int *vec) {
    int m = getMax(vec);    // Obtener el valor máximo

    // Aplicar counting sort para cada dígito
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(vec, exp);

    mostrarVec(vec);        // Mostrar el vector ordenado
    cout << "\n";
}

// QuickSort
// Función para particionar el arreglo alrededor de un pivote
int partition(int *vec, int low, int high) {
    int pivot = vec[high];    // Pivote
    int i = low - 1;          // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

// Función auxiliar recursiva de quicksort
void quickSortAux(int *vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);    // Índice del pivote
        quickSortAux(vec, low, pi - 1);         // Ordenar los elementos antes del pivote
        quickSortAux(vec, pi + 1, high);        // Ordenar los elementos después del pivote
    }
}

// Función principal llamada desde el main
void quicksort(int *vec) {
    quickSortAux(vec, 0, tamanoGlobal - 1);     // Llama a la función auxiliar
    mostrarVec(vec);                            // Muestra el vector ordenado
    cout << "\n";
}

//funcion para mostrar el vector ordenado
void mostrarVec(int *vec){
	for (int i = 0; i < tamanoGlobal; i++) {
		cout << vec[i] << "\t";
		if ((i + 1) % 5 == 0)
			cout << "\n";
	}
}