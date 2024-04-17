#include <iostream>
#include <iomanip>
using namespace std;

// Definición de la estructura alumno
struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    // Declaración de un array de 3 alumnos
    struct Alumno alumnos[3];

    // Solicitar datos al usuario para cada alumno
    for (int i = 0; i < 3; i++) {
        cout << "Ingrese los datos del alumno " << i + 1 << ":\n";

        cout << "Nombre: ";
        cin >> alumnos[i].nombre;

        cout << "Edad: ";
        cin >> alumnos[i].edad;

        cout << "Promedio: ";
        cin >> alumnos[i].promedio;

        cout << "\n";
    }

    // Encontrar al alumno con el mejor promedio
    int indiceMejorPromedio = 0;
    for (int i = 1; i < 3; i++) {
        if (alumnos[i].promedio > alumnos[indiceMejorPromedio].promedio) {
            indiceMejorPromedio = i;
        }
    }

    // Imprimir los datos del alumno con mejor promedio
    cout << "Datos del alumno con mejor promedio:\n";
    cout << "Nombre: " << alumnos[indiceMejorPromedio].nombre << "\n";
    cout << "Edad: " << alumnos[indiceMejorPromedio].edad << "\n";
    cout << "Promedio: " << fixed << setprecision(1) << alumnos[indiceMejorPromedio].promedio << "\n";

    return 0;
}

