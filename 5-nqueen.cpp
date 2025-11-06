#include <bits/stdc++.h>
using namespace std;
#define N 8

void printBoard(vector<vector<int>>& board){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout<<(board[i][j]?"Q ":"_ ");
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>& board,int row,int col){
    for(int i=0;i<N;i++) if(board[i][col]) return false;
    for(int j=0;j<N;j++) if(board[row][j]) return false;
    for(int i=-N;i<=N;i++){
        if(row+i>=0&&row+i<N&&col+i>=0&&col+i<N)
            if(board[row+i][col+i]) return false;
        if(row+i>=0&&row+i<N&&col-i>=0&&col-i<N)
            if(board[row+i][col-i]) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board,int row,int fixed_row){
    if(row==N) return true;
    if(row==fixed_row) return solve(board,row+1,fixed_row);
    for(int col=0;col<N;col++){
        if(isSafe(board,row,col)){
            board[row][col]=1;
            if(solve(board,row+1,fixed_row)) return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int fixed_row,fixed_col;
    cout<<"Enter the row & column where the first queen is placed:\n";
    cout<<"(Note that rows and columns are from 0 - 7)\n";
    cout<<"Enter the row number: ";
    cin>>fixed_row;
    cout<<"Enter the column number: ";
    cin>>fixed_col;
    vector<vector<int>> board(N,vector<int>(N,0));
    board[fixed_row][fixed_col]=1;
    if(solve(board,0,fixed_row)) printBoard(board);
    else cout<<"No solution found.\n";
    return 0;
}
