class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>>space(m,vector<int>(n,0));
        //ans = m * n;
        for(int i = 0 ; i < walls.size() ; i++){
            space[walls[i][0]][walls[i][1]] = -1; //wall
            
        }
        for(int i = 0 ; i < guards.size() ; i++){
            int x = guards[i][0];
            int y = guards[i][1];
            
            //Top
            int t = x - 1;
            while(t >= 0 ){
                if(space[t][y] == 1 || space[t][y] == -1 || space[t][y] == 5){
                    break;
                }
                space[t--][y] = 1;
            }
            //Bottom
            int b = x + 1 ;
            while(b < space.size()){
                if(space[b][y] == 2 || space[b][y] == -1 || space[b][y] == 5){
                    break;
                }
                space[b++][y] = 2;                
            }
            //Left
            int l = y - 1;
            while(l >= 0 ){
                if(space[x][l] == 3 || space[x][l] == -1 || space[x][l] == 5){
                    break;
                }
                space[x][l--] = 3;                
            }
            //Right
            int r = y + 1 ;
            while(r < space[0].size()){
                if(space[x][r] == 4 || space[x][r] == -1 || space[x][r] == 5){
                    break;
                }
                space[x][r++] = 4;
            }
            space[x][y] = 5; //guards
        }
        
        int ans = 0;
        for(int i = 0 ; i < space.size() ; i++ ){
            for(int j = 0 ; j < space[0].size() ; j++ ){
                //cout<<space[i][j]<<" ";
                ans += (space[i][j] == 0) ? 1 : 0;
            }
            //cout<<endl;
        }
        return ans;
        
    }
};