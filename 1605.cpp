#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int cs=colSum.size();
        int rs=rowSum.size();
        vector<vector<int>> mat(rowSum.size(),vector<int>(colSum.size()));
        int mn,ii=0,jj=0;
        while(ii<rs && jj<cs){
            if(rowSum[ii]<colSum[jj]){
                mat[ii][jj]=rowSum[ii];
                colSum[jj]-=rowSum[ii];
                rowSum[ii]=0;
                ii++;
            }
            else{
                mat[ii][jj]=colSum[jj];
                rowSum[ii]-=colSum[jj];
                colSum[jj]=0;
                jj++;
            }
        }  
        return mat;
    }
};