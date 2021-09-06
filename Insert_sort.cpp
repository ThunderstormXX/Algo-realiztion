#include <iostream>
#include <vector>
using namespace std ;



vector<int> insert_sort( vector<int>& mass  ) {
  int x, i ;
  for( int j = 1 ; j < mass.size() ; ++j) {
    x = mass[j];
    i = j - 1 ;
    while ( i > -1 && mass[i] > x) {
      mass[i+1] = mass[i];
      --i;
    }
    mass[i+1] = x;
  }
  return mass;
}

int main() {
  int n ;
  int x ;
  vector<int> mass ;
  cin >> n ;
  for(int i = 0 ; i < n ; i ++ ) {
    cin >> x ;
    mass.push_back(x);
  }
  
  mass = insert_sort(mass );
  cout << '\n';
  for(int i = 0 ; i < n ; i ++ ) {
    cout << mass[i] << ' ';
  }
}