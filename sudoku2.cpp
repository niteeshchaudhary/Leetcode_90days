#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
vector<unordered_map<char,bool>> row(9);
vector<unordered_map<char,bool>> col(9);
vector<unordered_map<char,bool>> box(9);
class Solution {
public:
    bool solve(vector<vector<char>>& board,int i,int j) {
        if(j==9){
            cout<<"next";
            j=j%9;
            i++;
        }
        if(i==9){
            cout<<"ys\n";
            return true;
        }
        if(board[i][j]!='.'){
            return solve(board,i,j+1);  
        }
        for(char ch='1';ch<='9';ch++){
            if(i==5 &&j==1&& ch=='1' ){
            cout<<!row[i][ch] <<" "<< !col[j][ch] <<" "<< !box[3*(i/3)+j/3][ch]<<")\n";        
            }
            
            if(!row[i][ch] && !col[j][ch] && !box[3*(i/3)+j/3][ch]){
                board[i][j]=ch;
                cout<<i<<" "<<j<<" "<<ch<<"\n";
                
                row[i][board[i][j]]=true;
                col[j][board[i][j]]=true;
                box[3*(i/3)+j/3][board[i][j]]=true;
                bool rs = solve(board,i,j+1);
                if(rs==false){
                    row[i][board[i][j]]=false;
                    col[j][board[i][j]]=false;
                    box[3*(i/3)+j/3][board[i][j]]=false;
                    board[i][j]='.';
                }
                else{
                    cout<<rs<<".\n";
                    return true;
                }
            }
        }
        cout<<i<<" "<<j<<" "<<" .. ..\n";
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool fnd=false;
        int si=-1,sj=-1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[i][board[i][j]]=true;
                    col[j][board[i][j]]=true;
                    box[3*(i/3)+j/3][board[i][j]]=true;
                }
                else{
                    if(!fnd){
                        fnd=true;
                        si=i;
                        sj=j;
                    }

                }
            }
        }
        bool rs= solve(board,si,sj);
        cout<<rs;  
    }
};
int main(){
    Solution s;
    vector<vector<char>> board={{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    s.solveSudoku(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}