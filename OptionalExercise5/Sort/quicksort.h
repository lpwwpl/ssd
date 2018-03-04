#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sort.h"

class quicksort : public sort 
{
  private:
    void sortPartition (int left, int right);
    int findPivot (int left, int right);
    int partition (int left, int right);

  protected:
    void init (int how_many, int workload_type);

  public:
     quicksort(int how_many, int workload_type);
     void sortNumbers();

};

#endif
