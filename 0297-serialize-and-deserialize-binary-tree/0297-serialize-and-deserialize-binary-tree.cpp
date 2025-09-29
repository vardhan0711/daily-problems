/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorder(TreeNode* root,string &st){
        if(root==nullptr){
            st.append("#,");
            return;
        }

        st.append(to_string(root->val));
        st.append(",");
        preorder(root->left,st);
        preorder(root->right,st);
    }    

    TreeNode* deserializer(queue<string>&q){
        string val=q.front();
        q.pop();
        if(val=="#")return nullptr;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserializer(q);
        root->right=deserializer(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st="";
        preorder(root,st);
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        queue<string>q;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            q.push(token);
        }
        return deserializer(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));