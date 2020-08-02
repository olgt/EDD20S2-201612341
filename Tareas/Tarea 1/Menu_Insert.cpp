#include "Menu_Insert.h"

void printOptionsInsert(LinkedList * listaEstudiantes){
    int id;
    string name;
    Nodo_Estudiante *nuevoEstudiante;

    cout << "**Insert Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;
    cout << endl;
    cout << "Enter the student's name: ";
    cin >> name;

    nuevoEstudiante = new Nodo_Estudiante(id, name);
    listaEstudiantes->addNode(nuevoEstudiante);
}
