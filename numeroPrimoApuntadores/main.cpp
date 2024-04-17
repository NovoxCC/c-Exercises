#include <iostream>

using namespace std;

// Función que verifica si un numero es primo o no
bool numeroEsPrimo(int num) {
    if (num <= 1) {
        return false; // Si el numero es menor o igual a 1, no es primo
    }
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false; // Si es divisible por un numero distinto de 1 o si mismo, no es primo
        }
    }
    
    return true; // Si no se encontraron divisores distintos de 1 o si mismo, es primo
}

int main() {
    int numero;
    bool esPrimoRe;
    bool* esPrimo = &esPrimoRe; 
	// Declaracion de un puntero bool y asignacion de direccion 
    // Asigna la direccion de memoria de 'esPrimoRe' al puntero

    cout << "Ingrese un numero: ";
    cin >> numero; // Lee un numero desde la entrada estandar

   *esPrimo = numeroEsPrimo(numero); // Llama a la función esPrimo para verificar si el numero es primo y almacena el resultado en la ubicacion apuntada por esPrimo


    if (*esPrimo) { //acceder al valor almacenado en la dirección de memoria a la que apunta el puntero
        cout << numero << " es un numero primo." << endl;
    } else {
        cout << numero << " no es un numero primo." << endl; 
    }

    return 0; 
}

