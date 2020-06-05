#include <iostream>
#include <list>
using namespace std;

int bfs(int start, list<int>* adj, int N, int choice)
{
	list<int> bfsq;
	int* visit = new int[N];
	for(int i=0; i<N; i++)
	{
		visit[i] = -99;
	}
	bfsq.push_back(start);
	visit[start] = 0;
	int curr;
	while(!bfsq.empty())
	{
		curr = bfsq.front();
		bfsq.pop_front();
		list<int> :: iterator i;
		for(i=adj[curr].begin(); i!=adj[curr].end(); ++i)
		{
			if(visit[*i] == -99)
			{
				bfsq.push_back(*i);
				visit[*i] = visit[curr] + 1;
			}
		}
	}
	if( choice==0 )	return curr;
	else
	return visit[curr];
	
	
}

int path( list<int>* adj, int N)
{
	
	// starting from any node find longest path node from there
	int farNode = bfs(0, adj, N, 0);
	
	// starting from derived node find longest path
	return bfs(farNode, adj, N, 1);
}

int main() {
	int N;
	cin >> N;
	list<int>* adj = new list<int>[N];
	for(int i=0; i<N-1; i++)
	{
		int e1, e2;
		cin >> e1 >> e2;
		adj[e1-1].push_back(e2-1);
		adj[e2-1].push_back(e1-1);
	}
	
	cout << path(adj, N) << endl;
	return 0;
}
