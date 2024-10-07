#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
const string symMap[] = {"  ","░░","▒▒","▓▓","██"}; //ASCII reference map

struct tileSpace{
    int arr[5][5];
};

const string operators[4] = {"add","subtract","flip","erase"};

vector<string> patterns = {"plus", "+", "diamond", "cross", "x", "border", "fill", "square","bevel",
                           "hash", "dots", "corners", "noise", "up", "down", "left", "right"};

//PROTOTYPES
struct tileSpace Pattern(string ref, int v = 0);
void Print(tileSpace t = Pattern("blank"));
void Operate(tileSpace &a, string opr, tileSpace b = Pattern("blank"));
int Reference(string s, string l = "pattern");
void clearStream();

vector<tileSpace> customs;

int main(){
    tileSpace tile = Pattern("blank");

    string pattern = "help",operation;
    int value;
    bool ignoreInput = true, ioTips = true, editing = false;

    while(pattern != "quit"){ //main menu
        if(ignoreInput == false){
            if(ioTips){cout << "\n(Tip: Try typing \"list\" to see the pattern names)";}
            cout << "\nEnter a menu option or the name of a pattern: ";
            cin >> pattern;
        }else{
            ignoreInput = false;
        }

        if(pattern == "list"){ //lists all of the currently implemented patterns
            cout << "\nThe current list of patterns are: ";
            for(string p:patterns){
                cout << p << ", ";
            }
            cout << endl;

        }else if(pattern == "help"){ //helps the user understand proper input formats
            cout << "\n\nMENU OPTIONS" << endl
            << "format: option" << endl
            << "\"help\" - brings up this menu" << endl
            << "\"list\" - shows a list of pattern names" << endl
            << "\"tips\" - toggles extra help tips" << endl
            << "\"clear\" - erases your current tile" << endl
            << "\"flip\" - inverts your current tile" << endl
            << "\"make\" - create a new pattern" << endl
            << "\"quit\" - exits the program" << endl

            << "\nTILE OPERATIONS" << endl
            << "format: pattern operation value (one input at a time)" << endl
            << "pattern - a predefined tile, type \"list\" to see a list of patterns" << endl
            << "operation - a function applied to your current tile" << endl
            << "\"add\" - adds the values of the pattern to your tile" << endl
            << "\"subtract\" - subtracts from your tile with the pattern's values" << endl
            << "\"show\" - shows the pattern without effecting your tile" << endl
            << "value - how transparent/opaque the pattern is" << endl;

        }else if(pattern == "quit"){ //ends the program
            cout << "\nThank you, have a good day!";

        }else if(pattern == "clear"){ //resets the user's current tile
            cout << "\nYour tile has been erased." << endl;
            Operate(tile,"erase");

        }else if(pattern == "flip"){ //inverts the user's current tile
            cout << "\nYour tile has been flipped." << endl;
            Operate(tile,"flip");

        }else if(pattern == "tips"){ //toggles handholding
            ioTips = !ioTips;
            cout << "\nExtra help has been turned " << ((ioTips)?"on.":"off.") << endl;

        }else if(pattern == "make"){ //creates a new pattern
            clearStream();
            do{
                if(ioTips){cout << "\n(Tip: The name can't have any spaces in it, and it can't be the name of any existing commands or patterns)";}
                cout << "\nEnter a name for your new pattern: ";
                cin >> pattern;
                if((Reference(pattern)!=-1)||(Reference(pattern,"operator")!=-1)){
                    cout << "\nERROR: The name for your pattern cannot be a pre-existing name." << endl;
                }
                clearStream();
            }while((Reference(pattern)!=-1)||(Reference(pattern,"operator")!=-1));
            

            if(ioTips){cout << "\n(Tip: 0 means that cell will be empty, any input that's not 1 or 0 will be treated as 0)";}
            cout << "\nEnter 5 values seperated by spaces (1 or 0) for each row." << endl;

            editing = true;
            tileSpace newtile = Pattern("blank");

            while(editing){ //tileSpace editor
                for(int y = 0; y < 5; y++){
                    cout << "\nFor row " << y+1 << ": ";
                    vector<int> inputs = {};
                    while(inputs.size()<5){
                        while(cin >> value){
                            if(cin.good())inputs.push_back(value);
                            if(inputs.size()>=5)break;
                        }
                        if(cin.fail()){
                            cin.clear();
                            cout << "\nERROR: A value was not accepted, try again: ";
                            inputs.clear();
                            clearStream();
                        }
                    }
                    clearStream();
                    for(int x = 0; x < 5; x++){
                        newtile.arr[y][x] = (inputs.at(x)==1)?4:0;
                    }
                }
                Print(newtile);
                cout << "\nAre you satisfied with this result? [Y/N] ";
                cin >> operation;
                if(operation == "Y"){
                    patterns.push_back(pattern);
                    customs.push_back(newtile);
                    editing = false;
                }else{
                    cout << "\nRestarting..." << endl;
                }
            }
        }else{ //if the first input wasn't a menu option, then decode it as an operation
            clearStream();
            if(Reference(pattern,"pattern") == -1){
                cout << "\nERROR: Invalid menu option/referenced pattern does not exist" << endl;
            }else{
                if(ioTips){cout << "\n(Tip: Try typing \"add\", \"subtract\", or \"show\")";}
                cout << "\nEnter an operation: ";
                cin >> operation;
                if(operation == "add" || operation == "subtract" || operation == "show"){
                    clearStream();
                    if(ioTips){cout << "\n(Tip: Enter a value between 0 to 4, 0 being completely transparent and 4 being completley solid)";}
                    cout << "\nEnter a value: ";
                    cin >> value;
                    Operate(tile,operation,Pattern(pattern,value));
                }else{
                    cout << "\nERROR: Invalid operation" << endl;
                    ignoreInput = true;
                    pattern = "help";
                }
            }
        }      
    }
    return 0;
}

//DEFINITIONS
void clearStream(){ //reject the rest of the inputs
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin.clear();
}

void Print(tileSpace t){ //print function for tileSpace
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cout << symMap[t.arr[y][x]];
        }
        cout << endl;
    }
}

void Operate(tileSpace &a, string opr, tileSpace b){ //performs an operation on two tileSpaces
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            switch(Reference(opr,"operator")){
            case 0: //add
                a.arr[y][x] += b.arr[y][x];
                break;
            case 1: //subtract
                a.arr[y][x] -= b.arr[y][x];
                break;
            case 2: //flip
                a.arr[y][x] = 4-a.arr[y][x];
                break;
            case 3: //erase
                a.arr[y][x] = 0;
                break;
            default: //invalid operator
                if(opr=="show")Print(b);
                return;
            }
            if(a.arr[y][x] < 0)a.arr[y][x] = 0;
            if(a.arr[y][x] > 4)a.arr[y][x] = 4;
        }
    }
    Print(a);
}

int Reference(string s, string l){ //returns the index of a string from the given array
    int size = (l == "operator")?5:patterns.size();
    for(int i = 0; i < size; i++){
        if(l == "operator"){
            if(s == operators[i])return i;
        }else{
            if(s == patterns.at(i))return i;
        }
    }
    return -1;
}

struct tileSpace Pattern(string ref, int v){    //creates a tileSpace when given a pattern name and value
    if(v < 0)v = 0;
    struct tileSpace pattern;
    
    int r = Reference(ref);
    switch(r){
        case -1: //no reference
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = 0;
                }
            }
            break;
        case 0: //plus
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x==2||y==2)?v:0;
                }
            }
            break;
        case 1: //+
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = ((y!=0&&y!=4)&&(x!=0&&x!=4)&&(x==2||y==2))?v:0;
                }
            }
            break;
        case 2: //diamond
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = ((((x<3)?x:4-x)+((y<3)?y:4-y))>1)?v:0;
                }
            }
            break;
        case 3: //cross
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x==y||x==4-y)?v:0;
                }
            }
            break;
        case 4: //x
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = ((x!=0&&x!=4)&&(x==y||x==4-y))?v:0;
                }
            }
            break;
        case 5: //border
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x!=0&&y!=0&&x!=4&&y!=4)?0:v;
                }
            }
            break;
        case 6: //fill
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = v;
                }
            }
            break;
        case 7: //square
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x!=0&&y!=0&&x!=4&&y!=4)?v:0;
                }
            }
            break;
        case 8: //bevel
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = ((x!=0&&y!=0&&x!=4&&y!=4)||(x==y||x==4-y))?v:0;
                }
            }
            pattern.arr[2][2] = 0;
            break;
        case 9: //hash
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x%2&&y%2)?v:0;
                }
            }
            break;
        case 10: //dots
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x%2==0&&y%2==0)?v:0;
                }
            }
            break;
        case 11: //corners
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x!=2&&y!=2)?v:0;
                }
            }
            break;
        case 12: //noise
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = rand()%(2)*v;
                }
            }
            break;
        case 13: //up
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (y < 2)?v:0;
                }
            }
            break;
        case 14: //down
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (y > 2)?v:0;
                }
            }
            break;
        case 15: //left
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x < 2)?v:0;
                }
            }
            break;
        case 16: //right
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (x > 2)?v:0;
                }
            }
            break;
        default: //custom patterns
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    pattern.arr[y][x] = (customs.at(r-17).arr[y][x]==4)?v:0;
                }
            }
            break;
    }
    return pattern;
}