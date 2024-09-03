class Solution {
public:
    
    int lcs(string word1,string word2)
    {
        vector<vector<int>>v(word1.length()+1,vector<int>(word2.length()+1,0));
        
        for(int i = 1 ; i < v.size() ; i++)
        {
            for(int j = 1 ; j < v[0].size() ;j++)
            {

                if(word1[i-1] == word2[j-1])
                {
                    v[i][j] = v[i-1][j-1]+1;
                    
                }
                else
                {
                    v[i][j] = max(v[i-1][j] , v[i][j-1]);
                }
            }
        }       
        
        return v[word1.length()][word2.length()];
    }
    int minDistance(string word1, string word2) {
        
        return word1.length()+word2.length()- 2* lcs(word1,word2);        
    }
};