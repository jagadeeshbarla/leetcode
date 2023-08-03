class Solution {
    vector<vector<int>>ans;
    map<vector<int>,int>m;
public:
    
    void fun(vector<int>temp,vector<int>& c, int t)
    {
       int sum = accumulate(temp.begin(),temp.end(),0);
       if(sum==t)
       {
           vector<int>s(temp.begin(),temp.end());
           sort(s.begin(),s.end());
           if(m.count(s)==1)
           {
                return;
           }
           m.insert({s,1});
           ans.emplace_back(temp);
           return;
       }
       else if(sum>t)
       {
           return;
       }
        for(int i=0;i<c.size();i++)
        {
           // fun(temp,c,t);
            temp.emplace_back(c[i]);
            fun(temp,c,t);
            temp.pop_back();
            //fun(temp,c,t);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>temp;
        fun(temp,c,t);
        return ans;
    }
};