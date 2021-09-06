#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std ;

int random(int a,int b)
{
    srand(time(NULL));
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);
}

void swp( vector<int>& mass , int i , int j) {
  int x = mass[i];
  mass[i] = mass[j];
  mass[j] = x ;
}

void Counting_sort( vector<int>& A , vector<int>& B , int k) {
  vector<int> C(k+1);
  for(int i = 0 ; i < k + 1 ; ++i) {
    C[i] = 0 ;
  }
  for( int i = 1 ; i < A.size() ; ++i ) {
    C[A[i]] = C[A[i]] + 1;
  }
  for(int i = 1 ; i < k + 1 ; ++i) {
    C[i] =C[i] + C[i-1];
  }
  for(int j = A.size()-1; j > 0 ; --j) {
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
}








int main() {
  int n ;
  int x ;
  int max = 10;
  vector<int> A ;
  vector<int> B ;
  cin >> n ;
  A.push_back(0);
  for(int i = 0 ; i < n ; i ++ ) {
    cin >> x ;
    A.push_back(x);
  }
  B.resize(n+1);
  Counting_sort(A,B,max); //  С учетом,что все элементы в пос-ти меньше max


  cout << '\n';
  for(int i = 1 ; i <= n ; i ++ ) {
    cout << B[i] << ' ';
  }
}