#include <iostream>
#include <cmath>
using namespace std;

double calcularPromedio(int datos[], int n) {
  double suma = 0;
  for (int i = 0; i < n; i++) {
    suma += datos[i];
  }
  return suma / n;
}

double calcularDesviacionTipica(int datos[], int n, double promedio) {
  double sumaCuadradaDiferencias = 0;
  for (int i = 0; i < n; i++) {
    double diferencia = datos[i] - promedio;
    sumaCuadradaDiferencias += diferencia * diferencia;
  }
  return sqrt(sumaCuadradaDiferencias / n);
}

int main() {
  int n;

  cout << "Ingrese el numero de datos: "; cin >> n;

  if (n <= 0) {
    cout << "Error: El numero de datos debe ser positivo." << endl;
    return 1;
  }

  int datos[n];

  for (int i = 0; i < n; i++) {
    cout << "Ingrese el dato " << i + 1 << ": ";
    cin >> datos[i];

    while (datos[i] <= 0) {
      cout << "Error: El dato debe ser positivo. Ingrese nuevamente: ";
      cin >> datos[i];
    }
  }

  double promedio = calcularPromedio(datos, n);

  double desviacionTipica = calcularDesviacionTipica(datos, n, promedio);

  cout << endl;
  cout << "Promedio general: " << promedio << endl;
  cout << "Desviacion tipica: " << desviacionTipica << endl;

  return 0;
}