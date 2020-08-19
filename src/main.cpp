#include "include/list.h"

int main (int argc, char *args[]) {
    if (argc > 1)
    {
        List simpleList;
        simpleList.name = string(args[1]);
        simpleList.print_menu();
    } else
    {
        cout << "Username not supplied.. exiting program" << endl;
    }
    
    
    return 0;
}