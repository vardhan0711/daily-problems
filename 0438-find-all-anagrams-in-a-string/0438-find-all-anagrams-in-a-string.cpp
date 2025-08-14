class Solution {
public:
  bool check(vector<int>&alph){
      for(int &i:alph){
          if(i!=0)return false;
      }
      return true;
  }    
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>alph(26,0);
        for(char ch:p){
            alph[ch-'a']++;
        }
        
        int i=0;
        int j=0;
        int k=p.size();
        vector<int>res;
        while(j<n){
            alph[s[j]-'a']--;
            if(j-i+1==k){
                if(check(alph)){
                    res.push_back(i);
                    
                }
                alph[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};