#include<vector>
using namespace std;
bool compare(const vector<int>&a,const vector<int>&b){
    return a[3]<b[3];
}
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> rb;
        for(int i=0;i<positions.size();i++){
            int d=directions[i]=='R'?1:-1;
            rb.push_back({positions[i],healths[i],d,i});
        }
        sort(rb.begin(),rb.end());
        vector<vector<int>> st;
        for(int i=0;i<rb.size();i++){
            if(((st.empty()|| st.back()[2]==-1)&& rb[i][2]==-1)||rb[i][2]==1){
                st.push_back(rb[i]);
            }
            else{
                vector<int> backrob=st.back();
                if(st.back()[1]<rb[i][1]){
                    while(!st.empty() && st.back()[2]==1 && st.back()[1]<rb[i][1]){
                        st.pop_back();
                        rb[i][1]--;
                        if(!st.empty() && st.back()[2]!=rb[i][2]){
                            if(st.back()[1]>rb[i][1]){
                                st.back()[1]--;
                            }
                            else if(st.back()[1]==rb[i][1]){
                                st.pop_back();
                                break;
                            }
                        }
                        else if(st.empty()||st.back()[2]==-1){
                            st.push_back(rb[i]);
                        }
                    }
                }
                else if(backrob[1]>rb[i][1]){
                    st.back()[1]--;
                }
                else{
                    st.pop_back();
                }
            }
        }
        sort(st.begin(),st.end(),compare);
        vector<int> fa;
        for(int i=0;i<st.size();i++){
            fa.push_back(st[i][1]);
        }
        return fa;
    }
};