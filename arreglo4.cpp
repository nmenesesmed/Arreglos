#include <iostream>

using namespace std;

void rellenarArreglo(int arreglo[], int tamano, int multiplo) {
  for (int i = 0; i < tamano; i++) {
    arreglo[i] = multiplo * (i + 1);
  }
}

void mostrarArreglo(int arreglo[], int tamano) {
  for (int i = 0; i < tamano; i++) {
    cout << arreglo[i] << " ";
  }
}

int main() {
  int tamano;
  int multiplo;

  cout << "Ingrese el tamanio del arreglo: ";
  cin >> tamano;

  cout << "Ingrese el multiplo: ";
  cin >> multiplo;

  int arreglo[tamano];

  rellenarArreglo(arreglo, tamano, multiplo);

  mostrarArreglo(arreglo, tamano);

  return 0;
}