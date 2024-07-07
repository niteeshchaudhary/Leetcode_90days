#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> profit(n),effective_cost(n);
        effective_cost[0]=prices[0];
        for(int i=1;i<n;i++){
            profit[i]=max(profit[i-1],prices[i]-fee-effective_cost[i-1]);
            effective_cost[i]=min(effective_cost[i-1],prices[i]-profit[i]);
        }
        return profit[prices.size()-1];
    }
};
