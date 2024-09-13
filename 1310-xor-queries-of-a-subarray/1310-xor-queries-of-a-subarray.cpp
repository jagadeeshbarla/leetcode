class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>temp;
        vector<int>ans;
        
        temp.emplace_back(arr[0]);
        for(int i = 1 ; i < arr.size() ; i++){
            temp.emplace_back(arr[i] ^ temp[temp.size()-1]);            
        }
        
        for(int i = 0 ; i < queries.size() ; i++){
            if(queries[i][0] == 0){
                ans.emplace_back(temp[queries[i][1]]);
            }
            else{
                ans.emplace_back(temp[queries[i][0]-1] ^ temp[queries[i][1]]);                
            }
        }
        return ans;        
    }
};