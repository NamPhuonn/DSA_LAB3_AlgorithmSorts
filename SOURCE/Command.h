#pragma once
#include "Header.h"
#include "Algorithm.h"
#include "DataGenerator.h"

bool inputOrder(int *a, int n, char* order);
void outputParameter(double time,unsigned long long comparision, char *parameter);
void output(double time1, double time2 , unsigned long long comparision1, unsigned long long comparision2);
void writeFile(int *a, int n, char nameFile[]);
void algorithmSort(char* algorithm, int *arr, int N,unsigned long long &comparision);
void readFile(int *&a, int &n, char *nameFile);