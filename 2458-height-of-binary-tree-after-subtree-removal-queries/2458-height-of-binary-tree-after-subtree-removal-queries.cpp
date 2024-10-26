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
class Solution {   
    
public:
    int trav(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max({root->val,trav(root->left),trav(root->right)});
    }
    int calculate_height(TreeNode* root,vector<pair<TreeNode*,char>>&parent_m,vector<int>&m){
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL){
            parent_m[root->left->val] = make_pair(root,'l');
        }
        if(root->right != NULL){
            parent_m[root->right->val] = make_pair(root,'r');
        }
        if(root->left != NULL || root->right != NULL){
            return m[root->val]  = 1 + max( calculate_height(root->left,parent_m,m) , calculate_height(root->right,parent_m,m) );
        }
        return m[root->val] = 0;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        int max_s = trav(root);
        vector<pair<TreeNode*,char>>parent_m(max_s+1);
        vector<int>m(max_s+1);
        calculate_height(root,parent_m,m);
        for(int i = 0 ; i < queries.size() ; i++){
            pair<TreeNode*,char>p = parent_m[queries[i]];
            int modefied_value = 0;
            bool flag = false,final = false,global = false;
            while(p.first != root){
                if(p.second == 'l'){
                    if(p.first->right != NULL){
                        int temp = m[p.first->right->val];
                        if(temp >= m[p.first->left->val]){
                            ans.emplace_back(m[root->val]);
                            global = true;
                            break;
                        }
                        modefied_value =  max(modefied_value , temp);  
                        modefied_value++;
                    }
                    else if(flag){   
                        modefied_value++;
                    }
                }
                if(p.second == 'r'){
                    if(p.first->left != NULL){
                        int temp = m[p.first->left->val];
                        if(temp >= m[p.first->right->val]){
                            ans.emplace_back(m[root->val]);
                            global = true;
                            break;
                        }
                        modefied_value = max(modefied_value , temp);
                        modefied_value++;
                    }
                    else if(flag){
                        modefied_value++;
                    }
                } 
                if(modefied_value == m[p.first->val]){
                    cout<<"j";
                    ans.emplace_back(m[root->val]);
                    global = true;
                    break;
                }
                flag = true;
                if(final){break;}
                if(p.first != root){p = parent_m[p.first->val];}
            }
            if(global){
                continue;
            }
            if(p.second == 'l'){
                if(p.first->right != NULL){
                    modefied_value =  max(modefied_value , m[p.first->right->val]);  
                    modefied_value++;
                }
                else if(flag){   
                    modefied_value++;    
                }
            }
            if(p.second == 'r'){
                if(p.first->left != NULL){
                    modefied_value = max(modefied_value , m[p.first->left->val]);
                    modefied_value++;
                }
                else if(flag){
                    modefied_value++;
                }
            } 
            ans.emplace_back(modefied_value);
        } 
        return ans;        
    }
};



        