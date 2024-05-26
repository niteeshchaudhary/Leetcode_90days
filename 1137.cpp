class Solution {
public:
    int tribonacci(int n) {
        int a[5]={0,1,1,2,4};
        if(n<5){
            return a[n];
        }
        for(int i=5;i<=n;i++){
            a[0]=a[1];
            a[1]=a[2];
            a[2]=a[3];
            a[3]=a[4];
            a[4]=a[3]+a[2]+a[1];
        }
        return a[4];
    }
};