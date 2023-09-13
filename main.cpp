#include <iostream>

using namespace std;

void printMatrix(int board[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++)
            cout << "\033[32m" << board[i][j] << "|" << "\033[0m";
        cout << endl;
    }
}

void placeQueen(int row, int column, int (*board)[8][8]){
    // * Fill around it
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if((row==0 and i==-1) or (column==0 and j==-1) or (column==7 and j==1) or (row==7 and i==1)){
                continue;
            }
        (*board)[row+i][column+j] = 2;
        }
    }    

    for(int i = 0; i < 8; i++){
        (*board)[row][i] = 2;
    }

    for(int i = 0; i < 8; i++){
        (*board)[i][column] = 2;
    }

    int yAsc, yDesc, xAsc, xDesc;

    for(int i = 1; i < 8; i++){
        yAsc = row+i;
        yDesc = row-i;
        xAsc = column+i;
        xDesc = column-i;

        (*board)[yAsc][xAsc] = 2;
        (*board)[yAsc][xDesc] = 2;

        (*board)[yDesc][xDesc] = 2;
        (*board)[yDesc][xAsc] = 2;
    }   

    (*board)[row][column] = 1;
}

int main(){

    int board[8][8] = {0}, r, c = 0, count = 1;

    int winingboards[8][8][100];

    placeQueen(5, 3, &board);
    
    printMatrix(board);

    return 0;
}

