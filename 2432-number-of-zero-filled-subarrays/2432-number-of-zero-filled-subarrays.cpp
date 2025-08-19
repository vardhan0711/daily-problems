class Solution {
public:
    using ll = long long;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll count=0;
        ll res=0;//no of zero filled subarray
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){count++;
            res+=count;}
            else {
                count=0;
            }
        }
        return res;
    }
};