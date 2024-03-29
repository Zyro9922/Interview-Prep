/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define fi              first
#define se              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>

#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << " ";
	}
	return os;
}

bool bfsCycleDetection(vector<vector<int>> graph, vector<int> &visited, int cur) {
	queue<int> q;
	q.push(cur);

	while (!q.empty()) {
		//Remove
		//Mark*
		//Work
		//Add*

		int rem = q.front();
		q.pop();

		if (visited[rem] == true)
			return true;

		visited[rem] = true;

		for (auto nbr : graph[rem]) {
			if (visited[nbr] == false) {
				q.push(nbr);
			}
		}
	}

	return false;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<int>> graph(vertices);

	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	vector<int> visited(vertices);
	bool found = false;
	for (int v = 0; v < vertices; v++) {
		if (visited[v] == false) {
			if (bfsCycleDetection(graph, visited, v)) {
				found = true;
				break;
			}
		}
	}

	found ? cout << "true" : cout << "false";
}