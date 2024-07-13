using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
         int maxlen=0,len=0;
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                    len+=2;
                }
                else{
                    maxlen=max(maxlen,len);
                    len=0;
                }
                if(open==0){
                    maxlen=max(maxlen,len);
                }
            }
        }
//------------------ Backwad Pass ----------------------------
        open=0;
        len=0;
        for(int i=s.size()-1;i>-1;i--){
            if(s[i]==')'){
                open++;
            }
            else{
                if(open>0){
                    open--;
                    len+=2;
                }
                else{
                    maxlen=max(maxlen,len);
                    len=0;
                }
                if(open==0){
                    maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
};