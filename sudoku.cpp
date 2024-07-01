// #include<vector>
// #include<unordered_map>
// #include<iostream>
// #include<stack>
// using namespace std;
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<unordered_map<char,bool>> row(9);
//         vector<unordered_map<char,bool>> col(9);
//         vector<unordered_map<char,bool>> box(9);
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 if(board[i][j]!='.'){
//                     if(!row[i][board[i][j]] && !col[j][board[i][j]] && !box[3*(i/3)+j/3][board[i][j]]){
//                         row[i][board[i][j]]=true;
//                         col[j][board[i][j]]=true;
//                         box[3*(i/3)+j/3][board[i][j]]=true;
//                     }
//                     else{
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
   

//     void solveSudoku(vector<vector<char>>& board) {
//         stack<pair<vector<vector<char>>,vector<int>>> st;
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 if(board[i][j]=='.'){
//                     st.push({board,{i,j}});
//                 }
//             }
//         }
//         while(!st.empty()){
//             pair<vector<vector<char>>,vector<int>> pr= st.top();
//             st.pop();
//             for(char ch='1';ch<='9';ch++){
//                 pr.first[pr.second[0]][pr.second[1]]=ch;
//                 if (isValidSudoku(pr.first)){
//                     bool fnd=false;
//                     int i=0,j=0;
//                     for(;i<board.size();i++){
//                         for( j=0;j<board[i].size();j++){
//                             if(board[i][j]=='.'){
//                                 st.push({pr.first,{i,j}});
//                                 fnd=true;
//                                 break;
//                             }
//                         }
//                         if(fnd){
//                             break;
//                         }
//                     }
//                     if(!fnd){
//                         cout<<"got "<<i<<" "<<j<<" \n";
//                         board= pr.first;
//                         return;
//                     }
//                 }

//             }
//         } 
//     }
// };

// int main(){
//     Solution s;
//     vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},
//                                 {'6','.','.','1','9','5','.','.','.'},
//                                 {'.','9','8','.','.','.','.','6','.'},
//                                 {'8','.','.','.','6','.','.','.','3'},
//                                 {'4','.','.','8','.','3','.','.','1'},
//                                 {'7','.','.','.','2','.','.','.','6'},
//                                 {'.','6','.','.','.','.','2','8','.'},
//                                 {'.','.','.','4','1','9','.','.','5'},
//                                 {'.','.','.','.','8','.','.','7','9'}};
//     s.solveSudoku(board);
//     for(int i=0;i<board.size();i++){
//         for(int j=0;j<board[i].size();j++){
//             cout<<board[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }


/*********************************** */
#include<vector>
#include<unordered_map>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,bool>> row(9);
        vector<unordered_map<char,bool>> col(9);
        vector<unordered_map<char,bool>> box(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!row[i][board[i][j]] && !col[j][board[i][j]] && !box[3*(i/3)+j/3][board[i][j]]){
                        row[i][board[i][j]]=true;
                        col[j][board[i][j]]=true;
                        box[3*(i/3)+j/3][board[i][j]]=true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
   

    vector<vector<char>> solveSudoku(vector<vector<char>>& board) {
        stack<vector<vector<char>>> st;
        unordered_map<int,bool> mp;
        st.push(board);
        while(!st.empty()){
            vector<vector<char>> pr= st.top();
            st.pop();
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    cout<<pr[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"____\n";
            bool fnd=false;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    if(pr[i][j]=='.'){
                        //cout<<"got "<<i<<" "<<j<<" \n";
                        for(char ch='1';ch<='9';ch++){
                            cout<<"| "<<i<<" "<<j<<" "<<ch<<" "<<st.size()<<" |\n";
                            pr[i][j]=ch;
                            if (!mp[i*1000+j*100+ch] && isValidSudoku(pr)){
                                st.push(pr);
                            }
                            mp[i*1000+j*100+ch]=true;
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

int main(){
    Solution s;
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    board=s.solveSudoku(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}