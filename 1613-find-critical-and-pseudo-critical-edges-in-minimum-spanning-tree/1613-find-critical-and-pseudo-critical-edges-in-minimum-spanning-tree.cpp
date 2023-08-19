class UnionFind
{
	std::vector<int> rank;
	std::vector<int> parent;
public:
	UnionFind(int n) : rank(n), parent(n) { std::iota(std::begin(parent), std::end(parent), 0); }

	int find(int u)
	{
		if (u != parent[u]) { parent[u] = find(parent[u]); }

		return parent[u];
	}

	void combine(int u, int v)
	{
		auto root_u = find(u);
		auto root_v = find(v);

		if (root_u == root_v) { return; }

		if (rank[root_u] == rank[root_v])
		{
			parent[root_v] = root_u;
			++rank[root_u];
		}
		else
		{
			if (rank[root_u] < rank[root_v]) { std::swap(root_u, root_v); }
			parent[root_v] = root_u;
		}
	}
}; 

class Solution
{
	void dfs(int u, std::vector<std::vector<std::pair<int, int>>> const& graph, std::vector<bool>& visited, int index)
	{
		if (visited[u]) { return; }
		visited[u] = true;

		for (auto const& edge : graph[u])
		{
			if (edge.first == index) { continue; }

			auto v = edge.second;
			dfs(v, graph, visited, index);
		}
	}
	std::pair<std::vector<int>, std::vector<int>> check_graph(int n, UnionFind& unionFind, std::vector<std::vector<int>> const& edges, std::vector<int> const& chunk)
	{
		if (std::size(chunk) == 1) { return std::pair{ chunk, std::vector<int>() }; }

		auto graph = std::vector<std::vector<std::pair<int, int>>>(n);
		for (auto index : chunk)
		{
			auto const& edge = edges[index];
			auto [c, d] = std::pair{ unionFind.find(edge[0]), unionFind.find(edge[1]) };
			graph[c].emplace_back(index, d);
			graph[d].emplace_back(index, c);
		}

		auto critical = std::vector<int>();
		auto pseudo = std::vector<int>();

		for (auto index : chunk)
		{
			auto const& edge = edges[index];
			auto [c, d] = std::pair{ unionFind.find(edge[0]), unionFind.find(edge[1]) };
			auto visited = std::vector<bool>(n);
			dfs(c, graph, visited, index);

			visited[d] ? pseudo.push_back(index) : critical.push_back(index);
		}

		return std::pair{ critical, pseudo };
	}
public:
	std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& edges)
	{
		auto unionFind = UnionFind(n);

		auto indices = std::vector<int>(std::size(edges));
		std::iota(std::begin(indices), std::end(indices), 0);

		std::sort(std::begin(indices), std::end(indices),
			[&edges](auto const& lhs, auto const& rhs) { return edges[lhs][2] < edges[rhs][2]; });

		auto critical = std::vector<int>();
		auto pseudo = std::vector<int>();

		for (auto iter = std::cbegin(indices); iter != std::cend(indices);)
		{

			auto weight = edges[*iter][2];
			auto jter = std::find_if_not(iter, std::cend(indices),
				[&edges, weight](auto k) { return edges[k][2] == weight; });

			auto chunk = std::vector<int>();
			for (; iter != jter; ++iter)
			{
				auto index = *iter;
				auto const& edge = edges[index];
				
				auto c = unionFind.find(edge[0]);
				auto d = unionFind.find(edge[1]);
				if (c != d) { chunk.push_back(index); }
			}
			
			auto [crit, pseu] = check_graph(n, unionFind, edges, chunk);
			critical.insert(std::cend(critical), std::cbegin(crit), std::cend(crit));
			pseudo.insert(std::cend(pseudo), std::cbegin(pseu), std::cend(pseu));

			for (auto index : chunk)
			{
				auto const& edge = edges[index];
				auto u = edge[0];
				auto v = edge[1];
				unionFind.combine(u, v);
			}
		}

		auto result = std::vector<std::vector<int>>(2);
		result[0] = std::move(critical);
		result[1] = std::move(pseudo);

		return result;
	}
};