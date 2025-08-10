class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mpp;
        for(int i=0;i<matches.size();i++){
            int loser=matches[i][1];
            mpp[loser]++;
        }
        vector<int>never;
        vector<int>once;
        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            if(mpp.find(winner)==mpp.end()){
                mpp[winner]=2;
                never.push_back(winner);
            }
            if(mpp[loser]==1){
                once.push_back(loser);
            }
            
        }
        sort(once.begin(),once.end());
        sort(never.begin(),never.end());
        return {never,once};
    }
};