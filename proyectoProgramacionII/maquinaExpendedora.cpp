#include <iostream>
#include <cstring>
#include <conio.h>
#include <ctype.h>

using namespace std;

void menuPrincipal();
void registrarProducto(int* contador);
void menuProducto();
void comprarproducto(int codigo);

struct Producto {
	int codigo;
	string nombre;
	int precio;
	int stock;
};

//limite de tipo de productos que se pueden almacenar 4*6
struct Producto arrayProducto [24];

//contador que aumenta cada que se agrega un tipo de producto 
int contadorProducto = 0;

int main(int argc, char** argv) {
	bool salir = false; 
	do{
		menuPrincipal();
		int opcion;
		opcion = getch();
		//1=49, 2=50 , 3=51
		switch(opcion){
			case 49:
				registrarProducto(&contadorProducto); 
				break;
			case 50:
				menuProducto();
				break;
			case 51:
				system ("cls");
				salir = true;
				break;
			default:
				system ("cls");
				cout << "\t     Seleccione una opcion valida" << endl; 
				cout << "\t\t(Enter para continuar)"; 
				getch();
				break;
		}
	}while(salir == false);		
	return 0;
}

// verifica si el codigo del producto ya esta 
int verificarCodigo(int codigo){
	for( int i = 0 ; i < contadorProducto; i++){
		if(arrayProducto[i].codigo == codigo ){
			return 1;
		}
	}
	if(codigo <= 999 && codigo > 0){
		return 0;
	}else{
		return 1;
	}
	
}

//funcion para ingresar los productos 
void registrarProducto(int* contador){
	// Y=121, N=110
	int respuesta = 0, temporalCodigo = 0;
	do{
		system ("cls");
		cout << "\t\tRegistrar productos" << endl;
		cout << "----------------------------------------------" << endl;
		if(contadorProducto < 24){
			cout << "Producto : " << contadorProducto + 1 << endl;
			cout << "Ingrese el codigo del producto (numerico max 3 cifras) = ";
			cin  >> temporalCodigo;
			cin.sync(); 
			int tempstk = 0;
			//if funciona con true o false (1 y 0)
			if( verificarCodigo(temporalCodigo) == 0){
				arrayProducto[contadorProducto].codigo = temporalCodigo;
				
				cout << "Ingrese el nombre del producto = ";
				getline(cin ,arrayProducto[contadorProducto].nombre);
			
				cout << "Ingrese el precio del producto = ";
				cin  >> arrayProducto[contadorProducto].precio;
			
				cout << "Ingrese el stock del producto = ";
				cin >> tempstk;
				cin.ignore();
				if(tempstk < 0){
					cout << endl <<"Stock del producto no valido "<< endl <<"\t\t (Enter para continuar)";
					getch();
					registrarProducto(contador);
				}else{
				arrayProducto[contadorProducto].stock = tempstk;
				tempstk = 0;	
				}
					
				contadorProducto++;
														
				if(contadorProducto < 24){
					cout << "Desea ingresar otro producto  Y/N ";
					respuesta = getch();
					cout << endl;
					}else{
						cout << "Ha llegado al limite de productos" << endl;
						cout << "\t\t(Enter para continuar)"; 
						getch();
						respuesta = 110;
					}
				}else{
					
					if(temporalCodigo > 999){
						cout << endl <<"Numero de cifras no valido "<< endl <<"\t\t (Enter para continuar)";
						getch();
						registrarProducto(contador);
					}else{
						cout << endl <<"El codigo ya ha sido registrado anteriormente intente otro."<< endl <<"\t\t (Enter para continuar)";
						getch();	
					}
		
					
				}
		}else{
			cout << "Ha llegado al limite de productos"; 
			cout << "\t\t(Enter para continuar)"; 
			getch();
			
		}
	
	}while(respuesta == 121);
}

//muestra los productos que hay en la maquina
void menuProducto(){
	system ("cls");
	//imprime los productos 
		int cont = 0;
	cout << "\t\tLista de productos" << endl;
	cout << "----------------------------------------------" << endl;
		for(int i = 0 ; i < 24 ; i++){
			//limitar nombre caracteres 
			
			//imprime los produtos
			if(cont < 3 ){
				cont++;
				cout << "["<< arrayProducto[i].codigo << "]" << arrayProducto[i].nombre << " $"<< arrayProducto[i].precio << "   " ; 	
			}else if (cont = 3){
				cout << "[" << arrayProducto[i].codigo << "]" << arrayProducto[i].nombre << "$"<< arrayProducto[i].precio << endl ; 
				cont=0;
			}
		}
		cout << "\n\tESC para regresar o otra tecla para comprar." << endl << endl;
		int opcion = getch();
		int eleccion;
		if(opcion == 27 ){
			menuPrincipal();
		}else if (opcion != 27){
			cout << "Ingrese un codigo: ";
			cin >> eleccion;	
			if(verificarCodigo(eleccion) == 1){
				comprarproducto(eleccion);
			}else{
				cout << "Codigo de producto invalido" << endl;
				cout << "\t\t(Enter para continuar)"; 
				getch();
				menuProducto();
			}
		}	
	system ("cls");
}

