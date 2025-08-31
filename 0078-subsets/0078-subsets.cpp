class Solution {
public:
    void solver(int i,vector<int>& nums,vector<vector<int>>&res,vector<int>&curr){
        int n=nums.size();
        if(i==n){res.push_back(curr);return ;}
        curr.push_back(nums[i]);
        solver(i+1,nums,res,curr);
        curr.pop_back();
        solver(i+1,nums,res,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>curr;
        solver(0,nums,res,curr);
        return res;
    }
};