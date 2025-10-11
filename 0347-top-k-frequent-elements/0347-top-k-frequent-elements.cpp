class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &it:mpp){

            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty()){
            auto el=pq.top();
            int num=el.second;
            pq.pop();
            res.push_back(num);
        }
        return res;

    }
};