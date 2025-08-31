class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        int i2=1,i3=1,i5=1;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int ugly_2=arr[i2]*2;
            int ugly_3=arr[i3]*3;
            int ugly_5=arr[i5]*5;
            int put=min({ugly_2,ugly_3,ugly_5});
            arr[i]=put;
            if(put==ugly_2){
                i2++;
            }
            if(put==ugly_3){
                i3++;
            }
            if(put==ugly_5){
                i5++;
            }
        }
        return arr[n];
    }
};