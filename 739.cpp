#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,pair<int,int>>> st;
        vector<int> ans(temperatures.size());
        st.push({temperatures[0],{0,1}});
        for(int i=1;i<temperatures.size();i++){
            pair<int,pair<int,int>> pr=st.top();
            while(pr.first<temperatures[i]){
                st.pop();
                ans[pr.second.first]=pr.second.second;
                if(!st.empty()){
                    st.top().second.second+=pr.second.second;
                    pr=st.top();
                }
                else{
                    break;
                }
            }
            st.push({temperatures[i],{i,1}});
        }
        return ans;
    }
};