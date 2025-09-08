class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]%m==k){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        int sum=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r1=sum%m;
            int r2=(r1-k+m)%m;
            res+=mpp[r2];
            mpp[r1]++;
        }
        return res;
    }
};