#include <cmath>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        double now=x/2.0,prev=1;
        if(now==0){
            return 0;
        }
        while(floor(now)!=floor(prev)){
            prev=now;
            now=0.5*(now+x/now);
        };
        return now;
    }
};