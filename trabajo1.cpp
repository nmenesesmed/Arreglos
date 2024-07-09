#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MESES = 12;
    string meses[MESES] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    double ventas[MESES];
    double sumaVentas = 0.0;
    double promedioVentas;
    int contadorMinimo = 0, contadorRegular = 0, contadorExcelente = 0;

    for (int i = 0; i < MESES; ++i) {
        cout << "Ingrese las ventas de " << meses[i] << ": ";
        cin >> ventas[i];
        sumaVentas += ventas[i];
    }

    promedioVentas = sumaVentas / MESES;

    cout << "Meses con ventas Excelentes: " << endl;
    for (int i = 0; i < MESES; ++i) {
        if (ventas[i] < 0.40 * promedioVentas) {
            contadorMinimo++;
        } else if (ventas[i] >= 0.40 * promedioVentas && ventas[i] <= 0.75 * promedioVentas) {
            contadorRegular++;
        } else if (ventas[i] > 0.75 * promedioVentas) {
            contadorExcelente++;
            cout << meses[i] << endl;
        }
    }

    cout << "Valor de la venta mensual promedio: " << promedioVentas << endl;
    cout << "Porcentaje de meses con ventas Minimas: " << (contadorMinimo * 100.0 / MESES) << "%" << endl;
    cout << "Porcentaje de meses con ventas Regulares: " << (contadorRegular * 100.0 / MESES) << "%" << endl;
    cout << "Porcentaje de meses con ventas Excelentes: " << (contadorExcelente * 100.0 / MESES) << "%" << endl;

    return 0;
}
