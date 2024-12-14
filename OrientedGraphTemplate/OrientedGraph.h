#pragma once
#include<vector>
#include<algorithm>
#include"IncidentEdgeIterator.h"
using namespace std;
template <class T>
class OrientedGraph
{
private:
	int size;
	vector<T> vertex_list;
	vector<vector<int>>matrix;
public:
	OrientedGraph() :size(0) {};

	OrientedGraph(OrientedGraph& other) 
	{
		this->size = other.size;
		this->vertex_list = other.vertex_list;
		this->matrix = other.matrix;
	}

	~OrientedGraph()=default;

	bool is_empty() 
	{
		return size == 0;
	}

	int get_size()
	{
		return size;
	}

	void clear()
	{
		size = 0;
		vertex_list.clear();
		matrix.clear();
	}

	bool is_vertex(T& value)
	{
		
		if (find(vertex_list.begin(), vertex_list.end(), value) != vertex_list.end())
			return true;
		else
			return false;
	}

	bool is_edge(T& from, T& to)
	{
		auto iter_from = find(vertex_list.begin(), vertex_list.end(), from);
		auto iter_to = find(vertex_list.begin(), vertex_list.end(), to);
		if (iter_to == vertex_list.end() || iter_from == vertex_list.end())
		{
			return false;
		}

		int pos_from = distance(vertex_list.begin(), iter_from);
		int pos_to = distance(vertex_list.begin(), iter_to);
		return matrix[pos_from][pos_to]==1;
	}

	int get_vertex_num() 
	{
		return vertex_list.size();
	}

	int get_edge_num()
	{
		int num = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) 
			{
				if (matrix[i][j] == 1) 
				{
					num++;
				}
			}
		}
		return num;
	}

	int get_vertex_outdegree(T& vertex) 
	{
		int num = 0;
		auto iter_vertex = find(vertex_list.begin(), vertex_list.end(), vertex);
		if (iter_vertex == vertex_list.end())
		{
			return -1;
		}
		int vertex_i = distance(vertex_list.begin(), iter_vertex);
		for (int j = 0; j < size; j++) 
		{
			if (matrix[vertex_i][j] == 1) 
			{
				num++;
			}
		}
		return num;
	}

	int get_vertex_indegree(T& vertex)
	{
		int num = 0;
		auto iter_vertex = find(vertex_list.begin(), vertex_list.end(), vertex);
		if (iter_vertex == vertex_list.end())
		{
			return -1;
		}
		int vertex_j = distance(vertex_list.begin(), iter_vertex);
		for (int i = 0; i < size; i++)
		{
			if (matrix[i][vertex_j] == 1)
			{
				num++;
			}
		}
		return num;
	}


	void add_vertex(T& value)
	{
		vertex_list.push_back(value);
		size++;

		for (auto& row : matrix)
		{
			row.push_back(0);
		}
		matrix.emplace_back(size, 0);
	}

	void add_edge(T& from, T& to)
	{
		auto iter_from = find(vertex_list.begin(), vertex_list.end(), from);
		auto iter_to = find(vertex_list.begin(), vertex_list.end(), to);
		if (iter_to == vertex_list.end() || iter_from == vertex_list.end())
		{
			return;
		}

		int pos_from = distance(vertex_list.begin(), iter_from);
		int pos_to = distance(vertex_list.begin(), iter_to);
		matrix[pos_from][pos_to] = 1;
	}

	void delete_edge(T& from, T& to)
	{
		auto iter_from = find(vertex_list.begin(), vertex_list.end(), from);
		auto iter_to = find(vertex_list.begin(), vertex_list.end(), to);
		if (iter_to == vertex_list.end() || iter_from == vertex_list.end())
		{
			return;
		}

		int pos_from = distance(vertex_list.begin(), iter_from);
		int pos_to = distance(vertex_list.begin(), iter_to);
		matrix[pos_from][pos_to] = 0;
	}

	void delete_vertex(T& vertex) 
	{
		auto iter_vertex = find(vertex_list.begin(), vertex_list.end(), vertex);
		if (iter_vertex== vertex_list.end())
		{
			return;
		}

		int index_vertex = distance(vertex_list.begin(), iter_vertex);
		vertex_list.erase(iter_vertex);
		matrix.erase(matrix.begin() + index_vertex);
		for (auto& row : matrix)
		{
			row.erase(row.begin() + index_vertex);
		}
		size--;
	}

	class VertexIter;

	VertexIter vertex_begin() const;
	VertexIter vertex_end() const;

	class EdgeIter;
	
	EdgeIter edges_begin() const;
	EdgeIter edges_end() const;

	class IncidentEdgeIterator;

	IncidentEdgeIterator incident_edges_begin(const T& vertex, bool outgoing) const;
	IncidentEdgeIterator incident_edges_end(const T& vertex, bool outgoing) const;

	class IncidentVertexIterator;

	IncidentVertexIterator incident_vertex_begin(const T& vertex) const;
	IncidentVertexIterator incident_vertex_end(const T& vertex) const;

	void delete_vertex(VertexIter iter) 
	{
		if (iter.graph != this)
		{
			return;
		}
		size_t index_vertex = iter.position;
		vertex_list.erase(vertex_list.begin() + index_vertex);
		matrix.erase(matrix.begin() + index_vertex);
		for (auto& row : matrix)
		{
			row.erase(row.begin() + index_vertex);
		}
		size--;
	}

	void delete_edge(EdgeIter iter) 
	{
		if (iter.graph != this)
		{
			return;
		}
		int row = iter.row;
		int col = iter.col;
		if (row < size && col < size) 
		{
			matrix[row][col] = 0;
		}
	}
};
