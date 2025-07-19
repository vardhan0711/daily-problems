class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        res.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string last = res.back() + "/";
            // Check if current folder is not a subfolder of the last added one
            if (folder[i].compare(0, last.size(), last) != 0) {
                res.push_back(folder[i]);
            }
        }

        return res;
    }
};
