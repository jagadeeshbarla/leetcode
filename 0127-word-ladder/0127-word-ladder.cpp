class Solution {
public:
    int check(string s1, string s2){
        int diff_count = 0 ;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] != s2[i]){
                diff_count++;
            }
        }
        return diff_count;
        }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        bool flag = true;
        for(int i = 0 ; i < wordList.size() ; i++){
            if(wordList[i] == endWord){
                flag = false;
            }
        }
        if(flag) return ans;
        ans++;
        queue<vector<string>>q;
        vector<string>temp(1,beginWord);
        q.push(temp);
        set<string>s;
        s.insert(beginWord);
        while(!q.empty()){
            vector<string>temp_1,temp_2;
            temp_1 = q.front();
            for(int i = 0 ;  i <  temp_1.size() ; i++){
                cout<<temp_1[i]<<" ";
                if(temp_1[i] == endWord){
                    return ans;
                }
                for(int j = 0 ; j < wordList.size() ; j++){
                    if(check(temp_1[i],wordList[j]) == 1 && s.find(wordList[j]) == s.end()){
                        temp_2.push_back(wordList[j]);
                        s.insert(wordList[j]);
                    } 
                }
            }
            cout<<endl;    
            q.pop();
            ans++;
            if(temp_2.size() > 0){
                q.push(temp_2);
            }  
            else{
                return 0;
            }
        }
        return ans;
        
        
    }
};