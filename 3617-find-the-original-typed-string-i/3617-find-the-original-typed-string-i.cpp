class Solution {
public:
    int possibleStringCount(string word) {
    int count = 0;

    for (int i = 1; i < word.length(); i++) {
        // If current char is same as previous
        if (word[i] == word[i - 1]) {
            count++;  
        }
    }
    return count + 1;  // +1 for the original string        
    }
};