class Solution {
    vector<int>ans;
public:
    int findDistance(int n , vector<vector<int>> &v){
        int curr = 0;
        vector<bool>flag(n+1,false);
        flag[0] = true;
        queue<vector<int>>q;
        vector<int>temp;
        temp.emplace_back(0);
        q.push(temp);
        
        
        while(!q.empty()){
            vector<int>qt1 = q.front();
            q.pop();
            vector<int>qt2;
            for(int i = 0 ; i < qt1.size() ; i++){
                if(qt1[i] == n-1){
                    return curr;
                }
                
                flag[qt1[i]] = true;
                for(int j = 0 ; j < v[qt1[i]].size() ; j++){
                    if(!flag[v[qt1[i]][j]]){
                        qt2.emplace_back( v[qt1[i]][j] );
                    }
                }
            }
            if(qt2.size() > 0){
                curr++;
                q.push(qt2);
            }
        }
        return curr;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>v;
        for(int i = 0; i < n-1 ; i++){
            vector<int>temp(1,i+1);
            v.emplace_back(temp);
        }
        vector<int>tt;
        v.emplace_back(tt);
        for(int i = 0 ; i < queries.size() ; i++){
            v[queries[i][0]].emplace_back(queries[i][1]);
            ans.emplace_back(findDistance(n,v));   
        }
        return ans;        
    }
};