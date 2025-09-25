class Solution {
public:
    int MST(vector<vector<int>>&points){
        int n=points.size();
        vector<bool>vis(n+10,false);
        int ans=0;
        vector<int>dis(n+10,INT_MAX);
        dis[0]=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(vis[j]==false&&(u==-1||dis[j]<dis[u])){
                    u=j;
                }
            }
            vis[u]=true;
            ans+=dis[u];
            for(int j=0;j<n;j++){
                if(vis[j]==false){
                    int res=abs(points[u][0]-points[j][0])+abs(points[u][1]-points[j][1]);
                    dis[j]=min(dis[j],res);
                }
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        return MST(points);
    }
};