class Solution {
public:
    int minIncrements(int n, vector<int>& cost) 
    {
        int ans = 0;
        while( n >= 3)
        {
            int i = (n/2)-1;
            
            //cout<<cost[i]<<" "<<cost[2*(i+1)]<<" "<<cost[ (2*(i+1))-1 ]<<endl;
            if( cost[2*(i+1)] != cost[ (2*(i+1))-1 ] )
            {
                ans += abs( cost[2*(i+1)] - cost[ (2*(i+1))-1 ]  );
            }
            
            cost[i] += max( cost[2*(i+1)] , cost[ (2*(i+1))-1 ]  );
            n -= 2;
            //cout<<cost[i]<<endl;
        }
        return ans;
    }
};