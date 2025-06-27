class Solution {
	public:
		int f(int i,int count,vector<int>& v,vector<vector<int>>& dp){
			if(i==v.size()) return 0;
			if(dp[i][count]!=-1) return dp[i][count];
			int take=count*v[i]+f(i+1,count+1,v,dp);
			int not_take=f(i+1,count,v,dp);
			return dp[i][count]=max(take,not_take);
		}

		int maxSatisfaction(vector<int>& v) {
			int n=v.size();
			sort(v.begin(),v.end());
			vector<vector<int>> dp(n,vector<int>(n+1,-1));
			return f(0,1,v,dp);
		}
	};
	