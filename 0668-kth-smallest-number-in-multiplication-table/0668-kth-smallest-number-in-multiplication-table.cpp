class Solution {
public:
    int countless(int m, int n ,int mid){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=std::min(mid/i,n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int left=1;
        int right=m*n;
        while(left<right){
            int mid=(left+right)/2;
            if(countless(m,n,mid)>=k){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return left;
    }
};