//comprar producto
void comprarproducto(int codigo){
	//identifica el producto
	int codigoCompra = 0;
	for(int i = 0 ; i < 24 ; i++ ){
		int temp = arrayProducto[codigo].codigo;
		if(temp == codigo)
			codigoCompra = temp;		
	}
	//menu compra
	int dinero = 0, tempdinero = 0, preciocompra = 0, opcion;
	int msg = 0;
	do{
		system ("cls");
		cout << "\t\tCompra productos" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Producto seleccionado : " << arrayProducto[codigoCompra].nombre << endl;
		cout << "Precio : " << arrayProducto[codigoCompra].precio << endl;
		cout << "Stock disponible : " << arrayProducto[codigoCompra].stock << endl;
		cout << "----------------------------------------------\n" << endl;
		if(msg == 0){
			cout << "\n\tESC para regresar o otra tecla para comprar." << endl << endl;
			opcion = getch();
			cout << "\e[A";	cout << "\e[A";	cout <<"\e[A";
			msg++;	
			
		}
		
		if(opcion == 27 ){
			dinero = 0;
			menuPrincipal();
		}
		if (opcion != 27){
			preciocompra = arrayProducto[codigoCompra].precio;
			cout << "Credito : " << dinero << endl;
			cout << "                                                      \r";
			cout << "Inserte dinero : ";
			cin >> tempdinero;
			if(tempdinero > 0){
		 		dinero += tempdinero;		
			}
		}
			
	}while(dinero < preciocompra);
	
	if(dinero >= preciocompra && dinero != 0){
		system ("cls");
		cout << "\t\tCompra realizada" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Producto seleccionado : " << arrayProducto[codigoCompra].nombre << endl;
		cout << "Precio : " << arrayProducto[codigoCompra].precio << endl;
		cout << "Credito : " << dinero << endl;
		cout << "Cambio : " << dinero - preciocompra << endl;
		cout << "----------------------------------------------" << endl;
		arrayProducto[codigoCompra].stock = arrayProducto[codigoCompra].stock - 1;
		if(arrayProducto[codigoCompra].stock == 0 ){
			for(int i = codigoCompra ; i < contadorProducto ; i++){
				arrayProducto[codigoCompra].nombre = arrayProducto[codigoCompra + 1].nombre;
				arrayProducto[codigoCompra].precio = arrayProducto[codigoCompra + 1].precio;
				arrayProducto[codigoCompra].stock = arrayProducto[codigoCompra + 1].stock;
				arrayProducto[codigoCompra].codigo = arrayProducto[codigoCompra + 1].codigo;
				contadorProducto--;
			}
		}
		cout << "\t\t(Enter para continuar)"; 
		getch();	
	}
	
}

//menu principal
void menuPrincipal(){
	system ("cls");	
	cout << "\t Menu principal maquina expendedora\n";
	cout << "|----------------------------------------|---------|" << endl;
	cout << "| ______________________________________ |         |" << endl;
	cout << "| |                                    | | credito |" << endl;
	cout << "| |                                    | | _______ |" << endl;
	cout << "| |                                    | ||       ||" << endl;	
	cout << "| |                                    | ||_______||" << endl;
	cout << "| |                                    | ||------ ||" << endl;
	cout << "| |                                    | ||1  2  3||" << endl;
	cout << "| |       1. Agregar productos.        | ||4  5  6||" << endl;
	cout << "| |       2. Ver lista de productos    | ||7  8  9||" << endl;
	cout << "| |          y comprar.                | ||*  0  #||" << endl;
	cout << "| |       3. Salir.                    | ||-------||" << endl;
	cout << "| |                                    | | o    __ |" << endl;
	cout << "| |                                    | | _______ |" << endl;
	cout << "| |                                    | ||_______||" << endl;
	cout << "| |                                    | ||_______||" << endl;
	cout << "| |                                    | |         |" << endl;
	cout << "| |                                    | |         |" << endl;
	cout << "| |                                    | |         |" << endl;
	cout << "| |                                    | |         |" << endl;
	cout << "| |____________________________________| |         |" << endl;
	cout << "|----------------------------------------|         |" << endl;
	cout << "|                 --------               |         |" << endl;
	cout << "|                  ------                |         |" << endl;	                                    
	cout << "|----------------------------------------|         |" << endl;
	cout << "|                                        |         |" << endl;
	cout << "|----------------------------------------|---------|" << endl;
	
}

