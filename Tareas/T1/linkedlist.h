#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Nodo_estudiante.h"
#include <iostream>
using namespace std;

class LinkedList
{
public:
    LinkedList();
    
    void deleteNode(int id);    
    void addNode(Nodo_Estudiante *nuevo);
    void searchNode(int id);
    int getSize();
    void printLinkedList();
    
    
private:
    Nodo_Estudiante *head;
    Nodo_Estudiante *tail;
    int size;
};

#endif // LINKEDLIST_H
