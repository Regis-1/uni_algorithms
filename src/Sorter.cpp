#include "../include/Sorter.hh"

template<typename T>
T Sorter<T>::partition(T* array, int i_low, int i_high){
	int pivot = array[i_high];
	int i = (i_low - 1);

	for(int j = i_low; j <= i_high - 1; j++){
		if(array[j] < pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1], &array[i_high]);
	return (i+1);
}

template<typename T>
void Sorter<T>::swap(T* a, T* b){
	T t = *a;
	*a = *b;
	*b = t;
}

template<typename T>
void Sorter<T>::merge(T* array, int i_low, int i_m, int i_high){
	int i, j, k; 
	int n1 = i_m - i_low + 1; 
	int n2 =  i_high - i_m; 
	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = array[i_low + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = array[i_m + 1+ j]; 

	i = 0;
	j = 0;
	k = i_low;
	while (i < n1 && j < n2){ 
		if (L[i] <= R[j]){ 
			array[k] = L[i]; 
			i++; 
		} 
		else{ 
			array[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1){ 
		array[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2){ 
		array[k] = R[j]; 
		j++; 
		k++; 
	} 
}

template<typename T>
void Sorter<T>::merge_sort(T* array, int i_low, int i_high){
	if(i_low < i_high){
		int i_m = (i_low + i_high)/2;
		merge_sort(array, i_low, i_m);
		merge_sort(array, i_m+1, i_high);

		merge(array, i_low, i_m, i_high);
	}
}

template<typename T>
void Sorter<T>::quick_sort(T* array, int i_low, int i_high){
	if(i_low < i_high){
		int p_i = partition(array, i_low, i_high);

		quick_sort(array, i_low, p_i - 1);
		quick_sort(array, p_i + 1, i_high);
	}
}

template<typename T>
void Sorter<T>::intro_sort(T* array){

}

template class Sorter<int>;
