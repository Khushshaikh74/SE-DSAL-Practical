#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j); 

int optCost(int freq[], int i, int j) {
    if (j < i) 
        return 0; 
    if (j == i)
        return freq[i]; 
    int fsum = sum(freq, i, j); 
    int min = INT_MAX; 
    for (int r = i; r <= j; ++r) { 
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j); 
        if (cost < min) 
            min = cost; 
    } 
    return min + fsum; 
} 

int optimalSearchTree(int eess[], int freq[], int n) {
    return optCost(freq, 0, n - 1); 
} 

int sum(int freq[], int i, int j) {
    int s = 0; 
    for (int e = i; e <= j; e++) 
        s += freq[e]; 
    return s; 
} 

int main() {
    cout<<"\n*DSAL Practical No : (D-10)*"<<endl;
    int eess[] = {10, 12, 20}; 
    int freq[] = {34, 0, 50}; 
    int n = sizeof(eess) / sizeof(eess[0]); 
    cout << "\nCost of Optimal BST is " << optimalSearchTree(eess, freq, n); 
    cout << endl; 
    cout << "\n*THANK YOU*";
    return 0; 
}