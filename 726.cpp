#include<map>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> mp;
        stack<pair<int,string>> st;
        string ans="";
        st.push({1,"."});
        for(int i=formula.size()-1;i>-1;i--){
            int myint=0,k=1;
            while(i>-1 && formula[i]<='9' && '0'<=formula[i]){
                myint=(formula[i]-'0')*k+myint;
                k*=10;
                i--;
            }
            if(myint==0){
                myint=1;
            }
            if(i>-1){
                string myele="";
                while(i>-1 && formula[i]>=97){
                    myele=formula[i]+myele;
                    i--;
                }
                myele=formula[i]+myele;
                st.push({st.top().first*myint,myele});

                if(formula[i]!=')'){
                    if(formula[i]!='('){
                        mp[st.top().second]+=st.top().first;
                        st.pop();
                    }
                    else{
                        st.pop();
                        st.pop();
                    }
                }
                else{
                    continue;
                }
            }
        }
        for(auto i:mp){
            if(i.second!=1)
                ans+=i.first+to_string(i.second);
            else
                ans+=i.first;
        }
        return ans;

    }
};