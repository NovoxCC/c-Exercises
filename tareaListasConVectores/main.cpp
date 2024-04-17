#include <iostream>
using namespace std;

const int MAX_TAMANO = 5; // Tamaño máximo de la lista

class Lista {
private:
    int elementos[MAX_TAMANO];
    int tamano;

public:
	
	// Constructor
    Lista();

    // Destructor
    ~Lista();

    // Método para insertar un elemento en la lista en una posición específica
    void insertar(int valor, int posicion);

    // Método para extraer un elemento de la lista en una posición específica
    int extraer(int posicion);

    // Método para imprimir la lista con índices
    void imprimir();
	
};
    // Constructor
    Lista::Lista() : tamano(0) {
        // Inicializar el arreglo de elementos
        for (int i = 0; i < MAX_TAMANO; i++) {
            elementos[i] = 0;
        }
    }

    // Destructor
    Lista::~Lista() {
        /*
		No es necesario realizar ninguna limpieza específica en este caso,
		como no se realiza ninguna asignación dinámica de memoria ni se 
		utilizan recursos externos, el destructor es opcional y no es necesario 
		realizar ninguna operación específica de limpieza.
        */
    }

    /*
    Método para insertar un elemento en la lista en una posición específica
	Se realiza una verificación para asegurarse de que la lista no esté llena (tamano < MAX_TAMANO) y de que la posición proporcionada sea válida (posicion >= 0 y posicion <= tamano).
	*/
    void Lista::insertar(int valor, int posicion) {
        if (tamano < MAX_TAMANO && posicion >= 0 && posicion <= tamano) {
            // Desplazar los elementos a la derecha para hacer espacio
            for (int i = tamano; i > posicion; i--) {
                elementos[i] = elementos[i - 1];
            }
            elementos[posicion] = valor;
            tamano++;
            cout << "Elemento insertado en la posicion " << posicion << ": " << valor << endl;
            cout << "Presiona Enter para Continuar...";
            cin.ignore(); // Limpia el búfer de entrada
            cin.get();    // Espera a que el usuario presione Enter
        } else {
            cout << "No se puede insertar en la posicion especificada." << endl;
            cout << "Presiona Enter para Continuar...";
            cin.ignore(); // Limpia el búfer de entrada
            cin.get();    // Espera a que el usuario presione Enter
        }
    }

    /// Método para extraer un elemento de la lista en una posición específica
	int Lista::extraer(int posicion) {
    if (posicion >= 0 && posicion < tamano) {
        int valor = elementos[posicion];
        
        // Desplazar los elementos a la izquierda para llenar el espacio
        for (int i = posicion; i < tamano - 1; i++) {
            elementos[i] = elementos[i + 1];
        }
        
        tamano--;
        cout << "Elemento extraido de la posicion " << posicion << ": " << valor << endl;
        cin.ignore(); // Limpia el búfer de entrada
        cin.get();    // Espera a que el usuario presione Enter
        return valor;
    } else {
        cout << "No se puede extraer en la posicion especificada." << endl;
        cout << "Presiona Enter para Continuar...";
        cin.ignore(); // Limpia el búfer de entrada
        cin.get();    // Espera a que el usuario presione Enter
        return -1;  // Valor sentinela para indicar error
    }
}

    // Método para imprimir la lista con índices
    void Lista::imprimir() {
        cout << "Lista: ";
        for (int i = 0; i < tamano; i++) {
            cout << "[" << i << "]" << elementos[i] << ", "; // Imprime el índice y el valor
        }
        cout << endl;
    }

    // Resto de los métodos de la clase (limpiarPantalla(), menu(), etc.)...

void Ejercicio(){
	cout << endl << "\t\tTarea Listas con vectores" << endl;
	cout << "Este Programa muestra el funcionamiento de una lista utilizando vectores." << endl;
	cout << ">Construye una clase lista, con los atributos y metodos necesarios." << endl;
	cout << ">Se desarrollo un metodo constructor constructor de la lista." << endl;
	cout << ">Se desarrollo un metodo insertar en la lista, con los casos de insercion." << endl;
	cout << ">Se desarrollo un metodo extraer de la lista, con los casos de extraccion." << endl;
	cout << ">Se desarrollo UN metodo impresion." << endl;
	cout << ">Se desarrollo un metodo extraer de la lista, con los casos de extraccion." << endl;
	cout << ">Se desarrollo un metodo extraer de la lista, con los casos de extraccion." << endl;
	cout << ">El tamaño de la lista aumenta o disminuye." << endl;
	cout << "Presiona Enter para Continuar...";
    cin.get();    // Espera a que el usuario presione Enter
}

int main() {
	setlocale(LC_ALL, "");
    Lista miLista;
    int opcion;
	Ejercicio();
    while (true) {
        system("cls"); // Llamada a un posible método para limpiar la pantalla
        cout << endl << "\t\tMenu:" << endl;
        cout << "1. Insertar elemento en la lista" << endl;
        cout << "2. Extraer elemento de la lista" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int valor, posicion;
            cout << "Ingrese el valor a insertar: ";
            cin >> valor;
            cout << "Ingrese la posicion de insercion: ";
            cin >> posicion;
            miLista.insertar(valor, posicion);
        } else if (opcion == 2) {
            int posicion;
            cout << "Ingrese la posicion del elemento a extraer: ";
            cin >> posicion;
            miLista.extraer(posicion);
        } else if (opcion == 3) {
            miLista.imprimir();
        } else if (opcion == 4) {
            break; // Salir del bucle si se elige la opción 4
        } else {
			cin.clear(); // restablecer el estado de la entrada estándar después de que se haya producido un error, como una entrada incorrecta.
			cin.ignore();// Limpia el búfer de entrada
            cout << "Opcion no valida." << endl;
            cout << "Presiona Enter para Continuar...";
            cin.ignore(); // Limpia el búfer de entrada
            cin.get();    // Espera a que el usuario presione Enter
        }
    }

    return 0;
}

