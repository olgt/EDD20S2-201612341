#include "linkedlist.h"

LinkedList::LinkedList() 
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}


void LinkedList::addNode(Nodo_Estudiante *nuevo){
    if(this->head == NULL){
        this->head = nuevo;
        this->tail = nuevo;
        this->size++;
    } else {
        this->tail->setSiguiente(nuevo);
        this->tail = nuevo;
        this->size++;
    }
    printLinkedList();
    getSize();
}

void LinkedList::searchNode(int id){
    Nodo_Estudiante *aux = this->head;
    while(aux != NULL){
        if(aux->getId() == id){
            cout << "Nodos Encontrados: " << endl;
            cout << aux->getName();
            cout << ",";
        }
        aux = aux->getSiguiente();
    }
}

void LinkedList::deleteNode(int id){
    Nodo_Estudiante *aux = this->head;
    Nodo_Estudiante *temp = this->head;
    while(aux != NULL){
        if(aux->getId() == id){
            if(aux == this->head){
                this->head = this->head->getSiguiente();
            } else if (aux == this->tail){
                temp->setSiguiente(NULL);
                this->tail = temp;
            }
            else{
                temp->setSiguiente(aux->getSiguiente());
            }
        }
        aux = aux->getSiguiente();
        if(temp != aux && temp->getSiguiente() != aux){
            temp = temp->getSiguiente();
        }
    }
}

void LinkedList::printLinkedList(){
    Nodo_Estudiante *aux = this->head;
    while(aux != NULL){
        aux->printEstudiante();
        cout << " -> ";
        aux = aux->getSiguiente();
    }
}

int LinkedList::getSize(){
    return this->size;
}
