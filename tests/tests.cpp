#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "size.hh"
#include "rectangle.hh"
#include <stdio.h>

// testy dla klasy Vector

TEST_CASE("vector - konstruktor bezparametryczny Vector()")
{
  Vector test = Vector();
  for(int i=0;i<SIZE;i++){
  CHECK(test[i]==0);
  }
}


TEST_CASE("vector - konstruktor parametryczny Vector(double[2])")
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


TEST_CASE("vector - operator ==") 
{
  double sample_pack1[2] = {1,2};
  Vector sample1 = Vector(sample_pack1);
  double sample_pack[2] = {1,2};
  Vector sample = Vector(sample_pack);    
  CHECK(sample == sample1);
}


TEST_CASE("vector - operator [out of size]") 
{
  double sample_pack[2] = {21,37};
  Vector sample = Vector(sample_pack);  

  WARN_THROWS(sample[3]);
 
}

// testy dla klasy Matrix 

TEST_CASE("Matrix - konstruktor bezparametryczny Matrix()")
{
  double temporary[2][2]={{1,0},
                          {0,1}};
  Matrix example = Matrix(temporary);
  Matrix test = Matrix();
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(test(i,j)==example(i,j));
    }
  }
}


TEST_CASE("Matrix - konstruktor parametryczny Matrix(double[2][2])")
{
  double example[2][2] = {{1,2},{1,2}}; 
  //double bad_sample[2][2] = {{2137,2137},{1,2}};
  Matrix test = Matrix(example);
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(test(i,j)==example[i][j]);
    }
  }    
}


TEST_CASE("Matrix - operator * (mnożenie macierzy2x2 razy wektor2x1")
{
   double correct_tab[2] = {280,280};

   double example1[2][2] = {{1,2},{1,2}}; 
   Matrix test = Matrix(example1);

   double example2[2] = {34,123};
   Vector test1 = Vector(example2);

   Vector result = test*test1;

   for(int i=0; i < 2; i++){
   CHECK(result[i] == correct_tab[i]);
   }
}     

TEST_CASE("Matrix - operator ()") 
{
 Matrix test = Matrix();
 WARN_THROWS(test(0,10));
}
  
// testy dla klasy rectangle

TEST_CASE("rectangle - konstruktor bezparametryczny rectangle()")
{
  Vector second_one;
  rectangle test = rectangle();
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++)
  CHECK(test(i,j)==second_one);
  }
}


TEST_CASE("rectangle - konstruktor parametryczny rectangle()")
{
 
  rectangle test = rectangle(wsp);
 
   for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++)
  CHECK(test(i,j)==wsp[i][j]);
  }
  
}


TEST_CASE("rectangle - operator +")
{
  rectangle test = rectangle();

  double second[2] = {2137,2137};
  Vector second_one = Vector(second);
  test = test + second_one;

 
   for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++)
  CHECK(test(i,j)==second_one);
  }
}


TEST_CASE("rectangle - operator <<")
{
  rectangle test = rectangle();
  std::ostringstream out;

  out << test;
  CHECK("0 0 \n0 0 \n0 0 \n0 0 \n" == out.str());
}


TEST_CASE("rectangle - operator ()") 
{
 rectangle test = rectangle();
 

  WARN_THROWS(test(0,10));
 
}


TEST_CASE("rectangle - translacja")
{
  double w1[2] = {85,115};
  double w2[2] = {85,165};
  double w3[2] = {435,165};
  double w4[2] = {435,115};
  Vector correct[2][2] = {{w1,w2},{w3,w4}};
  rectangle ok = rectangle(correct);

  rectangle test = rectangle(wsp); // wsp to Vector[][2] i znajduje sie w rectangle.hh
  double przesuniecie[2] = {-15,15};
  Vector przesuniecia = Vector(przesuniecie);
  test = test + przesuniecia;
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(test(i,j) == ok(i,j));
    }
  }
}

/*
TEST_CASE("rectangle - rotacja o -180 stopni 1 raz")
{
  double w1[2] = {-100,-100};
  double w2[2] = {-100,-150};
  double w3[2] = {-450,-150};
  double w4[2] = {-450,-100};
  Vector correct[2][2] = {{w1,w2},{w3,w4}};
  rectangle ok = rectangle(correct);

  rectangle test = rectangle(wsp); // wsp to Vector[][2] i znajduje sie w rectangle.hh
  test.rotacja(-180,1);
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(test(i,j) == ok(i,j));
    }
  }
}
*/