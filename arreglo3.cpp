#include <iostream>
using namespace std;

int main() {
  double temperaturas[100];
  double temperaturaMaxima = temperaturas[0];
  int diasTemperaturaMaxima[100] = {0};

  for (int i = 0; i < 7; i++) {
    cout << "Ingrese la temperatura para el dia " << i + 1 << ": ";
    cin >> temperaturas[i];

    if (temperaturas[i] > temperaturaMaxima) {
      temperaturaMaxima = temperaturas[i];
      for (int j = 0; j < 7; j++) {
        diasTemperaturaMaxima[j] = 0;
      }
      diasTemperaturaMaxima[i] = 1;
    } else if (temperaturas[i] == temperaturaMaxima) {
      diasTemperaturaMaxima[i] = 1;
    }
  }

  cout << "Temperatura maxima: " << temperaturaMaxima << endl;
  cout << "Dias con temperatura maxima: ";

  bool primerDia = true;
  for (int i = 0; i < 7; i++) {
    if (diasTemperaturaMaxima[i] == 1) {
      if (!primerDia) {
        cout << ", ";
      }
      cout << "Dia " << i + 1;
      primerDia = false;
    }
  }

  if (primerDia) {
    cout << "Ninguno";
  }

  cout << endl;

  return 0;
}