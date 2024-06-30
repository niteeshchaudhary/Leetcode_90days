#include<string>
#include<unordered_map>
using namespace std;
class Solution {
    unordered_map<int,pair<int,bool>> mp;
public:
    bool match(string &s,int i, string &p,int j,int sl,int pl) {
        if(mp[i*100+j].first){
            return mp[i*100+j].second;
        }
        if(i==sl && j==pl){
            return true;
        }
        else if(i==sl){
            while(j+1<pl && p[j+1]=='*'){
                j++;
            }
            if(p[j]=='*'){
            while(j<pl && p[j]=='*'){
                j++;
            }
            j--;
            while(j+2<pl && p[j+2]=='*'){
                j+=2;
            }
            j++;
            }
            while(j<pl && p[j]=='*'){
                j++;
            }
            if(j==pl){
                return true;
            }

            return false;
        }
        else if(j==pl){
            return false;
        }
        if(s[i]==p[j] || p[j]=='.'){
            mp[(i+1)*100+(j+1)]= {1,match(s,i+1,p,j+1,sl,pl)};
            if(p[j+1]=='*'){
                mp[(i)*100+(j+1)]={1,match(s,i,p,j+2,sl,pl)};
                return mp[(i+1)*100+(j+1)].second || mp[(i)*100+(j+1)].second;
            }
            else
                return mp[(i+1)*100+(j+1)].second;
        }
        else if(p[j]=='*'){
            if(p[j-1]==s[i] || p[j-1]=='.'){
                mp[(i+1)*100+j]={1,match(s,i+1,p,j,sl,pl)};
                mp[(i+1)*100+(j+1)]={1,match(s,i+1,p,j+1,sl,pl)};
                mp[(i)*100+(j+1)]= {1,match(s,i,p,j+1,sl,pl)};
                return  mp[(i+1)*100+j].second || mp[(i+1)*100+(j+1)].second || mp[(i)*100+(j+1)].second;
            }
            else{
                mp[(i)*100+(j+1)]= {1,match(s,i,p,j+1,sl,pl)};
                return mp[(i)*100+(j+1)].second;
            }
        }
        else{
            if(j+1<pl && p[j+1]=='*'){
                mp[(i)*100+(j+1)]={1,match(s,i,p,j+1,sl,pl)};
                return  mp[(i)*100+(j+1)].second;
            }
            else{
                return false;
            }
        }
    }
    bool isMatch(string s, string p) {
        return match(s,0,p,0,s.size(),p.size());
        
    }
};