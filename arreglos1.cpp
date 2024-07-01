#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Ingresa la cantidad de elementos del arreglo: ";
    cin >> n ;
    int arr[n];
     for (int i = 0 ; i < n ; i++){
        cout << "Ingresa el elemento " << i + 1 << " : ";
        cin >> arr[i];
     }

     int sum = 0;
     int cont_ceros = 0;

     for (int i = 0 ; i < n ; i++){
        sum += arr[i];

        if (arr[i] ==0 ){
            cont_ceros++;
        }
     }
     double porc_ceros = (double) cont_ceros/ n * 100;
     cout << "La sumatoria de todos los elementos es: " << sum << endl;
     cout << "El porcentaje de los valores cero ingresados es: " << porc_ceros <<"%" << endl;

    return 0;
}