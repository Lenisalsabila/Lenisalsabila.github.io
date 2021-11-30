 #include<iostream>

class heap
{
private:
  int * hp;
public:
  int heap_size;
  int parent(int i)
  {
    return (i/2);
  }
  int left(int i)
  {
    return 2*i;
  }
  int right(int i)
  {
    return (2*i+1);
  }
  void max_heapify( int i);
  void build_max_heap();
  void heap_sort();
  heap(int * a, size_t size)
  {
    heap_size = size;
    hp = a;
  }
};


void heap::max_heapify(int i)
{
  int l = left(i);
  int r = right(i);
  int largest=i;
  /* Finding the largest among nodes and two children */
  if (l <= heap_size && hp[l]>hp[i])
    largest = l;
  else
    largest = i;
  if(r<= heap_size && hp[r]>hp[largest])
    largest = r;
  if(largest != i)
    {
      int temp = hp[i];
      hp[i] = hp[largest];
      hp[largest] = temp;
      max_heapify(largest);
    } 
}

void heap::build_max_heap()
{
  for(int i = heap_size/2; i>=1; i--)
    {
      max_heapify(i);
    }
}

void heap::heap_sort()
{
  build_max_heap();
  for(int i = heap_size; i>1; i--)
    {
      int temp = hp[1];
      hp[1]=hp[i];
      hp[i] = temp;
      heap_size--;
      max_heapify(1);
    }
}



int main()
{
  int arr[] = {1,2,3,1,5};
  heap xh(arr, 4);
  xh.heap_sort();
  std::cout<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4];
  return 0;
}
