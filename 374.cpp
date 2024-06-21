/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
#include<cmath>
#include <utility>
#include <cstdlib>
using namespace std;

int upper;

int guess(int num){
    int pick=rand()%upper+1;
    if(num==pick){
        return 0;
    }
    else if(num<pick){
        return 1;
    }
    return -1;
}


class Solution {
public:
    int guessNumber(int n) {
        long int temp=ceil(n/2.0),init=0,top=n;
        int rs=guess(temp);
        while(rs!=0){
            if(rs==-1){
                top=temp;
                temp=ceil((init+temp)/2.0);
            }
            else if(rs==1){
                init=temp;
                temp=ceil((init+top)/2.0);
            }
            rs=guess(temp);
            
        }
       return temp;
    }

};


class Solution2 {
public:
    int binSearch(unsigned int l,unsigned int r){
        int mid=(l+r)/2;
        if(l>r){
            return -1;
        }
        int result=guess(mid);
        if(result==0){
            return mid;
        }
        else if (result==1){
            return binSearch(mid+1,r);
        }
        return binSearch(l,mid-1);
    }
    int guessNumber(int n) {
        upper=n;
        return binSearch(1,n);
    }
};
    