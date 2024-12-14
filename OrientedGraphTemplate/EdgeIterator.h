#pragma once
#include"OrientedGraph.h"
#include <iterator>
#include <list>
#include <vector>

using namespace std;

template <class T>
class OrientedGraph<T>::EdgeIter
{
private:
    const OrientedGraph<T>* graph;
    int row;
    int col;

    void move_to_next_edge()
    {
        while (row < graph->size) 
        {
            while (col < graph->size)
            {
                if (graph->matrix[row][col] == 1) 
                {
                        return;
                }
                ++col;
            }
            col = 0;
            ++row;
        }
    }

public:
    using iterator_category = forward_iterator_tag;
    using value_type = pair<T, T>;
    using difference_type = ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    friend class OrientedGraph;

    EdgeIter(const OrientedGraph<T>* graph, int row, int col)
    {
        this->col = col;
        this->row = row;
        this->graph = graph;
        move_to_next_edge();
    }

    value_type operator*() const 
    {
        return { graph->vertex_list[row], graph->vertex_list[col] };
    }

    EdgeIter& operator++() 
    {
        ++col;
        move_to_next_edge();
        return *this;
    }

    EdgeIter operator++(int)
    {
        EdgeIter temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const EdgeIter& other) const 
    {
        return graph == other.graph && row == other.row && col == other.col;
    }

    bool operator!=(const EdgeIter& other) const
    {
        return graph != other.graph || row != other.row || col != other.col;
    }

};

template <class T>
typename OrientedGraph<T>::EdgeIter OrientedGraph<T>::edges_begin() const
{
    return EdgeIter(this, 0, 0);
}

template <class T>
typename OrientedGraph<T>::EdgeIter OrientedGraph<T>::edges_end() const
{
    return EdgeIter(this, size, 0);
}