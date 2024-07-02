class Solution {
public:
    bool solve(vector<vector<char>>& board,int i,int j,vector<unordered_map<char,bool>>& row,vector<unordered_map<char,bool>>& col,vector<unordered_map<char,bool>>& box) {
        if(j==9){
            j=j%9;
            i++;
        }
        if(i==9){
            return true;
        }
        if(board[i][j]!='.'){
            return solve(board,i,j+1,row,col,box);  
        }
        for(char ch='1';ch<='9';ch++){
            if(!row[i][ch] && !col[j][ch] && !box[3*(i/3)+j/3][ch]){
                board[i][j]=ch;
                
                row[i][board[i][j]]=true;
                col[j][board[i][j]]=true;
                box[3*(i/3)+j/3][board[i][j]]=true;
                bool rs = solve(board,i,j+1,row,col,box);
                if(rs==false){
                    row[i][board[i][j]]=false;
                    col[j][board[i][j]]=false;
                    box[3*(i/3)+j/3][board[i][j]]=false;
                    board[i][j]='.';
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,bool>> row(9);
        vector<unordered_map<char,bool>> col(9);
        vector<unordered_map<char,bool>> box(9);
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
        bool rs= solve(board,si,sj,row,col,box);
    }
};