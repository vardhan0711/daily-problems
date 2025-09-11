class Solution {
public:
    bool isVowel(char ch){
        return ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string sortVowels(string s) {
        vector<char>arr;
        for(char ch:s){
            if(isVowel(ch)){
                arr.push_back(ch);
            }
        }
        sort(arr.begin(),arr.end());
        int id=0;
        for(char &ch:s){
            if(isVowel(ch)){
                ch=arr[id++];
            }
        }
        return s;
    }   
};