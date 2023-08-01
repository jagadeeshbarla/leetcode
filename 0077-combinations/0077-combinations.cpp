class Solution {
    vector<vector<int>> ans_1;
    map<vector<int>,int>map;
public:
    
    void fun(vector<int>&curr,int n,int k)
    {
       for(int i=0;i<k;i++)
       {           
           curr[i]+=1;
           if(curr[i]<=n)
           {
               set<int>s(curr.begin(),curr.end());
               if(s.size()==k )
               {
                    vector<int>temp;
                    temp = curr;
                    sort(temp.begin(),temp.end());
                    if(map.count(temp)<=0)
                    {
                        map[temp]=1;
                        ans_1.emplace_back(temp);
                        fun(temp,n,k);
                    }
               }
           }
           curr[i]-=1;
       }
    }
    vector<vector<int>> combine(int n, int k) {

      vector<int>temp;
      for(int i=1;i<=k;i++)
      {
          temp.emplace_back(i);
      }
      map[temp]=1;
      ans_1.emplace_back(temp);
      fun(temp,n,k);
        
      //set<vector<int>>s(ans_1.begin(),ans_1.end());
     // vector<vector<int>>nam(s.begin(),s.end());
      return ans_1;  
    }
};