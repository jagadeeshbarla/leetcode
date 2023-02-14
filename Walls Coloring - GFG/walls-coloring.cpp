//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &c, int N) 
    {
        // Write your code here.
        for(int i=c.size()-2;i!=-1;i--)
        {
          c[i][0]+=min(c[i+1][1],c[i+1][2]);
          c[i][1]+=min(c[i+1][0],c[i+1][2]); 
          c[i][2]+=min(c[i+1][1],c[i+1][0]);
        }
        int min=INT_MAX;
        int i=2;
        while(i>=0)
        {
            if(c[0][i]<min)
            {
                min=c[0][i];
            }
            i--;
        }
        for(int i=0;i<c.size();i++)
        {
            for(int j=0;j<3;j++)
            {
               // cout<<c[i][j]<<"  ";
            }
            //cout<<endl;
        }
        return min;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends