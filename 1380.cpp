#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> row(matrix.size());
        vector<int> col(matrix[0].size());
        unordered_map<int,int> rvmp;
        vector<int> ans;
        for(int i=0;i<matrix[0].size();i++){
            col[i]=INT_MIN;
        }
        for(int i=0;i<matrix.size();i++){
            int cl=INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                cl=min(cl,matrix[i][j]);
                col[j]=max(col[j],matrix[i][j]);
            }
            rvmp[cl]=i;
            row[i]=cl;
        }
        for(int i=0;i<matrix[0].size();i++){
            if(row[rvmp[col[i]]]==col[i]){
                ans.push_back(col[i]);
            }
        }

        return ans;
    }

};