#include <iostream>
#include <cstdlib>

#include "sort.h"
#include "selectionsort.h"
#include "quicksort.h"

using namespace std;

/*
 * This runs the sorts with your workloads and collects
 * timing information. Depending on the speed of your machine, it
 * could take hours to run. We suggest that, to collect your results,
 * you run it paramaterized as shown above. But, you probably want to 
 * test your workloads with much smaller lists and fewer iterations, 
 * first.
 * 
 * If you abolutely can't wait for the results, reduce the number
 * of ITERATIONS, perhaps all the way to 1. This makes your results
 * a little less reliable, since outliers can get in the way, but...
 * If it is still going to slowly for you to finish on time, try 
 * only MAX_SIZE=12000 ...or even MAX_SIZE=6000 iterations.
 * If you have to reduce MAX_SIZE below 24000, also reduce MIN_LIST
 * to 1500 or 750.
 */
int main (int argc, char *argv[])
{
  sort *s;

  
  cout << "Selection sort: Average case" << endl;
  for (int l=MIN_SIZE; l<= MAX_SIZE; l *=2)
  {
    s = new selectionsort(l, AVG_CASE);
    s->report();

    delete s;
  }
  
  cout << endl;

  cout << "Quick sort: Average case" << endl;
  for (int m=MIN_SIZE; m<= MAX_SIZE; m *=2)
  {
    s = new quicksort(m, AVG_CASE);
    s->report();

    delete s;
  }

  cout << "Quick sort: Worst case" << endl;
  for (int n=MIN_SIZE; n<= MAX_SIZE; n *=2)
  {
    s = new quicksort(n, WORST_CASE);
    s->report();

    delete s;
  }
  
  return EXIT_SUCCESS;
}
