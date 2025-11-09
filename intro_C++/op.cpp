#include <iostream>
using namespace std;
int main() {
   char op;
   int n1, n2;
   cout << "opération souhaitée (+ ou *) ? ";
   cin >> op;
   cout << "donnez 2 nombres entiers : ";
   cin >> n1 >> n2;
   if (op == '+')
      cout << "leur somme est : " << n1 + n2 << "\n";
   else
      cout << "leur produit est : " << n1 * n2 << "\n";
}