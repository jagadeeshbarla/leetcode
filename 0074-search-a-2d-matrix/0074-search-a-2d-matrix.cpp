class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) 
    {
    
    for(int i=0;i<m.size();i++)
    {
        //cout<<m[i][0]<<"   "<<m[i][m[0].size()-1];
        if( m[i][0]<=t   && m[i][m[0].size()-1]>=t  )
        {
            for(int j=0;j<m[0].size();j++)
            {
                if(m[i][j]==t)
                {return true;}
            }
            break;
        }
    }
    return false;    
    }
};