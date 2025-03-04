#pragma once
#include "OrientedGraph.h"
#include <iterator>

using namespace std;


template <class T>
class OrientedGraph<T>::VertexIter
{
private:
	const OrientedGraph<T>* graph;
	size_t position;
public:
	using value_type = T;
	using difference_type = ptrdiff_t;
	using iterator_category = bidirectional_iterator_tag;

	friend class OrientedGraph;

	VertexIter(const OrientedGraph<T>* graph, size_t pos) 
	{
		this->graph = graph;
		this->position = pos;
	}
	
	T& operator * () const 
	{
		return graph->vertex_list[position];
	}
	
	T* operator ->() const
	{
		return &graph->vertex_list[position];
	}

	VertexIter operator ++() 
	{
		position++;
		return* this;
	}

	VertexIter operator ++(int) 
	{
		VertexIter temp = *this;
		++(*this);
		return temp;
	}

	VertexIter operator --()
	{
		position--;
		return* this;
	}

	VertexIter operator --(int)
	{
		VertexIter temp = *this;
		--(*this);
		return temp;
	}

	bool operator == (const VertexIter& other)const 
	{
		return graph == other.graph;
	}

	bool operator !=(const VertexIter& other)const
	{
		return graph != other.graph;
	}
};

template <class T>
typename OrientedGraph<T>::VertexIter OrientedGraph<T>::vertex_begin() const
{
	return VertexIter(this, 0);
}

template <class T>
typename OrientedGraph<T>::VertexIter OrientedGraph<T>::vertex_end() const
{
	return VertexIter(this, vertex_list.size());
}