class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> S;
        unordered_map<char,int>T;
        for(char ch:s){
            S[ch]++;
        }
        for(char ch:t){
            T[ch]++;
        }
        return T==S;

    }
};