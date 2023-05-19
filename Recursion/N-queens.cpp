#include<iostream>
#include<vector>
using namespace std;
/*
   The n-queens puzzle is the problem of placing n queens on an n x n
   chessboard such that no two queens attack each other.
*/


bool isSafe(int i,int j,vector<vector<char>>&chessBoard,int n){
        int tempI = i;
        while(tempI>=0){
            if(chessBoard[tempI][j] == 'Q') return false;
            tempI--;
        }
        tempI = i;
        int tempJ = j;

        //top-right
        while(tempI>=0 && tempJ<=n-1){
            if(chessBoard[tempI][tempJ] == 'Q') return false;
            tempI--;
            tempJ++;
        }

        tempI = i;
        tempJ = j;

        //top-left
        while(tempI>=0 && tempJ>=0){
            if(chessBoard[tempI][tempJ] == 'Q') return false;
            tempI--;
            tempJ--;
        }

        return true;
    }


    void help(int i,int n,vector<vector<char>>&chessBoard,vector<vector<string>>&ans){
        if(i == n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string currRow = "";
                for(int j=0;j<n;j++){
                    currRow.push_back(chessBoard[i][j]);
                }
                temp.push_back(currRow);
            }
            ans.push_back(temp);
            return;
        }
        for(int j = 0;j<n;j++){
            if(isSafe(i,j,chessBoard,n)){
                chessBoard[i][j] = 'Q';
                help(i+1,n,chessBoard,ans);
                chessBoard[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>chessBoard(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        help(0,n,chessBoard,ans);
        return ans;
    }


// for understanding purpose
int isSafe(char board[][4],int r, int c,int n){
    // check for the column
    for(int i=0;i<r;i++){
        if(board[i][c] == 'Q'){
            return 0;
        }
    }
    // '\'
    for(int i=r,j=c; i>=0 && j>=0;j--,i--){
        if(board[i][j] == 'Q'){
            return 0;
        }
    }
    // '/'
    for(int i=r,j=c;i>=0 && j<n;i--,j++){
        if(board[i][j] == 'Q'){
            return 0;
        }
    }
    return 1;
}

void printSol(char board[][4],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nQueen(char board[][4],int r, int n){
    if(r == n){
        printSol(board,n);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(board,r,i,n)){
            board[r][i] = 'Q';
            nQueen(board,r+1,n);
            board[r][i] = '-';
        }
    }
}

int main() {
    char board[4][4];
    memset(board, '-', sizeof board);
    nQueen(board,0,4);
    
    return 0;
}