class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        
        // Always include nums[0]
        int smallest = INT_MAX, secondSmallest = INT_MAX;
        
        for(int i = 1; i < n; i++){
            if(nums[i] < smallest){
                secondSmallest = smallest;
                smallest = nums[i];
            } else if(nums[i] < secondSmallest){
                secondSmallest = nums[i];
            }
        }
        
        return nums[0] + smallest + secondSmallest;
    }
};
