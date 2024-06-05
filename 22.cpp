#include<queue>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<pair<string,vector<int>>> q;
        vector<string> ans;
        if(n==0){
            return ans;
        }
        q.push({"(",{n-1,n}});
        while(!q.empty()){
            pair<string,vector<int>> pr=q.front();
            q.pop();
            if(pr.second[0]==0 && pr.second[1]==0){
                ans.push_back(pr.first);
            }
            else if(pr.second[0]==0){
                q.push({pr.first+")",{0,pr.second[1]-1}});
            }
            else if(pr.second[0]>0 && pr.second[1]>0){
                if(pr.second[0]<pr.second[1]){
                    q.push({pr.first+")",{pr.second[0],pr.second[1]-1}});
                    q.push({pr.first+"(",{pr.second[0]-1,pr.second[1]}});
                }
                else{
                    q.push({pr.first+"(",{pr.second[0]-1,pr.second[1]}});
                }
            }
        }
        return ans;
    }
};