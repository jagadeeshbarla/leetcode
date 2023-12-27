class Solution {
public:
    int minCost(string c, vector<int>& n) {
        
        int ans = 0 ;
        char pre = c[0];
        int sum = n[0];
        int min_e = n[0];
        for(int i = 1 ; i < c.size() ; i++)
        {
            if(pre == c[i])
            {
                
                while(i < c.size() && pre == c[i])
                {
                    sum+=n[i];
                    min_e = max(min_e,n[i]);
                    //cout<<i<<" - "<<sum<<" "<<min_e<<endl;
                    i++; 
                }
                ans = ans + sum - min_e;
                
            }
            if(i < c.size())
            {
                    sum = n[i];
                    min_e = n[i];
                    pre = c[i];
            }
            
           // cout<<i<<" "<<sum<<" "<<min_e<<endl;
        }
        return ans;
    }
};