#include <iostream>
#include <cstdlib>

using namespace std;
const string symMap[] = {"  ","░░","▒▒","▓▓","██"}; //ASCII reference map

void PrintTile(int tile[5][5]){ //prints a symbol based on the index's value
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cout << symMap[tile[y][x]];
        }
        cout << endl;
    }
}

void Erase(int tile[5][5]){ //sets every value of a given array to 0 which correlates to "empty"
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            tile[y][x] = 0;
        }
    }
}

void Invert(int tile[5][5]){    //since max opacity is 4, subtracting 4 by every value in the array "flips" the value
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            tile[y][x] = 4-tile[y][x];
        }
    }
}

void Add(int tile1[5][5],int tile2[5][5]){  //takes the values from the second argument and adds them to the first argument
    int newVal;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            newVal = tile1[y][x] += tile2[y][x];
            if(newVal < 0){newVal = 0;} //automatically clamps the values to minimum and maximum "opacity"
            if(newVal > 4){newVal = 4;}
            tile1[y][x] = newVal;
        }
    }
}

void Subtract(int tile1[5][5],int tile2[5][5]){ //does the inverse of the Add method
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

void Prefab(int tile[5][5], string ptrn, string opr, int v){    //main method to create and operate with patterns
    int pattern[5][5];

    if(v < 0)v = 0; //simple value clamping although it won't necessarily effect the output without it
    if(v > 4)v = 4;

    if(ptrn == "plus"){ //the definition of every pattern mapped to its name, I would use switch statements if they supported strings
        int pattern[5][5] = {{0,0,v,0,0},
                             {0,0,v,0,0},
                             {v,v,v,v,v},
                             {0,0,v,0,0},
                             {0,0,v,0,0}};
    }else if(ptrn == "left"){
        int pattern[5][5] = {{v,v,0,0,0},
                             {v,v,0,0,0},
                             {v,v,0,0,0},
                             {v,v,0,0,0},
                             {v,v,0,0,0}};
    }else if(ptrn == "right"){
        int pattern[5][5] = {{0,0,0,v,v},
                             {0,0,0,v,v},
                             {0,0,0,v,v},
                             {0,0,0,v,v},
                             {0,0,0,v,v}};
    }else if(ptrn == "up"){
        int pattern[5][5] = {{v,v,v,v,v},
                             {v,v,v,v,v},
                             {0,0,0,0,0},
                             {0,0,0,0,0},
                             {0,0,0,0,0}};
    }else if(ptrn == "down"){
        int pattern[5][5] = {{0,0,0,0,0},
                             {0,0,0,0,0},
                             {0,0,0,0,0},
                             {v,v,v,v,v},
                             {v,v,v,v,v}};
    }else if(ptrn == "diamond"){
        int pattern[5][5] = {{0,0,v,0,0},
                             {0,v,v,v,0},
                             {v,v,v,v,v},
                             {0,v,v,v,0},
                             {0,0,v,0,0}};
    }else if(ptrn == "+"){
        int pattern[5][5] = {{0,0,0,0,0},
                             {0,0,v,0,0},
                             {0,v,v,v,0},
                             {0,0,v,0,0},
                             {0,0,0,0,0}};
    }else if(ptrn == "x"){
        int pattern[5][5] = {{0,0,0,0,0},
                             {0,v,0,v,0},
                             {0,0,v,0,0},
                             {0,v,0,v,0},
                             {0,0,0,0,0}};
    }else if(ptrn == "cross"){
        int pattern[5][5] = {{v,0,0,0,v},
                             {0,v,0,v,0},
                             {0,0,v,0,0},
                             {0,v,0,v,0},
                             {v,0,0,0,v}};
    }else if(ptrn == "border"){
        int pattern[5][5] = {{v,v,v,v,v},
                             {v,0,0,0,v},
                             {v,0,0,0,v},
                             {v,0,0,0,v},
                             {v,v,v,v,v}};
    }else if(ptrn == "bevel"){
        int pattern[5][5] = {{v,0,0,0,v},
                             {0,v,v,v,0},
                             {0,v,0,v,0},
                             {0,v,v,v,0},
                             {v,0,0,0,v}};
    }else if(ptrn == "fill"){
        int pattern[5][5] = {{v,v,v,v,v},
                             {v,v,v,v,v},
                             {v,v,v,v,v},
                             {v,v,v,v,v},
                             {v,v,v,v,v}};
    }else if(ptrn == "square"){
        int pattern[5][5] = {{0,0,0,0,0},
                             {0,v,v,v,0},
                             {0,v,v,v,0},
                             {0,v,v,v,0},
                             {0,0,0,0,0}};
    }else if(ptrn == "hash"){
        int pattern[5][5] = {{0,v,0,v,0},
                             {v,v,v,v,v},
                             {0,v,0,v,0},
                             {v,v,v,v,v},
                             {0,v,0,v,0}};
    }else if(ptrn == "dots"){
        int pattern[5][5] = {{v,0,v,0,v},
                             {0,0,0,0,0},
                             {v,0,v,0,v},
                             {0,0,0,0,0},
                             {v,0,v,0,v}};
    }else if(ptrn == "corners"){
        int pattern[5][5] = {{v,v,0,v,v},
                             {v,v,0,v,v},
                             {0,0,0,0,0},
                             {v,v,0,v,v},
                             {v,v,0,v,v}};
    }else if(ptrn == "noise"){  //similar to the fill pattern, but every tile is random
        int pattern[5][5] = {{(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v)},
                             {(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v)},
                             {(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v)},
                             {(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v)},
                             {(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v),(rand()%(2)*v)}};
    }else{
        cout << "\nERROR: Invalid pattern.";
        return;
    }

    if(opr == "add"){   //process the operation
        Add(tile,pattern);
        PrintTile(tile);
    }else if(opr == "subtract"){
        Subtract(tile,pattern);
        PrintTile(tile);
    }else{
        PrintTile(pattern);
    }

}

//combine operating methods
//try to make prefab return a int*
//make patterns open-ended, let user create their own patterns

int main(){
    int tile[5][5] = {{0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0}};

    string pattern = "help",operation;
    int value;
    bool clearStack = true, ioTips = true;

    while(pattern != "quit"){   //a hybrid user input system that accepts multiple formats of inputs, most edge cases can be solved just by inputting a menu option a few times until it works
        if(clearStack == false){
            if(ioTips){cout << "\n(Tip: Try typing \"list\" to see the pattern names!)";}
            cout << "\nEnter a command: ";
            cin >> pattern;
        }else{
            clearStack = false;
        }

        if(pattern == "list"){  //lists all of the currently implemented patterns
            cout << "\nThe current list of patterns are: plus, +, diamond, cross, x, border, fill, square\nbevel, hash, dots, corners, noise, up, down, left, right" << endl;

        }else if(pattern == "help"){    //helps the user understand proper input formatting
            cout << "\n\nMENU OPTIONS" << endl
            << "\"help\" - brings up this menu" << endl
            << "\"list\" - shows a list of pattern names" << endl
            << "\"hide\" - disables extra help tips" << endl
            << "\"clear\" - erases your current tile" << endl
            << "\"flip\" - inverts your current tile" << endl
            << "\"quit\" - exits the program" << endl

            << "\nTILE OPERATIONS" << endl
            << "format - pattern operation value" << endl
            << "pattern - a predefined tile, type \"list\" to see a list of patterns" << endl
            << "operation - a function applied to your current tile"
            << "\"add\" - adds the values of the pattern to your tile" << endl
            << "\"subtract\" - subtracts from your tile with the pattern's values" << endl
            << "\"show\" - shows the pattern without effecting your tile" << endl
            << "value - how transparent/opaque the pattern is" << endl;

        }else if(pattern == "quit"){    //ends the program
            cout << "\nThank you, have a good day!";

        }else if(pattern == "clear"){   //resets the user's current tile
            cout << "\nYour tile has been erased." << endl;
            Erase(tile);

        }else if(pattern == "flip"){    //inverts the user's current tile
            cout << "\nYour tile has been flipped." << endl;
            Invert(tile);
            PrintTile(tile);

        }else if(pattern == "hide"){    //turns off handholding
            cout << "\nExtra help has been turned off." << endl;
            ioTips = false;

        }else{  //if the first input wasn't a menu option, then process it as an operation
            if(ioTips){cout << "\n(Tip: Try typing \"add\", \"subtract\", or \"show\"!";}
            cout << "\nEnter an operation: ";
            cin >> operation;
            if(operation == "add" || operation == "subtract" || operation == "show"){
                if(ioTips){cout << "\n(Tip: Enter a value between 0 to 4, 0 being completely transparent and 4 being completley solid!";}
            cout << "\nEnter a value: ";
                cin >> value;
                Prefab(tile, pattern, operation, value);
            }else{
                cout << "\nERROR: Invalid operation";
                clearStack = true;
                pattern = "help";
            }
        }
        
    }

    return 0;

}