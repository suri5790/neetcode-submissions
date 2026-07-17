class Dsu{

    private:
    vector<int>par,size;
    public:
    Dsu(int n){
      par.resize(n+1);size.resize(n+1);
      for(int i=0;i<=n;i++){
        par[i]=i;size[i]=1;
      }
    }

    int findpar(int node){
        if(par[node]==node)return node;
        else return par[node]=findpar(par[node]);
    }
    void unionbysize(int u,int v){
        int u_par=findpar(u);
        int v_par=findpar(v);
        if(u_par==v_par)return ;
        if(size[u_par]<size[v_par]){
            size[v_par]+=size[u_par];
            par[u_par]=v_par;
        }
        else {
            size[u_par]+=size[v_par];
            par[v_par]=u_par;
        }
    }
};

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Dsu d(n);
        vector<int>res;
        for(int i=0;i<n;i++){
            int u_par=d.findpar(edges[i][0]);
            int v_par=d.findpar(edges[i][1]);
            if(u_par==v_par){res.push_back(edges[i][0]);res.push_back(edges[i][1]);return res;}
            else d.unionbysize(edges[i][0],edges[i][1]);
        }
        return {-1,-1};
    }
};
