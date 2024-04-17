#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Clase para representar un producto
class Producto {
public:
    int codigo;
    string nombre;
    int precio;

    Producto(int cod, const string& nom, int prec)
        : codigo(cod), nombre(nom), precio(prec) {}
};

// Clase Pedido actualizada
class Pedido {
public:
    int numeroDePedido;
    string nombreCliente;
    vector<pair<Producto, int>> productos;  // Pares de Producto y cantidad

    Pedido(int numero, const string& nombre)
        : numeroDePedido(numero), nombreCliente(nombre) {}

    // Método para agregar un producto con una cantidad específica a la orden
    void agregarProducto(const Producto& producto, int cantidad) {
        productos.push_back(make_pair(producto, cantidad));
    }

    // Método para guardar la orden en un archivo
    void guardarPedido() {
        ofstream archivo("orden_" + to_string(numeroDePedido) + ".txt");
        if (archivo.is_open()) {
            archivo << "Orden #" << numeroDePedido << " para " << nombreCliente << ":" << endl;
            for (const auto& par : productos) {
                archivo << par.second << "x " << par.first.nombre << " - $" << par.first.precio << " c/u" << endl;
            }
            archivo << "Total: $" << calcularTotal() << endl;
            archivo << "-----------------------" << endl;
            archivo.close();
        } else {
            cout << "No se pudo crear el archivo de la orden." << endl;
        }
    }

    // Método para calcular el total de la orden
    int calcularTotal() const {
        int total = 0;
        for (const auto& par : productos) {
            total += par.second * par.first.precio;
        }
        return total;
    }
};

class ColaPedido {
public:
    // Estructura de nodo para la cola
    struct Nodo {
        Pedido* pedido;
        Nodo* siguiente;

        Nodo(Pedido* p) : pedido(p), siguiente(nullptr) {}
    };

    Nodo* frente;
    Nodo* final;

    ColaPedido() : frente(nullptr), final(nullptr) {}

