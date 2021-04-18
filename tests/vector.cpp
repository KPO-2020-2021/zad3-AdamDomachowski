#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "size.hh"
#include <stdio.h>


TEST_CASE("vector - konstruktor bezparametryczny Vector()")
{
  Vector test = Vector();
  for(int i=0;i<SIZE;i++){
  CHECK(test[i]==0);
  }
}


TEST_CASE("vector - konstruktor parametryczny Vector() (tylko dla 2 elementowego)")
{
  double example[2] = {1,2}; 
  //double bad_sample[2] = {2137,2137};
  Vector test = Vector(example);
  for(int i=0;i<SIZE;i++){
  CHECK(test[i]==example[i]);
  }
}


TEST_CASE("vector - operator +")
{
  double first[2] = {1,2}; 
  Vector first_one = Vector(first);

  double second[2] = {2137,2137};
  Vector second_one = Vector(second);
  first_one + second_one;

  double sum[2] = {2138,2139};
  Vector sample = Vector(sum);

  for(int i=0;i<SIZE;i++){
  CHECK(first_one[i]==sample[i]);
  }
}


TEST_CASE("vector - operator -")
{
  double first[2] = {1,2}; 
  Vector first_one = Vector(first);

  double second[2] = {2137,2137};
  Vector second_one = Vector(second);
  first_one - second_one;

  double sum[2] = {-2136,-2135};
  Vector sample = Vector(sum);

  for(int i=0;i<SIZE;i++){
  CHECK(first_one[i]==sample[i]);
  }
}


TEST_CASE("vector - operator <<")
{
  double sample_pack[2] = {21,37};
  std::ostringstream out;
  Vector sample = Vector(sample_pack);
  out << sample;

  CHECK("21 37 " == out.str());
}


TEST_CASE("vector - operator >>") 
{
  Vector sample;  

  std::istringstream in("21 15");
  in >> sample;
  std::ostringstream out;
  out << sample;

  CHECK("21 15 " == out.str());
}

/*
TEST_CASE("vector - operator ==") 
{
  double sample_pack1[2] = {1,2};
  Vector sample1 = Vector(sample_pack1);
  double sample_pack[2] = {1,2};
  Vector sample = Vector(sample_pack);    
  CHECK(sample1 == sample);
}
*/

TEST_CASE("vector - operator [] (standard)") 
{
  double sample_pack[2] = {21,37};
  Vector sample = Vector(sample_pack);  
  for(int i=0;i<SIZE;i++){
  CHECK(sample[i]==sample_pack[i]);
  }
}

/*
TEST_CASE("vector - operator [out of size]") 
{
  double sample_pack[2] = {21,37};
  Vector sample = Vector(sample_pack);  
  for(int i=0;i<SIZE;i++){
  CHECK(sample[3]==false);
  }
}
*/