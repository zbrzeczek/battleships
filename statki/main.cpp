//
//  main.cpp
//  statki
//


#include <iostream>
#include <stdlib.h>
//#include <windows.h>
#include <time.h>
using namespace std;


int tablica_sprawdzajaca[2][12][12] = {
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}
};

char tablica[2][10][10] = {
        {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}},
        {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}}
};

char tablica_shots[2][10][10] = {
    {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}},
    {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}}
};
char columns[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int statkiGracza[4] = {0, 0, 0, 0};
int shots[2] = {0, 0};
char way[2] = {' ',' '};
char z = ' ';
int xMain, yMain;
int zmiennax, zmiennay;
int sides[4] = {0, 0, 0, 0};
int sidesMain = 0;
char wayComp = ' ';
int idkname=1;
 
void changeShipAmount(int nrStatku, int iloscStatku, int statkiGracza[4], int* suma){
    int x = statkiGracza[nrStatku-1];
    *suma = *suma - (x*2) - 2;
    if (*suma + (iloscStatku*2)+2 > 100){
        cout << "There's too little space for that" << endl << "Try again";
        cout << endl;
        cout << "-------------------------------" << endl << endl;
    }
    else statkiGracza[nrStatku-1] = iloscStatku;
}

void markSquaresAround(int wyborDlugosci, char stronaOs, int polex, int poley, int gracz){
    int x = wyborDlugosci+2;
    if (stronaOs == 'h'){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-1][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex+1][poley-1+j] = 1;
            }
        }
    }
    else if (stronaOs == 'v'){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-1+j][poley-1] = 1;
                tablica_sprawdzajaca[gracz-1][polex-1+j][poley] = 1;
                tablica_sprawdzajaca[gracz-1][polex-1+j][poley+1] = 1;
            }
        }
    }
    else if(stronaOs == 's'){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-1][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex+1][poley-1+j] = 1;
            }
        }
    }
}

bool checkSquaresAround(int wyborDlugosci,int polex,int poley, char stronaOs, int gracz){
    bool sprawdzanieMiejsca = true;
    for(int y = 0; y<wyborDlugosci; y++){
        if (stronaOs == 'h'){
            if(tablica_sprawdzajaca[gracz-1][polex][poley+y]==1) sprawdzanieMiejsca=false;
        }
        else if (stronaOs == 'v'){
            if(tablica_sprawdzajaca[gracz-1][polex+y][poley]==1) sprawdzanieMiejsca=false;
        }
        else {
            if(tablica_sprawdzajaca[gracz-1][polex][poley]==1) sprawdzanieMiejsca=false;
        }
    }
    return sprawdzanieMiejsca;
}

void chooseShipAmount(int statkiGracza[4]){
    int nrStatku, iloscStatku;
    bool powtorzenie = true;
    int decyzja;
    int ilosc, suma = 0, sum;
    for (int nrStatku = 4; nrStatku > 0; nrStatku--){
        cout << "-------------------------------" << endl;
        cout << "Choose the amount of ships" << endl;
        cout << "-------------------------------" << endl << endl;
        cout << "Choose " << nrStatku << "-square ships" << endl;
        cin >> ilosc;
        int zmienna = nrStatku + nrStatku +2;
        sum = ilosc * zmienna;
        suma = suma + sum;
        if (suma > 100){
            cout << "Too much ships " << endl << "Try again!!" << endl;
            nrStatku++;
            suma = suma - sum;
            //Sleep(2000);
        }
        else statkiGracza[nrStatku-1] = ilosc;
        cout << endl;
        system("CLS");
    }
    cout << endl;
    system("CLS");
    
    while (powtorzenie == true) {
        cout << "Current amount of ships:"<< endl << endl;
        cout << "-------------------------" << endl;
        for (int z = 0; z<4; z++){
            cout << z+1 << "-square ships: " << statkiGracza[z] << endl;
        }
        cout << "-------------------------" << endl << endl;
        cout << "After starting the game it's not possible to change the amount of ships!!" << endl <<endl;
        cout << "Do you want to change your amount of ships? " << endl << "Yes  <- 1" << endl<< "No  <- 2" << endl;
        cin >> decyzja;
        cout << endl;
        if (decyzja == 1) {
            system("CLS");
            cout << "Which ships do you want to change?" << endl;
            cin >> nrStatku;
            cout << "Type the amount of ship:" << endl;
            cin >> iloscStatku;
            cout << endl;
            system("CLS");
            changeShipAmount(nrStatku, iloscStatku, statkiGracza, &suma);
        }
        else powtorzenie = false;
        system("CLS");
    }
}

