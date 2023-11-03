class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string>ans;
        
        int curr = 1;
        for(int i = 0 ; i <  target.size() ;i++)
        {
            if(target[i]!=curr)
            {
                while(target[i] != curr)
                {
                    ans.emplace_back("Push");
                    ans.emplace_back("Pop");
                    curr++;
                }
                i--;
                
            }   
            else
            {
                ans.emplace_back("Push");
                curr++;
            }
            
        }
        return ans;
    }
};