#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

#define MaxTamaPila 4

class Pila {
private:
    int pila[MaxTamaPila];
    int cima;

public:
    Pila();     // constructor
    ~Pila();    // destructor
    void vaciaP();
    void insertarP(int elemento);
    int quitarP();
    int estavaciaP();
    void imprimirP();
    int estallenaP();
    void transferirP(Pila& destino);
    void operacionesP();
};

int SeleccionarP() {
    int op;
    bool salir = false;
    do {
        cout << "\t\t Ingresar datos pila.\n";
        cout << "\t Seleccione la pila:\n";
        cout << " 1. Pila 1.\n";
        cout << " 2. Pila 2.\n";
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
            cout << "\t\t Ingresa una opcion valida.\n";
            system("PAUSE");
            break;
        }
    } while (!salir);

}

Pila::Pila() { // Constructor
    cima = -1;
}

Pila::~Pila() { // Destructor
    cout << "\nGracias por utilizar este programa. \n";
}

void Pila::vaciaP() {
    cima = -1;
}

void Pila::insertarP(int _elemento) {
    if (estallenaP()) {
        cout << "\nDesbordamiento pila";
        exit(1);
    } else {
        cima++;
        pila[cima] = _elemento;
        cout << "Se inserta la cima: " << _elemento << " -> cima: " << cima << endl;
    }
}

int Pila::quitarP() {
    int aux;
    if (estavaciaP()) {
        cout << "\nSe intenta sacar un elemento en pila vacía";
        exit(1);
    } else {
        aux = pila[cima];
        cout << "\nSe elimina la cima: " << aux << " -> cima: " << cima;
        cima--;
        return aux;
    }
}

int Pila::estallenaP() {
    return cima == MaxTamaPila - 1;
}

int Pila::estavaciaP() {
    return cima == -1;
}

void Pila::imprimirP() {
    if (estavaciaP()) {
        cout << "Pila vacía, valor de cima: " << cima << endl;
    } else if (estallenaP()) {
        cout << "Pila llena:" << endl;
        for (int i = 0; i <= cima; ++i) {
            cout << pila[i] << " ";
        }
        cout << "-> cima: " << cima << endl;
    } else {
        cout << "Pila:" << endl;
        for (int i = 0; i <= cima; ++i) {
            cout << pila[i] << " ";
        }
        cout << endl;
    }
}

void Pila::transferirP(Pila& destino) {
    while (!estavaciaP() && !destino.estallenaP()) {
        destino.insertarP(quitarP());
    }
    cout << "Elementos transferidos." << endl;
}

void Pila::operacionesP() {
    imprimirP();
    if (!estavaciaP()) {
        int mayor = pila[0];
        int menor = pila[0];

        for (int i = 1; i <= cima; ++i) {
            if (pila[i] > mayor) {
                mayor = pila[i];
            }
            if (pila[i] < menor) {
                menor = pila[i];
            }
        }

        cout << "Mayor valor en la pila: " << mayor << endl;
        cout << "Menor valor en la pila: " << menor << endl;
    } else {
        cout << "La pila está vacía." << endl;
    }
}

int main() {
	setlocale(LC_ALL, "");
    Pila P1, P2;
    int op = 0, dp = 0;
    bool salir = false;

    do {
        cout << "\t\t Ejercicio pilas\n\n";
        cout << "\t 1. Imprimir pila.\n";
        cout << "\t 2. Transferir pila.\n";
        cout << "\t 3. Operar pila.\n";
        cout << "\t 4. Ingresar datos pila.\n";
        cout << "\t 5. Salir.\n";
        cin >> op;
        switch (op) {
        case 1:
            system("cls");
            // Imprimir la pila según lo requerido
            cout << "\t\t Pila 1:\n";
            P1.imprimirP();
            cout << "\t\t Pila 2:\n";
            P2.imprimirP();
            system("PAUSE");
            system("cls");
            break;
        case 2:
            system("cls");
            // Transferir elementos de P1 a P2
            P1.transferirP(P2);
            // Imprimir ambas pilas después de la transferencia
            cout << "Pila 1 después de transferir: ";
            P1.imprimirP();
            cout << "Pila 2 después de transferir: ";
            P2.imprimirP();
            system("PAUSE");
            system("cls");
            break;
        case 3:
            system("cls");
            // Operaciones en Pilas
            if (SeleccionarP()) {
            	system("cls");
				cout << "\t\t Operando en Pila 1.\n";
				P1.operacionesP();
            } else {
            	system("cls");
                cout << "\t\t Operando en Pila 2.\n";
            	P2.operacionesP();
            }
            
            system("PAUSE");
            system("cls");
            break;
        case 4:
            system("cls");
            if (SeleccionarP()) {
                cout << "\t\t Pila 1.\n";
                cout << "Ingrese el dato: ";
                cin >> dp;
                P1.insertarP(dp);
                dp = 0;
                system("cls");
            } else {
                cout << "\t\t Pila 2.\n";
                cout << "Ingrese el dato: ";
                cin >> dp;
                P2.insertarP(dp);
                dp = 0;
                system("cls");
            }
            break;
        case 5:
            system("cls");
            salir = true;
            break;
        default:
            system("cls");
            cout << "\t\t Ingresa una opcion valida.\n";
            system("PAUSE");
            system("cls");
            break;
        }
    } while (!salir);

    system("PAUSE");
    return EXIT_SUCCESS;
}













