#include <iostream>
#include <list>
using namespace std;


bool cycleUtil(int start, list<int>* adjL, int n, bool* visited, int parent)
{
	visited[start] = true;
	list<int> :: iterator i;
	for(i = adjL[start].begin(); i!=adjL[start].end(); ++i) // recursive dfs
	{
		if(!visited[*i])
		{
			
			if(cycleUtil(*i, adjL, n, visited, start))	return true;
			
		}
		 else if( *i != parent) // check if cycle
		 	return true;
	}
	return false;
}

bool checkTree(list<int>* adjL, int n)
{
	bool* visited = new bool[n];
	for(int i=0; i<n; i++)
	{
		visited[i] = false;
	}
	
	if(cycleUtil(0, adjL, n, visited, -1)) // detects cyclic graph
		return false;
	
	for(int i=0; i<n; i++)
	{
		if(!visited[i])	return false;
	}
	
	
	return true;
}


int main() {
	int m, n;
	cin >> n >> m;
	list<int>* adjL = new list<int>[n];
	for(int i=0; i<m; i++)
	{
		int a1, a2;
		cin >> a1 >> a2;
		adjL[a1-1].push_back(a2-1);
		adjL[a2-1].push_back(a1-1);
	}
	if( m != n-1 )	cout << "NO" << endl; // a connected tree will have (# of edges = # of nodes -1 )
	else
	{
		cout << (checkTree(adjL, n) ? "YES" : "NO") << endl;  // to check if it is acyclic & connected
	}
	return 0;
}
