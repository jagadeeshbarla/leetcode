class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {    
        int ans = 1;
        //cout<<nums.size()<<endl;
        int curr;
        int halt = 0;
        
        while( halt < nums.size() ){
            curr = halt;
            int min_e = nums[halt];
            int max_e = nums[halt];
            int min_i = halt;
            int max_i = halt;
            int max_f = 0;
            int min_f = 0;
            
            int l_max_i = -1;
            int l_min_i = -1;
            while( curr < nums.size()){
                
                
                if(min_e > nums[curr])
                {
                    min_e = nums[curr];
                    min_i = curr;
                    min_f = 1;
                }
                if(min_e == nums[curr])
                {
                    l_min_i = curr;
                }
                
                if(max_e < nums[curr])
                {
                    max_e = nums[curr];
                    max_i = curr;
                    max_f = 1;
                }
                if(max_e == nums[curr])
                {
                    l_max_i = curr;
                }
                //cout<<abs(max_e - min_e)<<"  "<<max_e - min_e<<endl;

                if(abs(max_e - min_e) <= limit){
                    ans = max( ans , abs(curr - halt) + 1);
                }
                else{
                    if(max_f == 1){
                    
                        halt = min_i;
                        if(l_min_i >= min_i)
                        {
                            halt = l_min_i;
                        }
                        //halt--;
                    }
                    if(min_f == 1)
                    {
                        halt = max_i;
                        if(l_max_i >= max_i)
                        {
                            halt = l_max_i;
                        }
                    
                        //halt--;
                    }
                    break;
                }
                
                min_f = 0;max_f = 0;
                if(curr == nums.size()-1 && halt == 0){return ans;}
                curr++;
            }
            halt++;
            
        }
        
        
        
        return ans;
    }
};
























//     int longestSubarray(vector<int>& nums, int limit) {
//         int ans = 1;
        
//         for(int i = 0 ; i < nums.size() ; i++){
//             int max_e = nums[i] ;
//             int min_e = nums[i] ;
//             int max_i = i ;
//             int min_i = i ;
            
//             for(int j = i ; j < nums.size() ; j++){
//                 if(min_e < nums[j])
//                 {
//                     min_e = nums[j];
//                     min_i = j;
//                 }
//                 if(max_e > nums[j])
//                 {
//                     max_e = nums[j];
//                     max_i = j;
//                 }
                
                
//                 if(abs(max_e - min_e) <= limit){
//                     ans = max(ans , abs(j - i ) + 1 ) ;
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };