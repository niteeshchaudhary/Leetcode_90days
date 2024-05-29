#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int num=0;
        short sg=1;
        bool fnd=false;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<58){
                if(num*sg>INT_MAX/10){
                    return INT_MAX;
                }
                if(num*sg<INT_MIN/10){
                    return INT_MIN;  
                }
                if(INT_MAX/10==sg*num){
                    if(s[i]-48>7){
                        return INT_MAX;
                    }
                }
                if(INT_MIN/10==sg*num){
                    if(s[i]-48>8){
                        return INT_MIN;
                    }
                    else{
                        return sg*num*10-(s[i]-48);
                    }
                }
                num=num*10+(s[i]-48);
                fnd=true;
            }
            else if(fnd){
                return sg*num;
            }
            else if(s[i]=='+'){
                sg=1;
                fnd=true;
            }
            else if(s[i]=='-'){
                sg=-1;
                fnd=true;
            }
            else if(s[i]!=' '){
                return sg*num;
            }
        }
        return sg*num;
    }
};