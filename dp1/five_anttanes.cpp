<<<<<<< ⌬ Tabnine Instruct <<<<<<<
‌#include <bits/stdc++.h>
‌using namespace std;
​/**
​ * @brief This function checks if the distance between any two antennas is within a given limit.
​ *
​ * @param a The position of the first antenna.
​ * @param b The position of the second antenna.
​ * @param c The position of the third antenna.
​ * @param d The position of the fourth antenna.
​ * @param e The position of the fifth antenna.
​ * @param k The maximum allowed distance between any two antennas.
​ *
​ * @return If the distance between any two antennas is greater than k, it returns ":(". Otherwise, it returns "Yay!".
​ */
int main(){
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    vector<int> antennas = {a, b, c, d, e};
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(antennas[j] - antennas[i] > k){
                cout << ":(";
                return 0; 
            }
        }
    }
    cout << "Yay!";
    return 0;
}
>>>>>>> ⌬ Tabnine Instruct >>>>>>>