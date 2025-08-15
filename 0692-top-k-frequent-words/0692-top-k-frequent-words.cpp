//done using the comparator sort which is defined in the main function 
//uses map to create a frequency storage and then sort it using lambda
//(Time : O(nlogn), Space : O(n))
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> vp;
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            vp.push_back({it.second, it.first});
        }
        //here is the comparator function 
        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        
        sort(vp.begin(), vp.end(), lambda);
        
        int i = 0;
        vector<string> result(k);
        while(i < k) {
            result[i] = vp[i].second;
            i++;
        }
        
        return result;
    }
};
