class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>s;
        for(int i = 0 ; i < banned.size() ; i++){
            s.insert(banned[i]);
        }
        int curr_sum = 0;
        int count = 0;
        int pointer = 1;
        
        
        while(true && pointer <= n){
            if(s.find(pointer) == s.end()){
                if( (pointer+curr_sum) == maxSum ){
                    count++;
                    return count;
                }
                else if((pointer+curr_sum) < maxSum){
                    curr_sum += pointer;
                    count++;
                }
                else{
                    return count;
                }
            }    
            pointer++;
        }
        return count;
    }
};