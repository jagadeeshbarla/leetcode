class Solution {
public:
    int minimumDeletions(string s) {
        //vector<int>a_count_b(s.size(),0);
        vector<int>a_count_a(s.size(),0);
        vector<int>b_count_b(s.size(),0);
        //vector<int>b_count_a(s.size(),0);
        
        
        
        if(s[0] == 'a')
        {
            //a_count_b[0] = 1;
        }
        else
        {
            b_count_b[0] = 1;
        }
        for(int i = 1 ; i < s.size() ; i++)
        {
            if(s[i] == 'a')
            {
                //a_count_b[i] = a_count_b[i-1] + 1;
                b_count_b[i] = b_count_b[i-1] ;
            }
            else
            {
                b_count_b[i] = b_count_b[i-1] + 1;
                //a_count_b[i] = a_count_b[i-1];
            }
        }

        if(s[s.size()-1] == 'b')
        {
            //b_count_a[s.size()-1] = 1;
        }
        else
        {
            a_count_a[s.size()-1] = 1;
        }
        for(int i =   s.size()-2 ; i >= 0 ; i--)
        {
            if(s[i] == 'b')
            {
                //b_count_a[i] = b_count_a[i+1] + 1;
                a_count_a[i] = a_count_a[i+1] ;
            } 
            else
            {
                //b_count_a[i] = b_count_a[i+1] ;
                a_count_a[i] = a_count_a[i+1] + 1;
            } 
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i < s.size() ; i++)
        {
            ans = min(ans,b_count_b[i]+a_count_a[i]-1);
        }
        return ans;        
    }
};