class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0,cost=0,result=0;
        for(int r=0;r<s.length();r++){
            cost+=abs(s[r]-t[r]);
            while(cost>maxCost){
                cost-=abs(s[l]-t[l]);
                l++;
            }
            result=max(result,r-l+1);
        }
        return result;
    }
};