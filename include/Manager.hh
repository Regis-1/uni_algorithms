#ifndef MANAGER_HH_
#define MANAGER_HH_

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <math.h>

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
		long int sort_array(T* array, int i_low, int i_high, int a_size);
		void random_array(T* array, int size);
		void print_array(T* array, int size);
		void set_algorithm(int alg);
		int get_eobs(int size, float percentage);
		void reverse_array(T* array, int size);
};

#endif
