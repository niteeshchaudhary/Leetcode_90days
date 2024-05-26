#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    unordered_map<int,int> mp;
public:
    int climb(vector<int>& cost,int i,int n){
        if(i>n){
            return 0;
        }
        if(i==n){
            return cost[n];
        }
        int lft=mp[i+1]!=0?mp[i+1]:climb(cost,i+1,n);
        if(mp[i+1]==0){
            mp[i+1]=lft;
        }
        int rt=mp[i+2]!=0?mp[i+2]:climb(cost,i+2,n);
        if(mp[i+2]==0){
            mp[i+2]=rt;
        }
        return min( cost[i]+lft, cost[i]+rt);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size()-1;
        return min( climb(cost,0,n), climb(cost,1,n));
    }
};