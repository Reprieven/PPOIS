#include<gtest/gtest.h>
#include"IncidentEdgeIteratorTest.h"
#include"IncidentVertexIteratorTest.h"
#include"OrientedGraphTest.h"
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}