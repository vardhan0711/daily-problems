class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string st:strs){
            string w=st;
            sort(w.begin(),w.end());
            mpp[w].push_back(st);
        }
        vector<vector<string>> res;
        for(auto &it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};