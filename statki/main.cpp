//
//  main.cpp
//  statki
//

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <time.h>

int checkTable[2][12][12] = {
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}
};
char shipsTable[2][10][10] = {
        {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}},
        {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}}
};
char shotsTable[2][10][10] = {
    {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}},
    {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}}
};
char columns[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
char columnDown[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
char avgSide[4] = {'v','h','V','H'};
int playerShips[4] = {0, 0, 0, 0};
int varTable[4];
int shots[2] = {0, 0};
char way[2] = {' ',' '};
int xMain, yMain;
char wayComp = ' ';
int hit[2] =  {0, 0};
 
//validation functions

bool checkNumberIsInt(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]) == false){
            return false;
        }
    }
    return true;
}

bool inRange(int x){
    if (x >0 && x < 11) return true;
    return false;
}

int valShipNum (string input) {
    checkNumberIsInt(input);
    if (checkNumberIsInt(input) == false) {
        return 1;
    }
    else {
        if (input == "1" || input == "2" || input == "3" || input == "4"){
            return 0;
        }
        else {
            return 2;
        }
    }
}

int decision(string decision){
    if (decision == "yes" || decision == "YES" || decision == "Yes"){
        return 1;
    }
    else if (decision == "no" || decision == "NO" || decision == "No"){
        return 0;
    }
    return 2;
}

int valColumn (string column) {
    if (checkNumberIsInt(column) == true) return 3;
    else {
        if (column.size() > 1) {
            return 2;
        }
        else {
            for (int c = 0; c<10; c++){
                if (column[0] == columns[c] || column[0] == columnDown[c]) {
                    return 0;
                }
            }
            return 1;
        }
    }
}

int valSide (string side) {
    if (checkNumberIsInt(side) == true) return 3;
    else {
        if (side.size() > 1) {
            return 2;
        }
        else {
            for (int c = 0; c<4; c++){
                if (side[0] == avgSide[c]) {
                    return 0;
                }
            }
            return 1;
        }
    }
}

int valRow (string row) {
    int rowInt;
    if (checkNumberIsInt(row) == false) return 2;
    else {
        rowInt = stoi(row);
        if (inRange(rowInt) == false) return 1;
        return 0;
    }
}

//program functions

bool checkIfPlace(int player){
    bool checkPlace = true;
    int lengthVarV=0, lengthVarH = 0;
    int placeCheck[4] = {0, 0, 0, 0};
    for (int poley = 1; poley < 11; poley++){
        for (int polex = 1; polex < 11; polex++){
            for (int length = 1; length<5; length++){
                lengthVarV=0;
                lengthVarH = 0;
                for(int y = 0; y<length; y++){
                    if(checkTable[player-1][polex+y][poley] == 0) lengthVarV++;
                    else if(checkTable[player-1][polex][poley+y] == 0) lengthVarH++;
                }
                if (lengthVarH == length){
                    placeCheck[length-1]++;
                }
                else if (lengthVarV == length){
                    placeCheck[length-1]++;
                }
            }
        }
    }
    for (int pl = 0; pl<4;pl++){
        if (placeCheck[pl] < varTable[pl]) checkPlace = false;
    }
    return checkPlace;
}

void markSquaresAround(int length, char stronaOs, int polex, int poley, int player){
    int x = length+2;
    if (stronaOs == 'h'){
        for (int j=0;j<x;j++){
            checkTable[player-1][polex-1][poley-1+j] = 1;
            checkTable[player-1][polex][poley-1+j] = 1;
            checkTable[player-1][polex+1][poley-1+j] = 1;
        }
    }
    else if (stronaOs == 'v'){
        for (int j=0;j<x;j++){
            checkTable[player-1][polex-1+j][poley-1] = 1;
            checkTable[player-1][polex-1+j][poley] = 1;
            checkTable[player-1][polex-1+j][poley+1] = 1;
        }
    }
    else if(stronaOs == 's'){
        for (int j=0;j<x;j++){
            checkTable[player-1][polex-1][poley-1+j] = 1;
            checkTable[player-1][polex][poley-1+j] = 1;
            checkTable[player-1][polex+1][poley-1+j] = 1;
        }
    }
}

bool checkSquaresAround(int length,int polex,int poley, char stronaOs, int player){
    bool sprawdzanieMiejsca = true;
    for(int y = 0; y<length; y++){
        if (stronaOs == 'h'){
            if(checkTable[player-1][polex][poley+y]==1) sprawdzanieMiejsca=false;
        }
        else if (stronaOs == 'v'){
            if(checkTable[player-1][polex+y][poley]==1) sprawdzanieMiejsca=false;
        }
        else {
            if(checkTable[player-1][polex][poley+y]==1) sprawdzanieMiejsca=false;
        }
    }
    return sprawdzanieMiejsca;
}

