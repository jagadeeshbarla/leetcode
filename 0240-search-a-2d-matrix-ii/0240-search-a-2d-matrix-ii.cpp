class Solution {
public:
    bool check(vector<int>& mat, int target)
    {
        int i = 0;
        int j = mat.size()-1;
        while(j>=i)
        {
            int mid = (i+j)/2;
            if(mat[mid]==target)
            {
                return true;
            }
            else if(mat[mid]<target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][0]>target )
            {
                break;
            }
            bool k = check(mat[i],target);
            if(k)
            {
                return true;
            }
        }
        return false;
    }
};