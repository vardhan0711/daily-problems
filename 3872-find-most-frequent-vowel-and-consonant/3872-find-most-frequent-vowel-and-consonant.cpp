class Solution {
public:
    bool isVowel(char ch ){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxFreqSum(string s) {
        unordered_map<char,int>vowels;
        unordered_map<char,int>cons;
        for(char ch:s){
            if(isVowel(ch)){
                vowels[ch]++;
            }
            else{
                cons[ch]++;
            }
        }
        int mostVowel=0;
        int mostCons=0;
        for(auto it:vowels){
            if(it.second>mostVowel){
                mostVowel=it.second;
            }
        }
        for(auto it:cons){
            if(it.second>mostCons){
                mostCons=it.second;
            }
        }   
        return mostVowel+mostCons;     
    }
};