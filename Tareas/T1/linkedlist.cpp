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
    //printLinkedList();
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

void LinkedList::createImage(){
    Nodo_Estudiante *aux = this->head;

    ofstream MyFile("LinkedList.gv");
    MyFile << "digraph G {";
    MyFile << "\n";

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
    MyFile << "}";
    MyFile.close();
    try {
        cout << "Creating" << endl;
        system("dot -Tps LinkedList.gv -o LinkedList.ps");
    } catch (exception e) {
        cout << "error occurred" << endl;
    }
}

void LinkedList::printOptionsInsert(){
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


void LinkedList::printOptionsDelete(){
    int id;

    cout << "**Delete Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    this->deleteNode(id);

}

void LinkedList::printOptionsSearch(){
    int id;

    cout << "**Search Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    this->searchNode(id);

}

Nodo_Estudiante* LinkedList::gethead(){
    return this->head;
}

LinkedList* LinkedList::copyList(){
    LinkedList *newList = new LinkedList(); //constante

    Nodo_Estudiante *actual = this->gethead(); //Constante

    while(actual != NULL){ //bucle
        newList->addNode(actual); //Otro metodo
        actual = actual->getSiguiente(); //Variable de control (n+1)
    }
    cout << "Lista Copiada: "; //constante
    newList->printLinkedList(); //Otro metodo
    return newList; //Constante
}
