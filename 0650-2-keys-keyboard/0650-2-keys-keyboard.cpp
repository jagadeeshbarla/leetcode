class Solution {
public:
    int minSteps(int n)
    {
     vector<int>v;
     v.emplace_back(0);
     v.emplace_back(0);
     v.emplace_back(2);
     v.emplace_back(3);
        
     for(int i=4;i<=n;i++)
     {
         if(i%2 == 0)
         {
            v.emplace_back(v[(i)/2]+2);
         }
         else
         {
           int j = i-1;
            int flag =1;
            while(j>=2)
            {
                if(i%j ==0)
                {
                    flag = 0;
                    int x = v[j]+(i/j);
                    v.emplace_back(x);
                    break;
                }
                j--;
            }
            if(flag == 1)
            {
                v.emplace_back(i);
            }
         }
     }
     return v[n];
    }
};