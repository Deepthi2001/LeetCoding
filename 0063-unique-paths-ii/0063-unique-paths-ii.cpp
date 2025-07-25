class Solution {
public:
    int uniquePathsWithObstaclesHelper(vector<vector<int>>& obstacleGrid, int i, int j){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 || j==0) return 1;
        if(i<0 || j<0) return 0;
        return uniquePathsWithObstaclesHelper(obstacleGrid,i-1,j)+uniquePathsWithObstaclesHelper(obstacleGrid,i,j-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // return uniquePathsWithObstaclesHelper(obstacleGrid,m-1,n-1);
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];        
    }
};