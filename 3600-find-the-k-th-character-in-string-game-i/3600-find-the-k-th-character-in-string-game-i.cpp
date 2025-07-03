class Solution {
public:
    char nextchar(char c){
        return (c=='z')?'a':c+1;
    }
    char kthCharacter(int k) {
        string st="a";
        while(st.size()<k){
            string next="";
            for(char c:st){
                next+=nextchar(c);
            }
            st+=next;
        }
        char res=st[k-1];
        return res;
    }
};