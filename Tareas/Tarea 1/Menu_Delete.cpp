#include "Menu_Delete.h"

void printOptionsDelete(LinkedList * listaEstudiantes){
    int id;

    cout << "**Delete Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    listaEstudiantes->deleteNode(id);

}
