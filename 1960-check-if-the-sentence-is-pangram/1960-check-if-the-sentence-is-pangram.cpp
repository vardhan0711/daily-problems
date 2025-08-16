class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char>st;
        for(char ch:s){
            st.insert(ch);
        }
        if(st.size()==26)return true;
        return false;
    }
};