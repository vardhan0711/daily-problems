class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> bank(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        queue<string>q;
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endWord)return level;
                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<curr.size();i++){
                        string next=curr;
                        next[i]=ch;
                        if(bank.find(next)!=bank.end()&&vis.find(next)==vis.end()){
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};