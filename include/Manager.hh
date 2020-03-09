#ifndef MANAGER_HH_
#define MANAGER_HH_

#include "../include/Sorter.hh"

enum Sort_algorithm{merge, quick, intro};

template<typename T>
class Manager{
	private:
		Sorter<T>* sorter = new Sorter<T>;
		int s_algorithm;
	public:
		T* create_array(int size);
		void delete_array(T* array);
		void sort_array(T* array);
		void set_algorithm(int alg);
};

#endif
