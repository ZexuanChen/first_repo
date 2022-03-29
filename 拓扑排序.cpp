#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5; 
int n, m, cnt, in[maxn];

struct Edge{
    int to, w, next;
} edge[maxn];
int head[maxn];

void init() 
{
    for (int i = 1; i <= n; i++) head[i] = -1;
}

void add_edge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void topSort()
{
	priority_queue<int, vector<int>, greater<int> > q;
    for (int i=1; i<=n; i++) if (in[i]==0) q.push(i);
    
    vector<int> ans; //ansΪ�������� 
    while(!q.empty()) {
        int p = q.top(); q.pop(); //ѡһ�����Ϊ0�ĵ㣬������ 
        ans.push_back(p);
        for(int i=head[p]; i != -1; i=edge[i].next) {
            int j=edge[i].to;
            in[j]--;
            if(in[j]==0) q.push(j);  
        }
    }
    
    if (ans.size() == n) {
        for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
        printf("\n");
    }
    else printf("No Answer!\n");   //  ans �еĳ�����n����ȣ���˵������������
}

int main()
{
	//������ͳ�����
	init();
	topSort();
}
