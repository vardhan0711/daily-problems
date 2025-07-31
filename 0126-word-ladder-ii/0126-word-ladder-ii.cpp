//won't be asked anywhere 
//too much complicacy
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> res;

        if (!wordSet.count(endWord)) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currLevel, nextLevel;
        unordered_set<string> visited;

        currLevel.insert(beginWord);

        bool found = false;

        while (!currLevel.empty() && !found) {
            for (auto word : currLevel) {
                visited.insert(word);
            }

            for (auto word : currLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (wordSet.count(temp) && !visited.count(temp)) {
                            if (temp == endWord) found = true;
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                        }
                    }
                    temp[i] = original;
                }
            }

            currLevel = move(nextLevel);
            nextLevel.clear();
        }

        if (!found) return res;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

    void dfs(string word, string& beginWord, unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            res.push_back(validPath);
            return;
        }

        for (auto& p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};