#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rs;
        for(int i=0;i<numRows;i++){
            vector<int> nw(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    nw[j]=1;
                }
                else{
                    nw[j]=rs[i-1][j-1]+rs[i-1][j];
                }
            }
            rs.push_back(nw);
        }
        return rs;
    }
};