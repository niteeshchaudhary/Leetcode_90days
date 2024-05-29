class Solution {
    const int INTMIN=-214748364,INTMAX=214748364;
public:
    int reverse(int x) {
        if(x==0){
            return 0;
        }
        int y=0;
        while(x!=0){
            if(y>INTMAX || y<INTMIN){
                return 0;
            }
            y=y*10+x%10;
            x=x/10;
        }
       
        return y;
    }
};