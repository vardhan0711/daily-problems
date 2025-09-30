class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int l=0;
        int res=0;
        int maxCnt=0;
        for(int r=0;r<s.size();r++){
            mpp[s[r]]++;
            maxCnt=max(maxCnt,mpp[s[r]]);
            if((r-l+1)-maxCnt>k){
                mpp[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
        }   
        return res;
    }
};