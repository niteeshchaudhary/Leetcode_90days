#include<cmath>

class Solution{
public:
     bool isPowerOfTwo(int n){
         if (n<1){
           return false;
         }
        if (int(log2(n))==log2(n)){
          return true;
        }
       return false;
    }
};
