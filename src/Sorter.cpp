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

//FROM HERE EVERYTHING NEEDED TO INTRO SORT
template<typename T>
void Sorter<T>::make_heap(T* array, int n, int i){
	int largest = i;
	int left = 2*i +1;
	int right = 2*i +2;

	if(left < n && array[left] > array[largest])
		largest = left;
	if(right < n && array[right] > array[largest])
		largest = right;
	if(largest != i){
		swap(&(array[i]), &(array[largest]));
		make_heap(array, n, largest);
	}
}

template<typename T>
void Sorter<T>::sort_heap(T* array, int n){
	for(int i=n/2 -1; i>=0; i--)
		make_heap(array, n, i);

	for(int i=n-1; i>=0; i--){
		swap(&(array[0]), &(array[i]));
		make_heap(array, i, 0);
	}
}

template<typename T>
void Sorter<T>::insertion_sort(T* array, T* begin , T* end){
	int left = begin - array;
	int right = end - array;
	for(int i = left + 1; i <= right; i++){
		int key = array[i];
		int j = i-1;

		while(j >= left && array[j] > key){
			array[j+1] = array[j];
			j=j-1;
		}
		array[j+1] = key;
	}
}

template<typename T>
T* Sorter<T>::median_of_three(T* a, T* b, T* c){
	if(*a < *b && *b < *c)
		return b;
	if(*a < *c && *c <= *b)
		return c;
	if(*b <= *a && *a < *c)
		return a;
	if(*b < *c && *c <= *a)
		return c;
	if(*c <= *a && *a < *b)
		return a;
	if(*c <= *b && *b <= *a)
		return b;
	return a;
}

template<typename T>
void Sorter<T>::intro_sort_run(T* array, T* begin, T* end, int depth_limit){
	int size = end - begin;
	int left = begin - array;
	int right = end - array;

	if(size < 16){
		insertion_sort(array, begin, end);
		return;
	}
	if(depth_limit == 0){
		sort_heap(array, size);
		return;
	}

	T* pivot = median_of_three(begin, begin+size/2, end);
	swap(pivot, end);

	T* p_partition_point = &(array[partition(array,left,right)]);
	intro_sort_run(array, begin, p_partition_point-1, depth_limit-1);
	intro_sort_run(array, p_partition_point+1, end, depth_limit-1);
}
/*-----------------------------------------------------------------------------------*/

template<typename T>
void Sorter<T>::swap(T* a, T* b){
	T t = *a;
	*a = *b;
	*b = t;
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
void Sorter<T>::intro_sort(T* array, int i_low, int i_high){
	T* begin = &(array[i_low]);
	T* end = &(array[i_high]);

	int depth_limit = 2*log(end - begin);
	intro_sort_run(array, begin, end, depth_limit);
}

template class Sorter<int>;
