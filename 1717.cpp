#include<string>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score=0;
        string hi="ab";
        int mxad=x,mnad=y;
        if(x<y){
            mxad=y;
            mnad=x;
            hi="ba";
        }
        int h0=0,h1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==hi[0]){
                h0++;
            }
            else if(s[i]==hi[1]){
                if(h0>0){
                    score+=mxad;
                    h0--;
                }
                else{
                    h1++;
                }
            }
            else{
                score+=min(h0,h1)*mnad;
                h0=0;
                h1=0;
            }
        }
        score+=min(h0,h1)*mnad;
        return score;
    }
};