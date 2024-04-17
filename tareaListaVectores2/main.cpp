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
    void extraer();

    // Método para imprimir la lista con índices
    void imprimir();
    
    // Método para agregar un elemento al final de la lista
    void append(int valor);
    
    // Método para eliminar todos los elementos de la lista
    void clear(); 
    
    // Método para extender la lista con elementos de otra lista
    void extend(const Lista& otraLista); 
    
    // Método para contar cuántas veces aparece un valor en la lista
    void count(int valor); 
    
    // Método para encontrar el índice de la primera ocurrencia de un valor en la lista
    void index(int valor); 
    
    // Método para invertir el orden de los elementos en la lista
    void reverse(); 
    
    // Método para obtener la longitud actual de la lista
    void len(); 
	
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

    void Lista::extraer() {
    	if(tamano == 0 ){
    		cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			int posicion;
            cout << "Ingrese la posicion del elemento a extraer: ";
            cin >> posicion;
            
			if (posicion >= 0 && posicion < tamano) {
        	// Si la posición proporcionada está dentro de los límites válidos de la lista...
        		int valor = elementos[posicion]; // Almacena el valor en la posición especificada

        	// Desplazar los elementos a la izquierda para llenar el espacio
        	for (int i = posicion; i < tamano - 1; i++) {
            	elementos[i] = elementos[i + 1]; // Mueve cada elemento hacia la izquierda
        	}

        	tamano--; // Reduce el tamaño de la lista
        	cout << "Elemento extraído de la posición " << posicion << ": " << valor << endl; // Muestra el elemento extraído
        	cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
        	cin.get();    // Espera a que el usuario presione Enter
    		} else {
        	// Si la posición proporcionada está fuera de los límites válidos de la lista...
        		cout << "No se puede extraer en la posición especificada." << endl; // Muestra un mensaje de error
        		cout << "Presiona Enter para Continuar...";
        		cin.ignore(); // Limpia el búfer de entrada
        		cin.get();    // Espera a que el usuario presione Enter
    		}
		}
	}


    // Método para imprimir la lista con índices
    void Lista::imprimir() {
        cout << "Lista: ";
        for (int i = 0; i < tamano; i++) {
            cout << "[" << i << "]" << elementos[i] << ", "; // Imprime el índice y el valor
        }
        cout << endl;
        cout << "Presiona Enter para Continuar...";
        cin.ignore(); // Limpia el búfer de entrada
    	cin.get();    // Espera a que el usuario presione Enter
    }
	// Método para agregar un elemento al final de la lista
	void Lista::append(int valor) {
    	if (tamano < MAX_TAMANO) {
        	elementos[tamano] = valor; // Agregar el valor al final de la lista
        	tamano++; // Aumentar el tamaño de la lista
    	} else {
        cout << "No se puede agregar más elementos, la lista está llena." << endl;
    	}
	}
	
	// Método para eliminar todos los elementos de la lista
	void Lista::clear() {
    	for (int i = 0; i < tamano; i++) {
        	elementos[i] = 0; // Establecer todos los elementos a 0
    	}
    	tamano = 0; // Establecer el tamaño de la lista a cero
	}
	
	// Método para contar cuántas veces aparece un valor en la lista
	void Lista::count(int valor) {
		if(tamano == 0 ){
			cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			int contador = 0; // Inicializa el contador para llevar un registro de las ocurrencias
    		for (int i = 0; i < tamano; i++) {
        		if (elementos[i] == valor) {
            		contador++; // Incrementa el contador cuando se encuentra una ocurrencia del valor en la lista
        		}
    		}
		cout << "El valor se encontro " << contador << " en la lista" << endl; // Devuelve el contador que representa la cantidad de veces que aparece el valor en la lista
		cout << "Presiona Enter para Continuar...";
        cin.ignore(); // Limpia el búfer de entrada
        cin.get();    // Espera a que el usuario presione Enter
		}
    	
	}
	
	// Método para encontrar el índice de la primera ocurrencia de un valor en la lista
	void Lista::index(int valor) {
		bool esta = false;
		if(tamano == 0 ){
			cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			for (int i = 0; i < tamano; i++) {
        		if (elementos[i] == valor) {
        			esta = true; // Verificar si se encontro el valor
            		cout << "El valor se encuentra en el indice " << i << " de la lista" << endl; // Devolver el índice de la primera ocurrencia del valor
            		cout << "Presiona Enter para Continuar...";
            		cin.ignore(); // Limpia el búfer de entrada
            		cin.get();    // Espera a que el usuario presione Enter
            		break;
        		}
    		}
		}
		if(esta = false ){
			cout << "El valor no se encontro en la lista" << endl;
    		cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
        	cin.get();   // Espera a que el usuario presione Enter
		}
		
	}
	
	// Método para invertir el orden de los elementos en la lista
	void Lista::reverse() {
		if(tamano == 0){
			cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			int inicio = 0; // Establece un índice de inicio al comienzo de la lista
   			int fin = tamano - 1; // Establece un índice de fin al final de la lista
    		while (inicio < fin) { // Inicia un bucle while para invertir la lista
        		int temp = elementos[inicio]; // Almacena temporalmente el elemento en la posición de inicio
        		elementos[inicio] = elementos[fin]; // Copia el elemento en la posición de fin en la posición de inicio
        		elementos[fin] = temp; // Copia el elemento temporal (originalmente en inicio) en la posición de fin
        		inicio++; // Incrementa el índice de inicio
        		fin--; // Decrementa el índice de fin
			}
			cout << "Lista invertida" << endl;
    		cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el búfer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
    	}
	}

	// Método para obtener la longitud actual de la lista
	void Lista::len() {
    	cout << "El tamaño de la lista es: " << tamano << endl; // Devolver el tamaño actual de la lista (cantidad de elementos)
    	cout << "Presiona Enter para Continuar...";
        cin.ignore(); // Limpia el búfer de entrada
    	cin.get();    // Espera a que el usuario presione Enter
	}
	
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
	cout << ">Se desarrollaron los metodos :append, clear, extend, count, index, reverse, len." << endl;
	cout << ">El tamaño de la lista aumenta o disminuye." << endl;
	cout << "Presiona Enter para Continuar...";
    cin.get();    // Espera a que el usuario presione Enter
}

int main() {
    setlocale(LC_ALL, "");
    Lista miLista;
    int opcion;
    int valor, posicion;
    bool ejecutar = true; // Variable para controlar la ejecución del bucle
    Ejercicio();

    while (ejecutar) {
        system("cls"); // Llamada a un posible método para limpiar la pantalla
        cout << endl << "\t\tMenu:" << endl;
        cout << "1. Insertar elemento en la lista" << endl;
        cout << "2. Extraer elemento de la lista" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "4. Append" << endl;
        cout << "5. Clear" << endl;
        cout << "6. Count" << endl;
        cout << "7. Index" << endl;
        cout << "8. Reverse" << endl;
        cout << "9. Len" << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                cout << "Ingrese la posicion de insercion: ";
                cin >> posicion;
                miLista.insertar(valor, posicion);
                break;
            }
            case 2: {
                miLista.extraer();
                break;
            }
            case 3:
                miLista.imprimir();
                break;
            case 4:
            	cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                miLista.append(valor);
                break;
            case 5:
                miLista.clear();
                break;
            case 6:
            	cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                miLista.count(valor);
                break;
			case 7:
				cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                miLista.index(valor);
                break;
			case 8:
                miLista.reverse();
                break;
            case 9:
            	miLista.len();
            	break;
            case 10:
                ejecutar = false; // Establecer la variable ejecutar en falso para salir del bucle
                break;
            default:
                cin.clear();
                cin.ignore();
                cout << "Opcion no valida." << endl;
                cout << "Presiona Enter para Continuar...";
                cin.ignore();
                cin.get();
                break;
        }
    }

    return 0;
}
