// Created by Niteesh Kamal Chaudhary on 09-07-2024
#include<vector>
#include<unordered_map>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
    
public:
    vector<vector<char>> solveSudoku(vector<vector<char>>& board) {
        stack<vector<vector<char>>> st;
        st.push(board);
        while(!st.empty()){
            vector<vector<char>> pr= st.top();
            st.pop();

            bool fnd=false;
            vector<unordered_map<char,bool>> row(9);
            vector<unordered_map<char,bool>> col(9);
            vector<unordered_map<char,bool>> box(9);
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(pr[i][j]=='.'){
                        //cout<<"got "<<i<<" "<<j<<" \n";
                        
                        for(int ii=i;ii<9;ii++){
                            for(int jj=j;jj<9;jj++){
                                if(pr[ii][jj]!='.'){
                                        row[ii][pr[ii][jj]]=true;
                                        col[jj][pr[ii][jj]]=true;
                                        box[3*(ii/3)+jj/3][pr[ii][jj]]=true;
                                }
                            }
                        }
                        
                        for(char ch='1';ch<='9';ch++){
                            pr[i][j]=ch;
                            if (!row[i][pr[i][j]] && !col[j][pr[i][j]] && !box[3*(i/3)+j/3][pr[i][j]]){
                                st.push(pr);
                            }
                            // mp[i*1000+j*100+ch]=true;
                        }
                        fnd=true;
                        break;
                    }
                }
                if(fnd){
                    break;
                }
            }
            if(!fnd){
                return pr;
            }
        }
        cout<<"here\n";
        return board;
    }
};
{{'3','1','2','5','4','7','8','6','9'}
{'9','4','7','6','8','1','2','3','5'}
{'6','5','8','9','3','2','7','1','4'}
{'1','8','5','3','6','4','9','7','2'}
{'2','9','3','7','1','8','4','5','6'}
{'4','7','6','2','9','5','3','8','1'}
{'8','6','4','1','2','3','5','9','7'}
{'7','2','9','8','5','6','1','4','3'}
{'5','3','1','4','7','9','6','2','8'}}

int main(){
    Solution s;
    vector<vector<char>> board={{'.','.','.','.','.','7','.','.','9'},{'.','4','.','.','8','1','2','.','.'},{'.','.','.','9','.','.','.','1','.'},{'.','.','5','3','.','.','.','7','2'},{'2','9','3','.','.','.','.','5','.'},{'.','.','.','.','.','5','3','.','.'},{'8','.','.','.','2','3','.','.','.'},{'7','.','.','.','5','.','.','4','.'},{'5','3','1','.','7','.','.','.','.'}};

    board=s.solveSudoku(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}