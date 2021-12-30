//
//  main.cpp
//  statki
//


#include <iostream>
#include <stdlib.h>
#include <vector>
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

int statkiGracza[4];
char player[10][10], player2[10][10];

void change_ships(int nrStatku, int iloscStatku, int statkiGracza[4], int* suma){
    int x = statkiGracza[nrStatku-1];
    *suma = *suma - (x*2) - 2;
    if (*suma + (iloscStatku*2)+2 > 100){
        cout << "There's too little space for that" << endl << "Try again";
        cout << endl;
        cout << "-------------------------------" << endl << endl;
    }
    else statkiGracza[nrStatku-1] = iloscStatku;
}

void around(int wyborDlugosci, string stronaOs, int polex, int poley, int gracz){
    int x = wyborDlugosci+2;
    if (stronaOs == "horizontally"){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-1][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex+1][poley-1+j] = 1;
            }
        }
    }
    else if (stronaOs == "vertically"){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-1+j][poley-1] = 1;
                tablica_sprawdzajaca[gracz-1][polex-1+j][poley] = 1;
                tablica_sprawdzajaca[gracz-1][polex-1+j][poley+1] = 1;
            }
        }
    }
    else if(stronaOs == "single"){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-1][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex][poley-1+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex+1][poley-1+j] = 1;
            }
        }
    }
}

bool around_check(int wyborDlugosci,int polex,int poley, string kierunekStatku, int gracz){
    bool sprawdzanieMiejsca = true;
    for(int y = 0; y<wyborDlugosci; y++){
        if (kierunekStatku == "horizontally"){
            if(tablica_sprawdzajaca[gracz-1][polex][poley+y]==1) sprawdzanieMiejsca=false;
        }
        else if (kierunekStatku == "vertically"){
            if(tablica_sprawdzajaca[gracz-1][polex+y][poley]==1) sprawdzanieMiejsca=false;
        }
        else {
            if(tablica_sprawdzajaca[gracz-1][polex][poley]==1) sprawdzanieMiejsca=false;
        }
    }
    return sprawdzanieMiejsca;
}

void choose_ships(int statkiGracza[4]){
    int nrStatku, iloscStatku;
    bool powtorzenie = true;
    int decyzja;
    cout << endl << "-------------------------------" << endl;
    cout << "Choose the amount of ships" << endl;
    cout << "-------------------------------" << endl << endl;
    int ilosc, suma = 0, sum;
    for (int nrStatku = 4; nrStatku > 0; nrStatku--){
        cout << "Choose " << nrStatku << "-square ships" << endl;
        cin >> ilosc;
        int zmienna = nrStatku + nrStatku +2;
        sum = ilosc * zmienna;
        suma = suma + sum;
        if (suma > 100){
            cout << "Too much ships " << nrStatku << endl;
            nrStatku++;
            suma = suma - sum;
        }
        else statkiGracza[nrStatku-1] = ilosc;
    }
    cout << endl;
    
    while (powtorzenie == true) {
        cout << "Current amount of ships:"<< endl;
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
            cout << "Which ships do you want to change?" << endl;
            cin >> nrStatku;
            cout << "Type the amount of ship:" << endl;
            cin >> iloscStatku;
            cout << endl;
            change_ships(nrStatku, iloscStatku, statkiGracza, &suma);
        }
        else powtorzenie = false;
    }
}

