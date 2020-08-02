#include "Nodo_estudiante.h"

Nodo_Estudiante::Nodo_Estudiante(int id, string nombre)
{
    this->id = id;
    this->nombre = nombre;

}

Nodo_Estudiante* Nodo_Estudiante::getSiguiente(){
    return this->siguiente;
}

void Nodo_Estudiante::setSiguiente(Nodo_Estudiante *n){
    this->siguiente = n;
}

int Nodo_Estudiante::getId(){
    return this->id;
}

string Nodo_Estudiante::getName(){
    return this->nombre;
}


void Nodo_Estudiante::printEstudiante(){
    cout << this->nombre;
    cout << " ";
    cout << this->id;
}
