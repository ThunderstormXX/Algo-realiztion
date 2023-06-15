#include <iostream>
#include <vector>
using namespace std ;

void swp( vector<int>& mass , int i , int j) {
  int x = mass[i];
  mass[i] = mass[j];
  mass[j] = x ;
}

int Partition ( vector<int>& mass , int p , int r ) {
  int x  = mass[r];
  int i = p - 1 ;
  for ( int j = p ; j < r ; ++ j) {
    if( mass[j] <= x) {
      ++i;
      swp(mass,i,j);
    }
  }
  swp(mass,i+1,r);
  return i + 1 ;
}

void quicksort( vector<int>& mass , int p , int r) {
  if(p < r) {
    int q = Partition(mass,p,r);
    quicksort(mass,p,q-1);
    quicksort(mass,q+1, r);
  }
}

int main() {
  int n ;
  int x ;
  vector<int> mass ;
  cin >> n ;
  mass.push_back(0);
  for(int i = 0 ; i < n ; i ++ ) {
    cin >> x ;
    mass.push_back(x);
  }
  quicksort(mass,1,n);


  cout << '\n';
  for(int i = 1 ; i <= n ; i ++ ) {
    cout << mass[i] << ' ';
  }
}