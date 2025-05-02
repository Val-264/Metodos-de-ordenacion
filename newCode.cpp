// Métodos de ordenación
// Este programa implementa varios algoritmos de ordenación y permite al usuario seleccionar cuál ejecutar.
// También mide el tiempo de ejecución de cada algoritmo.

#include <iostream>
#include <ctime>    // Para la función srand() y rand()
#include <cstdlib>  // Para funciones estándar como rand()
#include <chrono>   // Para medir el tiempo de ejecución

using namespace std;

// Prototipos de funciones
void menu();
void crearVector(int *vecG, int *vecC, int tam);
void pedirTam();
void liberarEsp(int *vecG, int *vecC);
void restaurarVecGlobal(int *vecG, int *vecC);
void seleccion(int *vec);
void insercion(int *vec);
void burbuja(int *vec);
void combsort(int *vec, int n);
void cocktailsort(int *vec, int n);
void countingsort(int *vec, int n);
void binsort(int *vec);
void shell(int *vec);
void shakesort(int *vec);
void gnomesort(int *vec);
void mergesort(int *vec);
void radixsort(int *vec);
void quicksort(int *vec);
void mostrarVec(int *vec);

// Variables globales para el vector y su tamaño
int *vectorGlobal = nullptr;  // Puntero al vector principal
int *vectorCopia = nullptr;   // Puntero a una copia del vector
int tamanoGlobal = 0;         // Tamaño del vector

int main() {
    srand(time(nullptr)); // Inicializa la semilla para números aleatorios
    menu();               // Llama al menú principal
    if (vectorGlobal != nullptr) {
        liberarEsp(vectorGlobal, vectorCopia); // Libera la memoria al salir
    }
    return 0;
}

// Función que muestra el menú principal y gestiona las opciones del usuario
void menu() {
    int opc = 0; // Variable para almacenar la opción seleccionada por el usuario
    do {
        // Mostrar las opciones del menú
        cout << "SELECCIONA UN METODO:\n";
        cout << "SELECCION...............1\n";
        cout << "INSERCCION..............2\n";
        cout << "BURBUJA.................3\n";
        cout << "COMBSORT................4\n";
        cout << "COCKTAILSORT............5\n";
        cout << "COUNTINGSORT............6\n";
        cout << "BINSORT.................7\n";
        cout << "SHELL...................8\n";
        cout << "SHAKERSORT..............9\n";
        cout << "GNOME SORT..............10\n";
        cout << "MERGESORT...............11\n";
        cout << "RADIXSORT...............12\n";
        cout << "QUICKSORT...............13\n";
        cout << "Pedir tamano del vector.14\n";
        cout << "Liberar espacio en memoria.15\n";
        cout << "Salir...................16\n";
        cout << "Elije una opcion: ";
        cin >> opc;

        switch (opc) {
            case 14: // Crear un nuevo vector
                pedirTam();
                break;
            case 15: // Liberar memoria
                if (vectorGlobal != nullptr) {
                    liberarEsp(vectorGlobal, vectorCopia);
                    vectorGlobal = nullptr;
                    vectorCopia = nullptr;
                    tamanoGlobal = 0;
                    cout << "Memoria liberada.\n";
                } else {
                    cout << "No hay vector creado.\n";
                }
                break;
            case 16: // Salir del programa
                cout << "Saliendo...\n";
                break;
            default:
                if (vectorGlobal == nullptr && opc >= 1 && opc <= 13) {
                    cout << "Primero debe crear un vector (opcion 14)\n";
                } else if (opc >= 1 && opc <= 13) {
                    cout << "Ejecutando algoritmo de ordenamiento " << opc << "\n";

                    // Restaurar el vector original antes de ejecutar el algoritmo
                    restaurarVecGlobal(vectorGlobal, vectorCopia);

                    // Medir el tiempo de ejecución del algoritmo seleccionado
                    auto start = chrono::high_resolution_clock::now();
                    switch (opc) {
                        case 1: seleccion(vectorGlobal); break;
                        case 2: insercion(vectorGlobal); break;
                        case 3: burbuja(vectorGlobal); break;
                        case 4: combsort(vectorGlobal, tamanoGlobal); break;
                        case 5: cocktailsort(vectorGlobal, tamanoGlobal); break;
                        case 6: countingsort(vectorGlobal, tamanoGlobal); break;
                        case 7: binsort(vectorGlobal); break;
                        case 8: shell(vectorGlobal); break;
                        case 9: shakesort(vectorGlobal); break;
                        case 10: gnomesort(vectorGlobal); break;
                        case 11: mergesort(vectorGlobal); break;
                        case 12: radixsort(vectorGlobal); break;
                        case 13: quicksort(vectorGlobal); break;
                    }
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, milli> duration = end - start;
                    cout << "Tiempo de ejecucion: " << duration.count() << " ms\n";
                }
                break;
        }
    } while (opc != 16); // Repetir hasta que el usuario elija salir
}

