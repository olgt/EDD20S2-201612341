#include "double_linked_list.h"

Double_Linked_List::Double_Linked_List()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}


void Double_Linked_List::printOptionsInsert(){
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
    this->addNode(nuevoEstudiante);
}

void Double_Linked_List::addNode(Nodo_Estudiante *nuevo){
    if(this->head == NULL){
        this->head = nuevo;
        this->tail = nuevo;
        this->size++;
    } else {
        this->tail->setSiguiente(nuevo);
        this->tail->getSiguiente()->setAnterior(this->tail);
        this->tail = nuevo;
        this->size++;
    }
    printList();
    getSize();
}

void Double_Linked_List::printOptionsSearch(){
    int id;

    cout << "**Search Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    this->searchNode(id);

}

void Double_Linked_List::searchNode(int id){
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

void Double_Linked_List::printOptionsDelete(){
    int id;

    cout << "**Delete Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    this->deleteNode(id);

}

void Double_Linked_List::deleteNode(int id){
    Nodo_Estudiante *aux = this->head;
    Nodo_Estudiante *temp = this->head;
    while(aux != NULL){

        if(aux->getId() == id){
            if(aux == this->head){
                if(aux->getSiguiente() == NULL){
                    this->head = NULL;
                } else {
                    this->head = this->head->getSiguiente();
                    this->head->setAnterior(NULL);
                }
            } else if (aux == this->tail){
                this->tail = aux->getAnterior();
                this->tail->setSiguiente(NULL);
            }
            else{
                aux->getAnterior()->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(aux->getAnterior());
            }
        }

        aux = aux->getSiguiente();
     }
}

void Double_Linked_List::printList(){
    Nodo_Estudiante *aux = this->head;
    while(aux != NULL){
        if(aux->getAnterior() != NULL){
            cout << "<-";
        }
        aux->printEstudiante();
        cout << " -> ";
        aux = aux->getSiguiente();
    }
}

int Double_Linked_List::getSize(){
    return this->size;
}

void Double_Linked_List::createImage(){
    Nodo_Estudiante *aux = this->head;

    ofstream MyFile("DoubleLinkedList.gv");
    MyFile << "digraph G {";
    MyFile << "\n";

    //Asignar flechas de siguiente
      while(aux != NULL){
          if(aux->getSiguiente() == NULL && aux == this->head){
              MyFile << aux->getId();
          }else if(aux->getSiguiente() != NULL){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile<< aux->getSiguiente()->getId();
              MyFile << "; \n";
          }
          aux = aux->getSiguiente();
      }
      //Asignar flechas de anterior
      aux = this->tail;
      while(aux != NULL){
          if(aux->getAnterior() == NULL && aux == this->tail){
              MyFile << aux->getId();
          }else if(aux->getAnterior() != NULL){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile<< aux->getAnterior()->getId();
              MyFile << "; \n";
          }
          aux = aux->getAnterior();
      }
    MyFile << "}";
    MyFile.close();
    try {
        cout << "Creating" << endl;
        system("dot -Tps DoubleLinkedList.gv -o DoubleLinkedList.ps");
    } catch (exception e) {
        cout << "error occurred" << endl;
    }
}
