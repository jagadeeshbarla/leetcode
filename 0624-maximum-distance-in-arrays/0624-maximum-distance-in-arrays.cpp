class Solution {
    
public:
    
    int maxDistance(vector<vector<int>>& arrays) {
        
        int max_num = INT_MIN;
        int max_num2 = INT_MIN;
        
        int min_num = INT_MAX;
        int min_num2 = INT_MAX;
        
        for(int i = 0 ; i < arrays.size() ; i++)
        {
            if(max_num < arrays[i][arrays[i].size()-1])
            {
                max_num2 = max_num;
                max_num = arrays[i][arrays[i].size()-1];
            }
            else if(max_num2 < arrays[i][arrays[i].size()-1])
            {
                max_num2 = arrays[i][arrays[i].size()-1];
            }
            
            if(min_num > arrays[i][0])
            {
                min_num2 = min_num;
                min_num = arrays[i][0];
            }
            
            else if(min_num2 > arrays[i][0])
            {
                min_num2 = arrays[i][0];
            }
            
        }
        
        for(int i = 0 ; i < arrays.size() ; i++)
        {
            if( max_num == arrays[i][arrays[i].size()-1] && min_num == arrays[i][0] ) // edge case
            {
                return max(    abs(max_num-min_num2) , abs(max_num2-min_num)    );
                //cout<<max_num<<" "<<min_num2<<" "<<max_num2<<" "<<min_num<<endl;
    
            }
        }
        
        
        
        return abs(max_num - min_num);
    }
};