void chooseShipAmount(){
    int nrShip, shipAmount;
    string shipAmountString;
    bool again = true;
    bool val = false;
    string odp;
    string nrShipString, iloscString;
    int ilosc, suma = 0, sum, sumaVar;
    int zmienna;
    for (int ship = 4; ship > 0; ship--){
        while (val == false) {
            cout << "-------------------------------" << endl;
            cout << "Choose the amount of ships" << endl;
            cout << "-------------------------------" << endl << endl;
            cout << "Choose " << ship << "-square ships" << endl;
            cin >> iloscString;
            if (checkNumberIsInt(iloscString) == true) {
                ilosc = stoi(iloscString);
                zmienna = ship + ship +2;
                sum = ilosc * zmienna;
                suma = suma + sum;
                if (suma > 100){
                    cout << "Too much ships " << endl << "Try again!!" << endl;
                    suma = suma - sum;
                }
                else {
                    playerShips[ship-1] = ilosc;
                    val = true;
                }
                cout << endl;
            }
            else {
                cout << iloscString << " is not an integer" << endl;
                cout << "try again" << endl;
            }
            Sleep(0500);
            system("CLS");
        }
        val = false;
    }
    
    while (again == true) {
        cout << "Current amount of ships:"<< endl << endl;
        cout << "-------------------------" << endl;
        for (int z = 0; z<4; z++){
            cout << z+1 << "-square ships: " << playerShips[z] << endl;
        }
        cout << "-------------------------" << endl << endl;
        cout << "After starting the game it's not possible to change the amount of ships!!" << endl <<endl;
        cout << "Do you want to change your amount of ships? " << endl << "yes or no" << endl;
        cin >> odp;
        while (decision(odp) == 2) {
            cout << "invalid input, try again" << endl;
            Sleep(500);
            system("CLS");
            cout << "Current amount of ships:"<< endl << endl;
            cout << "-------------------------" << endl;
            for (int z = 0; z<4; z++){
                cout << z+1 << "-square ships: " << playerShips[z] << endl;
            }
            cout << "-------------------------" << endl << endl;
            cout << "After starting the game it's not possible to change the amount of ships!!" << endl <<endl;
            cout << "Do you want to change your amount of ships? " << endl << "yes or no" << endl;
            cin >> odp;
        }
        Sleep(500);
        system("CLS");
        if (decision(odp) == 1) {
            cout << "Current amount of ships:"<< endl << endl;
            cout << "-------------------------" << endl;
            for (int z = 0; z<4; z++){
                cout << z+1 << "-square ships: " << playerShips[z] << endl;
            }
            cout << "-------------------------" << endl << endl;
            cout << "Which ships do you want to change?" << endl;
            cin >> nrShipString;
            while (valShipNum(nrShipString) != 0){
                if (valShipNum(nrShipString) == 1){
                    cout << nrShipString << " is not an integer"<<endl;
                    cout << "Try again " << endl;
                }
                else {
                    cout << nrShipString << " is not an available input, try again"<<endl;
                }
                Sleep(500);
                system("CLS");
                cout << "Current amount of ships:"<< endl << endl;
                cout << "-------------------------" << endl;
                for (int z = 0; z<4; z++){
                    cout << z+1 << "-square ships: " << playerShips[z] << endl;
                }
                cout << "-------------------------" << endl << endl;
                cout << "Which ships do you want to change?" << endl;
                cin >> nrShipString;
            }
            nrShip = stoi(nrShipString);
            while (val == false) {
                cout << "Type the amount of ship:" << endl;
                cin >> shipAmountString;
                if (checkNumberIsInt(shipAmountString) == true) {
                    ilosc = stoi(shipAmountString);
                    sumaVar = suma;
                    zmienna = nrShip + nrShip +2;
                    suma = suma - playerShips[nrShip-1]*zmienna;
                    sum = ilosc * zmienna;
                    suma = suma + sum;
                    if (suma > 100){
                        cout << "Too much ships " << endl << "Try again!!" << endl;
                        suma = sumaVar;
                    }
                    else {
                        playerShips[nrShip-1] = ilosc;
                        val = true;
                    }
                    cout << endl;
                }
                else {
                    cout << shipAmountString << " is not an integer" << endl;
                    cout << "try again" << endl;
                }
                Sleep(0500);
                system("CLS");
            }
            cout << endl;
            system("CLS");
            playerShips[nrShip-1] = ilosc;
            cout << "Changes were saved" << endl;
            val = false;
        }
        else again = false;
        system("CLS");
    }
}

void displayPlaceShips(int player){
    cout << "     A B C D E F G H I J                "<< endl;
    cout << "   * * * * * * * * * * * *              "<< endl;
    for (int i =0;i<10;i++){
        if (i==9) cout << i+1 << " ";
        else cout << i+1 << "  ";
        cout << "* ";
        for(int j = 0; j<10;j++){
            cout << shipsTable[player-1][i][j] << " ";
        }
        cout << "* ";
        if (i == 4) cout << "    If ship has more than 1 square,";
        else if (i == 5) cout << "    it'll be placed either vertically (downwards) or";
        else if (i == 6) cout << "    horizontally (to the right) from chosen square";
        cout << endl;
    }
    cout << "   * * * * * * * * * * * *"<< endl << endl;
    cout << "----------------------------" << endl;
}

