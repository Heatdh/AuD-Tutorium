#include <iostream>

int iterative(int *a, int start_index, int end_index, int element)
{
   while (start_index <= end_index)
   {
      int middle = start_index + (end_index - start_index) / 2;
      if (a[middle] == element)
         return middle;
      if (a[middle] < element)
         start_index = middle + 1;
      else
         end_index = middle - 1;
   }
   return -1;
}
int recursive(int *a, int start_index, int end_index, int element)
{
   if (end_index >= start_index)
   {
      int middle = start_index + (end_index - start_index) / 2;
      if (a[middle] == element)
         return middle;
      if (a[middle] > element)
         return recursive(a, start_index, middle - 1, element);
      return recursive(a, middle + 1, end_index, element);
   }
   return -1;
}

int main()
{
   int a[] = {1, 5, 10, 15, 20, 25, 30};
   int n = 7;
   int x_search = 10;
   int get_index_it = iterative(a, 0, n - 1, x_search);
   int get_index_rec = iterative(a, 0, n - 1, x_search);

   if (get_index_it == -1)
   {
      std::cout << "iteratively, Element not found ";
   }
   else
   {
      std::cout << "iteratively,Element found at index : " << get_index_it << "\n";
      std::cout << "rec,Element found at index : " << get_index_rec;
   }
   return 0;
}