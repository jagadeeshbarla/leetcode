class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        for(int i = matrix.size()-2 ; i >= 0 ; i--)
        {
            for(int j = 0; j < matrix[i].size() ; j++)
            {
                int min_s = INT_MAX;
                for(int k = 0; k < matrix[i+1].size() ; k++)
                {
                    if(k == j)
                    {
                        continue;
                    }
                    if(matrix[i+1][k] < min_s)
                    {
                        min_s = matrix[i+1][k];
                    }
                
                }
                matrix[i][j] += min_s;
            }
        }
        
        
       /* for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return *min_element(matrix[0].begin(),matrix[0].end());
        
    }
};