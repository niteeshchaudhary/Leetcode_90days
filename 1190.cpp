#include<string>
using namespace std;
class Solution {
public:
    int i=0;
    string get_rev(string s,int sz,int d){
        string temp="";
        for(;i<sz;i++){
            if(s[i]=='('){
                i++;
                if(d%2){
                    temp = get_rev(s,sz,d+1)+temp;
                }
                else{
                    temp+= get_rev(s,sz,d+1);
                }
            }
            else if(s[i]==')'){
                return temp;
            }
            else{
                if(d%2){
                    temp=s[i]+temp;
                }
                else{
                    temp+=s[i];
                }
            }
        }
        return temp;
    }
    string reverseParentheses(string s) {
        return get_rev(s,s.size(),0);
    }
};