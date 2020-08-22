#include "doublecircularlinkedlist.h"

DoubleCircularLinkedList::DoubleCircularLinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}


void DoubleCircularLinkedList::printOptionsInsert(){
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

void DoubleCircularLinkedList::addNode(Nodo_Estudiante *nuevo){
    if(this->head == NULL){
        this->head = nuevo;
        this->tail = nuevo;
        this->head->setAnterior(this->tail);
        this->tail->setSiguiente(this->head);
        this->size++;
    } else {
        this->tail->setSiguiente(nuevo);
        this->tail->getSiguiente()->setAnterior(this->tail);
        this->tail = nuevo;
        this->tail->setSiguiente(this->head);
        this->head->setAnterior(this->tail);
        this->size++;
    }
    printList();
    getSize();
}

void DoubleCircularLinkedList::printOptionsSearch(){
    int id;

    cout << "**Search Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    this->searchNode(id);

}

void DoubleCircularLinkedList::searchNode(int id){
    Nodo_Estudiante *aux = this->head;

    cout << "Nodos Encontrados: " << endl;

    //Caso Especial que Aux sea Cabeza
    if(aux->getId() == id){
        cout << aux->getName();
        cout << ",";
    }
    aux = aux->getSiguiente();

    //Ciclo empezando desde el segundo nodo
    while(aux != this->head){
        if(aux->getId() == id){
            cout << aux->getName();
            cout << ",";
        }
        aux = aux->getSiguiente();
    }
}

void DoubleCircularLinkedList::printOptionsDelete(){
    int id;

    cout << "**Delete Menu**" << endl;
    cout << "Enter the student's id: ";
    cin >> id;

    this->deleteNode(id);

}

void DoubleCircularLinkedList::deleteNode(int id){
    Nodo_Estudiante *aux = this->head;
    int pasarInicio = 1;

    while(aux != NULL){
        if(aux->getId() == id){
            if(aux == this->head){
                if(aux->getSiguiente() == this->head){
                    this->head = NULL;
                    break;
                } else {
                    this->head = this->head->getSiguiente();
                    this->head->setAnterior(this->tail);
                    this->tail->setSiguiente(this->head);
                }
            } else if (aux == this->tail){
                this->tail = aux->getAnterior();
                this->tail->setSiguiente(this->head);
                this->head->setAnterior(this->tail);
            }
            else{
                aux->getAnterior()->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(aux->getAnterior());
            }
        }

        aux = aux->getSiguiente();

        //cortamos el ciclo si pasamos por el inico de nuevo
        if(aux == this->head){
            break;
        }
     }
}

void DoubleCircularLinkedList::printList(){
    Nodo_Estudiante *aux = this->head;

    if(this->head != NULL){
        if(this->head->getAnterior() != NULL){
            cout << "TAIL: ";
            cout << this->head->getAnterior()->getId();
            cout << "<-";
        }
        cout << this->head->getId();
        cout << "->";
        aux = aux->getSiguiente();
    }

    while(aux != this->head){
        if(aux->getAnterior() != NULL){
            cout << "<-";
        }
        aux->printEstudiante();
        cout << " -> ";
        aux = aux->getSiguiente();

        if(aux == this->head){
            cout << "Head: ";
            cout << aux->getId();
        }
    }
}

int DoubleCircularLinkedList::getSize(){
    return this->size;
}

//Todo:

void DoubleCircularLinkedList::createImage(){
    Nodo_Estudiante *aux = this->head;

    ofstream MyFile("DoubleCircLinkedList.gv");
    MyFile << "digraph G {";
    MyFile << "\n";

    //Asignar flechas de siguiente
      while(aux != NULL){
          if(aux->getSiguiente() == this->head && aux == this->head){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile << aux->getId();
              MyFile << "; \n";
          }else if(aux->getSiguiente() != this->head){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile<< aux->getSiguiente()->getId();
              MyFile << "; \n";
          }else if(aux->getSiguiente() == this->head){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile<< aux->getSiguiente()->getId();
              MyFile << "; \n";
              break;
          }
          aux = aux->getSiguiente();
      }
      //Asignar flechas de anterior
      aux = this->tail;
      while(aux != NULL){
          if(aux->getAnterior() == this->tail && aux == this->tail){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile << aux->getId();
              MyFile << "; \n";
              break;
          }else if(aux->getAnterior() != this->tail){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile<< aux->getAnterior()->getId();
              MyFile << "; \n";
          }else if(aux->getAnterior() == this->tail){
              MyFile << aux->getId();
              MyFile << "->";
              MyFile<< aux->getAnterior()->getId();
              MyFile << "; \n";
              break;
          }

          aux = aux->getAnterior();
      }
    MyFile << "}";
    MyFile.close();
    try {
        cout << "Creating" << endl;
        system("dot -Tps DoubleCircLinkedList.gv -o DoubleCircLinkedList.ps");
    } catch (exception e) {
        cout << "error occurred" << endl;
    }
}
