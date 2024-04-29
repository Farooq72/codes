#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<vector<int>> &board,int row,int col,int N){
    for(int i=0;i<row;++i){
        if(board[i][col] ==1){
            return false;
        }
    }

    for(int i=row,j = col;i>=0 &&j>=0;--i,--j){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i=row,j = col;i>=0 &&j<N;--i,j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

bool solveNqueensUtil(vector<vector<int>> &board,int row,int N){
    if(row >=N){
        return true;
    }

    for(int col =0;col<N;++col){
        if(issafe(board,row,col,N)){
            board[row][col] = 1;
            if(solveNqueensUtil(board,row+1,N)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;

}

void SolveNqueens(int N){
    vector<vector<int>> board(N,vector<int>(N,0));
    if(solveNqueensUtil(board,0,N)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << board[i][j] <<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"There is no solution exists";
    }
}

int main(){
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    SolveNqueens(N);
}