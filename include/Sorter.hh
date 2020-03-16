#ifndef SORTER_HH_
#define SORTER_HH_

#include <math.h>

template<typename T>
class Sorter{
	private:
		T partition( T* array, int i_low, int i_high);
		void merge(T* array, int i_low, int i_m, int i_high);
		void make_heap(T* array, int n, int i);
		void sort_heap(T* array, int n);
		void insertion_sort(T* array, T* begin, T* end);
		T* median_of_three(T* a, T* b, T* c);
		void intro_sort_run(T* array, T* begin, T* end, int depth_limit);
	public:
		void swap(T* a, T* b);
		void merge_sort(T* array, int i_low, int i_high);
		void quick_sort(T* array, int i_low, int i_high);
		void intro_sort(T* array, int i_low, int i_high);
};

#endif
