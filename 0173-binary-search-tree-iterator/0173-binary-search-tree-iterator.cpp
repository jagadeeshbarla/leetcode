/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    int i = 0;
    vector<int>v;
    void trav(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        trav(root->left);
        v.emplace_back(root->val);
        trav(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        trav(root);        
    }
    
    int next() {
        return v[i++];        
    }
    
    bool hasNext() {
        if(i >= v.size()){
            return false;
        }
        return true;        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */