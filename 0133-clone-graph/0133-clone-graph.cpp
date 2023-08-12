/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        if(node->neighbors.size()==0)
        {
            Node* naim = new Node(node->val);
            return naim;
        }
        
        map<int,Node*>m;
        
        Node* new_node = new Node(node->val);
        queue<Node*>q;
        m.insert({new_node->val,new_node});
        
        vector<Node*>curr;
        for(int i=0;i<node->neighbors.size();i++)
        {
            Node* newnode = new Node(node->neighbors[i]->val);
            curr.emplace_back(newnode);
            q.push(node->neighbors[i]);
            m.insert({newnode->val,newnode});
        }
        new_node->neighbors=curr;
        
        
        
        while(!q.empty())
        {
            
            Node* cnode = q.front();
            //cout<<cnode->val<<":";
            q.pop();
            Node* realnode = m[cnode->val];
            
            cout<<realnode->val<<":"<<cnode->neighbors.size()<<":";
            vector<Node*>curr_l;
            for(int i=0;i<cnode->neighbors.size();i++)
            {
                if(m.count(cnode->neighbors[i]->val)==1)
                {
                    Node* temp = m[cnode->neighbors[i]->val];
                    curr_l.emplace_back(temp);
                    cout<<temp->val<<" ";
                }
                else
                {
                    
                    Node* newnodel = new Node(cnode->neighbors[i]->val);
                    m.insert({newnodel->val,newnodel});
                    curr_l.emplace_back(newnodel);
                    q.push(cnode->neighbors[i]);
                    cout<<"kk";
                }    
            }
            cout<<endl;
            realnode->neighbors=curr_l;
            
            
        }
        
        return new_node;
    }
};