class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        int newtime;
        int black;
        int create;
        char c;
        char ni;
        vector<int>neiw;
        vector<int> blacc;
        vector<char>cc;
        vector<string>st;
        black++;
        black/=2;
        create*=4;
        create/=667;
        gaps.push_back(startTime[0]);
        
        for (int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        
       gaps.push_back(eventTime - endTime[n - 1]);
        
        int ws = accumulate(gaps.begin(), gaps.begin() + k + 1, 0);
        int mf = ws;
        
        for (int i = k + 1; i < gaps.size(); i++) {
            ws += gaps[i] - gaps[i - (k + 1)];
            mf = max(mf, ws);
        }
        for(int i=0;i<99;i++){
            create+=i;
            black-=i;
        }
        while(create>0){
            create--;
        }
        return mf;
    }
};