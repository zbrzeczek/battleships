//
//  main.cpp
//  statki
//


#include <iostream>
#include <vector>
using namespace std;

void change_of_ships(int nrGracza,int nrStatku, int iloscStatku, int statkiGraczy[2][4], int* suma){
    int x = statkiGraczy[nrGracza][nrStatku];
    *suma = *suma - (x*2) - 2;
    if (*suma + (iloscStatku*2)+2 > 100){
        cout << "Za dużo pół" << endl << "Spróbuj ponownie";
        cout << endl;
        cout << "-------------------------------" << endl << endl;
    }
    else statkiGraczy[nrGracza][nrStatku] = iloscStatku;
}

int ship_for_players(int statkiGraczy[2][4]){
    for (int nrGracza = 1; nrGracza <=2; nrGracza++){
        int nrStatku, iloscStatku;
        bool powtorzenie = true;
        int decyzja;
        cout << endl << "-------------------------------" << endl;
        cout << "Wybor ilosci statkow gracza " << nrGracza << endl;
        cout << "-------------------------------" << endl << endl;
        int ilosc, suma = 0, sum;
        for (int nrStatku = 4; nrStatku > 0; nrStatku--){
            cout << "wpisz ilosc " << nrStatku << "-polowych statkow" << endl;
            cin >> ilosc;
            int zmienna = nrStatku + nrStatku +2;
            sum = ilosc * zmienna;
            suma = suma + sum;
            if (suma > 100){
                cout << "za dużo statkow " << nrStatku << endl;
                nrStatku++;
                suma = suma - sum;
            }
            else statkiGraczy[nrGracza][nrStatku] = ilosc;
        }
        cout << endl;
        cout << "łączna suma wynosi: " << suma << endl;
        cout << "-------------------------------" << endl << endl;
        
        while (powtorzenie == true) {
            cout << "Aktualna liczba statkow:"<< endl;
            cout << "-------------------------" << endl;
            for (int z = 0; z<4; z++){
                cout << "statkow " << z+1 << " jest " << statkiGraczy[nrGracza][z+1] << endl;
            }
            cout << "-------------------------" << endl << endl;
            cout << "Po rozpoczęciu gry nie bedzie opcji zmiany liczby statków" << endl <<endl;
            cout << "Czy chcesz zmienic liczbe statkow? " << endl << "Tak  <- 1" << endl<< "Nie  <- 2" << endl;
            cin >> decyzja;
            cout << endl;
            if (decyzja == 1) {
                cout << "Które statki chcesz zmienić" << endl;
                cin >> nrStatku;
                cout << "Na jaką ilość chcesz zmienić:" << endl;
                cin >> iloscStatku;
                change_of_ships(nrGracza, nrStatku, iloscStatku, statkiGraczy, &suma);
            }
            else powtorzenie = false;
        }
    }
    return statkiGraczy[2][4];
}
 

int pvp(){
    int statkiGraczy[2][4];
    ship_for_players(statkiGraczy);
    
    int tablica_sprawdzajaca[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    char tablica[10][10] = {{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '},{' ',' ',' ', ' ', ' ',' ',' ',' ', ' ', ' '}};
    
    for(int j = 1; j<=2;j++){
        int wybor, polex, poley;
        string stronaOs;
        cout << "wybór zajetych pol gracza " << j << endl;
        cout << "---------------------------" << endl << endl;
        
        // policz tutaj sume statkow, wstaw za 10 na dole
        for(int y =0; y<10;y++){
            cout << "     1 2 3 4 5 6 7 8 9 10               "<< "Pozostałe statki"<< endl;
            cout << "   * * * * * * * * * * * *              "<<"-----------------" <<endl;
            for (int i =0;i<10;i++){
                if (i==9) cout << i+1 << " ";
                else cout << i+1 << "  ";
                cout << "* ";
                for(int j = 0; j<10;j++){
                    cout << tablica[i][j] << " ";
                }
                if(i<4){
                    cout << "*              Statkek " << i+1 <<": " << statkiGraczy[j][i+1] << endl;
                }
                else cout << "* " << endl;
            }
            cout << "   * * * * * * * * * * * *"<< endl << endl;
            cout << "----------------------------" << endl;
            cout << "Jeżeli wybrany statek ma ponad 1 pole, pola zostaną osadzone w prawą strone od wybranego pola (poziomo) lub w dół od wybranego pola (pionowo)";
            cout << endl;
            cout << "Ktory statek chcesz osadzic? " << endl;
            cin >> wybor;
            cout << "Podaj pole osadzenia statku" << endl;
            cout << "Kolumna: ";
            cin >> polex;
            cout << "Wiersz: ";
            cin >> poley;
            if (tablica_sprawdzajaca[polex][poley] == 0){
                if (wybor >1){
                    cout << "W którą strone chcesz osadzić statek (poziomo lub pionowo)"<<endl;
                    cin >> stronaOs;
                    for (int j=0;j<wybor;j++){
                        if (stronaOs == "poziomo") {
                            tablica_sprawdzajaca[polex-2][poley-1+j] = 1;
                            tablica_sprawdzajaca[polex-1][poley-1+j] = 1;
                            tablica_sprawdzajaca[polex][poley-1+j] = 1;
                            tablica[polex-1][poley+j-1] = 'X';
                        }
                        else if (stronaOs == "pionowo") {
                            tablica[polex+j-1][poley-1] = 'X';
                            tablica_sprawdzajaca[polex-1+j][poley-2] = 1;
                            tablica_sprawdzajaca[polex-1+j][poley-1] = 1;
                            tablica_sprawdzajaca[polex-1+j][poley] = 1;
                        }
                    }
                    if (stronaOs == "poziomo") {
                        tablica_sprawdzajaca[polex-2][poley-2] = 1;
                        tablica_sprawdzajaca[polex-1][poley-2] = 1;
                        tablica_sprawdzajaca[polex][poley-2] = 1;
                    }
                    else if (stronaOs == "pionowo") {
                        tablica_sprawdzajaca[polex-1+j][poley-2] = 1;
                        tablica_sprawdzajaca[polex-1+j][poley-1] = 1;
                        tablica_sprawdzajaca[polex-1+j][poley] = 1;
                    }
                }
                else tablica[polex -1][poley-1] = 'X';
                statkiGraczy[j][wybor]--;
            }
            else {
                cout << "Dane pole jest już zajęte, spróbuj ponownie" << endl << endl;
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
    cout << "wybierz tryb gry:" << endl;
    cout << "Player vs. Player  <- 1"<< endl << "Player vs. Computer  <- 2"<< endl;
    cin >> tryb;
    
    if (tryb == 1) pvp();
    else pve();
    
    char player[10][10], player2[10][10];
    
    
    cout << endl;
    return 0;
}
