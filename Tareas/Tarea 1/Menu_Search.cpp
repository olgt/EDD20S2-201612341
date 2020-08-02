#include "Menu_Search.h"

void printOptionsSearch(LinkedList * listaEstudiantes){
    int id;

    cout << "**Search Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    listaEstudiantes->searchNode(id);

}
