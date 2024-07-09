#include <iostream>
#include <cstdlib>
#include <ctime>  // Incluir la librería <ctime> para time

using namespace std;

int main() {
  int n, min, max;
  cout << "Ingrese el numero de valores aleatorios: "; 
  cin >> n;
  cout << "Ingrese el rango minimo: "; 
  cin >> min;
  cout << "Ingrese el rango maximo: "; 
  cin >> max;

  if (min > max) {
    cout << "Error: El rango minimo no puede ser mayor que el rango maximo." << endl;
    return 1;
  }

  srand(static_cast<unsigned int>(time(NULL)));  // Utilizar time(NULL) y convertir a unsigned int

  int* valoresAleatorios = new int[n];

  for (int i = 0; i < n; i++) {
    valoresAleatorios[i] = rand() % (max - min + 1) + min;
  }

  cout << endl << "Valores aleatorios:" << endl;
  for (int i = 0; i < n; i++) {
    cout << valoresAleatorios[i] << " ";
  }
  cout << endl;

  int frecuencias[max - min + 1];

  for (int i = min; i <= max; i++) {
    frecuencias[i - min] = 0;
  }

  for (int i = 0; i < n; i++) {
    int valor = valoresAleatorios[i];
    frecuencias[valor - min]++;
}


  cout << endl << "Tabla de frecuencias:" << endl;
  for (int i = min; i <= max; i++) {
    cout << i << ": " << frecuencias[i - min] << endl;
  }

  delete[] valoresAleatorios;

  return 0;
}