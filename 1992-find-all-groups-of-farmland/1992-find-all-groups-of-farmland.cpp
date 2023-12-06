class Solution {
public:
    
    
    void trav(vector<vector<int>>& land, int i,int j,vector<int>& temp)
    {
        if(i  == land.size()  || j == land[0].size() || land[i][j] ==0 || land[i][j] == 2)
        {
            return ;
        }
        temp[2] = max(temp[2],i);
        temp[3] = max(temp[3],j);
        land[i][j] = 2;
        trav(land,i+1,j,temp);
        trav(land,i,j+1,temp);
    }
    
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        
        for(int i = 0 ; i < land.size() ; i++)
        {
            for(int j = 0 ; j < land[0].size() ; j++)
            {
                if(land[i][j] == 1)
                {
                    vector<int>temp;
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    
                    trav(land,i+1,j,temp);
                    trav(land,i,j+1,temp);
                    ans.emplace_back(temp);
                    land[i][j] = 2;
                }
            }
        }
        return ans;
    }
};