class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        int res=0;
        for(auto it:mpp){
            if(it.second>n/2){
                res=it.first;
            }
        }
        return res;
    }
};