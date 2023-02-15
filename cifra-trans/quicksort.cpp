// C++ program for insertion sort
 
#include <bits/stdc++.h>
#include <string>
using namespace std;

// Function to sort an array using
// insertion sort

void swapChar(char *a, char *b) {
    char aux = *a;
    *a = *b;
    *b = aux;
}

void insertionSortEncode(string& message, string& chave) {
    int i, key, j;
    char aux;
    for (i = 1; i < message.length(); i++)
    {
        key = message[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && message[j] > key)
        {
            message[j + 1] = message[j];
            swapChar(&chave[j], &chave[j+1]);
            j = j - 1;
        }
        message[j + 1] = key;
    }
}

void insertionSortDecode(string& message, string& chave) {
    int i, key, j;
    char aux;
    for (i = 1; i < chave.length(); i++)
    {
        key = chave[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && chave[j] > key)
        {
            chave[j + 1] = chave[j];
            swapChar(&message[j], &message[j+1]);
            j = j - 1;
        }
        chave[j + 1] = key;
    }
}
 
// Driver code
int main()
{
    unsigned int soma{0};
    string key{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (int i=0; i<key.length(); ++i)
        soma += key[i];
    cout << soma << endl;
    string s{"VASCODAGAMA"};
    insertionSortEncode(s, key);
    cout << s << endl;
    cout << key << endl;
}
// This is code is contributed by rathbhupendra