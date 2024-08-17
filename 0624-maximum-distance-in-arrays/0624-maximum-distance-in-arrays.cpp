class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int max_num = INT_MIN;
        int max_num2 = INT_MIN;
        int min_num = INT_MAX;
        int min_num2 = INT_MAX;
        
        int flag;
        
        for(int i = 0 ; i < arrays.size() ; i++)
        {
            //If first_maximum and first_minimum comes from one particular arrays[i]
            if(max_num < arrays[i][arrays[i].size()-1] && min_num > arrays[i][0])
            {
                max_num2 = max_num;
                max_num = arrays[i][arrays[i].size()-1];
                min_num2 = min_num;
                min_num = arrays[i][0];
                flag = 0;
                continue;
            }
            if(max_num < arrays[i][arrays[i].size()-1])
            {
                max_num2 = max_num;
                max_num = arrays[i][arrays[i].size()-1];
                flag = 1;
            }
            else if(max_num2 < arrays[i][arrays[i].size()-1])
            {
                max_num2 = arrays[i][arrays[i].size()-1];
            }
            
            if(min_num > arrays[i][0])
            {
                min_num2 = min_num;
                min_num = arrays[i][0];
                flag = 1;
            }
            
            else if(min_num2 > arrays[i][0])
            {
                min_num2 = arrays[i][0];
            }
            
        }
        
        if( flag == 0)
        {
            return max(    abs(max_num-min_num2) , abs(max_num2-min_num)    );
        }
        
        return abs(max_num - min_num);
    }
};