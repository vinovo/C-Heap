#include "cutest/CuTest.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
    
/* 
 * Add your tests here
 * A few sample tests 
 * are provided
 */

void TestHeap(CuTest *tc) {
  Heap* h = makeHeap(10);
  CuAssertIntEquals(tc, 0, h->size);
  cleanupHeap(h);
}

void TestOne(CuTest *tc) {
  int two = 2;
  int four = 4;
  CuAssertIntEquals(tc, four, two+two);
}

void TestTwo(CuTest *tc) {
  char* lol = "lol";
  char* alsoLol = "lol";
  CuAssertStrEquals(tc, lol, alsoLol);
}

void TestMakeHeap(CuTest *tc) {
	Heap* h = makeHeap(10);
	CuAssertIntEquals(tc, 10, h->capacity);
	cleanupHeap(h);
}

void TestAdd(CuTest *tc) {
	Heap* h = makeHeap(3);
	add(h, 2, "3");
	add(h, 1, "1");
	add(h, 0, "0");
	add(h, 2, "2");
	CuAssertIntEquals(tc, 0, h->elements[0].key);
	CuAssertStrEquals(tc, "0", h->elements[0].value);
	CuAssertIntEquals(tc, 1, h->elements[1].key);
	CuAssertStrEquals(tc, "1", h->elements[1].value);
	CuAssertIntEquals(tc, 2, h->elements[2].key);
	CuAssertStrEquals(tc, "3", h->elements[2].value);
	CuAssertIntEquals(tc, 2, h->elements[3].key);
	CuAssertStrEquals(tc, "2", h->elements[3].value);
	cleanupHeap(h);
}

CuSuite* StrUtilGetSuite() {
  CuSuite* suite = CuSuiteNew();

  /** ADD YOUR TESTS HERE **/
  SUITE_ADD_TEST(suite, TestHeap);
  SUITE_ADD_TEST(suite, TestOne);
  SUITE_ADD_TEST(suite, TestTwo);
  return suite;
}


// Don't edit below this line

void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();
  CuSuite* ourSuite = StrUtilGetSuite();
  
  CuSuiteAddSuite(suite, ourSuite);

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);

  CuStringDelete(output);
  CuSuiteDelete(suite);
  free(ourSuite);
}

int main(void) {
  RunAllTests();
  return 0;
}