void displayPlaceShips(int gracz){
    cout << "     A B C D E F G H I J                "<< endl;
    cout << "   * * * * * * * * * * * *              "<< endl;
    for (int i =0;i<10;i++){
        if (i==9) cout << i+1 << " ";
        else cout << i+1 << "  ";
        cout << "* ";
        for(int j = 0; j<10;j++){
            cout << tablica[gracz-1][i][j] << " ";
        }
        cout << "* " << endl;
    }
    cout << "   * * * * * * * * * * * *"<< endl << endl;
    cout << "----------------------------" << endl;
}

void displayShipsIngame(int gracz){
    cout << "     A B C D E F G H I J                "<<"     A B C D E F G H I J    "<<endl;
    cout << "   * * * * * * * * * * * *              "<<"   * * * * * * * * * * * *  "<<endl;
    for (int i =0;i<10;i++){
        //tablica z statkami
        if (i==9) cout << i+1 << " ";
        else cout << i+1 << "  ";
        cout << "* ";
        for(int j = 0; j<10;j++){
            cout << tablica[gracz-1][i][j] << " ";
        }
        cout << "*              ";
        
        //tablica z shots
        if (i==9) cout << i+1 << " ";
        else cout << i+1 << "  ";
        cout << "* ";
        for(int j = 0; j<10;j++){
            cout << tablica_shots[gracz-1][i][j] << " ";
        }
        cout << "*" << endl;
    }
    
    cout << "   * * * * * * * * * * * *              "<<"   * * * * * * * * * * * * " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

void placeShips(int iloscGraczy, string names[2]){
    int suma;
    chooseShipAmount(statkiGracza);
    for(int gracz = 1; gracz<=iloscGraczy;gracz++){
        int zmiennaTablica[4] = {statkiGracza[0], statkiGracza[1], statkiGracza[2], statkiGracza[3]};
        int wyborDlugosci, polex, poley;
        char poleyc, stronaOs;
        
        cout << "Place ships - Player " << names[gracz-1] << endl;
        cout << "---------------------------" << endl << endl;
        
        suma = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
        displayPlaceShips(gracz);
        cout << endl;
        for(int y =0; y<suma;y++){
            cout << "Ships left"<< endl;
            cout << "---------------------------" << endl;
            for (int i =0;i<4;i++){
                    cout << "Ship " << i+1 <<": " << zmiennaTablica[i] << endl;
                }
            cout << endl;
            cout << "If ship has more than 1 square, it'll be placed either vertically (downwards) or horizontally (to the right) from chosen square";
            cout << endl;
            cout << "Which ship do you want to place?" << endl;
            cin >> wyborDlugosci;
            if (zmiennaTablica[wyborDlugosci-1] == 0) {
                cout << "You have no " << wyborDlugosci <<"-squared ships left!" << endl;
                cout << "Try again" << endl;
                y--;
                //Sleep(2000);
                //system("CLS");
            }
            else {
                cout << "Choose square" << endl;
                cout << "Column: ";
                cin >> poleyc;
                //char to int convert
                for (int column = 0; column<10; column++){
                    if (columns[column] == poleyc) poley = column+1;
                }

                cout << "Row: ";
                cin >> polex;
                cout << endl;
                if (wyborDlugosci >1){
                    cout << "Choose direction: vertically (v) or horizontally (h)"<<endl;
                    cin >> stronaOs;
                }
                else stronaOs='s';
                cout << endl;
                if (checkSquaresAround(wyborDlugosci, polex, poley, stronaOs, gracz) == true){
                    markSquaresAround(wyborDlugosci, stronaOs, polex, poley,gracz);
                    if (stronaOs == 'h'){
                        for (int j=0;j<wyborDlugosci;j++){
                            tablica[gracz-1][polex-1][poley-1+j] = 'X';
                        }
                    }
                    else if (stronaOs == 'v'){
                        for (int j=0;j<wyborDlugosci;j++){
                            tablica[gracz-1][polex-1+j][poley-1] = 'X';
                        }
                    }
                    else if(stronaOs == 's'){
                        for (int j=0;j<wyborDlugosci;j++){
                            tablica[gracz-1][polex-1][poley-1] = 'X';
                        }
                    }
                    zmiennaTablica[wyborDlugosci-1]--;
                }
                else{
                    cout << "You can't place it here" << endl;
                    cout << "----------------------------" << endl << endl;
                    y--;
                }
                displayShipsIngame(gracz);
            }
        }
        cout << "You placed all your ships!!" << endl;
        cout << "---------------------------" << endl << endl;
        //Sleep(3000);
        //system("CLS");
    }
}

void placeCompShips() {
    int zmiennaTablica[4] = {statkiGracza[0], statkiGracza[1], statkiGracza[2], statkiGracza[3]};
    int suma, wyborDlugosci, polex, poley;
    int stronaOsRand;
    char stronaOs;
    cout << "Place ships - Comp " << endl;
    cout << "---------------------------" << endl << endl;
        
    suma = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
    displayPlaceShips(2);
    cout << endl;
    for (int i = 4; i >0;i--){
        for(int y = statkiGracza[i-1]; y>0;y--){
            cout << "Ships left"<< endl;
            cout << "---------------------------" << endl;
            for (int z =0;z<4;z++){
                    cout << "Ship " << z+1 <<": " << zmiennaTablica[i] << endl;
                }
            cout << endl;
            cout << "Which ship do you want to place?" << endl;
            wyborDlugosci = i;
            cout << wyborDlugosci << endl;
            cout << "Choose square" << endl;
            cout << "Column: ";
            poley = rand() % 10+1;
            cout << poley << endl;
            cout << "Row: ";
            polex = rand() % 10+1;
            cout << polex << endl;
            cout << endl;
            if (wyborDlugosci >1){
                //0 - verticaly, 1 - horizontally
                stronaOsRand = rand() %2;
            }
            //2 - onesquare
            else stronaOs= 's';
            if (stronaOsRand == 0) stronaOs = 'v';
            else stronaOs = 'h';
            cout << endl;
            if (checkSquaresAround(wyborDlugosci, polex, poley, stronaOs, 2) == true){
                markSquaresAround(wyborDlugosci, stronaOs, polex, poley,2);
                if (stronaOs == 'h'){
                        for (int j=0;j<wyborDlugosci;j++){
                            tablica[1][polex-1][poley-1+j] = 'X';
                        }
                    }
                    else if (stronaOs == 'v'){
                        for (int j=0;j<wyborDlugosci;j++){
                            tablica[1][polex-1+j][poley-1] = 'X';
                        }
                    }
                    else if(stronaOs == 's'){
                        for (int j=0;j<wyborDlugosci;j++){
                            tablica[1][polex-1][poley-1] = 'X';
                        }
                    }
                    zmiennaTablica[wyborDlugosci-1]--;
                }
                else{
                    cout << "You can't place it here" << endl;
                    cout << "----------------------------" << endl << endl;
                    y++;
                }
                displayShipsIngame(2);
            }
    }
        cout << "You placed all your ships!!" << endl;
        cout << "---------------------------" << endl << endl;
        //Sleep(3000);
        //system("CLS");
}

void playerShots(int x, int y, int gracz, int shotships, int *hit){
    int zmienna;
    int size = 0;
    int zmiennaSize = 0;
    int tableShots = 0;
    if (gracz == 1) zmienna = 0;
    else zmienna = 1;
    if (tablica[zmienna][x-1][y-1] == 'X') {
        tablica_shots[gracz][x-1][y-1] = '#';
        tableShots++;
        zmiennaSize++;
        //pamietaj ze od strzalu statek moze byc w 2 kierunki 
        if (tablica[zmienna][x-2][y-1] == 'X') way[gracz] = 'V';
        else if (tablica[zmienna][x][y-1] == 'X') way[gracz] = 'V';
        else if (tablica[zmienna][x-1][y-2] == 'X') way[gracz] = 'H';
        else if (tablica[zmienna][x-1][y] == 'X') way[gracz] = 'H';
        else way[gracz] = 'S';
        cout << way[gracz] << endl;
        if (way[gracz] == 'V'){
            for (int b = 1; b<4;b++){
                if (tablica[zmienna][x-1-b][y-1] == 'X') {
                size++;
                }
            }
            for (int f = 1; f<4;f++){
                if (tablica[zmienna][x-1+f][y-1] == 'X') {
                size++;
                }
            }
        }
        else if (way[gracz] == 'H'){
            for (int b = 1; b<4;b++){
                if (tablica[zmienna][x-1][y-1-b] == 'X') {
                    size++;
                }
            }
            for (int f = 1; f<4;f++){
                if (tablica[zmienna][x-1][y-1+f] == 'X') {
                    size++;
                }
            }
        }
        for (int i = 1; i < size+1; i++){
            if (way[gracz] == 'V'){
                if (tablica_shots[gracz][x-1-i][y-1] == '#' || tablica_shots[gracz][x-1+i][y-1] == '#') {
                    tableShots++;
                }
            }
            else if (way[gracz] == 'H'){
                if (tablica_shots[gracz][x-1][y-1-i] == '#' || tablica_shots[gracz][x-1][y-1+i] == '#') {
                    tableShots++;
                }
            }

        }
        cout << tableShots << endl << size+1 << endl;
        if (tableShots == size+1){
            cout << "Hit and Sunk!!" << endl;
            cout << "You shot " << size+1 << "-squared ship!" << endl;
            shots[gracz]++;
            *hit = 2;
        }
        else cout << "Hit! "<<endl;
        *hit = 1;
    }
    else {
        cout << "Miss :((" << endl;
        tablica_shots[gracz][x-1][y-1] = '-';
        *hit = 0;
    }
}

void compShots(int *hit, int *hitComp){
    int zmienna;
    int hitt = *hit;
    
    if (*hitComp == 0){
        cout << "Choose column: ";
        yMain = rand() % 10+1;
        zmiennay = yMain;
        cout << "Choose Row: ";
        xMain = rand() % 10+1;
        zmiennax = xMain;
        playerShots(xMain, yMain, 1, shots[1], &hitt);
        if (hitt == 1) {
            *hitComp = 1;
            *hit = 1;
        }
        else if (hitt == 0) *hit = 0;
    }
        
    else if (*hitComp == 1) {
        bool random = true;
        while (random == true) {
            zmienna = rand() % 4;
            cout << zmienna;
            if (zmienna == 0) {
                //vertical
                if (sides[zmienna] == 0){
                    playerShots(xMain, yMain-1, 1, shots[1], &hitt);
                    if (hitt == 2) {
                        *hitComp = 0;
                        *hit = 1;
                    }
                    else if (hitt == 1){
                        sidesMain = zmienna;
                        wayComp = 'v';
                        *hitComp = 2;
                        *hit = 1;
                    }
                    else if (hitt == 0){
                        *hit = 0;
                    }
                    random = false;
                    sides[zmienna] = 1;
                }
            }
            else if (zmienna == 1){
                if (sides[zmienna] == 0){
                    playerShots(xMain, yMain+1, 1, shots[1], &hitt);
                    if (hitt == 2) {
                        *hitComp = 0;
                        *hit = 1;
                    }
                    else if (hitt == 1){
                        sidesMain = zmienna;
                        wayComp = 'v';
                        *hitComp = 2;
                        *hit = 1;
                    }
                    else if (hitt == 0){
                        *hit = 0;
                    }
                    random = false;
                    sides[zmienna] = 1;
                    
                }
            }
            else if (zmienna == 2){
                //horizontal
                if (sides[zmienna] == 0){
                    playerShots(xMain-1, yMain, 1, shots[1], &hitt);
                    if (hitt == 2) {
                        *hitComp = 0;
                        *hit = 1;
                    }
                    else if (hitt == 1){
                        sidesMain = zmienna;
                        wayComp = 'h';
                        *hitComp = 2;
                        *hit = 1;
                    }
                    else if (hitt == 0){
                        *hit = 0;
                    }
                    random = false;
                    sides[zmienna] = 1;
                }
            }
            else {
                if (sides[zmienna] == 0){
                    playerShots(xMain+1, yMain, 1, shots[1], &hitt);
                    if (hitt == 2) {
                        *hitComp = 0;
                        *hit = 1;
                    }
                    else if (hitt == 1){
                        sidesMain = zmienna;
                        wayComp = 'h';
                        *hitComp = 2;
                        *hit = 1;
                    }
                    else if (hitt == 0){
                        *hit = 0;
                    }
                    random = false;
                    sides[zmienna] = 1;
                }
            }
        }
    }
    else {
        if (wayComp == 'v'){
            bool shoting = true;
            int i =  1;
            int sideOfshot = rand() % 2;
            if (sideOfshot == 0){
                while (shoting == true) {
                    if (tablica_shots[1][xMain][yMain-i] == ' '){
                        playerShots(xMain, yMain-i, 1, shots[1], &hitt);
                        cout << hitt << endl;
                        if (hitt == 2) {
                            *hitComp = 0;
                            sidesMain = 0;
                            *hit = 1;
                        }
                        else if (hitt == 1){
                            *hit = 1;
                        }
                        else {
                            *hit = 0;
                        }
                        shoting = false;
                    }
                    else i++;
                }
            }
            else {
                while (shoting == true) {
                    if (tablica_shots[1][xMain][yMain+i] == ' '){
                        playerShots(xMain, yMain+i, 1, shots[1], &hitt);
                        if (hitt == 2) {
                            *hitComp = 0;
                            sidesMain = 0;
                            *hit = 1;
                        }
                        else if (hitt == 1){
                            *hit = 1;
                        }
                        else {
                            *hit = 0;
                        }
                        shoting = false;
                    }
                    else i++;
                }
            }
        }
        else if (wayComp == 'h'){
            bool shoting = true;
            int i =  1;
            int sideOfshot = rand() % 2;
            if (sideOfshot == 0){
                while (shoting == true) {
                    if (tablica_shots[1][xMain-i][yMain] == ' '){
                        playerShots(xMain-i, yMain, 1, shots[1], &hitt);
                        if (hitt == 2) {
                            *hitComp = 0;
                            sidesMain = 0;
                            *hit = 1;
                        }
                        else if (hitt == 1){
                            *hit = 1;
                        }
                        else {
                            *hit = 0;
                        }
                        shoting = false;
                    }
                    else i++;
                }
            }
            else {
                while (shoting == true) {
                    if (tablica_shots[1][xMain+i][yMain] == ' '){
                        playerShots(xMain+i, yMain, 1, shots[1], &hitt);
                        if (hitt == 2) {
                            *hitComp = 0;
                            sidesMain = 0;
                            *hit = 1;
                        }
                        else if (hitt == 1){
                            *hit = 1;
                        }
                        else {
                            *hit = 0;
                        }
                        shoting = false;
                    }
                    else i++;
                }
            }
        }
    }
    // hit comp po 2 jest 2
    cout << *hitComp << endl;
    cout << yMain << endl;
    cout << xMain << endl;
}

int pvp(){
    int y,x, suma;
    int hit[2] =  {0, 0};
    char yc;
    int turn = 0;
    string names[2];
    bool game = true;
    
    cout << "Name of player 1:" << endl;
    cin >> names[0];
    cout << "Name of player 2:" << endl;
    cin >> names[1];
    system("CLS");
    placeShips(2, names);
    suma = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
    turn = rand() % 2;
    
    if (turn == 1){
        displayShipsIngame(2);
        cout << "Player " << names[1] << " make your shot" << endl;
        cout << "Choose column: ";
        cin >> yc;
        for (int column = 0; column<10; column++){
                if (columns[column] == yc) y = column+1;
            }
        cout << "Choose Row: ";
        cin >> x;   
        playerShots(x, y, 1, shots[1], &hit[1]);
        if (hit[1] == 0) turn = 0;
        displayShipsIngame(2);
        if (shots[1] == suma) {
            cout << "Congratulations! Player "<< names[1] << " won!" <<endl;
            game = false;
        }
        //Sleep(3000);
        //system("CLS");
    }
    while(game == true){
        if (turn == 0){
            displayShipsIngame(1);
            cout << "Player " << names[0] << " make your shot" << endl;
            cout << "Choose column: ";
            cin >> yc;
            for (int column = 0; column<10; column++){
                if (columns[column] == yc) y = column+1;
            }

            cout << "Choose Row: ";
            cin >> x;
            
            playerShots(x, y, 0, shots[0], &hit[0]);
            displayShipsIngame(1);
            if (shots[0] == suma) {
                cout << "Congratulations! Player "<< names[0] << " won!" <<endl;
                game = false;
            } 
            if (hit[0] == 0) turn = 1;
            //Sleep(3000);
            //system("CLS");
        }
        else if (turn == 1){
            displayShipsIngame(2);
            cout << "Player " << names[1] << " make your shot" << endl;
            cout << "Choose column: ";
            cin >> yc;
            for (int column = 0; column<10; column++){
                if (columns[column] == yc) y = column+1;
            }
            cout << "Choose Row: ";
            cin >> x;
            
            playerShots(x, y, 1, shots[1], &hit[1]);
            displayShipsIngame(2);
            if (shots[1] == suma) {
                cout << "Congratulations! Player "<< names[1] << " won!" <<endl;
                game = false;
            }
            if (hit[1] == 0) turn = 0;
            //Sleep(3000);
            //system("CLS");
        }
    
    /*

    in hit make a move once again when hit
     
     */
    
    }
    return 0;
}

int pve(){
    srand (time(NULL));
    int y, x, suma;
    int hit[2] =  {0, 0};
    int hitComp = 0;
    char yc;
    int turn = 0;
    string names[1];
    bool game = true;

    cout << "Name of player:" << endl;
    cin >> names[0];
    system("CLS");
    placeShips(1, names);
    placeCompShips();
    suma = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
    //computer was able to set X amount of ships what do you want to do: A - stay like that, B - change yours ships, C - reshuffle
    turn = rand() % 2;

    if (turn == 1){
        // random computer shots (inteligenty)
        displayShipsIngame(2);
        cout << "Computer make your shot" << endl;
        compShots(&hit[1], &hitComp);
        if (hit[1] == 0) turn = 0;
        displayShipsIngame(2);
        if (shots[1] == suma) {
            cout << "Congratulations! Computer won!" <<endl;
            game = false;
        }
        //Sleep(3000);
        //system("CLS");
    }
    while(game == true){
        if (turn == 0){
            displayShipsIngame(1);
            cout << "Player " << names[0] << " make your shot" << endl;
            cout << "Choose column: ";
            cin >> yc;
            for (int column = 0; column<10; column++){
                if (columns[column] == yc) y = column+1;
            }

            cout << "Choose Row: ";
            cin >> x;
            
            playerShots(x, y, 0, shots[0], &hit[0]);
            if (hit[0] == 0) turn = 1;
            displayShipsIngame(1);
            if (shots[0] == suma) {
                cout << "Congratulations! Player "<< names[0] << " won!" <<endl;
                game = false;
            }
            //Sleep(3000);
            //system("CLS");
        }
        else if (turn == 1){
            displayShipsIngame(2);
            cout << "Computer make your shot" << endl;
            compShots(&hit[1], &hitComp);
            displayShipsIngame(2);
            if (hit[1] == 0) turn = 0;
            if (shots[1] == suma) {
                cout << "Congratulations! Computer won!" <<endl;
                game = false;
            }
            //Sleep(3000);
            //system("CLS");
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    string tryb;
    int trybint;
    bool choosing = true;
    bool game = true;
    string odp;
    while (game == true){
        while (choosing == true){
            cout << "Choose gamemode:" << endl;
            cout << "Player vs. Player <- PvP"<< endl << "Player vs. Computer  <- PvE"<< endl;
            cin >> tryb;
            if (tryb == "PvP" || tryb == "PvE" || tryb == "pvp" || tryb == "pve"){
                if (tryb == "PvP" || tryb == "pvp") trybint = 1;
                else trybint = 0;
                choosing = false;
            }
            else {
                cout << "Not allowed input, try again" << endl;
                cout << "Allowed inputs: PvP, PvE, pvp, pve" << endl;
            }
        }
        //system("CLS");
        if (trybint == 1) pvp();
        else pve();
        system("CLS");
        cout << "Do you want to play again? (yes or no)" << endl;
        cin >> odp;
        if (odp == "no") game = false;
        else {
            for (int z = 0;z<2;z++){
                for (int x = 0;x < 10;x++){
                    for (int y = 0;y<10;y++){
                        tablica[z][x][y] = ' ';
                        tablica_shots[z][x][y] = ' ';
                        tablica_sprawdzajaca[z][x+1][y+1] = 0;
                    }
                }
            }
        }
        system("CLS");
    }
    return 0;
}
