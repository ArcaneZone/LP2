#include<bits/stdc++.h>
using namespace std;

void printBoard( vector<vector<int>> chess){
    int N=chess.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isValid(vector<vector<int>>chess,int row,int col){
    //checking in the same row
    for(int i=0;i<col;i++)
        if(chess[row][i])
            return false;
    
    //checking in the dioganal upper left
    int i,j;
    int N=chess.size();
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(chess[i][j])
            return false;
    }
    //checking in the dioganal lower left
    for(i=row,j=col;i< N && j>=0;i++,j--){
        if(chess[i][j])
            return false;
    }
    return true;
}
bool nQueens(vector<vector<int>>& chess,int col){
    int N=chess.size();
    if(col>=N)
        return true;
    
    for(int i=0;i<N;i++){
        if(isValid(chess,i,col)){
            chess[i][col]=1;
            printBoard(chess);
            cout<<endl;
        if(nQueens(chess,col+1))
            return true;
        cout<<"backtracking";
        chess[i][col]=0;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> chess={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    if(nQueens(chess,0)==false){
        cout<<"NO SOLUTION FOUND";
    }
}