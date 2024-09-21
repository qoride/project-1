#include <iostream>

using namespace std;
const string symMap[] = {"  ","░░","▒▒","▓▓","██"}; //ASCII reference map

void PrintTile(int tile[5][5]){
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cout << symMap[tile[y][x]];
        }
        cout << endl;
    }
}

void Erase(int tile[5][5]){
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            tile[y][x] = 0;
        }
    }
}

void Add(int tile1[5][5],int tile2[5][5]){
    int newVal;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            newVal = tile1[y][x] += tile2[y][x];
            if(newVal < 0){newVal = 0;}
            if(newVal > 4){newVal = 4;}
            tile1[y][x] = newVal;
        }
    }
}

void Subtract(int tile1[5][5],int tile2[5][5]){
    int newVal;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            newVal = tile1[y][x] -= tile2[y][x];
            if(newVal < 0){newVal = 0;}
            if(newVal > 4){newVal = 4;}
            tile1[y][x] = newVal;
        }
    }
}

int main(){
    int tile[5][5] = {{0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0}};

    string pattern,operation,value;

    cout << "Type \"list\" to see the list of patterns, \"help\" for help on how to format an input, or \"quit\" to stop the program." << endl;

    while(pattern != "quit"){
        cout << "Please enter a command: ";
        cin >> pattern;

        if(pattern == "list"){
            cout << "\nThe current list of patterns are: plus, bigplus, cross, border, fill, square, hash";

        }else if(pattern == "help"){
            cout << "\n\nEnter up to 3 arguments, each seperated by spaces." << endl;
            cout << "\nThe first input should either be a menu option (list, help, quit) or the name of a pattern." << endl;
            cout << "The second input should be the operation applied to your tile with the referenced pattern." << endl;
            cout << "Possible operations are add, subtract, and show." << endl;
            cout << "Add and subtract will directly modify your tile, while show will only show you what the selected pattern looks like." << endl;
            cout << "The last input is the value used to determine how potent the operation is." << endl;
            cout << "\nAn example of a valid input would look like: border add 5" << endl;

        }else if(pattern == "quit"){
            cout << "\n\nHere's your final pattern! Have a good day!\n";
            PrintTile(tile);
        }else{
            cin >> operation;
            if(operation == "add"){
                cin >> value;
                //Add();
            }else if(operation == "subtract"){
                cin >> value;
                //Subtract();
            }else if(operation == "show"){
                //PrintTile();
            }
        }
        
    }

    return 0;
}
