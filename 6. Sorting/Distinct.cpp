#include <vector>
#include <set>

int solution(vector<int> &A) {
   set<int> B;
   
   for (int i = 0; i < A.size(); i++) {
       B.insert(A[i]);
   }
   
   return B.size();
}