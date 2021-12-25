//
//  main.cpp
//  statki
//


#include <iostream>
#include <vector>
using namespace std;


int tablica_sprawdzajaca[2][10][10] = {
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
};

char tablica[2][10][10] = {
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
                tablica_sprawdzajaca[gracz-1][polex-2][poley-2+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex-1][poley-2+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex][poley-2+j] = 1;
            }
        }
    }
    else if (stronaOs == "vertically"){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-2+j][poley-2] = 1;
                tablica_sprawdzajaca[gracz-1][polex-2+j][poley-1] = 1;
                tablica_sprawdzajaca[gracz-1][polex-2+j][poley] = 1;
            }
        }
    }
    else if(stronaOs == "single"){
        for (int j=0;j<x;j++){
            for(int i=0; i<3;i++){
                tablica_sprawdzajaca[gracz-1][polex-2][poley-2+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex-1][poley-2+j] = 1;
                tablica_sprawdzajaca[gracz-1][polex][poley-2+j] = 1;
            }
        }
    }
}

bool around_check(int wyborDlugosci,int polex,int poley, string kierunekStatku, int gracz){
    bool sprawdzanieMiejsca = true;
    int zmiennax, zmiennay;
    if (kierunekStatku == "horizontally"){
        zmiennay = wyborDlugosci+2;
        zmiennax = 3;
    }
    else if (kierunekStatku == "vertically"){
        zmiennax = wyborDlugosci+2;
        zmiennay = 3;
    }
    else {
        zmiennax = 3;
        zmiennay = 3;
    }
    
    for(int x= 0; x<zmiennax;x++){
        for(int y = 0; y<zmiennay; y++){
            if(tablica_sprawdzajaca[gracz-1][x][y]==1) sprawdzanieMiejsca=false;
        }
    }
    return sprawdzanieMiejsca;
}

int choose_ships(int statkiGraczy[4]){
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
        else statkiGraczy[nrStatku] = ilosc;
    }
    cout << endl;
    
    while (powtorzenie == true) {
        cout << "Current amount of ships:"<< endl;
        cout << "-------------------------" << endl;
        for (int z = 0; z<4; z++){
            cout << z+1 << "-square ships: " << statkiGraczy[z+1] << endl;
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
            change_ships(nrStatku, iloscStatku, statkiGraczy, &suma);
        }
        else powtorzenie = false;
    }
    return 0;
}
 
int pvp(){
    choose_ships(statkiGracza);
    
    for(int gracz = 1; gracz<=2;gracz++){
        int wyborDlugosci, polex, poley, statkiGracza1, statkiGracza2;
        string stronaOs;
        cout << "Place ships - Player " << gracz << endl;
        cout << "---------------------------" << endl << endl;
        
        statkiGracza1 = statkiGracza[0] + statkiGracza[1] +statkiGracza[2] + statkiGracza[3];
        // policz tutaj sume statkow, wstaw za 10 na dole
        for(int y =0; y<statkiGracza1;y++){
            cout << "     1 2 3 4 5 6 7 8 9 10               "<< "Ships left"<< endl;
            cout << "   * * * * * * * * * * * *              "<<"-----------------" <<endl;
            for (int i =0;i<10;i++){
                if (i==9) cout << i+1 << " ";
                else cout << i+1 << "  ";
                cout << "* ";
                for(int j = 0; j<10;j++){
                    cout << tablica[gracz-1][i][j] << " ";
                }
                if(i<4){
                    cout << "*              Ship " << i+1 <<": " << statkiGracza[i+1] << endl;
                }
                else cout << "* " << endl;
            }
            cout << "   * * * * * * * * * * * *"<< endl << endl;
            cout << "----------------------------" << endl;
            cout << "If chosen ship has more than 1 square, it'll be placed either vertically or horizontally from chosen square";
            cout << endl;
            cout << "Which ship do you want to place?" << endl;
            cin >> wyborDlugosci;
            cout << "Choose square" << endl;
            cout << "Column: ";
            cin >> poley;
            cout << "Row: ";
            cin >> polex;
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
                statkiGracza[wyborDlugosci]--;
            }
            else{
                cout << "You can't place it here" << endl;
                cout << "----------------------------" << endl << endl;
                y--;
            }
        }
    }
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
