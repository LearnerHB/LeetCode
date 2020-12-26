/**	骰子的点数	🌟🌟

将一个骰子投掷n次，获得的总点数为s，s的可能范围为n~6n。
掷出某一点数，可能有多种掷法，例如投掷2次，掷出3点，共有[1,2],[2,1]两种掷法。
请求出投掷n次，掷出n~6n点分别有多少种掷法。

样例1
输入：n=1
输出：[1, 1, 1, 1, 1, 1]
解释：投掷1次，可能出现的点数为1-6，共计6种。
每种点数都只有1种掷法。所以输出[1, 1, 1, 1, 1, 1]。

样例2
输入：n=2
输出：[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]
解释：投掷2次，可能出现的点数为2-12，共计11种。
每种点数可能掷法数目分别为1,2,3,4,5,6,5,4,3,2,1。
所以输出[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]。

思路
0. 暴力枚举，O(N!)，会TLE，不可取
1. 动态规划, O(N^2)
dp[i][j]表示用i个骰子扔出和为j的可能数，第i个骰子可能扔出1-6的点数
其等于k从1到6情况下 dp[i-1][j-k]*dp[1][k]的求和，因为dp[i][k]为1
所以dp[i][j] = dp[i-1][j-k]
(
dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1; 
dp[1][4] = 1; dp[1][5] = 1; dp[1][6] = 1;
)
   
*/
//暴力枚举，会TLE
class Solution {
public:
    vector<int> numberOfDice(int n) {
    	vector<int> ans;
    	for (int i = n; i <= 6*n; i++)
    		ans.push_back(dfs(n, i));

    	return ans;

    }
    int dfs (int n, int sum) {
    	if (sum < 0)	return 0;
    	if (!n)			return !sum;

    	int a = 0;
    	for (int i = 1; i <= 6; i++)
    		a += dfs(n-1, sum-i);

    	return a;
    }
};

//使用二维数组
class Solution {
public:
    vector<int> numberOfDice(int n) {
    	vector<int> ans;
       	vector<vector<int>>dp(n+1, vector<int>(n*6+1));
       	dp[0][0] = 1;
       	for (int i = 1; i <= n; i++) 
       		for (int j = i; j <= i * 6; j++) 
       			for (int k = 1; k <= 6; k++) {
       				if (j-k<0)
       					break;
       				dp[i][j] += dp[i-1][j-k];
       			}
       	for (int i = n; i <= n*6; i++)
       		ans.push_back(dp[n][i]);

       	return ans;
    }
};

//由于我们最后只需要使用n个骰子的情况，所以我们可以用一维数组
class Solution {
public:
	vector<int> numberOfDice(int n) {
		vector<int> dp(6*n+1, 0);
		for (int i = 1; i <= 6; i++)
			dp[i] = 1;
		for (int i = 2; i <= n; i++){ //这一层用来遍历从2个骰子到n个骰子的情况
			//为啥这里j可以到0，而上面的情况到i就可以。这里如果写到i会出现错误
			for (int j = 6*i; j >= 0; j--) { //这一层用来遍历可能出现的各种点数
				dp[j] = 0;//由于使用了滚动数组，dp会被反复使用，所以每次用都要初始化
				for (int k = 1; k <= 6; k++){
					if (j-k<0)
						break;
					dp[j] += dp[j-k];
				}
			}
		}
		vector<int>ans(dp.begin()+n, dp.end());

		return ans;
	}
};
