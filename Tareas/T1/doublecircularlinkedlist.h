#ifndef DOUBLECIRCULARLINKEDLIST_H
#define DOUBLECIRCULARLINKEDLIST_H


#include <iostream>
#include <string>
#include <fstream>
#include "Nodo_estudiante.h"

using namespace std;


class DoubleCircularLinkedList
{
public:
    DoubleCircularLinkedList();

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

#endif // DOUBLECIRCULARLINKEDLIST_H
