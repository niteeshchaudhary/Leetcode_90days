#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> matrix(word1.size()+1,vector<int>(word2.size()+1));
        for(int i=0;i<word1.size()+1;i++){
            matrix[i][0]=i;
        }
        for(int j=0;j<word2.size()+1;j++){
            matrix[0][j]=j;
        }
        for(int i=1;i<word1.size()+1;i++){
           for(int j=1;j<word2.size()+1;j++){
                if(word1[i-1]!=word2[j-1]){
                    matrix[i][j]=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]))+1;
                }
                else{
                    matrix[i][j]=matrix[i-1][j-1];
                }
           }
        }

        return matrix[word1.size()][word2.size()];
    }
};