#include "include/list.h"

void List::print_menu()
{
    int choice;

    cout << "************************" << endl;
    cout << " 1 - Print list." << endl;
    cout << " 2 - Add to list." << endl;
    cout << " 3 - Delete from list." << endl;
    cout << " 4 - Save list." << endl;
    cout << " 5 - Exit program." << endl;
    cout << " Please enter a choice: ";
    cin >> choice;

    if (choice == 5)
    {
        return;
    }
    else if ( choice == 4) {
        save_list();
    }
    else if (choice == 1)
    {
        print_list();
    }
    else if (choice == 2)
    {
        add_item();
    }
    else if (choice == 3)
    {
        delete_item();
    }
    else
    {
        cout << "Sorry this function is not implemented yet." << endl;
    }
}

void List::add_item()
{

    string item;

    // Remove any character in the buffer
    cin.ignore(10000, '\n'); // ignora el caracter \n si lo que se necesita es ignorar sierta cantidad de caracteres antes del \n cin.ignore(10000,'\n')

    cout << "*** Add Item ***" << endl;
    cout << "Type in an item and press enter: " << endl;

    getline(cin, item);

    list.push_back(item);

    if ((int)list.size() > 0)
    {
        cout << "Successfully added an item to the list." << endl;
    }
    // cin.clear(); // Apaga el aviso de que hay algo mal
    //

    print_menu();
}

void List::delete_item()
{
    cout << "*** Delete Item ***" << endl;
    cout << "Select an item index number to delete." << endl;
    if (list.size())
    {
        for (int i = 0; i < (int)list.size(); i++)
        {
            cout << i+1 << " : " << list[i] << endl;
        }

        cout << "Choice: ";
        int choiceNum;
        cin >> choiceNum;
        choiceNum = choiceNum - 1;
        list.erase(list.begin()+choiceNum);
    }
    else
    {
        cout << "There is no items on the list." << endl;
    }

    print_menu();
}

void List::print_list()
{
    cout << "*** Printing list ***" << endl;

    if (list.size())
    {
        for (int i = 0; i < (int)list.size(); i++)
        {   
            if ( i != 0) {
                cout << "* " << list[i] << endl;
            }
            
        }
    }
    else
    {
        cout << "There is no items on the list." << endl;
    }

    print_menu();
}

bool List::find_userList(){
    bool userFound = false;
    // system("clear");
    cout << "**** Welcome " << name << " ****"<< endl;

    for (int ui = 0; ui < (int)mainList.size(); ui++) {
        if (mainList[ui][0] == name) {
            cout << "User has been found: " << mainList[ui][0] << endl;
            list = mainList[ui];
            currentUserIndex = ui;
            userFound = true;
            break;
        }
    }

    if (userFound == false){
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size() - 1;
    }

    return userFound;
}

void List::save_list() {
    cout << "Saving the list...";
    mainList[currentUserIndex] = list;
    print_menu();
}