void displayShipsIngame(int player){
    int zmienna;
    if (player == 2) zmienna = 1;
    else if (player == 1) zmienna = 2;
    cout << "         Enemy shots                    "<<"         Your shots" << endl;
    cout << "     A B C D E F G H I J                "<<"     A B C D E F G H I J    "<<endl;
    cout << "   * * * * * * * * * * * *              "<<"   * * * * * * * * * * * *  "<<endl;
    for (int i =0;i<10;i++){
        //table with enemy shots
        if (i==9) cout << i+1 << " ";
        else cout << i+1 << "  ";
        cout << "* ";
        for(int j = 0; j<10;j++){
            cout << shotsTable[zmienna-1][i][j] << " ";
        }
        cout << "*              ";
        
        //table with player shots
        if (i==9) cout << i+1 << " ";
        else cout << i+1 << "  ";
        cout << "* ";
        for(int j = 0; j<10;j++){
            cout << shotsTable[player-1][i][j] << " ";
        }
        cout << "*" << endl;
    }
    cout << "   * * * * * * * * * * * *              "<<"   * * * * * * * * * * * * " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

void placeShips(int numPlayers, string names[2]){
    int suma, decisint;
    string lengthString, decis;
    chooseShipAmount();
    for(int player = 1; player<=numPlayers;player++){
        bool again = true;
        for (int u = 0; u<4; u++){
            varTable[u] = playerShips[u];
        }
        int length, polex, poley;
        char poleyc, stronaOs;
        string poleycString, polexString, stronaOsString;
        
        cout << "Place ships - Player " << names[player-1] << endl;
        cout << "---------------------------" << endl << endl;
        
        int y = 0;
        suma = playerShips[0] + playerShips[1] + playerShips[2] + playerShips[3];
        while(y<suma){
            if (checkIfPlace(player) == true){
                displayPlaceShips(player);
                cout << "Ships left"<< endl;
                cout << "---------------------------" << endl;
                for (int i =0;i<4;i++){
                        cout << "Ship " << i+1 <<": " << varTable[i] << endl;
                    }
                cout << endl;
                cout << "Which ships do you want to place?" << endl;
                cin >> lengthString;
                //validation
                while (valShipNum(lengthString) != 0){
                    if (valShipNum(lengthString) == 1){
                        cout << lengthString << " is not an integer"<<endl;
                        cout << "Try again " << endl;
                    }
                    else {
                        cout << lengthString << " is not an available input, try again"<<endl;
                    }
                    Sleep(1000);
                    system("CLS");
                    displayPlaceShips(player);
                    cout << "Ships left"<< endl;
                    cout << "---------------------------" << endl;
                    for (int i =0;i<4;i++){
                        cout << "Ship " << i+1 <<": " << varTable[i] << endl;
                    }
                    cout << endl;
                    cout << "Which ships do you want to place?" << endl;
                    cin >> lengthString;
                }
                length = stoi(lengthString);
                if (varTable[length-1] == 0) {
                    cout << "You have no " << length <<"-squared ships left!" << endl;
                    cout << "Try again" << endl;
                    y--;
                    Sleep(1000);
                    system("CLS");
                }
                else {
                    cout << "Choose square" << endl;
                    cout << "Column: ";
                    cin >> poleycString;
                    //validation
                    while (valColumn(poleycString) != 0){
                        if (valColumn(poleycString) == 3) {
                            cout << "input cannot be an integer" << endl;
                            cout << "try again" << endl;
                        }
                        else if (valColumn(poleycString) == 2) {
                            cout << "input needs to be only 1 letter" << endl;
                            cout << "try again" << endl;
                        }
                        else if (valColumn(poleycString) == 1) {
                            cout << "not available input" << endl;
                            cout << "try again" << endl;
                        }
                        Sleep(1000);
                        system("CLS");                        
                        displayPlaceShips(player);
                        cout << "Ships left"<< endl;
                        cout << "---------------------------" << endl;
                        for (int i =0;i<4;i++){
                            cout << "Ship " << i+1 <<": " << varTable[i] << endl;
                        }
                        cout << endl;
                        cout << "Choose square" << endl;
                        cout << "Column: ";
                        cin >> poleycString;
                    }
                    //poleyc = poleycString;
                    //char to int convert
                    for (int column = 0; column<10; column++){
                        if (columns[column] == poleycString[0]) poley = column+1;
                        else if (columnDown[column] == poleycString[0]) poley = column+1;
                    }

                    cout << "Row: ";
                    cin >> polexString;
                    //validation
                    while (valRow(polexString) != 0){
                        if (valRow(polexString) == 2) {
                            cout << "input must be an integer!" << endl;
                            cout << "try again" << endl;
                        }
                        else if (valRow(polexString) == 1) {
                            cout << "input not in range" << endl;
                            cout << "try again" << endl;
                        }
                        Sleep(1000);
                        system("CLS");                        
                        displayPlaceShips(player);
                        cout << "Ships left"<< endl;
                        cout << "---------------------------" << endl;
                        for (int i =0;i<4;i++){
                            cout << "Ship " << i+1 <<": " << varTable[i] << endl;
                        }
                        cout << endl;
                        cout << "Choose square" << endl;
                        cout << "Row: ";
                        cin >> polexString;
                    }
                    polex = stoi(polexString);
                    cout << endl;
                    if (length >1){
                        cout << "Choose direction: vertically (v) or horizontally (h)"<<endl;
                        cin >> stronaOsString;
                        //validation
                        while (valSide(stronaOsString) != 0){
                            if (valColumn(stronaOsString) == 3) {
                                cout << "input cannot be an integer" << endl;
                                cout << "try again" << endl;
                            }
                            else if (valSide(stronaOsString) == 2) {
                                cout << "input needs to be only 1 letter" << endl;
                                cout << "try again" << endl;
                            }
                            else if (valSide(stronaOsString) == 1) {
                                cout << "not available input" << endl;
                                cout << "try again" << endl;
                            }
                            system("CLS");
                            cout << "Choose direction: vertically (v) or horizontally (h)"<<endl;
                            cin >> stronaOsString;
                        }
                        stronaOs = stronaOsString[0];
                    }
                    else stronaOs='s';
                    cout << endl;
                    if (checkSquaresAround(length, polex, poley, stronaOs, player) == true){
                        markSquaresAround(length, stronaOs, polex, poley,player);
                        if (stronaOs == 'h' || stronaOs == 'H'){
                            for (int j=0;j<length;j++){
                                shipsTable[player-1][polex-1][poley-1+j] = 'X';
                            }
                        }
                        else if (stronaOs == 'v' || stronaOs == 'V'){
                            for (int j=0;j<length;j++){
                                shipsTable[player-1][polex-1+j][poley-1] = 'X';
                            }
                        }
                        else if(stronaOs == 's'){
                            for (int j=0;j<length;j++){
                                shipsTable[player-1][polex-1][poley-1] = 'X';
                            }
                        }
                        varTable[length-1]--;
                    }
                    else{
                        cout << "You can't place it here" << endl;
                        cout << "----------------------------" << endl << endl;
                        Sleep(1000);
                        y--;
                    }
                }
                y++;
            }
            else {
                while (again == true) {
                    displayPlaceShips(player);
                    cout << "There's not enough space on board for the rest of your ships :((" << endl;
                    cout << "What do you want to do?" << endl;
                    cout << "1 <- change ship amount (will result in placing ALL ships again)" << endl;
                    cout << "2 <- end placing here (your opponent will have the same amount of ship)" << endl;
                    cin >> decis;
                    if (checkNumberIsInt(decis)==true){
                        decisint = stoi(decis);
                        if(decisint == 1) {
                            chooseShipAmount();
                            y = 0;
                            again = false;
                        }
                        else if (decisint == 2 ){
                            y = suma;
                            again = false;
                            for (int u = 0; u<4; u++){
                                playerShips[u] = playerShips[u] - varTable[u];
                            }
                        }
                        else cout << "wrong input " << endl;
                    }
                    else {
                        cout << "input cannot be a string" << endl;
                        system("CLS");
                    }
                }
            }
            system("CLS");
        }
        cout << "You placed all your ships!!" << endl;
        cout << "---------------------------" << endl << endl;
        Sleep(1000);
        system("CLS");
    }
}

void placeCompShips() {
    for (int u = 0; u<4; u++){
        varTable[u] = playerShips[u];
    }
    int suma, length, polex, poley;
    int stronaOsRand;
    char stronaOs;  

    suma = playerShips[0] + playerShips[1] + playerShips[2] + playerShips[3];
    for (int i = 4; i >0;i--){
        for(int y = playerShips[i-1]; y>0;y--){
            length = i;
            poley = rand() % 10+1;
            polex = rand() % 10+1;
            if (length >1){
                stronaOsRand = rand() %2;
            }
            else stronaOs= 's';
            if (stronaOsRand == 0) stronaOs = 'v';
            else stronaOs = 'h';
            if (checkSquaresAround(length, polex, poley, stronaOs, 2) == true){
                markSquaresAround(length, stronaOs, polex, poley,2);
                if (stronaOs == 'h'){
                        for (int j=0;j<length;j++){
                            shipsTable[1][polex-1][poley-1+j] = 'X';
                        }
                    }
                else if (stronaOs == 'v'){
                    for (int j=0;j<length;j++){
                        shipsTable[1][polex-1+j][poley-1] = 'X';
                    }
                }
                else if(stronaOs == 's'){
                    for (int j=0;j<length;j++){
                        shipsTable[1][polex-1][poley-1] = 'X';
                    }
                }
                varTable[length-1]--;
            }
            else y++;
        }
    }
    cout << "Computer placed all its ships!!" << endl;
    cout << "---------------------------" << endl << endl;
    Sleep(1000);
    system("CLS");
}

void playerShots(int x, int y, int player, int shotships){
    int zmienna, b = 1;
    int size = 0;
    int zmiennaSize = 0;
    int tableShots = 0;
    if (player == 1) zmienna = 0;
    else zmienna = 1;
    if (shipsTable[zmienna][x-1][y-1] == 'X') {
        shotsTable[player][x-1][y-1] = '#';
        tableShots++;
        zmiennaSize++;
        if (shipsTable[zmienna][x-2][y-1] == 'X' && x-b > 0) way[player] = 'V';
        else if (shipsTable[zmienna][x][y-1] == 'X' && x+b < 11) way[player] = 'V';
        else if (shipsTable[zmienna][x-1][y-2] == 'X' && y-b > 0) way[player] = 'H';
        else if (shipsTable[zmienna][x-1][y] == 'X' && y+b < 11) way[player] = 'H';
        else way[player] = 'S';
        if (way[player] == 'V'){
            while (shipsTable[zmienna][x-1-b][y-1] == 'X' && x-b > 0) {
                size++;
                b++;
            }
            b=1;
            while (shipsTable[zmienna][x-1+b][y-1] == 'X' && x+b < 11) {
                size++;
                b++;
            }
        }
        else if (way[player] == 'H'){
            while (shipsTable[zmienna][x-1][y-1-b] == 'X' && y-b > 0) {
                size++;
                b++;
            }
            b=1;
            while (shipsTable[zmienna][x-1][y-1+b] == 'X' && y+b < 11) {
                size++;
                b++;
            }
        }
        for (int i = 1; i < size+1; i++){
            if (way[player] == 'V'){
                if (shotsTable[player][x-1-i][y-1] == '#' && x-i > 0) {
                    tableShots++;
                }
                if (shotsTable[player][x-1+i][y-1] == '#' && x+i < 11){
                    tableShots++;
                }
            }
            else if (way[player] == 'H'){
                if (shotsTable[player][x-1][y-1-i] == '#' && y-i > 0) {
                    tableShots++;
                }
                if (shotsTable[player][x-1][y-1+i] == '#' && y+i < 11){
                    tableShots++;
                }
            }

        }
        if (tableShots == size+1){
            cout << "Hit and Sunk!!" << endl;
            cout << "You shot " << size+1 << "-squared ship!" << endl;
            if (way[player] == 'V') {
                if (shotsTable[player][x][y-1] == ' ' || shotsTable[player][x][y-1] == '-' || x == 10) {
                    for(int sizeV = 0; sizeV <size+3; sizeV++){
                        for(int sizeH = 0; sizeH <3; sizeH++){
                            if (shotsTable[player][x-sizeV][y-sizeH] == ' ' && x-sizeV >= 0 && y-sizeH >= 0){
                                shotsTable[player][x-sizeV][y-sizeH] = '-';
                            }
                        }
                    }
                }
                else if (shotsTable[player][x-2][y-1] == ' ' || shotsTable[player][x-2][y-1] == '-' || x-1 == 0) {
                    for(int sizeV = 0; sizeV <size+3; sizeV++){
                        for(int sizeH = 0; sizeH <3; sizeH++){
                            if (shotsTable[player][x-2+sizeV][y-2+sizeH] == ' ' && x-2+sizeV < 10 && y-2+sizeH < 10){
                                shotsTable[player][x-2+sizeV][y-2+sizeH] = '-';
                            }
                        }
                    }
                }
            }
            else if (way[player] == 'H'){
                if (shotsTable[player][x-1][y] == ' ' || shotsTable[player][x-1][y] == '-' || y == 10) {
                    for(int sizeV = 0; sizeV <3; sizeV++){
                        for(int sizeH = 0; sizeH <size+3; sizeH++){
                            if (shotsTable[player][x-sizeV][y-sizeH] == ' ' && x-sizeV >= 0 && y-sizeH >= 0){
                                shotsTable[player][x-sizeV][y-sizeH] = '-';
                            }
                        }
                    }
                }
                else if (shotsTable[player][x-1][y-2] == ' ' || shotsTable[player][x-1][y-2] == '-' || y-1 == 0) {
                    for(int sizeV = 0; sizeV <3; sizeV++){
                        for(int sizeH = 0; sizeH <size+3; sizeH++){
                            if (shotsTable[player][x-2+sizeV][y-2+sizeH] == ' ' && x-2+sizeV <10 && y-2+sizeH <10 ){
                                shotsTable[player][x-2+sizeV][y-2+sizeH] = '-';
                            }
                        }
                    }
                }
            }
            else {
                for(int sizeV = 0; sizeV <3; sizeV++){
                    for(int sizeH = 0; sizeH <3; sizeH++){
                        if (shotsTable[player][x-2+sizeV][y-2+sizeH] == ' ' && x-2+sizeV < 10 && y-2+sizeH < 10){
                            shotsTable[player][x-2+sizeV][y-2+sizeH] = '-';
                        }
                    }
                }
            }
            shots[player]++;
            hit[player] = 2;
        }
        else {
            cout << "Hit! "<<endl;
            hit[player] = 1;
        }
    }
    else {
        cout << "Miss :((" << endl;
        shotsTable[player][x-1][y-1] = '-';
        hit[player] = 0;
    }
}

void compShots(int *hitComp) {
    int zmienna;
    bool hitCompBool = true;
    if (*hitComp == 0){
        while (hitCompBool == true){
            yMain = rand() % 10+1;
            xMain = rand() % 10+1;

            if (shotsTable[1][xMain-1][yMain-1] == ' '){
                playerShots(xMain, yMain, 1, shots[1]);
                if (hit[1] == 1) *hitComp = 1;
                hitCompBool = false;
            }
        }
    }
        
    else if (*hitComp == 1) {
        bool random = true;
        while (random == true) {
            zmienna = rand() % 4;
            if (zmienna == 0) {
                //horizontal
                if (shotsTable[1][xMain-1][yMain-2] == ' ' && yMain-1 > 0){
                    playerShots(xMain, yMain-1, 1, shots[1]);
                    if (hit[1] == 2) *hitComp = 0;
                    else if (hit[1] == 1){
                        wayComp = 'h';
                        *hitComp = 2;
                    }
                    random = false;
                }
            }
            else if (zmienna == 1){
                if (shotsTable[1][xMain-1][yMain] == ' ' && yMain+1 < 11){
                    playerShots(xMain, yMain+1, 1, shots[1]);
                    if (hit[1] == 2) *hitComp = 0;
                    else if (hit[1] == 1){
                        wayComp = 'h';
                        *hitComp = 2;
                    }
                    random = false;
                }
            }
            else if (zmienna == 2){
                //vertical
                if (shotsTable[1][xMain-2][yMain-1] == ' ' && xMain-1 > 0){
                    playerShots(xMain-1, yMain, 1, shots[1]);
                    if (hit[1] == 2) *hitComp = 0;
                    else if (hit[1] == 1){
                        wayComp = 'v';
                        *hitComp = 2;
                    }
                    random = false;
                }
            }
            else {
                if (shotsTable[1][xMain][yMain-1] == ' ' && xMain+1 < 11){
                    playerShots(xMain+1, yMain, 1, shots[1]);
                    if (hit[1] == 2) *hitComp = 0;
                    else if (hit[1] == 1){
                        wayComp = 'v';
                        *hitComp = 2;
                    }
                    random = false;
                }
            }
        }
    }
    else {
        if (wayComp == 'h'){
            bool shoting = true;
            int i =  1;
            int sideOfshot = rand() % 2;
            while (shoting == true) {
                if (sideOfshot == 0 && yMain-i > 0){
                    if (shotsTable[1][xMain-1][yMain-i-1] == ' '){
                        playerShots(xMain, yMain-i, 1, shots[1]);
                        shoting = false;
                    }
                    else if (shotsTable[1][xMain-1][yMain-i-1] == '#') i++;
                    else {
                        sideOfshot = 1;
                        i = 1;
                    }
                }
                else if (yMain-i <= 0) sideOfshot = 1;
                if (sideOfshot == 1 && yMain+i < 11) {
                    if (shotsTable[1][xMain-1][yMain+i-1] == ' '){
                        playerShots(xMain, yMain+i, 1, shots[1]);
                        shoting = false;
                    }
                    else if (shotsTable[1][xMain-1][yMain+i-1] == '#') i++;
                    else {
                        sideOfshot = 0;
                        i = 1;
                    }
                }
                else if (yMain+i >= 11) sideOfshot = 0; 
            }
        }
        else if (wayComp == 'v'){
            bool shoting = true;
            int i =  1;
            int sideOfshot = rand() % 2;
            while (shoting == true){
                if (sideOfshot == 0 && xMain+i < 11){
                    if (shotsTable[1][xMain-i-1][yMain-1] == ' '){
                        playerShots(xMain-i, yMain, 1, shots[1]);
                        shoting = false;
                    }
                    else if (shotsTable[1][xMain-i-1][yMain-1] == '#') i++;
                    else {
                        sideOfshot = 1;
                        i = 1;
                    }
                }
                else if (xMain+i >= 11) sideOfshot = 1;
                if (sideOfshot == 1 && xMain-i > 0) {
                    if (shotsTable[1][xMain+i-1][yMain-1] == ' '){
                        playerShots(xMain+i, yMain, 1, shots[1]);
                        shoting = false;
                    }
                    else if (shotsTable[1][xMain+i-1][yMain-1] == '#') i++;
                    else {
                        sideOfshot = 0;
                        i = 1;
                    }
                }
                else if (xMain - i <= 0) sideOfshot = 0;
            }
        }
        if (hit[1] == 2) {
            *hitComp = 0;
            wayComp = ' ';
        }
    }
}

int pvp(){
    int y,x, suma;
    char yc;
    string ycString, xString;
    int turn = 0;
    string names[2];
    bool game = true;
    
    cout << "---------------------------" << endl;
    cout << "Name of player 1:" << endl;
    cout << "---------------------------" << endl;
    cin >> names[0];
    Sleep(300);
    system("CLS");
    cout << "---------------------------" << endl;
    cout << "Name of player 2:" << endl;
    cout << "---------------------------" << endl;
    cin >> names[1];
    Sleep(300);
    system("CLS");
    placeShips(2, names);
    turn = rand() % 2;

    suma = playerShips[0] + playerShips[1] + playerShips[2] + playerShips[3];
    if (turn == 1){
        displayShipsIngame(2);
        cout << "Player " << names[1] << " make your shot" << endl;
        cout << "Choose column: ";
        cin >> ycString;
        while (valColumn(ycString) != 0){
            if (valColumn(ycString) == 3) {
                cout << "input cannot be an integer" << endl;
                cout << "try again" << endl;
            }
            else if (valColumn(ycString) == 2) {
                cout << "input needs to be only 1 letter" << endl;
                cout << "try again" << endl;
            }
            else if (valColumn(ycString) == 1) {
                cout << "not available input" << endl;
                cout << "try again" << endl;
            }
            Sleep(300);
            system("CLS");
            cout << "Choose square" << endl;
            cout << "Column: ";
            cin >> ycString;
        }
        //char to int convert
        for (int column = 0; column<10; column++){
            if (columns[column] == ycString[0]) y = column+1;
            else if (columnDown[column] == ycString[0]) y = column+1;
        }

        cout << "Choose Row: ";
        cin >> xString;
        while (valRow(xString) != 0){
            if (valRow(xString) == 2) {
                cout << "input must be an integer!" << endl;
                cout << "try again" << endl;
            }
            else if (valRow(xString) == 1) {
                cout << "input not in range" << endl;
                cout << "try again" << endl;
            }
            system("CLS");
            cout << "Row: ";
            cin >> xString;
        }
        x = stoi(xString);
        cout << endl;
        playerShots(x, y, 1, shots[1]);
        Sleep(1000);
        system("CLS");
        if (hit[1] == 0) turn = 0;
        displayShipsIngame(2);
        if (shots[1] == suma) {
            cout << "Congratulations! Player "<< names[1] << " won!" <<endl;
            game = false;
        }
        Sleep(1000);
        system("CLS");
    }
    while(game == true){
        if (turn == 0){
            displayShipsIngame(1);
            cout << "Player " << names[0] << " make your shot" << endl;
            cout << "Choose column: ";
            cin >> ycString;
            while (valColumn(ycString) != 0){
                if (valColumn(ycString) == 3) {
                    cout << "input cannot be an integer" << endl;
                    cout << "try again" << endl;
                }
                else if (valColumn(ycString) == 2) {
                    cout << "input needs to be only 1 letter" << endl;
                    cout << "try again" << endl;
                }
                else if (valColumn(ycString) == 1) {
                    cout << "not available input" << endl;
                    cout << "try again" << endl;
                }
                Sleep(2000);
                system("CLS");
                cout << "Choose square" << endl;
                cout << "Column: ";
                cin >> ycString;
            }
            //char to int convert
            for (int column = 0; column<10; column++){
                if (columns[column] == ycString[0]) y = column+1;
                else if (columnDown[column] == ycString[0]) y = column+1;
            }

            cout << "Choose Row: ";
            cin >> xString;
            while (valRow(xString) != 0){
                if (valRow(xString) == 2) {
                    cout << "input must be an integer!" << endl;
                    cout << "try again" << endl;
                }
                else if (valRow(xString) == 1) {
                    cout << "input not in range" << endl;
                    cout << "try again" << endl;
                }
                system("CLS");
                cout << "Row: ";
                cin >> xString;
            }
            x = stoi(xString);
            playerShots(x, y, 0, shots[0]);
            Sleep(1000);
            system("CLS");
            displayShipsIngame(1);
            if (shots[0] == suma) {
                cout << "Congratulations! Player "<< names[0] << " won!" <<endl;
                game = false;
            }
            if (hit[0] == 0) turn = 1;
            Sleep(1000);
            system("CLS");
        }
        else if (turn == 1){
            displayShipsIngame(2);
            cout << "Player " << names[1] << " make your shot" << endl;
            cout << "Choose column: ";
            cin >> ycString;
            while (valColumn(ycString) != 0){
                if (valColumn(ycString) == 3) {
                    cout << "input cannot be an integer" << endl;
                    cout << "try again" << endl;
                }
                else if (valColumn(ycString) == 2) {
                    cout << "input needs to be only 1 letter" << endl;
                    cout << "try again" << endl;
                }
                else if (valColumn(ycString) == 1) {
                    cout << "not available input" << endl;
                    cout << "try again" << endl;
                }
                Sleep(2000);
                system("CLS");
                cout << "Choose square" << endl;
                cout << "Column: ";
                cin >> ycString;
            }
            //char to int convert
            for (int column = 0; column<10; column++){
                if (columns[column] == ycString[0]) y = column+1;
                else if (columnDown[column] == ycString[0]) y = column+1;
            }
            cout << "Choose Row: ";
            cin >> xString;
            while (valRow(xString) != 0){
                if (valRow(xString) == 2) {
                    cout << "input must be an integer!" << endl;
                    cout << "try again" << endl;
                }
                else if (valRow(xString) == 1) {
                    cout << "input not in range" << endl;
                    cout << "try again" << endl;
                }
                system("CLS");
                cout << "Row: ";
                cin >> xString;
            }
            x = stoi(xString);
            playerShots(x, y, 1, shots[1]);
            Sleep(1000);
            system("CLS");
            displayShipsIngame(2);
            if (shots[1] == suma) {
                cout << "Congratulations! Player "<< names[1] << " won!" <<endl;
                game = false;
            }
            if (hit[1] == 0) turn = 0;
            Sleep(1000);
            system("CLS");
        }
    }
    return 0;
}

int pve() {
    int y = 0, x, suma;
    int hitComp = 0;
    char yc;
    string ycString, xString;
    int turn = 0;
    string names[1];
    bool game = true;
    cout << "---------------------------" << endl;
    cout << "Name of player:" << endl;
    cout << "---------------------------" << endl;
    cin >> names[0];
    system("CLS");
    placeShips(1, names);
    placeCompShips();
    suma = playerShips[0] + playerShips[1] + playerShips[2] + playerShips[3];
    turn = rand() % 2;

    if (turn == 1){
        // random computer shots 
        displayShipsIngame(2);
        cout << "Computer make your shot" << endl;
        compShots(&hitComp);
        system("CLS");
        if (hit[1] == 0) turn = 0;
        displayShipsIngame(2);
        if (shots[1] == suma) {
            cout << "Congratulations! Computer won!" <<endl;
            game = false;
        }
        Sleep(1000);
        system("CLS");
    }
    while(game == true){
        if (turn == 0){
            displayShipsIngame(1);
            cout << "Player " << names[0] << " make your shot" << endl;
            cout << "Choose column: ";
            cin >> ycString;
            while (valColumn(ycString) != 0){
                if (valColumn(ycString) == 3) {
                    cout << "input cannot be an integer" << endl;
                    cout << "try again" << endl;
                }
                else if (valColumn(ycString) == 2) {
                    cout << "input needs to be only 1 letter" << endl;
                    cout << "try again" << endl;
                }
                else if (valColumn(ycString) == 1) {
                    cout << "not available input" << endl;
                    cout << "try again" << endl;
                }
                Sleep(1000);
                system("CLS");
                cout << "Choose square" << endl;
                cout << "Column: ";
                cin >> ycString;
            }
            //char to int convert
            for (int column = 0; column<10; column++){
                if (columns[column] == ycString[0]) y = column+1;
                else if (columnDown[column] == ycString[0]) y = column+1;
            }

            cout << "Choose Row: ";
            cin >> xString;
            while (valRow(xString) != 0){
                if (valRow(xString) == 2) {
                    cout << "input must be an integer!" << endl;
                    cout << "try again" << endl;
                }
                else if (valRow(xString) == 1) {
                    cout << "input not in range" << endl;
                    cout << "try again" << endl;
                }
                system("CLS");
                cout << "Row: ";
                cin >> xString;
            }
            x = stoi(xString);
            playerShots(x, y, 0, shots[0]);
            system("CLS");
            if (hit[0] == 0) turn = 1;
            displayShipsIngame(1);
            if (shots[0] == suma) {
                cout << "Congratulations! Player "<< names[0] << " won!" <<endl;
                game = false;
            }
            Sleep(2000);
            system("CLS");
        }
        else if (turn == 1){
            displayShipsIngame(2);
            cout << "Computer make your shot" << endl;
            compShots(&hitComp);
            system("CLS");
            displayShipsIngame(2);
            if (hit[1] == 0) turn = 0;
            if (shots[1] == suma) {
                cout << "Congratulations! Computer won!" <<endl;
                game = false;
            }
            Sleep(1000);
            system("CLS");
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    string tryb;
    int trybint = 0;
    bool choosing = true;
    bool game = true;
    string odp;
    while (game == true){
        while (choosing == true){
            cout << "              |    |    |                _           _   _   _           _     _               " << endl;    
            cout << "             )_)  )_)  )_)              | |         | | | | | |         | |   (_)              " << endl;   
            cout << "            )___))___))___)             | |__   __ _| |_| |_| | ___  ___| |___ _ _ __  ___     " << endl; 
            cout << "           )____)____)_____)            | '_  |/ _` | __| __| |/ _  | __| '_  | | '_  | __|    " << endl;
            cout << "         _____|____|____|______         | |_) | (_| | |_| |_| |  __/___ | | | | | |_) |__ |    " << endl;
            cout << "---------|                   /----------|_.__/  __,_|___|___|_|____||___/_| |_|_| .__/|___/--- " << endl; 
            cout << "  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^                                                   | |            " << endl; 
            cout << "    ^^^^      ^^^^     ^^^    ^^                                                |_|            " << endl; 
            cout << "         ^^^^      ^^^                                                                         " << endl; 
            cout << endl << endl;
            cout << "                                     Choose gamemode:" << endl;
            cout << "                   Player vs. Player <- PvP     Player vs. Computer  <- PvE"<< endl;
            cout << "                                           "; cin >> tryb;
            if (tryb == "PvP" || tryb == "PvE" || tryb == "pvp" || tryb == "pve"){
                if (tryb == "PvP" || tryb == "pvp") trybint = 1;
                else trybint = 0;
                choosing = false;
            }
            else {
                cout << "Not allowed input, try again" << endl;
                Sleep(500);
                system("CLS");
            }
        }
        system("CLS");
        if (trybint == 1) pvp();
        else pve();
        system("CLS");
        cout << "Do you want to play again? (yes or no)" << endl;
        cin >> odp;
        while (decision(odp) == 2) {
            cout << "invalid input, try again" << endl;
            Sleep(1000);
            system("CLS");
            cout << "Do you want to play again? (yes or no)" << endl;
            cin >> odp;
        }
        if (decision(odp) == 0) game = false;
        else if (decision(odp) == 1){
            for (int y = 0; y<10; y++){
                for (int x = 0; x<10; x++){
                    for (int p=0; p < 2; p++){
                        checkTable[p][x+1][y+1] = 0;
                        shipsTable[p][x][y] = ' ';
                        shotsTable[p][x][y] = ' ';
                    }
                }
                if (y < 4){
                    playerShips[y] = 0;
                }
                if (y < 2){
                    shots[y] = 0;
                    way[y] = ' ';
                    hit[y] = 0;
                }
            }
            wayComp = ' ';
        }
        system("CLS");
    }
    return 0;
}

