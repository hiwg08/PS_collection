#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, MAX = INT_MIN;

vector<int> Graph[10001];

bool Vis[10001]{ 0 };

int Ans[10001]{ 0 };

// 지금 보면 어려운 문제가 아닌데, 왜이렇게 정답률이 낮을까 싶다.
// 초반에 틀렸던 이유는 불필요하게 map을 썼기 때문이다.

int DFS(int Idx)
{
	Vis[Idx] = true;

	int ret = 1;

	for (int i = 0; i < (int)Graph[Idx].size(); i++)
	{
		if (!Vis[Graph[Idx][i]])
			ret += DFS(Graph[Idx][i]);
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		Graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(Vis, false, sizeof(Vis));
		Ans[i] = DFS(i) - 1;
		MAX = max(MAX, Ans[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (Ans[i] == MAX) cout << i << " ";
	}
	cout << '\n';
}