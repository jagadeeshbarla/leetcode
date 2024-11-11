/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int>ans;
public:
    int trav(TreeNode* root , int target , int k , int ko){
        if(root == NULL){
            return INT_MIN;
        }
        if(k == 0){
            ans.emplace_back(root->val);
        }
        if(k != INT_MIN){
            //cout<<root->val<<" -> "<<ko<<endl;
            trav(root->left , target , k-1,ko);
            trav(root->right,target, k-1,ko);
            return INT_MIN;            
        }
        if(root->val == target){
            if(ko == 0){
                ans.emplace_back(root->val);
            }
            trav(root->left , target , ko-1,ko);
            trav(root->right,target, ko-1,ko);
            return ko - 1;
        }
        int l = trav(root->left,target,k,ko);
        int r = trav(root->right,target,k,ko);
        
        if(l != INT_MIN){
            trav(root->right,target,l-1,ko); 
            root->right = root -> left = NULL;
            if(l == 0){
                ans.emplace_back(root->val);
            }
            return l - 1;
        }
        
        if(r != INT_MIN){
            trav(root->left,target,r-1,ko);
            root->left = root->right = NULL;
            if(r == 0){
                ans.emplace_back(root->val);
            }
            return r - 1;
        }
        return INT_MIN;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        trav(root,target->val,INT_MIN,k);    
        return ans;
    }
};