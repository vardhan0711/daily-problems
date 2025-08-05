class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int len=1;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if( (curr&nums[j])!=0){
                    break;
                }
                else{
                    curr|=nums[j];
                    len=max(len,j-i+1);
                }
            }
        }
        return len;
    }
};