#include <iostream>
using namespace std;


bool is_prime(int n) {
    int d = 2;
    bool primo;
    if (n <= 1) return false;
    else {
        primo = true;
        while (primo && d <= n/2) {
            if (n % d == 0) {
                primo =false;
            }
            d++;
        } return primo;
    }
}


int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if (is_prime(n)) {
        cout<<"Prime"<<endl;
    } else cout<<"\nIsn't prime"<<endl;
    return 0;
}