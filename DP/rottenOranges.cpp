// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int dfs(vector<vector<int>>& grid, int x,int y,int depth,vector<vector<int>>& dp){
        int m1,m2,m3,m4;
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return numeric_limits<int>::max();
        cerr << x << ' ' << y << endl;
        if(grid[x][y] != 1) return depth;
        m1 = m2 = m3 = m4 = numeric_limits<int>::max();
        
        m1 = dfs(grid,x+1,y,depth+1,dp);
        m2 = dfs(grid,x-1,y,depth+1,dp);
        m3 = dfs(grid,x,y+1,depth+1,dp);
        m4 = dfs(grid,x,y-1,depth+1,dp);
        
        dp[x][y] = min(dp[x][y],min(m1,min(m2,min(m3,m4))));
        return dp[x][y];
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),numeric_limits<int>::max()));
        
        if(grid.size() == 0 || grid[0].size() == 0) return -1;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++)
                if(dp[i][j] == numeric_limits<int>::max() && grid[i][j] == 1)
                    dfs(grid,i,j,0,dp);
        }
        
        int _max = -1;
        
        for(auto i : dp)
            for(auto j : i)
                if(j != numeric_limits<int>::max())
                    _max = max(_max,j);
                
        return _max;
    }
};

// { Driver Code Starts.
int main(){
    freopen("in.txt","r",stdin);
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends