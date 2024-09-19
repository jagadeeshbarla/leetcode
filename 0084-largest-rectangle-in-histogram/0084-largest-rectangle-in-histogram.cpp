class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        vector<int>l(heights.size());
        vector<int>r(heights.size());
        l[0] = 0;
        r[r.size()-1] = heights.size()-1;
        
        //l_vector stores the indexes
        for(int i = 1 ; i < heights.size() ; i++){
            l[i] = i;
            int temp = i-1;
            while(temp >=0 && heights[i] <= heights[temp]){
                if(heights[i] == heights[temp]){
                    l[i] = l[temp]; 
                    break;
                }
                l[i] = temp--;
            }
            
        }
        
        //r_vector stores the indexs
        for(int i = heights.size()-2 ; i >= 0 ; i--){
            r[i] = i;
            int temp = i+1;
            while(temp < heights.size() && heights[i] <= heights[temp]){
                if(heights[i] == heights[temp]){
                    r[i] = r[temp];    
                    break;
                }
                r[i] = temp++;
            }           
        }
        
        
        //calculate ans
        int ans = 0;
        for(int i = 0 ; i < heights.size() ; i++){
            //cout<<r[i]<<" "<<l[i]<<endl;
            ans = max(ans,heights[i]*(r[i] - l[i] +1 ));            
        }
        return ans;
    }
};




// [0,2,1,5,6,2,3,0]
// [2,1,5,6,2,3,0]
// [0,2,1,5,6,2,3]
// [2,4]
// [1]
// [0,2,1,5,6,2,3,0]
// [1,1,1,1,1]
// [5,4,3,2,1]
// [1,2,3,4,5]
// [6,2,5,4,5,1,6]
// [0,0,0,0,0]
// [10,10,1,10,10]
// [1000,1000,1000,1000]
// [1,1000,1]
// [1,2,1]
// [2,1,2]
// [2,1,2,1]
// [1,2,1,2]
// [2,1,2,1,2]
// [1,2,1,2,1]
// [2,1,2,1,2,1]
// [1,2,1,2,1,2]
// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
