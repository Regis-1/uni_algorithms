#ifndef SORTER_HH_
#define SORTER_HH_

template<typename T>
class Sorter{
	private:
		T partition( T* array, int i_low, int i_high);
		void swap(T* a, T* b);
		void merge(T* array, int i_low, int i_m, int i_high);
	public:
		void merge_sort(T* array, int i_low, int i_high);
		void quick_sort(T* array, int i_low, int i_high);
		void intro_sort(T* array);
};

#endif
