class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res(nums.size()/3,vector<int>(3));
        sort(nums.begin(),nums.end());
        int ind=0;
        for(int i=0;i<nums.size();i+=3){
            if(i+2<nums.size()&&nums[i+2]-nums[i]<=k){
                res[ind]={nums[i],nums[i+1],nums[i+2]};
                ind++;
            }else{
                return vector<vector<int>>();
            }
        }
        return res;
    }

};