void display_ships(int gracz){
    cout << "     1 2 3 4 5 6 7 8 9 10               "<< endl;
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

void display_ingame(int gracz){
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
    cout << "-------------------------------------------------------" << endl;
}

void place_ships(int iloscGraczy, string names[2]){
    int suma;
    choose_ships(statkiGracza);
    int zmiennaTablica[4];
    for(int gracz = 1; gracz<=iloscGraczy;gracz++){
        zmiennaTablica[0] = statkiGracza[0];
        zmiennaTablica[1] = statkiGracza[1];
        zmiennaTablica[2] = statkiGracza[2];
        zmiennaTablica[3] = statkiGracza[3];
        int wyborDlugosci, polex, poley;
        string stronaOs;
        
        cout << "Place ships - Player " << names[gracz-1] << endl;
        cout << "---------------------------" << endl << endl;
        
        suma = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
        display_ships(gracz);
        cout << endl << endl << endl;
        for(int y =0; y<suma;y++){
            cout << "Ships left"<< endl;
            cout << "-----------------" <<endl;
            for (int i =0;i<4;i++){
                    cout << "Ship " << i+1 <<": " << zmiennaTablica[i] << endl;
                }
            cout << endl;
            cout << "If chosen ship has more than 1 square, it'll be placed either vertically or horizontally from chosen square";
            cout << endl;
            cout << "Which ship do you want to place?" << endl;
            cin >> wyborDlugosci;
            cout << "Choose square" << endl;
            cout << "Column: ";
            cin >> poley;
            cout << "Row: ";
            cin >> polex;
            cout << endl;
            if (wyborDlugosci >1){
                cout << "Choose direction (vertically or horizontally)"<<endl;
                cin >> stronaOs;
            }
            else stronaOs="single";
            
            if (around_check(wyborDlugosci, polex, poley, stronaOs, gracz) == true){
                around(wyborDlugosci, stronaOs, polex, poley,gracz);
                if (stronaOs == "horizontally"){
                    for (int j=0;j<wyborDlugosci;j++){
                        tablica[gracz-1][polex-1][poley-1+j] = 'X';
                    }
                }
                else if (stronaOs == "vertically"){
                    for (int j=0;j<wyborDlugosci;j++){
                        tablica[gracz-1][polex-1+j][poley-1] = 'X';
                    }
                }
                else if(stronaOs == "single"){
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
            display_ships(gracz);
        }
        cout << "You placed all your ships!!" << endl;
        cout << "---------------------------" << endl << endl;
    }
}

int pvp(){
    int y,x;
    int turn = 0;
    string names[2];
    bool game = true;
    
    cout << "Name of player 1:" << endl;
    cin >> names[0];
    cout << "Name of player 1:" << endl;
    cin >> names[1];
    /*int suma;
    choose_ships(statkiGracza);
    int zmiennaTablica[4];
    for(int gracz = 1; gracz<=2;gracz++){
        // zrob to jakos zeby byla dodatkowa zmienna zeby kazda z osob miala osobne odliczanie przy statkach stawianiu
        zmiennaTablica[0] = statkiGracza[0];
        zmiennaTablica[1] = statkiGracza[1];
        zmiennaTablica[2] = statkiGracza[2];
        zmiennaTablica[3] = statkiGracza[3];
        int wyborDlugosci, polex, poley;
        string stronaOs;
        
        cout << "Place ships - Player " << gracz << endl;
        cout << "---------------------------" << endl << endl;
        
        suma = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
        display_ships(gracz);
        cout << endl << endl << endl;
        for(int y =0; y<suma;y++){
            cout << "Ships left"<< endl;
            cout << "-----------------" <<endl;
            for (int i =0;i<4;i++){
                    cout << "Ship " << i+1 <<": " << zmiennaTablica[i] << endl;
                }
            cout << endl;
            cout << "If chosen ship has more than 1 square, it'll be placed either vertically or horizontally from chosen square";
            cout << endl;
            cout << "Which ship do you want to place?" << endl;
            cin >> wyborDlugosci;
            cout << "Choose square" << endl;
            cout << "Column: ";
            cin >> poley;
            cout << "Row: ";
            cin >> polex;
            cout << endl;
            if (wyborDlugosci >1){
                cout << "Choose direction (vertically or horizontally)"<<endl;
                cin >> stronaOs;
            }
            else stronaOs="single";
            
            if (around_check(wyborDlugosci, polex, poley, stronaOs, gracz) == true){
                around(wyborDlugosci, stronaOs, polex, poley,gracz);
                if (stronaOs == "horizontally"){
                    for (int j=0;j<wyborDlugosci;j++){
                        tablica[gracz-1][polex-1][poley-1+j] = 'X';
                    }
                }
                else if (stronaOs == "vertically"){
                    for (int j=0;j<wyborDlugosci;j++){
                        tablica[gracz-1][polex-1+j][poley-1] = 'X';
                    }
                }
                else if(stronaOs == "single"){
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
            display_ships(gracz);
        }
    }
     */
    place_ships(2, names);
    
    turn = rand() % 2;
    
    /*if (turn == 1){
        display_ingame(2);
        turn = 0;
    }*/
    //while(game == true){
        if (turn == 0){
            display_ingame(1);
            cout << "Make your shot" << endl;
            cout << "Choose column: ";
            cin >> y;
            cout << "Choose Row: ";
            cin >> x;
            
            if (tablica[1][x-1][y-1] == 'X') {
                cout << "Hit!!" << endl;
                tablica_shots[0][x-1][y-1] = '#';
            }
            else {
                cout << "Miss :((" << endl;
                tablica_shots[0][x-1][y-1] = '-';
            }
            turn = 1;
        }
        else if (turn == 1){
            display_ingame(2);
            cout << "Make your shot" << endl;
            cout << "Choose column: ";
            cin >> y;
            cout << "Choose Row: ";
            cin >> x;
            
            if (tablica[0][x-1][y-1] == 'X') {
                cout << "Hit!!" << endl;
                tablica_shots[1][x-1][y-1] = '#';
            }
            else {
                cout << "Miss :((" << endl;
                tablica_shots[1][x-1][y-1] = '-';
            }
            turn = 0;
        }
    //}
    
    
    //display how many ships are available
    
    //in dispaly do ABCD not 1234

    /*
     
     make shot
     
     diplay the outcome
     
     check if its win
     
     player 2 the same
     
     */
    
    return 0;
    
}


int pve(){
    
    return 0;
}


int main() {
    int tryb;
    cout << "Choose gamemode:" << endl;
    cout << "Player vs. Player  <- 1"<< endl << "Player vs. Computer  <- 2"<< endl;
    cin >> tryb;
    
    if (tryb == 1) pvp();
    else pve();
    
    
    
    cout << endl;
    return 0;
}
