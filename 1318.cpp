class Solution {
public:
    int minFlips(int a, int b, int c) {
        int diff=(a|b)^c,cnt;
        int rep=a&b&diff;
        while(diff!=0 || rep!=0){
            cnt+=(1&diff)+(1&rep);
            diff=diff>>1;
            rep=rep>>1;
        }
        return cnt;
    }
};