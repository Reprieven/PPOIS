#pragma once
#include "OrientedGraph.h"
#include <iterator>
#include <utility>

template <class T>
class OrientedGraph<T>::IncidentEdgeIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = std::pair<T, T>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

private:
    const OrientedGraph<T>* graph;
    int vertex_index;             
    int current_index;             
    bool is_outgoing;              

public:
    IncidentEdgeIterator(const OrientedGraph<T>* g, int vertex, int current, bool outgoing)
    {
        graph = g;
        vertex_index = vertex;
        current_index = current;
        is_outgoing = outgoing;
        move_to_next_valid_edge();
    }

    value_type operator*() const 
    {
        if (is_outgoing)
        {
            return { graph->vertex_list[vertex_index], graph->vertex_list[current_index] };
        }
        else
        {
            return { graph->vertex_list[current_index], graph->vertex_list[vertex_index] };
        }
    }

    IncidentEdgeIterator& operator++() 
    {
        ++current_index;
        move_to_next_valid_edge();
        return *this;
    }

    IncidentEdgeIterator operator++(int) 
    {
        IncidentEdgeIterator temp = *this;
        ++(*this);
        return temp;
    }

    IncidentEdgeIterator& operator--() 
    {
        --current_index;
        move_to_previous_valid_edge();
        return *this;
    }

    IncidentEdgeIterator operator--(int) 
    {
        IncidentEdgeIterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const IncidentEdgeIterator& other) const 
    {
        return graph == other.graph && vertex_index == other.vertex_index &&
            current_index == other.current_index && is_outgoing == other.is_outgoing;
    }

    bool operator!=(const IncidentEdgeIterator& other) const 
    {
        return !(*this == other);
    }

private:
    void move_to_next_valid_edge() 
    {
        while (current_index < graph->size) 
        {
            if (is_outgoing && graph->matrix[vertex_index][current_index] == 1) 
            {
                return;
            }
            if (!is_outgoing && graph->matrix[current_index][vertex_index] == 1) 
            {
                return;
            }
            ++current_index;
        }
    }

    void move_to_previous_valid_edge() 
    {
        while (current_index >= 0) {
            if (is_outgoing && graph->matrix[vertex_index][current_index] == 1) 
            {
                return;
            }
            if (!is_outgoing && graph->matrix[current_index][vertex_index] == 1) 
            {
                return;
            }
            --current_index;
        }
    }
};

template <class T>
typename OrientedGraph<T>::IncidentEdgeIterator
OrientedGraph<T>::incident_edges_begin(const T& vertex, bool outgoing) const 
{
    auto iter_vertex = std::find(vertex_list.begin(), vertex_list.end(), vertex);
    if (iter_vertex == vertex_list.end()) {
        return IncidentEdgeIterator(this, -1, -1, outgoing);
    }
    int vertex_index = std::distance(vertex_list.begin(), iter_vertex);
    return IncidentEdgeIterator(this, vertex_index, 0, outgoing);
}

template <class T>
typename OrientedGraph<T>::IncidentEdgeIterator
OrientedGraph<T>::incident_edges_end(const T& vertex, bool outgoing) const 
{
    auto iter_vertex = std::find(vertex_list.begin(), vertex_list.end(), vertex);
    if (iter_vertex == vertex_list.end()) {
        return IncidentEdgeIterator(this, -1, -1, outgoing);
    }
    int vertex_index = std::distance(vertex_list.begin(), iter_vertex);
    return IncidentEdgeIterator(this, vertex_index, this->size, outgoing);
}