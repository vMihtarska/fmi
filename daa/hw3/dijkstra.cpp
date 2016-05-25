#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

struct Pair
{
	Pair() :x(0), y(0) {}
	Pair(int x, int y) :x(x), y(y) {}
	int x, y;
};

struct Node
{
	int v;
	long long int w;
	long long int d;

	Node() :v(-1), w(1000000000000000000), d(0) {}

	Node(int v)
	{
		this->v = v;
		d = 0;
		w = 1000000000000000000;
	}

	Node(int v, long long int w)
	{
		this->v = v;
		d = 0;
		this->w = w;
	}

	Node(int v, bool visited)
	{
		this->v = v;
		d = 0;
		w = 1000000000000000000;
	}

	Node(const Node& o)
	{
		v = o.v;
		w = o.w;
		d = o.d;
	}

	Node& operator=(const Node& o)
	{
		v = o.v;
		w = o.w;
		d = o.d;
		return *this;
	}

	friend bool operator>(const Node& o1, const Node& o2)
	{
		return o1.d > o2.d;
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
			v[0].v = i;
			e.push_back(v);
		}
		size = n;
	}

	void AddEdge(int x, int y, long long int w)
	{
		bool in = false;
		for (int i = 0; i < e[x].size(); i++)
		{
			if (e[x][i].v == y && e[x][i].w > w)
			{
				in = true;
				e[x][i].w = w;
				break;
			}
		}
		if (!in)
			e[x].push_back(Node(y, w));
	}

	void printWeight()
	{
		for (int i = 0; i < e.size(); i++)
		{
			std::cout << e[i][0].v << " w: "
				<< e[i][0].w << " p: " << "\n";
		}
	}
	std::vector<std::vector<Node>> e;
	int size;
private:
};

std::vector<long long> Dijkstra(Graph g, int start)
{
	std::priority_queue<Node, std::vector<Node>, std::greater<Node> > pq;

	std::vector<bool> marked(g.e.size());
	std::vector<long long> distances(g.e.size());

	for (int i = 0; i < g.e.size(); i++)
	{
		marked[i] = false;
		distances[i] = 0;
	}

	pq.push(Node(start));
	while (!pq.empty())
	{
		Node curr = pq.top();
		pq.pop();
		if (!marked[curr.v])
		{
			marked[curr.v] = true;
			distances[curr.v] = curr.d;
			for (int i = 1; i < g.e[curr.v].size(); i++)
			{
				g.e[curr.v][i].d = g.e[curr.v][i].w + distances[curr.v];
				pq.push(g.e[curr.v][i]);
			}
		}
	}

	return distances;
}


int main()
{

	std::cin.sync_with_stdio(0);

	int n, m;
	std::cin >> n >> m;

	Graph g(n);

	int x, y;
	long long w;
	for (int i = 0; i < m; i++)
	{
		std::cin >> x >> y >> w;
		g.AddEdge(x, y, w);
	}

	std::vector<std::vector<long long>> vec(n);
	for (int i = 0; i < n; i++)
	{
		vec[i] = Dijkstra(g, i);
	}

	int q;
	std::cin >> q;

	for (int i = 0; i < q; i++)
	{
		std::cin >> x >> y;
		if (vec[x][y] == 0 && x != y)
			std::cout << "unreachable\n";
		else
			std::cout << vec[x][y] << "\n";
	}
}