#import <iostream>
#import <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int as=a.size(),bs=b.size();
        string st="";
        int ans=0;
        while(as>0||bs>0||ans>0){
            if (as>0)
                ans+=a[--as]-'0';
            if (bs>0)
                ans+=b[--bs]-'0';
            if(ans%2){
                st="1"+st;
            }
            else{
                st="0"+st;
            }
            ans/=2; 
        }
        return st;
    }
};