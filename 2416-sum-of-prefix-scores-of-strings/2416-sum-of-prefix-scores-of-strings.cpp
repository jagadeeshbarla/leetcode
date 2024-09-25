struct TrieNode{
    TrieNode* child[26];
    bool wordEnd;
    int count = 0 ;
    TrieNode(){
        wordEnd = false;
        for(int i = 0 ; i < 26 ; i++){
            child[i] = NULL;
        }
    }
};


class Solution {
public:
    void insert(TrieNode* root, const string& key){
        TrieNode* curr = root;
        for(char c : key){
            if(curr->child[c-'a'] == NULL){
                TrieNode* newNode = new TrieNode();
                curr->child[c-'a'] = newNode;
            }
            curr = curr->child[c-'a'];
            curr->count+=1;
        }
        curr->wordEnd = true;
    }
    int countf(TrieNode* root , const string& key){
        TrieNode* curr = root;
        int ans = 0;
        //curr = curr->child[key[0]-'a'];
        for(char c : key){
            
            curr = curr->child[c-'a'];
            ans+= curr->count;
        }
        return ans;        
    }    
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans(words.size(),0);
        TrieNode* root = new TrieNode();
        for(int i = 0 ; i < words.size() ; i++){
            insert(root,words[i]);            
        }                
        for(int i  = 0 ; i < words.size() ; i++){
            ans[i] = countf(root,words[i]);
        }
        return ans;        
    }
};