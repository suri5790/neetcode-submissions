class Solution {
public:
    int m,n;
    int f(int i,int j,vector<vector<int>>&v,string &t1,string &t2){
        if(i>=m || j>=n)return 0;
        if(v[i][j]!=-1)return v[i][j];
        int maxi=0;
        if(t1[i]==t2[j]){
            maxi=max(maxi,1+f(i+1,j+1,v,t1,t2));
        }
        else {
            maxi=max(f(i+1,j,v,t1,t2),f(i,j+1,v,t1,t2));
        }
        return v[i][j]=maxi;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();n=text2.size();
        vector<vector<int>>v(m,vector<int>(n,-1));
        return f(0,0,v,text1,text2);
    }
};
