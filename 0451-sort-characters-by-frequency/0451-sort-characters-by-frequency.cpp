class Solution {
public:
    typedef pair<char,int>p;
    
    struct lambda{
        bool operator()(p &p1,p &p2){
            return p1.second<p2.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<p,vector<p>,lambda>pq;
        unordered_map<char,int>mpp;
        for(auto ch:s){
            mpp[ch]++;
        }
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }
        string st="";
        while(!pq.empty()){
            p temp=pq.top();
            pq.pop();
            st+=string(temp.second,temp.first);
        }
        return st;
    }
};