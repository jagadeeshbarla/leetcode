class Solution {
public:
    string getHint(string secret, string guess) 
    {
     
     int count_c=0;
     string s,g;
     for(int i=0;i<secret.size();i++)
     {
        
         if(secret[i]==guess[i])
         {
             count_c++;
         }
         else
         {
             s+=secret[i];
             g+=guess[i];
         }
         
     }
        
      vector<int>sv(10,0);
      vector<int>gv(10,0);
     for(int i=0;i<g.size();i++)
     {
         sv[int(g[i])-48]++;
         gv[int(s[i])-48]++;
     }
     int m=0;
     
     for(int i=0;i<sv.size();i++){m+=min(sv[i],gv[i]);}
        
     //cout<<s<<"  "<<g;
     string ans;
     ans += c(count_c);
     ans += char(65);
     ans += c(m);
     ans += char(66);
        
     return ans;
        
    }
    string c(int n)
    {
        string ans="";
        if(n==0)
        {
            return "0";
        }
        while(n>0)
        {
            ans+=char((n%10)+48);
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        return ans;
    }
};