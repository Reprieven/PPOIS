#pragma once
#include"OrientedGraph.h"
#include"VertexIterator.h"
#include"EdgeIterator.h"
TEST(OrientedGraphTest, GetSizeTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	EXPECT_EQ(graph1.get_size(), 1);
};

TEST(OrientedGraphTest, VertexTrueCheckTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	EXPECT_TRUE(graph1.is_vertex(vertex1));
};

TEST(OrientedGraphTest, VertexFalseCheckTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	vertex1 = 1;
	EXPECT_FALSE(graph1.is_vertex(vertex1));
};

TEST(OrientedGraphTest, EdgeTrueCheckTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.add_edge(vertex1, vertex2);
	EXPECT_TRUE(graph1.is_edge(vertex1, vertex2));
};

TEST(OrientedGraphTest, EdgeFalseCheckTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.add_edge(vertex1, vertex2);
	EXPECT_FALSE(graph1.is_edge(vertex2,vertex1));
};

TEST(OrientedGraphTest, IsEmptyTest)
{
	OrientedGraph<int>graph1;
	EXPECT_TRUE(graph1.is_empty());
};

TEST(OrientedGraphTest, ClearTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.clear();
	EXPECT_TRUE(graph1.is_empty());
};

TEST(OrientedGraphTest, GetVertexNumTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	EXPECT_EQ(graph1.get_vertex_num(), 2);
};

TEST(OrientedGraphTest, GetEdgeNumTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.add_edge(vertex1, vertex2);
	graph1.add_edge(vertex1, vertex1);
	EXPECT_EQ(graph1.get_edge_num(), 2);
};

TEST(OrientedGraphTest, GetVertexOutdegreeTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.add_edge(vertex1, vertex2);
	EXPECT_EQ(graph1.get_vertex_outdegree(vertex1), 1);
};

TEST(OrientedGraphTest, GetVertexIndegreeTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.add_edge(vertex1, vertex2);
	EXPECT_EQ(graph1.get_vertex_indegree(vertex2), 1);
};

TEST(OrientedGraphTest, DeleteVertexTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	graph1.delete_vertex(vertex1);
	EXPECT_FALSE(graph1.is_vertex(vertex1));
};

TEST(OrientedGraphTest, DeleteEdgeTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	graph1.add_edge(vertex1, vertex1);
	graph1.delete_edge(vertex1, vertex1);
	EXPECT_FALSE(graph1.is_edge(vertex1, vertex1));
};

TEST(OrientedGraphTest, DeleteVertexByIterTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_vertex(vertex2);
	auto iter = graph1.vertex_begin();
	++iter;
	graph1.delete_vertex(iter);
	EXPECT_FALSE(graph1.is_vertex(vertex2));
};

TEST(OrientedGraphTest, DeleteEdgeByIterTest)
{
	OrientedGraph<int>graph1;
	int vertex1 = 12;
	graph1.add_vertex(vertex1);
	int vertex2 = 1;
	graph1.add_edge(vertex1, vertex1);
	graph1.add_edge(vertex1, vertex2);
	auto iter = graph1.edges_begin();
	graph1.delete_edge(iter);
	++iter;
	graph1.delete_edge(iter);
	EXPECT_FALSE(graph1.is_edge(vertex1, vertex1) || graph1.is_edge(vertex1, vertex2));
};

