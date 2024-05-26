#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
public:
    void dfs(int num,int dest,vector<int> part,int dep,int k){
        if (num!=0)
            part.push_back(num);
        if(dep==k){
            if(num==dest)
                ans.push_back(part);
            return;
        }
        if(num>dest){
        return;
        }

        for(int i=num+1;i<=9;i++){
            dfs(i,dest-num,part,dep+1,k);
        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> part;
        dfs(0,n,part,0,k);
        return ans;
    }
};