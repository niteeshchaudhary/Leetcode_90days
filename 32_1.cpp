#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        st.push({'.',0});
        int mxlen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',0});
            }
            else{
                if(st.top().first=='('){
                    pair<char,int>pr=st.top();
                    st.pop();
                    st.top().second+=pr.second+2;
                    mxlen=max(mxlen,st.top().second);
                }
                else{
                    st.push({')',0});
                }
            }
        }
        return mxlen;
    }
};