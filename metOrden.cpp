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