class Solution {
public:
int s(int m,int n,vector<vector<int>> &v1){
if(m==0 && n==0)return 1;
int x=0,y=0;
if(v1[m][n]!=-1)return v1[m][n];
if(m-1>=0) x= s(m-1,n,v1);
if(n-1>=0) y=s(m,n-1,v1);
 return v1[m][n]=x+y;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> v1(m,vector<int>(n,-1));
       
       
        return  s(m-1,n-1,v1);
    }
};