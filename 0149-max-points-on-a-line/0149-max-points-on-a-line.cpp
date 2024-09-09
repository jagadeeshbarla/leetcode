class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int ans = 1;
        for(int i = 0 ; i < points.size() ; i++) 
        {
            unordered_map<float,int>m;
            for(int j = i+1 ; j < points.size() ; j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                float inc;
                if( x != 0)
                {
                    inc = (float)y/x;
                }
                else
                {
                    inc = FLT_MAX;
                }
                m[inc]+=1;
                ans = max(ans , m[inc]+1);
                
            }
        }
        return ans;
    }
};