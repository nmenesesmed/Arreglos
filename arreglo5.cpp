#include <iostream>
#include <string>
using namespace std;

void ingresarNombres(string* clase, int cantidad, const string& nombreClase) {
    cout << "Ingrese los nombres de los estudiantes de " << nombreClase << ":\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << "Estudiante " << i + 1 << ": ";
        cin >> clase[i];
    }
}

int encontrarComunes(string* clase1, int cantidad1, string* clase2, int cantidad2, string* comunes) {
    int contador = 0;
    for (int i = 0; i < cantidad1; ++i) {
        for (int j = 0; j < cantidad2; ++j) {
            if (clase1[i] == clase2[j]) {
                comunes[contador++] = clase1[i];
                break;
            }
        }
    }
    return contador;
}

int main() {
    int cantidadFundamentos, cantidadGrafica;
    
    cout << "Ingrese la cantidad de estudiantes en Fundamentos de Programacion: ";
    cin >> cantidadFundamentos;
    string* fundamentos = new string[cantidadFundamentos];

    cout << "Ingrese la cantidad de estudiantes en Programacion Grafica: ";
    cin >> cantidadGrafica;
    string* grafica = new string[cantidadGrafica];
    
    ingresarNombres(fundamentos, cantidadFundamentos, "Fundamentos de Programacion");
    ingresarNombres(grafica, cantidadGrafica, "Programacion Grafica");
    
    // El peor caso es que todos los estudiantes son comunes, entonces usamos el tamaño máximo posible
    string* comunes = new string[cantidadFundamentos < cantidadGrafica ? cantidadFundamentos : cantidadGrafica];
    int cantidadComunes = encontrarComunes(fundamentos, cantidadFundamentos, grafica, cantidadGrafica, comunes);
    
    cout << "Estudiantes comunes en ambas asignaturas:\n";
    for (int i = 0; i < cantidadComunes; ++i) {
        cout << comunes[i] << endl;
    }
    cout << "Cantidad de estudiantes comunes: " << cantidadComunes << endl;

    delete[] fundamentos;
    delete[] grafica;
    delete[] comunes;

    return 0;
}
