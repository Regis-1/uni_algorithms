#include "../include/Manager.hh"

template<typename T>
T* Manager<T>::create_array(int size){
	return new T[size];
}

template<typename T>
void Manager<T>::delete_array(T* array){
	delete[] array;
}

template<typename T>
long int Manager<T>::sort_array(T* array, int i_low, int i_high, int a_size){
	auto t1=std::chrono::high_resolution_clock::now();
	auto t2=std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

	switch(s_algorithm){
		case merge:
			t1 = std::chrono::high_resolution_clock::now();
			sorter->merge_sort(array, i_low, i_high);
			t2 = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
			return duration;
		case quick:
			t1 = std::chrono::high_resolution_clock::now();
			sorter->quick_sort(array, i_low, i_high);
			t2 = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
			return duration;
		case intro:
			t1 = std::chrono::high_resolution_clock::now();
			sorter->intro_sort(array, a_size);
			t2 = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
			return duration;
		default:
			std::cout<<"Error in sort switch!"<<std::endl;
	}	
	return -1;
}

template<typename T>
void Manager<T>::random_array(T* array, int size){
	for(int i=0; i < size; i++){
		array[i] = rand() % 1000;
	}	
}

template<typename T>
void Manager<T>::print_array(T* array, int size){
	for(int i=0; i < size; i++){
		std::cout<<array[i]<<"/";
	}
}

template<typename T>
void Manager<T>::set_algorithm(int alg){
	s_algorithm = alg;
}

template<typename T>
int Manager<T>::get_eobs(int size, float percentage){
	float float_index = (float)size * (percentage/100.0);
	return std::round(float_index);
}

template<typename T>
void Manager<T>::reverse_array(T* array, int size){
	int i = 0;
	int j = size-1;
	while(i <= j){	
		sorter->swap(&array[i], &array[j]);
		i++;
		j--;
	}
}

template class Manager<int>;
