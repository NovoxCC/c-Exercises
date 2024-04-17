#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

#define MaxTamaCola 4

class Cola {
private:
    int cola[MaxTamaCola];
    int frente;
    int fin;

public:
    Cola();         // constructor
    ~Cola();        // destructor
    void vaciaC();
    void insertarC(int elemento);
    int quitarC();
    int estavaciaC();
    void imprimirC();
    int estallenaC();
    void transferirC(Cola& destino);
    void operacionesC();
};

int SeleccionarC() {
    int op;
    bool salir = false;
    do {
        cout << "\t Seleccione la cola:\n";
        cout << " 1. Cola 1.\n";
        cout << " 2. Cola 2.\n";
        cin >> op;
        switch (op) {
        case 1:
            salir = true;
            return 1;
            break;
        case 2:
            salir = true;
            return 0;
            break;
        default:
            system("cls");
            cout << "\t\t Ingresa una opción válida.\n";
            system("PAUSE");
            break;
        }
    } while (!salir);
}

Cola::Cola() { // Constructor
    frente = fin = -1;
}

Cola::~Cola() { // Destructor
    cout << "\nGracias por utilizar este programa. \n";
}

void Cola::vaciaC() {
    frente = fin = -1;
}

void Cola::insertarC(int _elemento) {
    if (estallenaC()) {
        cout << "\nDesbordamiento cola";
        exit(1);
    } else {
        if (frente == -1) {
            frente = fin = 0;
        } else {
            fin = (fin + 1) % MaxTamaCola;
        }
        cola[fin] = _elemento;
        cout << "Se inserta el elemento: " << _elemento << endl;
    }
}

int Cola::quitarC() {
    int aux;
    if (estavaciaC()) {
        cout << "\nSe intenta sacar un elemento en cola vacía";
        exit(1);
    } else {
        aux = cola[frente];
        frente = (frente + 1) % MaxTamaCola;
        return aux;
    }
}

int Cola::estallenaC() {
    return (frente == fin + 1) || (frente == 0 && fin == MaxTamaCola - 1);
}

int Cola::estavaciaC() {
    return frente == -1;
}

void Cola::imprimirC() {
    if (estavaciaC()) {
        cout << "Cola vacía." << endl;
    } else if (estallenaC()) {
        cout << "Cola llena:" << endl;
        for (int i = frente; i != fin; i = (i + 1) % MaxTamaCola) {
            cout << cola[i] << " ";
        }
        cout << cola[fin] << endl;
    } else {
        cout << "Cola:" << endl;
        for (int i = frente; i != fin; i = (i + 1) % MaxTamaCola) {
            cout << cola[i] << " ";
        }
        cout << cola[fin] << endl;
    }
}

void Cola::transferirC(Cola& destino) {
    if (!estavaciaC()) {
        while (!estavaciaC() && !destino.estallenaC()) {
            destino.insertarC(quitarC());
        }
        cout << "Elementos transferidos." << endl;
    } else {
        cout << "La cola origen está vacía. No se puede transferir." << endl;
    }
}

void Cola::operacionesC() {
    if (!estavaciaC()) {
        imprimirC();
        int mayor = cola[frente];
        int menor = cola[frente];

        for (int i = frente; i != fin; i = (i + 1) % MaxTamaCola) {
            if (cola[i] > mayor) {
                mayor = cola[i];
            }
            if (cola[i] < menor) {
                menor = cola[i];
            }
        }

        cout << "Mayor valor en la cola: " << mayor << endl;
        cout << "Menor valor en la cola: " << menor << endl;
    } else {
        cout << "La cola está vacía." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "spanish");
    Cola C1, C2;
    int op = 0, dato = 0, tam = 0;
    bool salir = false;

    do {
    	system("cls");
        cout << "\t\t Ejercicio colas\n\n";
        cout << "\t 1. Imprimir cola.\n";
        cout << "\t 2. Transferir cola.\n";
        cout << "\t 3. Operar cola.\n";
        cout << "\t 4. Ingresar datos a cola.\n";
        cout << "\t 5. Salir.\n";
        cin >> op;
        switch (op) {
        case 1:
            system("cls");
            // Imprimir las colas según lo requerido
            cout << "\t\t Cola 1:\n";
            C1.imprimirC();
            cout << "\t\t Cola 2:\n";
            C2.imprimirC();
            system("PAUSE");
            break;
        case 2:
            system("cls");
            // Transferir elementos de C1 a C2
            C1.transferirC(C2);
            // Imprimir ambas colas después de la transferencia
            cout << "Cola 1 después de transferir: ";
            C1.imprimirC();
            cout << "Cola 2 después de transferir: ";
            C2.imprimirC();
            system("PAUSE");
            break;
        case 3:
            system("cls");
            // Operaciones en Colas
            if (SeleccionarC()) {
                system("cls");
                cout << "\t\t Operando en Cola 1.\n";
                C1.operacionesC();
            } else {
                system("cls");
                cout << "\t\t Operando en Cola 2.\n";
                C2.operacionesC();
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            if (SeleccionarC()) {
                cout << "\t\t Cola 1.\n";
                cout << "Ingrese el dato: ";
                cin >> dato;
                C1.insertarC(dato);
                dato = 0;
                system("cls");
            } else {
                cout << "\t\t Cola 2.\n";
                cout << "Ingrese el dato: ";
                cin >> dato;
                C2.insertarC(dato);
                dato = 0;
                system("cls");
            }
            break;
        case 5:
            system("cls");
            salir = true;
            break;
        default:
            system("cls");
            cout << "\t\t Ingresa una opción válida.\n";
            system("PAUSE");
            break;
        }
    } while (!salir);

    return 0;
}

