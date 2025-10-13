class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int maxLen = 0;
        int currCost = 0;
        
        int i = 0, j = 0;
        while(j < n) {
            currCost += abs(s[j] - t[j]);//calculate the current cost to convert the window
            
            while (currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;//shrink window
            }
            
            maxLen = max(maxLen, j - i + 1);//maximum window size
            j++;//expand the window size
        }
        
        return maxLen;
    }
};
