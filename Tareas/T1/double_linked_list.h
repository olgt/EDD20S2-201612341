#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include "Nodo_estudiante.h"

using namespace std;


class Double_Linked_List
{
public:
    Double_Linked_List();

    void addNode(Nodo_Estudiante *nuevo);
    void deleteNode(int id);
    void searchNode(int id);
    int getSize();
    void printList();
    void createImage();

    void printOptionsInsert();
    void printOptionsDelete();
    void printOptionsSearch();


private:
    Nodo_Estudiante *head;
    Nodo_Estudiante *tail;
    int size;
};

#endif // DOUBLE_LINKED_LIST_H
