class Solution {
public:
    int m,n;
    int dfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
 
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=1;
        if(i+1<m){
            if(mat[i+1][j]>mat[i][j]){
                maxi=max(maxi,1+dfs(i+1,j,mat,dp));
            }
        }
        if(i-1>=0){
             if(mat[i-1][j]>mat[i][j]){
                maxi=max(maxi,1+dfs(i-1,j,mat,dp));
            }
        }
        if(j+1<n){
            if(mat[i][j+1]>mat[i][j]){
                maxi=max(maxi,1+dfs(i,j+1,mat,dp));
            }
        }
        if(j-1>=0){
            if(mat[i][j-1]>mat[i][j]){
                maxi=max(maxi,1+dfs(i,j-1,mat,dp));
            }
        }

        return dp[i][j]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        m=mat.size();n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    dp[i][j]=dfs(i,j,mat,dp);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               maxi=max(maxi,dp[i][j]);
            }
        }
        return  maxi;
    }
};