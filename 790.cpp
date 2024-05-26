#include<vector>
using namespace std;
class Solution {
    int mod=1000000000 + 7;
public:
    int numTilings(int n) {
       int sum=0;
       vector<int> vc={0,1,2,5};
       if(n<4){
        return vc[n];
       }
       for(int i=4;i<=n;i++){
        sum=(sum+vc[1]+0L)%mod;
        int ans=((2L+vc[2]+vc[3])%mod+sum*2L%mod)%mod;
        vc[0]=vc[1];
        vc[1]=vc[2];
        vc[2]=vc[3];
        vc[3]=ans;
       }
       return vc[3];
    }
};