#pragma once
#include "OrientedGraph.h"
#include <iterator>

template <class T>
class OrientedGraph<T>::IncidentVertexIterator
{
private:
    const OrientedGraph<T>* graph;
    int vertex_index;
    int current_index;

public:
    IncidentVertexIterator(const OrientedGraph<T>* graph, int vertex_index, int current_index)
    {
        this->graph = graph;
        this->vertex_index = vertex_index;
        this->current_index = current_index;
    }

    const T& operator*() const
    {
        return graph->vertex_list[current_index];
    }

    IncidentVertexIterator& operator++()
    {
        while (++current_index < graph->size) 
        {
            if (graph->matrix[vertex_index][current_index] == 1) 
            {
                return *this;
            }
        }
        current_index = graph->size;
        return *this;
    }

    IncidentVertexIterator operator++(int)
    {
        IncidentVertexIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const IncidentVertexIterator& other) const
    {
        return current_index == other.current_index && vertex_index == other.vertex_index && graph == other.graph;
    }

    bool operator!=(const IncidentVertexIterator& other) const
    {
        return !(*this == other);
    }
};

template <class T>
typename OrientedGraph<T>::IncidentVertexIterator  OrientedGraph<T>::incident_vertex_begin(const T& vertex) const
{
    auto iter_vertex = find(vertex_list.begin(), vertex_list.end(), vertex);
    if (iter_vertex == vertex_list.end()) {
        return IncidentVertexIterator(this, -1, size);
    }

    int vertex_index = distance(vertex_list.begin(), iter_vertex);
    return IncidentVertexIterator(this, vertex_index, -1);
}

template <class T>
typename OrientedGraph<T>::IncidentVertexIterator  OrientedGraph<T>::incident_vertex_end(const T& vertex) const
{
    auto iter_vertex = find(vertex_list.begin(), vertex_list.end(), vertex);
    if (iter_vertex == vertex_list.end()) {
        return IncidentVertexIterator(this, -1, size);
    }

    int vertex_index = distance(vertex_list.begin(), iter_vertex);
    return IncidentVertexIterator(this, vertex_index, size);
}