#ifndef NODO_ESTUDIANTE_H
#define NODO_ESTUDIANTE_H
#include <iostream>
#include <string>
using namespace std;

class Nodo_Estudiante
{
private:
    int id;
    string nombre;
    Nodo_Estudiante *siguiente;

public:
    Nodo_Estudiante(int id, string nombre);
    void setSiguiente(Nodo_Estudiante *n);
    Nodo_Estudiante* getSiguiente();
    int getId();
    string getName();
    void printEstudiante();
};

#endif // NODO_ESTUDIANTE_H
