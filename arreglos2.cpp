#include <iostream>

using namespace std;

void separarParesImpares(int arr[], int n, int evenArr[], int& evenCount, int oddArr[], int& oddCount) {
  evenCount = 0; //even : par
  oddCount = 0; //odd : impar

  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenArr[evenCount++] = arr[i];
    } else {
      oddArr[oddCount++] = arr[i];
    }
  }
}

int main() {
  int n;
  cout << "Ingrese la cantidad de elementos del arreglo: ";
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cout << "Ingrese el elemento " << i + 1 << ": ";
    cin >> arr[i];
  }

  int evenArr[n], oddArr[n];
  int evenCount, oddCount;

  separarParesImpares(arr, n, evenArr, evenCount, oddArr, oddCount);

  cout << "Arreglo de pares: ";
  for (int i = 0; i < evenCount; i++) {
    cout << evenArr[i] << " ";
  }

  cout << endl << "Arreglo de impares: ";
  for (int i = 0; i < oddCount; i++) {
    cout << oddArr[i] << " ";
  }

  return 0;
}
