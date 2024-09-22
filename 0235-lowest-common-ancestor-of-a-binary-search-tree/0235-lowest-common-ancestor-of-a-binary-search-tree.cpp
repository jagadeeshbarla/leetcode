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
    TreeNode* ans = NULL;
    vector<bool>trav(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<bool>temp(2,false);
        
        if(root == NULL){
            return temp;
        }
        vector<bool>temp_l,temp_r;
        temp_l = trav(root->left,p,q);
        temp_r = trav(root->right,p,q);
        if(root->val == p->val || root->val == q->val){
            if(temp_l[0] | temp_l[1] | temp_r[0] | temp_r[1]){
                ans = root;
            }
            else{
                if(root->val == p->val){
                    temp[0] = true;
                }
                else{
                    temp[1] = true;
                }
            }
        }
        
        if(temp_l[0]){
            if(temp_r[1]){
                ans = root;
            }
            else{
                temp[0] = true;
            }
        }
        else if(temp_l[1]){
            if(temp_r[0]){
                ans = root;
            }
            else{
                temp[1] = true;
            }
        }
        else if(temp_r[0]){
            if(temp_l[1]){
                ans = root;
            }
            else{
                temp[0] = true;
            }
        }
        else if(temp_r[1]){
            if(temp_l[0]){
                ans = root;
            }
            else{
                temp[1] = true;
            }
        }
        
        return temp;                
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<bool>temp;
        temp = trav(root,p,q);
        if(temp[0] & temp[1]){
            ans = root;
        }
        return ans;
        
    }
};