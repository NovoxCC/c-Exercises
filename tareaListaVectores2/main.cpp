#include <iostream>
using namespace std;

const int MAX_TAMANO = 5; // Tama�o m�ximo de la lista

class Lista {
private:
    int elementos[MAX_TAMANO];
    int tamano;

public:
	
	// Constructor
    Lista();

    // Destructor
    ~Lista();

    // M�todo para insertar un elemento en la lista en una posici�n espec�fica
    void insertar(int valor, int posicion);

    // M�todo para extraer un elemento de la lista en una posici�n espec�fica
    void extraer();

    // M�todo para imprimir la lista con �ndices
    void imprimir();
    
    // M�todo para agregar un elemento al final de la lista
    void append(int valor);
    
    // M�todo para eliminar todos los elementos de la lista
    void clear(); 
    
    // M�todo para extender la lista con elementos de otra lista
    void extend(const Lista& otraLista); 
    
    // M�todo para contar cu�ntas veces aparece un valor en la lista
    void count(int valor); 
    
    // M�todo para encontrar el �ndice de la primera ocurrencia de un valor en la lista
    void index(int valor); 
    
    // M�todo para invertir el orden de los elementos en la lista
    void reverse(); 
    
    // M�todo para obtener la longitud actual de la lista
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
		No es necesario realizar ninguna limpieza espec�fica en este caso,
		como no se realiza ninguna asignaci�n din�mica de memoria ni se 
		utilizan recursos externos, el destructor es opcional y no es necesario 
		realizar ninguna operaci�n espec�fica de limpieza.
        */
    }

    /*
    M�todo para insertar un elemento en la lista en una posici�n espec�fica
	Se realiza una verificaci�n para asegurarse de que la lista no est� llena (tamano < MAX_TAMANO) y de que la posici�n proporcionada sea v�lida (posicion >= 0 y posicion <= tamano).
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
            cin.ignore(); // Limpia el b�fer de entrada
            cin.get();    // Espera a que el usuario presione Enter
        } else {
            cout << "No se puede insertar en la posicion especificada." << endl;
            cout << "Presiona Enter para Continuar...";
            cin.ignore(); // Limpia el b�fer de entrada
            cin.get();    // Espera a que el usuario presione Enter
        }
    }

    void Lista::extraer() {
    	if(tamano == 0 ){
    		cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			int posicion;
            cout << "Ingrese la posicion del elemento a extraer: ";
            cin >> posicion;
            
			if (posicion >= 0 && posicion < tamano) {
        	// Si la posici�n proporcionada est� dentro de los l�mites v�lidos de la lista...
        		int valor = elementos[posicion]; // Almacena el valor en la posici�n especificada

        	// Desplazar los elementos a la izquierda para llenar el espacio
        	for (int i = posicion; i < tamano - 1; i++) {
            	elementos[i] = elementos[i + 1]; // Mueve cada elemento hacia la izquierda
        	}

        	tamano--; // Reduce el tama�o de la lista
        	cout << "Elemento extra�do de la posici�n " << posicion << ": " << valor << endl; // Muestra el elemento extra�do
        	cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
        	cin.get();    // Espera a que el usuario presione Enter
    		} else {
        	// Si la posici�n proporcionada est� fuera de los l�mites v�lidos de la lista...
        		cout << "No se puede extraer en la posici�n especificada." << endl; // Muestra un mensaje de error
        		cout << "Presiona Enter para Continuar...";
        		cin.ignore(); // Limpia el b�fer de entrada
        		cin.get();    // Espera a que el usuario presione Enter
    		}
		}
	}


    // M�todo para imprimir la lista con �ndices
    void Lista::imprimir() {
        cout << "Lista: ";
        for (int i = 0; i < tamano; i++) {
            cout << "[" << i << "]" << elementos[i] << ", "; // Imprime el �ndice y el valor
        }
        cout << endl;
        cout << "Presiona Enter para Continuar...";
        cin.ignore(); // Limpia el b�fer de entrada
    	cin.get();    // Espera a que el usuario presione Enter
    }
	// M�todo para agregar un elemento al final de la lista
	void Lista::append(int valor) {
    	if (tamano < MAX_TAMANO) {
        	elementos[tamano] = valor; // Agregar el valor al final de la lista
        	tamano++; // Aumentar el tama�o de la lista
    	} else {
        cout << "No se puede agregar m�s elementos, la lista est� llena." << endl;
    	}
	}
	
	// M�todo para eliminar todos los elementos de la lista
	void Lista::clear() {
    	for (int i = 0; i < tamano; i++) {
        	elementos[i] = 0; // Establecer todos los elementos a 0
    	}
    	tamano = 0; // Establecer el tama�o de la lista a cero
	}
	
	// M�todo para contar cu�ntas veces aparece un valor en la lista
	void Lista::count(int valor) {
		if(tamano == 0 ){
			cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
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
        cin.ignore(); // Limpia el b�fer de entrada
        cin.get();    // Espera a que el usuario presione Enter
		}
    	
	}
	
	// M�todo para encontrar el �ndice de la primera ocurrencia de un valor en la lista
	void Lista::index(int valor) {
		bool esta = false;
		if(tamano == 0 ){
			cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			for (int i = 0; i < tamano; i++) {
        		if (elementos[i] == valor) {
        			esta = true; // Verificar si se encontro el valor
            		cout << "El valor se encuentra en el indice " << i << " de la lista" << endl; // Devolver el �ndice de la primera ocurrencia del valor
            		cout << "Presiona Enter para Continuar...";
            		cin.ignore(); // Limpia el b�fer de entrada
            		cin.get();    // Espera a que el usuario presione Enter
            		break;
        		}
    		}
		}
		if(esta = false ){
			cout << "El valor no se encontro en la lista" << endl;
    		cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
        	cin.get();   // Espera a que el usuario presione Enter
		}
		
	}
	
	// M�todo para invertir el orden de los elementos en la lista
	void Lista::reverse() {
		if(tamano == 0){
			cout << "La lista esta vacia" << endl;
			cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
		}else{
			int inicio = 0; // Establece un �ndice de inicio al comienzo de la lista
   			int fin = tamano - 1; // Establece un �ndice de fin al final de la lista
    		while (inicio < fin) { // Inicia un bucle while para invertir la lista
        		int temp = elementos[inicio]; // Almacena temporalmente el elemento en la posici�n de inicio
        		elementos[inicio] = elementos[fin]; // Copia el elemento en la posici�n de fin en la posici�n de inicio
        		elementos[fin] = temp; // Copia el elemento temporal (originalmente en inicio) en la posici�n de fin
        		inicio++; // Incrementa el �ndice de inicio
        		fin--; // Decrementa el �ndice de fin
			}
			cout << "Lista invertida" << endl;
    		cout << "Presiona Enter para Continuar...";
        	cin.ignore(); // Limpia el b�fer de entrada
    		cin.get();    // Espera a que el usuario presione Enter
    	}
	}

	// M�todo para obtener la longitud actual de la lista
	void Lista::len() {
    	cout << "El tama�o de la lista es: " << tamano << endl; // Devolver el tama�o actual de la lista (cantidad de elementos)
    	cout << "Presiona Enter para Continuar...";
        cin.ignore(); // Limpia el b�fer de entrada
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
	cout << ">El tama�o de la lista aumenta o disminuye." << endl;
	cout << "Presiona Enter para Continuar...";
    cin.get();    // Espera a que el usuario presione Enter
}

int main() {
    setlocale(LC_ALL, "");
    Lista miLista;
    int opcion;
    int valor, posicion;
    bool ejecutar = true; // Variable para controlar la ejecuci�n del bucle
    Ejercicio();

    while (ejecutar) {
        system("cls"); // Llamada a un posible m�todo para limpiar la pantalla
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
