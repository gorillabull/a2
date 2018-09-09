// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

/*
Name: Leonardo Vasilev 2000213591 Assignment #2
Descriptions: An implementation of quicksort and bubblesort.
Input: A file containing a number, one per line
*/
#include <iostream> 
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
 
#include <math.h>



using namespace std;


void bbs(int*, int);
void qsort(int*, int, int, int&);
int partition(int*, int, int, int&);
void insertionSort(int*, int);
int abs(int);


#define abss(a) (a < 0 ? a = sqrt(a*a) : a=a );

/*
function_identifier: Function to get the absolute value of a number
paramaters:  an signed integer
return value: the absolute value of the signed int
*/
int abs(int in) {
	if (in<0)
	{
		return sqrt(in*in);
	}
	else
	{
		return in;
	}
	return 0;
}


/*
Function_identifier: Main entry point for program
paramaters: void
return value: 0 if everything went well
*/
int main() {

	int arr[1000];
	int arr2[1000];

	int iter = 0;
	int qsort_cmps = 0;


	string line;

	while (std::getline(std::cin, line)) {
		stringstream abc(line);

		abc >> arr[iter];
		iter++;
		if (iter > 500)break;
	}
	iter--;

	//make a copy of the array so we can sort it with a different algo
	for (int i = 0; i < iter; i++) {
		arr2[i] = arr[i];

	}
	bbs(arr, iter);
	qsort(arr2, 0, iter, qsort_cmps);


	for (int i = 0; i < iter; i++) {
		cout << arr2[i] << endl;
	}

	std::cout << "Qsort # of Comparisons " << qsort_cmps << endl;


	return 1;

}
/*
function_identifier:
paramaters:
return value:
*/
void bbs(int arr[], int len) {
	int cmps = 0;

	int s = 0;
	int tmp = 0;

	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			cmps++;
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	std::cout << "BubbleSort Comparisons " << cmps << std::endl;
}


/*
function_identifier: bla bla bla
paramaters:
return value:
*/
void qsort(int arr[], int l, int h, int & cmps) {
	int pivot = 0;
	int * insertion_arr;

	if (l < h) {

		if (abs(l - h) <= 4) {
			insertion_arr = new int[1234];
			for (int i = l; i <= h; i++)
			{
				insertion_arr[i] = arr[i];
			}
			insertionSort(insertion_arr, abs(l - h)); 
													  
			for (int i = l; i <= h; i++)
			{
				arr[i] = insertion_arr[i];
			}
			delete insertion_arr;
		}
		else {

			pivot = partition(arr, l, h, cmps);
			qsort(arr, l, pivot - 1, cmps);
			qsort(arr, pivot + 1, h, cmps);
		}
		//recursively call on l to pi-1 AND
		//pi+1, high (elements before and after pivot 

	}

}


/*
function_identifier:
paramaters:
return value:
*/
int partition(int arr[], int l, int h, int& cmps) {
	int pivot = arr[h];
	int i = (l - 1);
	int tmp = 0;

	for (int j = l; j <= h - 1; j++) {
		cmps++;
		if (arr[j] <= pivot) {
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	tmp = arr[i + 1];
	arr[i + 1] = arr[h];
	arr[h] = tmp;
	return i + 1;

}





/*
function_identifier:
paramaters:
return value:
*/
void insertionSort(int arr[], int n)
{
	int a, b, c;
	for (a = 1; a < n; a++)
	{
		b = arr[a];
		c = a - 1;

		while (arr[c] > b  && c >= 0)
		{
			arr[c + 1] = arr[c];
			c = c - 1;
		}
		arr[c + 1] = b;
	}
}
