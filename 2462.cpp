#include<queue>
using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>, greater<int>> pql;
        priority_queue<int,vector<int>, greater<int>> pqr;

        int n=costs.size();
        if(n==1){
            if(k==1)
                return costs[0];
            else
                return 0;
        }

        int i=0,p=n-1;
        long long cost=0;
        while(i<candidates && i<=p){
                pql.push(costs[i++]);
                if(i>p)
                break;
                pqr.push(costs[p--]);
        }
        for(int j=0;j<k;j++){
            if(pql.empty()){
                  cost+=pqr.top();
                    pqr.pop();
            }
            else if(pqr.empty()){
                 cost+=pql.top();
                    pql.pop();
            }
            else{
                if(pql.top()<=pqr.top()){
                    cost+=pql.top();
                    pql.pop();
                    if(i<=p){
                        pql.push(costs[i]);
                        i++;
                    }
                }
                else{
                    cost+=pqr.top();
                    pqr.pop();
                    if(i<=p){
                        pqr.push(costs[p]);  
                        p--; 
                    }
                }
            }
           
        }
        return cost;
    }
};