class Solution {
public:
    int diri[4]={1,-1,0,0};
    int dirj[4]={0,0,1,-1};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>  >q;
        q.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        while(!q.empty()){
            auto it=q.top();q.pop();
            int curmin=it.first,ii=it.second.first,jj=it.second.second;
            if(ii==n-1 && jj==n-1)return curmin;
            for(int i=0;i<4;i++){
                int ni=ii+diri[i],nj=jj+dirj[i];
                if(ni>=0 && nj<n && ni<n && nj>=0 &&dis[ni][nj]>max(curmin,grid[ni][nj])){
                    q.push({max(curmin,grid[ni][nj]),{ni,nj}});
                    dis[ni][nj]=max(curmin,grid[ni][nj]);
                }
            }
        }
        return -1;
    }
};
