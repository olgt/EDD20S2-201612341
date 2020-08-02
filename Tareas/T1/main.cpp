#include <Menu_Insert.h>
#include <Menu_Delete.h>
#include <Menu_Search.h>
#include <Utilities.h>
#include <linkedlist.h>

#include <iostream>
#include <string>

using namespace std;

bool isContinue = true;

LinkedList * listaEstudiantes = new LinkedList();

int main(){

    int a;
    string menuOptions[] = {"**Simple Linked Lists**", "1. Insert", "2. Search", "3. Delete", "4. Show List", "5. Exit"};

    while(isContinue){
        for(int index = 0; index < 6 ; index++){
            cout << menuOptions[index] << endl;
        }
        cout << "Choose your option: ";

        cin >> a;
        PrintSpaces();

        if(a == 1){
            printOptionsInsert(listaEstudiantes);
            PrintSpaces();
        }
        if(a == 2){
            printOptionsSearch(listaEstudiantes);
            PrintSpaces();
        }
        if(a == 3){
            printOptionsDelete(listaEstudiantes);
            PrintSpaces();
        }
        if(a == 4){
            listaEstudiantes->printLinkedList();
            PrintSpaces();
        }
        if(a == 5){
            isContinue = false;
        }
    }
    return 0;
}
