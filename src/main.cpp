#include "include/list.h"
#include "include/database.h"

int main (int argc, char *args[]) {
    if (argc > 1)
    {
        Database data;
        List simpleList;
        
        simpleList.name = string(args[1]);
        simpleList.mainList = data.read();
        simpleList.find_userList();
        simpleList.print_menu();
        data.write(simpleList.mainList);
    } else
    {
        cout << "Username not supplied.. exiting program" << endl;
    }
    
    return 0;
}