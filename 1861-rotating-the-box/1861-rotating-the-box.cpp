class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>>ans(box[0].size(), vector<char>(box.size(),'.'));
        for(int i = 0 ; i < box.size() ; i++){
            int pointer = box[0].size()-1;
            for(int j = box[0].size()-1 ; j >= 0 ; j--){
                if(box[i][j] == '*'){
                    ans[j][i] = '*';
                    pointer = j-1;
                }
                else if(box[i][j] == '#'){
                    ans[pointer][i] = '#';
                    pointer--;
                }
                else{
                    ans[j][i] = '.';
                }
            }
        }
        for(int i = 0 ; i < ans.size() ; i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
        
    }
};