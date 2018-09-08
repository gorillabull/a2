#include <iostream> 
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>



using namespace std;

 
void bbs(int*, int);
void qsort(int*,int,int, int&);
int partition(int*,int,int, int&);


int main() {
int arr[1000];
int arr2[1000];
 
int iter = 0 ;
int qsort_cmps = 0;

 
string line; 

while(std::getline(std::cin,line)){
stringstream abc(line);

abc>>arr[iter] ;
iter++;
if (iter>500)break;
}

for(int i =0 ; i<iter; i++){
arr2[i] = arr[i] ;

}
bbs(arr,iter);
qsort(arr2,0,16,qsort_cmps);


for(int i =0; i <iter; i++){
cout<<arr[i]<<endl;
}

std::cout<<"Qsort # of Comparisons "<<qsort_cmps<<endl;


return 0; 


}

void bbs(int arr[], int len  ) {
int cmps = 0 ; 

int s = 0;
int tmp = 0 ; 

for (int i = 0; i < len-1; i++){
	for ( int j =0; j< len -i -1; j++){
		cmps++;
		if(arr[j] > arr[j+1]){
			tmp = arr[j]; 
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
		}
}
}
		
std::cout<<"BubbleSort Comparisons "<<cmps<<std::endl; 
} 

void qsort(int arr[] , int l, int h, int & cmps){
int pivot = 0 ; 

if (l<h){

if (abs(l-h)<=4){
insertionSort(arr,abs(l-h)); /*todo 
this about hov this vill vork this is not correct 
*/ 
}
else{

pivot = partition(arr, l, h, cmps );
qsort(arr,l, pivot-1, cmps);
qsort(arr,pivot+1, h,cmps);
}
//recursively call on l to pi-1 AND
//pi+1, high (elements before and after pivot 

}
}

int partition(int arr[] , int l , int h, int& cmps){
int pivot = arr[h]; 
int i = (l -1); 
int tmp = 0 ; 

for (int j = l; j<=h-1; j++){
cmps++;
	if (arr[j] <=pivot ){
		i++; 
		tmp = arr[i]; 
		arr[i] = arr[j];
		arr[j] = tmp;		
	}
}

tmp = arr[i+1];
arr[i+1] = arr[h];
arr[h] = tmp;
return i +1; 

}





/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}




