// Metodos de ordenacion 
//

#include <iostream>
#include <time.h>    // Mejor usar <ctime> en lugar de <time.h>
#include <stdlib.h>   // Mejor usar <cstdlib> en lugar of <stdlib.h>
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
                    	
						case 11: restaurarVecGlobal(vectorGlobal, vectorCopia);												
								 mergesort(vectorGlobal); break;
                    	
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
	for(int i = 0; i < tamanoGlobal; i++){
		cout << vec[i] << "\t";	
		if((i+1) % 5 == 0) cout << "\n";
	}
	
	cout<<"\n";
}

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
	for(int i = 0; i < tamanoGlobal; i++){
		cout << vec[i] << "\t";	
		if((i+1) % 5 == 0) cout << "\n";
	}
		
	cout << "\n";
}

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
	for(int i = 0; i < tamanoGlobal; i++){
		cout << vec[i] << "\t";	
		if((i+1) % 5 == 0) cout << "\n";
	}

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
}


void binsort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

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
	for(int i = 0; i < tamanoGlobal; i++){
		cout << vec[i] << "\t";	
		if((i+1) % 5 == 0) cout << "\n";
	}
	
	cout << "\n";	
}

void shakesort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

void gnomesort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

void mergesort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

void radixsort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
} 

void quicksort(int *vec) {
	cout << "Esta funcion no ha sido implementada";	
}