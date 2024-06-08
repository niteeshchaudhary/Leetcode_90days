#include<cmath>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        short sign=((dividend<0 && divisor>0)||(dividend>0&& divisor<0))?-1:1;
        unsigned remainder=abs(dividend),divi=abs(divisor),ans=0;
        while(remainder>=divi){
            int brute=1;
            while(remainder>divi<<brute){
                brute++;
            }
            brute--;
            remainder-=divi<<brute;
            ans+=1<<brute;
        }
        if(ans>INT_MAX){
            if(sign==-1){
                return INT_MIN;
            } 
            return INT_MAX;
        }
        return sign*ans;
    }
};