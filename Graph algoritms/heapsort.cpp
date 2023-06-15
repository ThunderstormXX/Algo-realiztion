#include <iostream>
#include <vector>
using namespace std ;



int Parent ( int i) {
  return(i/2);
}
int Left ( int i ) {
  return 2*i ;
}
int Right( int i ) {
  return 2*i + 1;
}
struct A{
  vector<int> mass ;
  int heap_size = 0;
};

void Max_Heapify ( A& A , int i) {
  int l = Left(i);
  int r = Right(i);
  int largest;
  if( l <= A.heap_size && A.mass[l] > A.mass[i])
    largest = l;
  else
    largest = i ;
  if( r <= A.heap_size && A.mass[r] > A.mass[largest])
    largest = r;
  if( largest != i) {
    int x = A.mass[i];
    A.mass[i] = A.mass[largest];
    A.mass[largest] = x;
    Max_Heapify( A , largest);
  } 
}

void Build_max_heap ( A& A ) {
  A.heap_size = A.mass.size() - 1;
  for(int i = A.heap_size ; i > 0 ; --i) {
    Max_Heapify( A , i);
  }
}

void Heap_sort ( A& A ) {
  Build_max_heap( A );
  for( int i = A.mass.size() - 1; i > 1 ; --i) {
    int x = A.mass[1];
    A.mass[1] = A.mass[i];
    A.mass[i] = x;
    A.heap_size = A.heap_size - 1;
    Max_Heapify( A , 1);
  }
}

int main() {
  int n ;
  int x ;
  A A ;
  cin >> n ;
  A.mass.push_back(0);
  for(int i = 0 ; i < n ; i ++ ) {
    cin >> x ;
    A.mass.push_back(x);
  }
  //mass = pyramid_sort(mass );
  //Max_Heapify(mass,2);
  //Build_max_heap( mass);
  Heap_sort(A);

  cout << '\n';
  for(int i = 1 ; i <= n ; i ++ ) {
    cout << A.mass[i] << ' ';
  }
}