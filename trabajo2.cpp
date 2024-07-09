#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void llenarVector(int vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        vec[i] = rand() % 201 - 100;
    }
}

void mostrarVector(const int vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void sumarVectores(const int vecA[], const int vecB[], int vecC[], int tam) {
    for (int i = 0; i < tam; i++) {
        vecC[i] = vecA[i] + vecB[i];
    }
}

void restarVectores(const int vecA[], const int vecB[], int vecC[], int tam) {
    for (int i = 0; i < tam; i++) {
        vecC[i] = vecA[i] - vecB[i];
    }
}

int main() {
    srand(time(0));
    int tam;

    cout << "Ingrese la longitud de los vectores: "; cin >> tam;

    int *vecA = new int[tam];
    int *vecB = new int[tam];
    int *vecC = new int[tam];

    int opcion;
    bool llenadoA = false, llenadoB = false, calculadoC = false;

    do {
        cout << "\nMenu:\n";
        cout << "1. Llenar Vector A de manera aleatoria\n";
        cout << "2. Llenar Vector B de manera aleatoria\n";
        cout << "3. Realizar C = A + B\n";
        cout << "4. Realizar C = A - B\n";
        cout << "5. Mostrar (Permitiendo al usuario elegir entre el Vector A, B o C)\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: "; cin >> opcion;

        switch (opcion) {
            case 1:
                llenarVector(vecA, tam);
                llenadoA = true;
                cout << "Vector A lleno de manera aleatoria.\n";
                break;

            case 2:
                llenarVector(vecB, tam);
                llenadoB = true;
                cout << "Vector B lleno de manera aleatoria.\n";
                break;

            case 3:
                if (llenadoA && llenadoB) {
                    sumarVectores(vecA, vecB, vecC, tam);
                    calculadoC = true;
                    cout << "Operacion C = A + B realizada.\n";
                } else {
                    cout << "Debe llenar ambos vectores A y B antes de realizar esta operacion.\n";
                }
                break;

            case 4:
                if (llenadoA && llenadoB) {
                    restarVectores(vecA, vecB, vecC, tam);
                    calculadoC = true;
                    cout << "Operacion C = A - B realizada.\n";
                } else {
                    cout << "Debe llenar ambos vectores A y B antes de realizar esta operacion.\n";
                }
                break;

            case 5:
                if (!llenadoA && !llenadoB && !calculadoC) {
                    cout << "Debe llenar al menos uno de los vectores o realizar una operacion antes de mostrar.\n";
                } else {
                    int opcionMostrar;
                    cout << "Seleccione el vector a mostrar (1 para A, 2 para B, 3 para C): ";
                    cin >> opcionMostrar;

                    switch (opcionMostrar) {
                        case 1:
                            if (llenadoA) {
                                cout << "Vector A: ";
                                mostrarVector(vecA, tam);
                            } else {
                                cout << "Vector A no ha sido llenado.\n";
                            }
                            break;

                        case 2:
                            if (llenadoB) {
                                cout << "Vector B: ";
                                mostrarVector(vecB, tam);
                            } else {
                                cout << "Vector B no ha sido llenado.\n";
                            }
                            break;

                        case 3:
                            if (calculadoC) {
                                cout << "Vector C: ";
                                mostrarVector(vecC, tam);
                            } else {
                                cout << "Vector C no ha sido calculado.\n";
                            }
                            break;

                        default:
                            cout << "Opcion no valida.\n";
                    }
                }
                break;

            case 6:
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    delete[] vecA;
    delete[] vecB;
    delete[] vecC;

    return 0;
}