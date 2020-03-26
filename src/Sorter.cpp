#include "../include/Sorter.hh"

//TWORZENIE PARTYCJI DLA QUICKSORT
template<typename T>
T Sorter<T>::partition(T* array, int i_low, int i_high){
	int i, j;
    if (i_high>=3)
		median_of_three(array,i_low,i_high);
	for (i=i_low, j=i_high-2; ; )
	{
		for ( ; array[i]<array[i_high-1]; ++i);
		for ( ; j>=i_low && array[j]>array[i_high-1]; --j);
		if (i<j)
			swap(&array[i++], &array[j--]);
		else break;
	}
	swap(&array[i], &array[i_high-1]);
	return i;
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
void Sorter<T>::insertion_sort(T* array, int n){
	long i, j;
	T temp;
	for (i=1; i<n; ++i)
	{
		temp=array[i];
		for (j=i; j>0 && temp<array[j-1]; --j)
		array[j]=array[j-1];
		array[j]=temp;
	}
}

template <typename T>
void Sorter<T>::median_of_three(T *array, int &L, int &R)
{
	if (array[++L-1]>array[--R])
		swap(&array[L-1], &array[R]);
	if (array[L-1]>array[R/2])
		swap(&array[L-1], &array[R/2]);  
	if (array[R/2]>array[R])
		swap(&array[R/2], &array[R]);
	swap(&array[R/2], &array[R-1]);
}

template<typename T>
void Sorter<T>::intro_sort_run(T* array, int n, int depth_limit){
	int i;
	if (depth_limit<=0)
	{
		sort_heap(array,n);
		return;
	}
	i=partition(array,0,n);
	if(i>9)
		intro_sort_run(array,i,depth_limit-1);
	if(n-1-i>9)
		intro_sort_run(array+i+1,n-1-i,depth_limit-1);
}

template<typename T>
void Sorter<T>::swap(T* a, T* b){
	T t = *a;
	*a = *b;
	*b = t;
}

//ALGORYTMY SORTOWANIA
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
	if(i_high <= i_low) return;

	int i = i_low - 1, j = i_high + 1, 
	pivot = array[(i_low+i_high)/2];

	while(1){
		while(pivot>array[++i]);
		while(pivot<array[--j]);

		if( i <= j)
			swap(&array[i],&array[j]);
		else
			break;
	}

	if(j > i_low)
		quick_sort(array, i_low, j);
	if(i < i_high)
		quick_sort(array, i, i_high);
}

template<typename T>
void Sorter<T>::intro_sort(T* array, int n){
	intro_sort_run(array, n, (int)floor(2*log(n)/M_LN2));
	insertion_sort(array, n);
}

template class Sorter<int>;
