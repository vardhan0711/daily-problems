class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hills=0;
        int valleys=0;
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i] == nums[i-1]) continue;            
            int l=i-1;
            while(l>=0&&nums[l]==nums[i]){
                l--;
            }
            int r=i+1;
            while(r<n&&nums[r]==nums[i]){
                r++;
            }
            if(l>=0&&r<n){
                if(nums[i]<nums[l]&&nums[i]<nums[r]){
                    valleys++;
                }
                if(nums[i]>nums[l]&&nums[i]>nums[r]){
                    hills++;
                }                
            }
        }
        return valleys+hills;
    }
};