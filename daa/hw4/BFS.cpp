#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct Node
{
	int v;
	bool visited;
	int w;
	int p;
	int path;

	Node(int v)
	{
		this->v = v;
		this->visited = false;
		p = -1;
		path = 0;
		w = 1000;
	}

	Node(int v, bool visited)
	{
		this->v = v;
		this->visited = visited;
		p = -1;
		path = 0;
		w = 1000;
	}
	Node(int v, int w)
	{
		this->v = v;
		this->visited = false;
		p = -1;
		path = 0;
		this->w = w;
	}
	Node(const Node& o)
	{
		v = o.v;
		visited = o.visited;
		p = o.p;
		w = o.w;
		path = o.path;
	}

	Node& operator=(const Node& o)
	{
		v = o.v;
		visited = o.visited;
		p = o.p;
		path = o.path;
		w = o.w;
		return *this;
	}

};

class Graph
{
public:
	Graph() : size(0) {}
	Graph(const Graph& o)
		:e(o.size)
	{
		for (int i = 0; i < o.size; i++)
		{
			e[i] = o.e[i];
		}
		size = o.size;
	}
	Graph(int n)
	{
		std::vector<Node> v;
		v.push_back(Node(0));
		for (int i = 0; i < n; i++)
		{
			v[0].v = i + 1;
			v[0].path = 0;
			e.push_back(v);
		}
		size = n;
	}
	void AddEdge(int x, int y, int w)
	{
		int in = false;
		for (int i = 0; i < e[x-1].size(); i++)
		{
			if (e[x-1][i].v == y)
			{
				in = true;
				if (e[x-1][i].w >w)
				{
					e[x-1][i].w = w;
				}
			}
		}
		if(!in)
			e[x - 1].push_back(Node(y, w));

		in = false;

		for (int i = 0; i < e[y-1].size(); i++)
		{
			if (e[y-1][i].v == x)
			{
				in = true;
				if (e[y-1][i].w >w)
				{
					e[y-1][i].w = w;
				}
			}
		}
		if (!in)
		e[y - 1].push_back(Node(x, w));
	}


	void print()
	{
		for (int i = 0; i < e.size(); i++)
		{
			for (int j = 0; j < e[i].size(); j++)
			{
				std::cout << e[i][j].v << " ";
			}
			std::cout << "\n";
		}
	}
	void printWeight()
	{
		for (int i = 0; i < e.size(); i++)
		{
			std::cout << e[i][0].v - 1 << " w: "
				<< e[i][0].w << " p: "
				<< e[i][0].p - 1 << "\n";
		}
	}
	std::vector<std::vector<Node>> e;
	int size;
private:
};

std::vector<int> sum(const Graph& g, int n)
{
	std::vector<int> res;
	res.push_back(n);
	int sum = 0;
	int par;
	while (n != 1)
	{
		par = g.e[n - 1][0].p;
		for (int i = 0; i < g.e[par - 1].size(); i++)
		{
			if (g.e[par - 1][i].v == n)
			{
				sum += g.e[par - 1][i].w;
				break;
			}
		}

		n = par;
		res.push_back(n);
	}

	res.push_back(sum);
	return res;
}

std::vector<int> BFSShortestRoute(Graph& g, int x, int y)
{
	std::queue<int> q;
	int b = 0;
	int min = 4000000;
	std::vector<int> shortestPath;
	g.e[x - 1][0].visited = true;
	q.push(x);
	int newValue = 0;
	while (!q.empty())
	{
		for (int i = 1; i < g.e[q.front() - 1].size(); i++)
		{

			if (g.e[q.front() - 1][i].v == y)
			{
				g.e[g.e[q.front() - 1][i].v - 1][0].p = q.front();

				newValue = g.e[q.front() - 1][0].path + 1;
				if (newValue < g.e[g.e[q.front() - 1][i].v - 1][0].path || g.e[g.e[q.front() - 1][i].v - 1][0].path == 0)
				{
					g.e[g.e[q.front() - 1][i].v - 1][0].p = q.front();
					g.e[g.e[q.front() - 1][i].v - 1][0].path = newValue;
				}

				if (newValue == b || b == 0)
				{
					//std::cout << sum(g, y);
					std::vector<int> currS = sum(g, y);
					if (min > currS[currS.size() - 1])
					{
						min = currS[currS.size() - 1];
						shortestPath = currS;
					}
					b = newValue;
				}
				else
					return shortestPath;
			}

			if (!g.e[g.e[q.front() - 1][i].v - 1][0].visited)
			{
				g.e[g.e[q.front() - 1][i].v - 1][0].visited = true;
				newValue = g.e[q.front() - 1][0].path + 1;
				if (newValue < g.e[g.e[q.front() - 1][i].v - 1][0].path || g.e[g.e[q.front() - 1][i].v - 1][0].path == 0)
				{
					g.e[g.e[q.front() - 1][i].v - 1][0].p = q.front();
					g.e[g.e[q.front() - 1][i].v - 1][0].path = newValue;
				}

				q.push(g.e[q.front() - 1][i].v);
			}
		}
		q.pop();
	}

	return shortestPath;
}

int main()
{
	std::cin.sync_with_stdio(0);

	int n, m;
	std::cin >> n >> m;
	Graph g(n);

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		std::cin >> a >> b >> c;
		g.AddEdge(a, b, c);
	}

	std::vector<int> res = BFSShortestRoute(g, 1, n);
	
	for (int i = res.size() - 1; i >= 0; i--)
	{
		if (i == res.size() - 1)
		{
			std::cout << res[i] << "\n";
		}
		else
			std::cout << res[i] << " ";
	}

	std::cout << "\n";
}