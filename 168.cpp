class Solution {
public:
    string convertToTitle(int columnNumber) {
        int q= columnNumber,r=-1;
        string ans="";
        string sup="ZABCDEFGHIJKLMNOPQRSTUVWXY";

        while(q!=0){
            r=q%26;
            q=q/26;
            if(r==0)
            {
                q-=1;
            }
            ans=sup[r]+ans;
        }
        return ans;
    }
};