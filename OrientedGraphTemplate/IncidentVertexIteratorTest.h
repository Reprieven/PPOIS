#pragma once
#include<gtest/gtest.h>
#include"IncidentVertexIterator.h"
#include<string>
TEST(IncidentVertexTest,IterTest)
{
    OrientedGraph<string> graph;
    string a = "A", b = "B", c = "C", d = "D";
    graph.add_vertex(a);
    graph.add_vertex(b);
    graph.add_vertex(c);
    graph.add_vertex(d);

    graph.add_edge(a, b);
    graph.add_edge(a, c);
    graph.add_edge(b, c);
    graph.add_edge(c, d);

    string vertex = "A";
    auto it = graph.incident_vertex_begin(vertex);
    auto end = graph.incident_vertex_end(vertex);

    vector<string> expected_vertices = {"B", "C"};
    vector<string> actual_vertices;

    for (++it; it != end; ++it) 
    {
        actual_vertices.push_back(*it);
    }

    EXPECT_EQ(expected_vertices, actual_vertices);
};

TEST(IncidentVertexTest,NoIterationTest)
{
    OrientedGraph<string> graph;
    string a = "A", b = "B", c = "C", d = "D";
    graph.add_vertex(a);
    graph.add_vertex(b);
    graph.add_vertex(c);
    graph.add_vertex(d);

    graph.add_edge(a, b);
    graph.add_edge(a, c);
    graph.add_edge(b, c);
    graph.add_edge(c, d);

    string vertex = "D";
    auto it = graph.incident_vertex_begin(vertex);
    auto end = graph.incident_vertex_end(vertex);
    EXPECT_EQ(++it, end);
};

TEST(IncidentVertexTest,InvalidIteratorTest)
{
    OrientedGraph<string> graph;
    string a = "A", b = "B", c = "C", d = "D";
    graph.add_vertex(a);
    graph.add_vertex(b);
    graph.add_vertex(c);
    graph.add_vertex(d);

    graph.add_edge(a, b);
    graph.add_edge(a, c);
    graph.add_edge(b, c);
    graph.add_edge(c, d);

    string vertex = "Z";
    auto it = graph.incident_vertex_begin(vertex);
    auto end = graph.incident_vertex_end(vertex);
    EXPECT_EQ(it, end);
};
