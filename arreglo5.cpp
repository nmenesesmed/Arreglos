#include <iostream>

using namespace std;

void obtenerNombres(char asignatura[], char nombres[][20], int *cantidad) {
  cout << "Ingrese los nombres de los alumnos de " << asignatura << ": ";

  int i = 0;
  char nombre[20];

  while (cin.getline(nombre, 20) && nombre[0] != '\0') {
    strcpy(nombres[i], nombre);
    i++;
  }

  *cantidad = i;
}

void obtenerAlumnosComunes(char nombresClase1[][20], int cantidadClase1, char nombresClase2[][20], int cantidadClase2, char alumnosComunes[][20], int *cantidadComunes) {
  *cantidadComunes = 0;

  for (int i = 0; i < cantidadClase1; i++) {
    for (int j = 0; j < cantidadClase2; j++) {
      if (strcmp(nombresClase1[i], nombresClase2[j]) == 0) {
        strcpy(alumnosComunes[*cantidadComunes], nombresClase1[i]);
        *cantidadComunes += 1;
        break;
      }
    }
  }
}

void mostrarAlumnosComunes(char alumnosComunes[][20], int cantidadComunes) {
  if (cantidadComunes == 0) {
    cout << "No hay alumnos comunes en las dos asignaturas." << endl;
  } else {
    cout << "Alumnos comunes: ";

    for (int i = 0; i < cantidadComunes; i++) {
      cout << alumnosComunes[i] << ", ";
    }

    cout << endl;
    cout << "Cantidad de alumnos comunes: " << cantidadComunes << endl;
  }
}

int main() {
  char nombresFundamentosProgramacion[20][20];
  char nombresProgramacionGrafica[20][20];

  int cantidadFundamentosProgramacion;
  int cantidadProgramacionGrafica;

  obtenerNombres("Fundamentos de Programación", nombresFundamentosProgramacion, &cantidadFundamentosProgramacion);
  obtenerNombres("Programación Gráfica", nombresProgramacionGrafica, &cantidadProgramacionGrafica);

  char alumnosComunes[20][20];
  int cantidadComunes;

  obtenerAlumnosComunes(nombresFundamentosProgramacion, cantidadFundamentosProgramacion, nombresProgramacionGrafica, cantidadProgramacionGrafica, alumnosComunes, &cantidadComunes);

  mostrarAlumnosComunes(alumnosComunes, cantidadComunes);

  return 0;
}