    void agregarPedido(Pedido* pedido) {
        Nodo* nuevoNodo = new Nodo(pedido);
        if (final == nullptr) {
            frente = nuevoNodo;
            final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    Pedido* tomarSiguientePedido() {
        if (frente == nullptr) {
            return nullptr;
        }

        Pedido* pedido = frente->pedido;
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
        return pedido;
    }
};

int main() {
    ColaPedido cola;

    // Lista de productos disponibles
    vector<Producto> productosDisponibles = {
        {1, "Cafe Espresso", 2},
        {2, "Cafe Americano", 2},
        {3, "Cappuccino", 3},
        {4, "Latte", 4},
        {5, "Mocha", 4},
        {6, "Te Negro", 2},
        {7, "Te Verde", 2},
        {8, "Te de Hierbas", 2},
        {9, "Croissant", 3},
        {10, "Galleta", 1},
        {11, "Muffin de Arandanos", 3},
        {12, "Bagel con Queso Crema", 3},
        {13, "Donut", 2},
        {14, "Sandwich de Pollo", 5},
        {15, "Sandwich Vegetariano", 4},
        {16, "Tarta de Chocolate", 4},
        {17, "Zumo de Naranja", 2},
        {18, "Agua Mineral", 1},
        {19, "Sandwich de Pavo", 4},
    };

      while (true) {
      	system("cls");
        cout << "Sistema de ordenes de una cafeteria" << endl;
        cout << "-------------------------" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Ordenar" << endl;
        cout << "2. Cocinar" << endl;
        cout << "3. Salir" << endl;
        cout << "-------------------------" << endl;
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Pedido* nuevoPedido = new Pedido(cola.frente == nullptr ? 1 : cola.final->pedido->numeroDePedido + 1, "Cliente");

                while (true) {
                	system("cls");
                	cout << "Sistema de ordenes de una cafeteria" << endl;
        			cout << "--------------------------------------------------" << endl;
                    cout << "Cliente, elija un producto de la lista:" << endl;
                    cout << "--------------------------------------------------" << endl;
                    for (const Producto& producto : productosDisponibles) {
                        cout << "Codigo: " << producto.codigo << ", Nombre: " << producto.nombre << ", Precio: $" << producto.precio << endl;
                    }
					cout << "--------------------------------------------------" << endl;
                    int codigoElegido;
                    cout << "Ingrese el codigo del producto deseado: ";
                    cin >> codigoElegido;

                    Producto productoElegido(0, "", 0);
                    bool productoEncontrado = false;
                    for (const Producto& producto : productosDisponibles) {
                        if (producto.codigo == codigoElegido) {
                            productoElegido = producto;
                            productoEncontrado = true;
                            break;
                        }
                    }

                    if (!productoEncontrado) {
                        cout << "Codigo de producto no valido. Intente nuevamente." << endl;
                        continue;
                    }

                    int cantidad;
                    cout << "Ingrese la cantidad deseada: ";
                    cin >> cantidad;
                    

                    nuevoPedido->agregarProducto(productoElegido, cantidad);

                    char continuar;
                    cout << "¿Desea agregar otro producto? (S/N): ";
                    cin >> continuar;

                    if (continuar != 'S' && continuar != 's') {
                        break;
                    }
                }

                cola.agregarPedido(nuevoPedido);
                nuevoPedido->guardarPedido();
                break;
            }
            case 2: {
            	system("cls");
            	cout << "Sistema de ordenes de una cafeteria" << endl;
        		cout << "--------------------------------------------------" << endl;
                cout << "Pedidos en espera:" << endl;
				cout << "--------------------------------------------------" << endl;
                int count = 0;
                ColaPedido::Nodo* temp = cola.frente;
                while (temp != nullptr && count < 3) {
                    cout << "Pedido #" << temp->pedido->numeroDePedido << " para " << temp->pedido->nombreCliente << endl;

                    // Mostrar contenido del pedido
                    for (const auto& par : temp->pedido->productos) {
                        cout << par.second << "x " << par.first.nombre << " - $" << par.first.precio << " c/u" << endl;
                    }

                    temp = temp->siguiente;
                    count++;

                    cout << "-------------------------" << endl;
                }

                cout << "Seleccione una opcion:" << endl;
                cout << "1. Volver al menu inicial" << endl;
                cout << "2. Despachar orden" << endl;
                cout << "-------------------------" << endl;
                int opcionCocina;
                cin >> opcionCocina;

                switch (opcionCocina) {
                    case 1: {
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el numero de la orden a despachar: ";
                        int numeroOrden;
                        cin >> numeroOrden;

                        ColaPedido::Nodo* nodoDespachar = cola.frente;
                        ColaPedido::Nodo* nodoAnterior = nullptr;

                        while (nodoDespachar != nullptr) {
                            if (nodoDespachar->pedido->numeroDePedido == numeroOrden) {
                                cout << "Despachando orden #" << nodoDespachar->pedido->numeroDePedido << " para " << nodoDespachar->pedido->nombreCliente << endl;

                                if (nodoAnterior == nullptr) {
                                    cola.frente = nodoDespachar->siguiente;
                                } else {
                                    nodoAnterior->siguiente = nodoDespachar->siguiente;
                                }

                                delete nodoDespachar->pedido;
                                delete nodoDespachar;
                                system("pause");
                                break;
                            }

                            nodoAnterior = nodoDespachar;
                            nodoDespachar = nodoDespachar->siguiente;
                        }

                        if (nodoDespachar == nullptr) {
                            cout << "Orden no encontrada." << endl;
                            system("pause");
                            
                        }

                        break;
                    }
                    default: {
                        cout << "Opcion no válida." << endl;
                        system("pause");
                        break;
                    }
                }

                break;
            }
            case 3: {
                return 0; // Terminar el programa
            }
            default: {
                cout << "Opcion no valida. Intente nuevamente." << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