// Función para pedir el tamaño del vector y crearlo
void pedirTam() {
    if (vectorGlobal != nullptr) {
        liberarEsp(vectorGlobal, vectorCopia);
    }

    int tam = 0;
    cout << "Tamano del vector: ";
    cin >> tam;
    while (tam <= 0) {
        cout << "El tamano debe ser positivo. Intente nuevamente: ";
        cin >> tam;
    }

    vectorGlobal = new int[tam];
    vectorCopia = new int[tam];
    tamanoGlobal = tam;
    crearVector(vectorGlobal, vectorCopia, tam);
}

// Función para generar un vector aleatorio
void crearVector(int *vecG, int *vecC, int tam) {
    cout << "Vector generado:\n";
    for (int i = 0; i < tam; i++) {
        vecG[i] = rand() % 2001; // Generar números aleatorios entre 0 y 2000
        cout << vecG[i] << "\t";
        if ((i + 1) % 5 == 0) cout << "\n"; // Formato de 5 columnas
    }

    // Hacer una copia del vector
    for (int i = 0; i < tam; i++) {
        vecC[i] = vecG[i];
    }
    cout << "\n";
}

// Función para liberar la memoria asignada dinámicamente
void liberarEsp(int *vecG, int *vecC) {
    delete[] vecG;
    delete[] vecC;
}

// Función para restaurar el vector original desde su copia
void restaurarVecGlobal(int *vecG, int *vecC) {
    for (int i = 0; i < tamanoGlobal; i++) {
        vecG[i] = vecC[i];
    }
}

// Función para mostrar el vector
void mostrarVec(int *vec) {
    for (int i = 0; i < tamanoGlobal; i++) {
        cout << vec[i] << "\t";
        if ((i + 1) % 5 == 0) cout << "\n";
    }
    cout << "\n";
}

// Implementación de los algoritmos de ordenación

//Seleccion
void seleccion(int *vec) {
	int menor, aux;
	for(int i = 0; i < tamanoGlobal-1; i++){
		menor=i; 
		for(int j = i+1; j < tamanoGlobal; j++){
			// Cambiar la posicion de menor a j si se cumple la condicon
			if(vec[j] < vec[menor]){
				menor = j; 
			}
		}

		/* Intercambio de posiciones: pasar el numero menor 
		a la derecha y el más grande a a la izuierda*/
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
		int tem = vec[i]; // Guardar el elemento actual a insertar
		j = i-1; 

		// Mover elementos mayores que tem hacia ala derecha
		while(j >= 0 && tem < vec[j]){
			vec[j+1] = vec[j]; /// Desplazar elemento
			j--; 
		}

		// Insertar tem en su posicion correcta
		vec[j+1]=tem;
	}

	// Mostrar vector ordenado
	mostrarVec(vec);
	cout << "\n";
}

