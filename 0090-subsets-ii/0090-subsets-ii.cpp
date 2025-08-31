class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //this question is same as i have did on gfg (power set) just think about excluding the duplicates
        //trying to solve using power set
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end()); //so that inside set all array goes in sorted form and it's became easy to find duplicates for set
        set<vector<int>>st;
        int subsets = 1<<n; //2^n = total subsets
        for(int num = 0; num<subsets; num++){
            vector<int>curr; //to store the current elements
            for(int i = 0; i<n; i++){
                if(num & (1<<i)){ //checking if it is set bit or not
                    curr.push_back(nums[i]); 
                }
            }
            st.insert(curr); //storing in st which will not store duplicates
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
//reason for using set is avoiding duplicates