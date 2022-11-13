#include "Algorithm.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
///////////////////////SELECTION SORT ////////////////////////////
void selectionSort(int *arr, int n, unsigned long long& comp)
{
    int i, j, min_idx;
    comp = 0;
    comp++;
    for (i = 0; i < n - 1; i++)
    {
        comp++;
        min_idx = i;
        comp++;
        //Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        for (j = i + 1; j < n; j++)
        {
            comp++;
            comp++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        
        //Hoán đổi phần tử nhỏ nhất tìm được với phần tử đầu tiên
        comp++;
        if (min_idx != i)
            HoanVi(arr[min_idx], arr[i]);
    }
}
///////////////////////INSERTION SORT ////////////////////////////
void insertionSort(int *arr, int n,unsigned long long &count_compare)
{
    int i = 1, key, j;
    count_compare = 0;
    while (++count_compare && i < n)
    {
        key = arr[i];
        j = i - 1;
        
        //Di chuyển giá trị lớn hơn key tới đúng vị trí của nó
        while (++count_compare && j >= 0 && arr[j] > key && ++count_compare)
        {
            
            arr[j + 1] = arr[j];
       
            j = j - 1;
        }
        arr[j + 1] = key;
        i++;
    }
}

///////////////////////BUBBLE SORT ////////////////////////////
void bubbleSort(int* arr, int l, int r , unsigned long long& comp) {
    comp = 0;
	for (int i = l;++comp && i < r; i++) {
        //Đưa phần tử i về đúng vị trí
		for (int j = i + 1;++comp && j < r; j++) {
			if (++comp && arr[i] > arr[j]) {
				HoanVi(arr[i], arr[j]);
				
			}
		}
	}
}
///////////////////////SHAKER SORT ////////////////////////////
void shakerSort(int *a, int n, unsigned long long &count_compare) {
    int L = 0, R = n - 1;
    count_compare = 0;
    while ( ++count_compare && L < R) {
        //Duyệt mảng từ trái qua phải để đưa phần tử nhỏ nhất về đúng vị trí
        for (int i = L; ++count_compare && i < R; ++i)
            if (++count_compare && a[i] > a[i + 1])
                HoanVi(a[i], a[i + 1]);
        --R;
        //Duyêt mảng từ phải qua trái để đưa phần tử lớn nhất về đúng vị trí
        for (int i = R - 1; ++count_compare && i >= L; --i)
            if (++count_compare && a[i] > a[i + 1])
                HoanVi(a[i], a[i + 1]);
        ++L;
    }
}
///////////////////////SHELL SORT ////////////////////////////
int shellSort(int* arr, int n, unsigned long long& comp)
{
    comp = 0;
    comp++;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        comp++;

        comp++;
        for (int i = gap; i < n; i += 1)
        {
            comp++;
            int temp = arr[i];

            int j;
            comp++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                comp++;
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
    return 0;
}
///////////////////////HEAP SORT ////////////////////////////
// Hàm tạo ra Binary Heap (max-heap)
void heapify(int *arr, int N, int i,unsigned long long &count_compare)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    //Nếu left child lớn hơn root
    if (++count_compare && left < N ) {
        if (++count_compare && arr[left] > arr[largest])
            largest = left;
    }
 
    //Nếu right child lớn hơn larges
    if (++count_compare && right < N ) {
        if (++count_compare && arr[right] > arr[largest])
            largest = right;
    }
 
    // Nếu largest không phải root
    if (++count_compare && largest != i) {
        HoanVi(arr[i],arr[largest]);
        heapify(arr, N, largest,count_compare);
    }
}
 
//Heap sort
void heapSort(int *arr, int N,unsigned long long &count_compare)
{
    //Xây dựng max-heap
    count_compare = 0;
    int i = N / 2 - 1;
    while (++count_compare && i >= 0){
        heapify(arr, N, i,count_compare);
        i--;
    }
 
    // Heap sort
    i = N - 1;
    while (++count_compare && i >=0)
    {
        HoanVi(arr[0], arr[i]);
        heapify(arr, i, 0,count_compare);
        i--;
    }
}
///////////////////////MERGE SORT ////////////////////////////
void Merge(int* a, int l, int r, unsigned long long& comp) {
	int mid = (l + r) / 2;
	int lsize = mid - l + 1;
	int rsize = r - mid;

	int* al = new int[lsize];
	int* ar = new int[rsize];
	for (int i = 0;++comp && i < lsize; i++) {
		al[i] = a[l + i];
	}
	for (int i = 0;++comp && i < rsize; i++) {
		ar[i] = a[mid + 1 + i];
	}
	int l_cur = 0;
	int r_cur = 0;
	int main_cur = l;

    //Merge 2 mảng thành 1
	while (++comp && l_cur < lsize && r_cur < rsize && ++comp ) {
		if (++comp && al[l_cur] < ar[r_cur]) {
			a[main_cur] = al[l_cur];
			l_cur++;
		}
		else {
			a[main_cur] = ar[r_cur];
			r_cur++;
		}
		main_cur++;
	}
    //Lưu mảng trái vào nếu còn giá trị
	while (++comp && l_cur < lsize) {
		a[main_cur] = al[l_cur];
		main_cur++;
		l_cur++;
		comp ++;
	}

    //Lưu mảng phải vào nếu còn giá trị
	while (++comp && r_cur < rsize) {
		a[main_cur] = ar[r_cur];
		main_cur++;
		r_cur++;
		comp ++;
	}
}

void mergeSort(int* a, int l, int r, unsigned long long& comp) {
	if (l >= r) return;
	comp++;
	int m = (l + r) / 2;
	mergeSort(a, l, m, comp);
	mergeSort(a, m + 1, r,comp);
	Merge(a, l, r, comp);
}
///////////////////////QUICK SORT ////////////////////////////
void quickSort(int *a, int l, int r,unsigned long long& comparison)
{
	//Nếu phần tử đầu bé hơn phần tử cuối
	if (++comparison && l <= r)
	{
		// Tạo pivot ở giữa
		int key = a[(l + r) / 2];
		int i = l;
		int j = r;

		while (++comparison && i <= j)
		{
			while (++comparison && a[i] < key)
				i++;
			while (++comparison && a[j] > key)
				j--;

			if (++comparison && i <= j)
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}

		//Đệ quy để chia 2 mảng dựa theo pivot
		if (++comparison && l < j)
			quickSort(a, l, j, comparison);
		if (++comparison && r > i)
			quickSort(a, i, r, comparison);
	}
}
///////////////////////COUNTING SORT ////////////////////////////
void countingSort(int* input, int n, unsigned long long& comp)
{
    comp = 0;
	int* output = new int[n];
	int max = input[0]; 
	int min = input[0];

	for (int i = 1;++comp && i < n; i++)
	{
		
		if (++comp && input[i] > max) {
			max = input[i]; //Giá trị lớn nhất trong mảng
		}
		else if (++comp && input[i] < min){
			min = input[i]; //Giá trị nhỏ nhất trong mảng
		}
	}

	int k = max - min + 1; //Kích thước của mảng

	int* count_array = new int[k]; //Tạo mảng để lưu giá trị input
	fill_n(count_array, k, 0); // Khởi tạo mảng với giá trị 0

	for (int i = 0;++comp && i < n; i++) {
		count_array[input[i] - min]++; 
	}
	
    //Thay đổi mảng count_array để chứa các phần tử đứng đúng vị trí
	for (int i = 1;++comp && i < k; i++) {
		count_array[i] += count_array[i - 1];
	}

	
	for (int i = 0;++comp && i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}


	for (int i = 0;++comp && i < n; i++) {
		input[i] = output[i];
	}
}
///////////////////////RADIX SORT ////////////////////////////
// Hàm lấy giá trị lớn nhất
int getMax(int *arr, int n, unsigned long long &comparision)
{
	int mx = arr[0];
	for (int i = 1; ++comparision && i < n;  i++) {
		if (++comparision && arr[i] > mx) {
			mx = arr[i];
		}	
	}
	return mx;
}

// Hàm sắp xếp các phần tử theo digit
void countSort(int *arr, int n, int exp, unsigned long long &comparision)
{
	int *output = new int [n]; 
	
	int i, count[10] = { 0 };

	for (i = 0; ++comparision && i < n; i++)
		count[(arr[i] / exp) % 10]++;

    //Đưa count[i] về đúng vị trí
	for (i = 1; ++comparision && i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; ++comparision && i >= 0; i--) {
		*(output + count[(arr[i] / exp) % 10] - 1) = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
    //Copy mảng output vào arr[] để arr[] chứa các phần tử đã sắp xếp theo digit
	for (i = 0; ++comparision && i < n; i++)
		arr[i] = output[i];
}

// Radix Sort
void radixSort(int *arr, int n, unsigned long long &comparision)
{
	int m = getMax(arr, n,comparision);

	for (int exp = 1; ++comparision && m / exp > 0; exp *= 10)
		countSort(arr, n, exp,comparision);
}
///////////////////////FLASH SORT ////////////////////////////
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
int __L[300000];
void flashSort(int *a, int n,unsigned long long &comparision) 
{
	if (++comparision && n <= 1) return;
	int m = n * 0.43;
	if (m <= 2) m = 2;
	// int m = n;
	for (int i = 0; ++comparision && i < m; ++i)
		__L[i] = 0;
	int Mx = a[0], Mn = a[0];
	for (int i = 1; ++comparision && i < n; ++i) {
		if (++comparision && Mx < a[i]) Mx = a[i];
		if (++comparision && Mn > a[i]) Mn = a[i];
	}
	if (++comparision && Mx == Mn)
		return;
	for (int i = 0; ++comparision && i < n; ++i)
		++__L[getK(a[i])];
	for (int i = 1; ++comparision && i < m; ++i)
		__L[i] += __L[i - 1];
	//step 2
	int count = 0;
	int i = 0;
	while (++comparision && count < n) {
		int k = getK(a[i]);
		while (++comparision && i >= __L[k])
			k = getK(a[++i]);
		int z = a[i];
		while (++comparision && i != __L[k]) {
			k = getK(z);
			int y = a[__L[k] - 1];
			a[--__L[k]] = z;
			z = y;
			++count;
		}
	}
	//step 3
	for (int k = 1; ++comparision && k < m; ++k) {
		for (int i = __L[k] - 2; ++comparision && i >= __L[k - 1]; --i)
			if (++comparision && a[i] > a[i + 1]) {
				int t = a[i], j = i;
				while (++comparision && t > a[j + 1]) {
					a[j] = a[j + 1]; ++j; 
				}
				a[j] = t;
			}
	}
}

