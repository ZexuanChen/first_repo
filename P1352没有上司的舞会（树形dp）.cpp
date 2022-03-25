#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 6e3 + 5;			 //����
int n, m, cnt, r[maxn], dp[maxn][2]; // n���㣬m����
bool vis[maxn];
struct Edge
{
	int to, w, next; //�յ㣬��Ȩ��ͬ������һ���ߵı��
} edge[maxn];		 //�߼�
int head[maxn];		 // head[i],��ʾ��iΪ���ĵ�һ�����ڱ߼������λ�ã���ţ�

void init() //��ʼ��
{
	for (int i = 0; i <= n; i++) head[i] = -1;
	cnt = 0;
}

void add(int u, int v) //�ӱߣ�u��㣬v�յ�
{
	edge[cnt].to = v;		  //�յ�
	edge[cnt].next = head[u]; //��uΪ�����һ���ߵı�ţ�Ҳ����������������ͬ����һ���ߵı��
	head[u] = cnt++;		  //������uΪ�����һ���ߵı��
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
