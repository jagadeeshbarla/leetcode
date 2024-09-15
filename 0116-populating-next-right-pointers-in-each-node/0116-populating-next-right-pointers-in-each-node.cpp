/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }        
        queue<vector<Node*>>q;
        vector<Node*>temp;
        temp.emplace_back(root);
        q.push(temp);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            vector<Node*>temp_1;
            for(int i = 0 ; i < temp.size() ; i++){
                if(temp[i]->left != NULL){
                    temp_1.emplace_back(temp[i]->left);
                }
                if(temp[i]->right != NULL){
                    temp_1.emplace_back(temp[i]->right);
                }
                if(i == temp.size()-1)
                {
                    break;
                }
                temp[i]->next = temp[i+1];
            }
            if(temp_1.size() > 0){
                q.push(temp_1);                
            }
                        
        }
        return root;
    }
};