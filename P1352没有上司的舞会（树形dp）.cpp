#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 6e3 + 5;//边数
int n, cnt, r[maxn], dp[maxn][2];
bool vis[maxn];
struct Edge
{
	int to, next;//终点，同起点的上一条边的编号
} edge[maxn];//边集
int head[maxn];//表示以i为起点的第一条边在边集数组的位置（编号）

void init() //初始化
{
	for (int i = 1; i <= n; i++) head[i] = -1;
}

void add(int u, int v) //加边，u起点，v终点
{
	edge[cnt].to = v;//终点
	edge[cnt].next = head[u]; //以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
	head[u] = cnt++;//更新以u为起点上一条边的编号
}

void dfs(int now)
{
	dp[now][0] = 0, dp[now][1] = r[now];
	for (int j = head[now]; j != -1; j = edge[j].next)
	{
		dfs(edge[j].to);
		dp[now][0] += max(dp[edge[j].to][0], dp[edge[j].to][1]);
		dp[now][1] += dp[edge[j].to][0];
	}
}

int main()
{
	cin >> n;
	init(); 
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	int l, k, root;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> l >> k;
		add(k, l);
		vis[l] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			root = i;
			break;
		}
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]);
}
