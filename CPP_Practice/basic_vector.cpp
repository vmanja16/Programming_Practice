#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<vector<int>> main_vec, sub_vec;
    int num_arrays, queries, arr_len;
    int i,j,k,incoming;
    cin >> num_arrays; cin >> queries;
    for (i=0; i< num_arrays; i++){
        vector<int> subvec;
        cin >> arr_len;
        for(j=0; j< arr_len; j++){
            cin >> incoming;
            subvec.push_back(incoming);  
        }
        main_vec.push_back(subvec);
    }
    for (k=0; k< queries; k++){
        cin >> i; cin >> j;
        cout << main_vec[i][j] << endl;
    }
    return 0;
}
