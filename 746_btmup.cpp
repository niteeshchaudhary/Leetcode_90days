#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1){
            return 0;
        }
        int ar[2]={cost[0],min(cost[0]+cost[1],cost[1]+0)};
        int temp;
        for(int i=2;i<cost.size();i++){
            temp=ar[0];
            ar[0]=ar[1];
            ar[1]=min(temp+cost[i],ar[1]+cost[i]);
        }
        return min(ar[0], ar[1]);
    }
};