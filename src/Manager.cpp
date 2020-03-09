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
void Manager<T>::set_algorithm(int alg){
	s_algorithm = alg;
}

template class Manager<int>;