// Burbuja
void burbuja(int *vec) {
	int aux = 0;

	//Recorrer todos los elementos del arreglo
	for(int i = 0; i < tamanoGlobal; i++){
		for(int j = 0; j < tamanoGlobal-1; j++){
			/*Comparar elementos adyacentes e intercmabiarlos 
			si están ene el orden incorrecto*/ 
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

void combsort(int *vec, int n) {
	// Paso 1: Inicializar variables para el algoritmo
    int tamanoGlobal = n;       // tamaño del arreglo
    float factorReduccion = 1.3; // Factor de reducción óptimo
    bool huboIntercambio = true; // Bandera para saber si hubo intercambios
    
    // Paso 2: Implementar el algoritmo CombSort
    while (tamanoGlobal > 1 || huboIntercambio) {
        // Reducir la brecha según el factor de reducción
        tamanoGlobal = static_cast<int>(tamanoGlobal / factorReduccion);
        if (tamanoGlobal < 1) tamanoGlobal = 1;  // La brecha mínima es 1
        
        huboIntercambio = false;  // Reiniciar la bandera de intercambio
        
        // Comparar elementos con la brecha actual
        for (int i = 0; i + tamanoGlobal < n; i++) {
            if (vec[i] > vec[i + tamanoGlobal]) {
                // Intercambiar elementos si están en orden incorrecto
                int temporal = vec[i];
                vec[i] = vec[i + tamanoGlobal];
                vec[i + tamanoGlobal] = temporal;
                huboIntercambio = true;
            }
        }
    }
    // Mostrar resultados 
    mostrarVec(vec);
    cout << "\n";
}
 

void cocktailsort(int *vec, int n) {
	bool intercambio = true;
    int inicio = 0;
    int fin = n - 1;

    while (intercambio) {
        intercambio = false;
        
        // Paso de izquierda a derecha (como BubbleSort)
        for (int i = inicio; i < fin; i++) {
            if (vec[i] > vec[i + 1]) {
                swap(vec[i], vec[i + 1]);
                intercambio = true;
            }
        }
        
        if (!intercambio) break; // Si no hubo intercambios, terminar
        
        intercambio = false;
        fin--; // Disminuir el fin porque el último elemento ya está ordenado
        
        // Paso de derecha a izquierda
        for (int i = fin - 1; i >= inicio; i--) {
            if (vec[i] > vec[i + 1]) {
                swap(vec[i], vec[i + 1]);
                intercambio = true;
            }
        }
        
        inicio++; // Aumentar el inicio porque el primer elemento ya está ordenado
        tamanoGlobal = fin - inicio; // Actualizar tamaño global
    }
    // Mostrar resultados 
    mostrarVec(vec);
    cout << "\n";
}



void countingsort(int *vec, int n) {
	if (n == 0) return;

    // Encontrar el valor máximo y mínimo manualmente
    int max_val = vec[0];
    int min_val = vec[0];
    
    for (int i = 1; i < n; i++) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
        if (vec[i] < min_val) {
            min_val = vec[i];
        }
    }

    int tamanoGlobal = max_val - min_val + 1;
    
    // Crear arreglo de conteo dinámicamente
    int* conteo = new int[tamanoGlobal](); // Inicializa a ceros
    
    // Contar la frecuencia de cada elemento
    for (int i = 0; i < n; i++) {
        conteo[vec[i] - min_val]++;
    }

    // Reconstruir el vector ordenado
    int indice = 0;
    for (int val = min_val; val <= max_val; val++) {
        while (conteo[val - min_val] > 0) {
            vec[indice] = val;
            indice++;
            conteo[val - min_val]--;
        }
    }
    
    // Liberar memoria del arreglo dinámico
    delete[] conteo;

    // Mostrar resultados 
    mostrarVec(vec);
    cout << "\n";
}

void binsort(int *vec) {
	
        if(tamanoGlobal < 2) return;
    
        // Paso 1: Encontrar mínimo y máximo
        int min_val = vec[0];
        int max_val = vec[0];
        for(int i = 1; i < tamanoGlobal; i++) {
            if(vec[i] < min_val) min_val = vec[i];
            if(vec[i] > max_val) max_val = vec[i];
        }
    
        // Paso 2: Crear array de conteo
        int rango = max_val - min_val + 1;
        int* contador = new int[rango]();
    
        // Paso 3: Contar frecuencias
        for(int i = 0; i < tamanoGlobal; i++) {
            contador[vec[i] - min_val]++;
        }
    
        // Paso 4: Reconstruir el array ordenado
        int indice = 0;
        for(int i = 0; i < rango; i++) {
            while(contador[i] > 0) {
                vec[indice++] = i + min_val;
                contador[i]--;
            }
        }
    
        delete[] contador;
    
        // Mostrar resultados 
        mostrarVec(vec);
        cout << "\n";
} 

//Sell
void shell(int *vec) {
	int j, temp; // Variables auxiliares para desplazamiento y almacenamiento temporal 
	int inc = tamanoGlobal/2; // Inicializar el incremento a mitad del tamano
	
	// Continuar mientras el incremento sea mayor que cero
	while(inc>0){
		// Realizar ordenacion por insercion para cada subarreglo definido por el incremento
		for(int i = inc; i < tamanoGlobal; i++){
			j=i; // Posicion actual en el subarreglo
			temp=vec[i]; // Almacenar temporlamente el valor a insertar 

			// Mover elementos mayores que temp dentro del subarreglo 
			while((j >= inc) && (vec[j-inc] > temp)){
				vec[j] = vec[j-inc]; // Desplazar elemento hacia adelante
				j = j-inc; //Retroceder en el subarreglo
			}
			vec[j] = temp; // Colocar temp en su posicion correcta
		}
		inc/= 2; // Reducir el incremento a la mitad para la siguiente iteracion
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
// Fin del programa