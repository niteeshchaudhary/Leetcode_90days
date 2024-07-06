#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
class Solution {
    unordered_map<int,char> mp={{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};
public:
    string create(int base,int mid,int number){
        string ans="";
        if(number/base>3){
            if(number<mid){
                for(int i=0;i<mid/base-number/base;i++){
                    ans+=mp[base];
                }
                ans+=mp[mid];
            }
            else if (number/(mid+4*base)<1){
                ans+=mp[mid];
                for(int i=0;i<number/base-mid/base;i++){
                    ans+=mp[base];
                }
            }
            else{
                ans+=mp[base];
                ans+=mp[base*10];
            }
        }
        else{
            for(int i=0;i<number/base;i++){
                ans+=mp[base];
            }
        }
        return ans;
    }
    string intToRoman(int num) {
        int q=0,r=0;
        string ans="";
        for(int i=1000;i>0;i/=10){
            if(num/i!=0){
                ans+=create(i,5*i,num);
                num=num%i;
            }
        }
        return ans;
    }
};