#include <iostream>
#include <limits> // Incluimos la cabecera para usar numeric_limits
using namespace std;

bool estriangulo(int lado1, int lado2, int lado3);
void ingresarDato(int& dato);

int main() {
    int a, b, c;
    ingresarDato(a);
    ingresarDato(b);
    ingresarDato(c);
    if (estriangulo(a, b, c)) {
        cout << "Si, se puede construir un triangulo";
    } else {
        cout << "No se puede construir un triangulo con esos segmentos de recta";
    }
    return 0;
}

void ingresarDato(int& dato) {
    while (true) {
        cout << "Ingrese el segmento de recta: ";
        cin >> dato;
        if (cin.fail()) { // Si la entrada no es un número válido
            cin.clear(); // Limpiamos el estado del flujo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoramos la entrada no válida
            cout << "Entrada no valida. Por favor, ingrese un numero valido." << endl;
        } else if (dato <= 0) {
            cout << "El valor debe ser positivo. Intentelo de nuevo." << endl;
        } else {
            break; // Salimos del bucle si la entrada es válida
        }
    }
}

bool estriangulo(int lado1, int lado2, int lado3) {
    return (lado1 < lado2 + lado3) && (lado2 < lado1 + lado3) && (lado3 < lado1 + lado2);
}
