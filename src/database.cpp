#include "include/database.h"

void Database::write(vector<vector<string>> mainList)
{

    ofstream db;
    db.open("db/lists");
    if ( db.is_open() ) {
        for (int i = 0; i < (int)mainList.size(); i++) {
            for (int li = 0; li < (int)mainList[i].size(); li++){
                if (li == 0){
                    db << "#" << mainList[i][li] << endl;
                }
                else {
                    db << mainList[i][li] << endl;
                }
            }
            db << "%" << endl;
        }
        
    } 
    else
    {
        cout << "Cannot open the file." << endl;
    }
    
    db.close();
}

vector<vector<string>> Database::read() {

    string line;
    ifstream db;

    vector<string> userList;

    db.open("db/lists");

    if (db.is_open())
    {
        while( getline(db, line, '\n')) {
            if (line.front() == '#'){
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if ( line.front() == '%') {
                mainList.push_back(userList);
                userList.clear();
            }
            else {

                userList.push_back(line);
            }
        }
    }
    else
    {
        cout << "Cannot open file for reading." << endl;
    }
    
    
    db.close();
    
    return mainList;
}