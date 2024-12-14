#pragma once
#include"IncidentEdgeIterator.h"
#include<string>

TEST(IncidentEdgeIteratorTest,OutgoingTest)
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
    auto it = graph.incident_edges_begin(vertex, true);
    auto end = graph.incident_edges_end(vertex, true);
    vector<pair<string,string>> expected_edges = 
    {
        {"A", "B"},
        {"A", "C"}
    };
    vector<pair<string,string>> actual_edges;
    for(;it!=end;++it)
    {
        actual_edges.push_back(*it);
    }
    EXPECT_EQ(expected_edges, actual_edges);
};

TEST(IncidentEdgeIteratorTest,IngoingTest)
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
    string vertex = "C";
    auto it = graph.incident_edges_begin(vertex, false);
    auto end = graph.incident_edges_end(vertex, false);
    vector<pair<string,string>> expected_edges = 
    {
        {"A", "C"},
        {"B", "C"}
    };
    vector<pair<string,string>> actual_edges;
    for(;it!=end;++it)
    {
        actual_edges.push_back(*it);
    }
    EXPECT_EQ(expected_edges, actual_edges);
};
