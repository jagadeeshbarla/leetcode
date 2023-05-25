class Solution {
public:
    int compress(vector<char>& c)
    {
        
        
        
        string ans ="";
        char pre = c[0];
        int count = 1;
        int flag = 0;
        for(int i=1;i<c.size();i++)
        {
            if(pre != c[i])
            {
                ans+=pre;
                if(count>1)
                {
                    ans+=to_string(count);
                }
                pre = c[i];
                count = 1;
               // flag = 1;
            }
            else
            {
                flag = 0;
                count ++;
            }
        }
        if(flag == 0)
        {
                ans+=pre;
                if(count>1)
                {
                    ans+=to_string(count);
                } 
        }
        cout<<ans;
        c.clear();
        
        for(int i=0;i<ans.size();i++)
        {
            c.emplace_back(ans[i]);
        }
        
        return c.size();
    }
};