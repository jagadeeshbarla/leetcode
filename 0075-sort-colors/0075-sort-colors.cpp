class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                a+=1;
            }
            if(nums[i]==1)
            {
                b+=1;
            }
            if(nums[i]==2)
            {
                c+=1;
            }
            
        }
        int i=0;
        while(a>0)
        {
            nums[i]=0;
            a--;
            i++;
        }
        while(b>0)
        {
            nums[i]=1;
            i++;
            b--;
        }
        while(c>0)
        {
            nums[i]=2;
            i++;
            c--;
        }
        //return nums;
        
    }
};