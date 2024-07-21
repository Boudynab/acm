#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int A=1;A<=N;++A) {
        for (int B=1;B<=(N/A);++B) {
            int C=N-A*B;
            if (C>0) {
                ++count;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
