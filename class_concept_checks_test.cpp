// (C) Copyright Jeremy Siek 2000. Permission to copy, use, modify,
// sell and distribute this software is granted provided this
// copyright notice appears in all copies. This software is provided
// "as is" without express or implied warranty, and with no claim as
// to its suitability for any purpose.

#include <boost/pending/concept_checks.hpp>

/*

  This file verifies that the BOOST_CLASS_REQUIRES macros of the
  Boost Concept Checking Library do not cause errors when
  they are not suppose to.

*/

struct foo { bool operator()(int) { return true; } };
struct bar { bool operator()(int, char) { return true; } };

class class_requires_test
{
  BOOST_CLASS_REQUIRES(int, EqualityComparableConcept);
  typedef int* int_ptr;
  typedef const int* const_int_ptr;
  BOOST_CLASS_REQUIRES2(int_ptr, const_int_ptr, Comparable2Concept);
  BOOST_CLASS_REQUIRES3(foo, bool, int,  UnaryFunctionConcept);
  BOOST_CLASS_REQUIRES4(bar, bool, int, char, BinaryFunctionConcept);
};

int
main()
{
  class_requires_test x;
  ignore_unused_variable_warning(x);
  return 0;
}
