class Solution {
public:
    vector<int>make_sub(int num){
        vector<int>v(32,0);
        int pointer = 0;
        int curr = 1;
        while(pointer < 32){
            if( (num & curr) ){
                v[pointer] = 1;
            }
            pointer++;
            curr = curr << 1;
        }
        return v;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<vector<int>>space;
        for(int i = 0 ; i < nums.size() ; i++ ){
            space.emplace_back( make_sub(nums[i]));
        }
        
        // for(int i = 0 ; i < space.size() ; i++){
        //     for(int j = 0 ; j < space[0].size() ; j++){
        //         cout<<space[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"*************************"<<endl;
        
        
        for(int i = 0 ; i < space[0].size() ;i++){
            for(int j = 1 ; j < space.size() ; j++){
                space[j][i] += space[j-1][i];                
            }
        }
        
        // for(int i = 0 ; i < space.size() ; i++){
        //     for(int j = 0 ; j < space[0].size() ; j++){
        //         cout<<space[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int>fans;
        for(int i = space.size() - 1 ; i >= 0 ; i--){
            int ans = 0;
            int curr = 1;
            for(int j = 0 ; j < 30 ; j++){
                if(j < maximumBit){
                    if(space[i][j]%2 == 0){
                        ans += curr;                                                
                    }
                }
                curr = curr << 1;
            }
            fans.emplace_back(ans);
        }
        return fans;     
    }
};