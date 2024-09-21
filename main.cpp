#include <iostream>

using namespace std;
const string charMap[] = {"  ","░░","▒▒","▓▓","██"}; //ASCII reference mappings

void PrintTile(int tile[5][5]){
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cout << charMap[tile[y][x]];
        }
        cout << endl;
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
        
    }

    return 0;
}
