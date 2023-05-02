#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int l = root*2 + 1; int r = root*2 + 2;
   int largest;
   if (l < n && arr[l] > arr[root]){
      largest = l;
   }
   else {
      largest = root;
   }
   if (r < n && arr[r] > arr[largest]){
      largest = r;
   }
   if (largest != root){
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for (int i = (n-1)/2; i >= 0; i--){
      heapify(arr, n, i);
   }
   
  
   for (int i = n-1; i >= 1; i--){
      int temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
      n -= 1;
      heapify(arr, n, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n;
   cout << "Enter array length :";
   cin >> n;
   int heap_arr[n];
   cout << "Enter elements of array one by one :"<< endl;
   for (int i = 0; i < n; i++){
      cin >> heap_arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}