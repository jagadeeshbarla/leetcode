class Solution {
    int m =-1;
public:
    bool dfs(int count,map<int,int>&ma,int target,vector<int>& e)
    {
        if(e[target]==-1)
            {
                return false ;
            }
        if(ma.count(target)==0)
        {
            
            count+=1;
            ma.insert({target,count});
            
            if(!dfs(count,ma,e[target],e))
            {ma.erase(target);return false;}
            return true;
        }
        if(ma.count(target)==1)
        {
            m=max(m,count-ma[target]+1);
            return true;  
        }
        return true;
    }
    int longestCycle(vector<int>& e) {
        vector<int>s(e.size(),0);
        
        for(int i=0;i<e.size();i++){if(e[i]!=-1)s[e[i]]++;}
        
        for(int i=0;i<s.size();i++)
        {  if(s[i]==0){e[i]=-1;}   }
        
    
        map<int,int>ma;
        for(int i=0;i<e.size();i++)
        {
          
            if(e[i]!=-1 && ma.count(i)==0)
            {
                int count =1;
                ma.insert({i,count});
                
                if(!dfs(count,ma,e[i],e))
                {ma.erase(i);}
               // dfs(count,ma,e[i],e);
            }
        }
        return m;
    }
};