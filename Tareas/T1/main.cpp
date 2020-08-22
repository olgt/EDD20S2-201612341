#include <Utilities.h>
#include <linkedlist.h>
#include <double_linked_list.h>
#include <doublecircularlinkedlist.h>
#include <iostream>
#include <string>

using namespace std;

bool isContinue = true;

LinkedList * listaEstudiantes = new LinkedList();
Double_Linked_List *listaDobleEstudiantes = new Double_Linked_List();
DoubleCircularLinkedList *listaDobCircularEstudiantes = new DoubleCircularLinkedList();
LinkedList* copiedList = new LinkedList();

int main(){

    int a;
    string menuOptions[] = {"**Simple And Double Linked Lists**", "1. Insert Node Linked List", "2. Search Node Linked List",
                            "3. Delete Node Linked List", "4. Show Linked List", "5. Create Image Linked List", ""
                            "6. Insert Node Dual Linked List", "7. Search Node Dual Linked List", "8. Delete Node Dual Linked List",
                            "9. Show Dual Linked List", "10. Create Image Dual Linked List", "11. Insert Node Circ. Doub. Linked List",
                            "12. Search Node Circ. Doub.Linked List", "13. Delete Node Circ. Doub. Linked List",
                            "14. Show Circ. Doub. Linked List", "15. Create Image Linked List", "16. *Tarea 2* Copy Linked List",
                            "17. Exit"};

    while(isContinue){
        for(int index = 0; index < 18 ; index++){
            cout << menuOptions[index] << endl;
        }
        cout << "Choose your option: ";

        cin >> a;
        PrintSpaces();

        if(a == 1){
            listaEstudiantes->printOptionsInsert();
            PrintSpaces();
        }
        if(a == 2){
            listaEstudiantes->printOptionsSearch();
            PrintSpaces();
        }
        if(a == 3){
            listaEstudiantes->printOptionsDelete();
            PrintSpaces();
        }
        if(a == 4){
            listaEstudiantes->printLinkedList();
            PrintSpaces();
        }
        if(a == 5){
            cout << "Image Creation...";
            listaEstudiantes->createImage();
            PrintSpaces();
        }
        if(a == 6){
            listaDobleEstudiantes->printOptionsInsert();
            PrintSpaces();
        }
        if(a == 7){
            listaDobleEstudiantes->printOptionsSearch();
            PrintSpaces();
        }
        if(a == 8){
            listaDobleEstudiantes->printOptionsDelete();
            PrintSpaces();
        }
        if(a == 9){
            listaDobleEstudiantes->printList();
            PrintSpaces();
        }
        if(a == 10){
            cout << "Image Creation...";
            listaDobleEstudiantes->createImage();
            PrintSpaces();
        }
        if(a == 11){
            listaDobCircularEstudiantes->printOptionsInsert();
            PrintSpaces();
        }
        if(a == 12){
            listaDobCircularEstudiantes->printOptionsSearch();
            PrintSpaces();
        }
        if(a == 13){
            listaDobCircularEstudiantes->printOptionsDelete();
            PrintSpaces();
        }
        if(a == 14){
            listaDobCircularEstudiantes->printList();
            PrintSpaces();
        }
        if(a == 15){
            cout << "Image Creation...";
            listaDobCircularEstudiantes->createImage();
            PrintSpaces();
        }

        if(a == 16){
            copiedList = listaEstudiantes->copyList();
        }
        if(a == 17){
            isContinue = false;
        }

    }
    return 0;
}
