class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>res,prev,curr;
        for(int i=0;i<arr.size();i++){
            curr.clear();
            curr.insert(arr[i]);
            for(int x:prev){
                curr.insert(x|arr[i]);
            }
            prev=curr;
            res.insert(curr.begin(),curr.end());
        }
        return res.size();
    }
};