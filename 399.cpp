#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    double bfs(unordered_map<string,vector<pair<string,double>>>& mp,string pool,string search){
        queue<pair<string,double>> q;
        unordered_map<string,bool> v;
        q.push(make_pair(pool,1.0));
        while(!q.empty()){
            pair<string,double> pr=q.front();
            q.pop();
            if(pr.first==search){
                return pr.second;
            }
            for(int i=0;i<mp[pr.first].size();i++){
                if(v[mp[pr.first][i].first]==1){
                    continue;
                }
                v[mp[pr.first][i].first]=1;
                q.push(make_pair(mp[pr.first][i].first,pr.second*mp[pr.first][i].second));
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> mp;
        vector<double> ans(queries.size(),-1.0);
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            mp[equations[i][1]].push_back(make_pair(equations[i][0],1.0/values[i]));
        }
        for(int i=0;i<queries.size();i++){
           if(!mp[queries[i][0]].empty() && !mp[queries[i][1]].empty()){
            ans[i]=bfs(mp,queries[i][0],queries[i][1]);
           } 
        }
        return ans;
    }
};