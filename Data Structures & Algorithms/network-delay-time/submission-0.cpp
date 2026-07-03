class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>a(n+1);
        for(auto it:times){
            a[it[0]].push_back({it[2],it[1]});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<> >q;
        q.push({0,k});
        dis[k]=0;
        while(!q.empty()){
            auto l=q.top();
            int u=l.first;
            int v=l.second;
            q.pop();
            for(auto it:a[v]){
                int d=it.first;
                int node=it.second;
                if(u+d<dis[node]){
                    dis[node]=u+d;
                    q.push({u+d,node});
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX)return -1;
            res=max(res,dis[i]);
        }
        
        return res;
    }
};