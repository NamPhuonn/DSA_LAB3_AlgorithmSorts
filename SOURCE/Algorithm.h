#pragma once
#include "Header.h"
#include "DataGenerator.h"

void swap(int* a, int* b);
void selectionSort(int *arr, int n, unsigned long long& comp);
void insertionSort(int *arr, int n,unsigned long long &count_compare);
void bubbleSort(int* arr, int l, int r , unsigned long long& comp);
void shakerSort(int *a, int n, unsigned long long &count_compare);
int shellSort(int* arr, int n, unsigned long long& comp);
void heapify(int *arr, int N, int i,unsigned long long &count_compare);
void heapSort(int *arr, int N,unsigned long long &count_compare);
void Merge(int* a, int l, int r, unsigned long long& comp);
void mergeSort(int* a, int l, int r, unsigned long long& comp);
void quickSort(int *a, int l, int r,unsigned long long& comparison);
void countingSort(int* input, int n, unsigned long long& comp);
int getMax(int *arr, int n, unsigned long long &comparision);
void countSort(int *arr, int n, int exp, unsigned long long &comparision);
void radixSort(int *arr, int n, unsigned long long &comparision);
void flashSort(int *a, int n,unsigned long long &comparision) ;

