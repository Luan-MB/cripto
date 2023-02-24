// C++ program to illustrate Rail Fence Cipher
// Encryption and Decryption
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;
 
// function to encrypt a message
string encryptRailFence(string text, int key)
{
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][(text.length())];
 
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = ' ';
 
    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i=0; i < text.length(); i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
        // fill the corresponding alphabet
        rail[row][col++] = text[i];
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }
 
    //now we can construct the cipher using the rail matrix
    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!=' ')
                result.push_back(rail[i][j]);
 
    return result;
}
 
// This function receives cipher-text and key
// and returns the original text after decryption
string decryptRailFence(string cipher, int key)
{
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][cipher.length()];
 
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = ' ';
 
    // to find the direction
    bool dir_down;
 
    int row = 0, col = 0;
 
    // mark the places with '*'
    for (int i=0; i < cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
 
        // place the marker
        rail[row][col++] = '*';
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }
 
    // now we can construct the fill the rail matrix
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];
 
 
    // now read the matrix in zig-zag manner to construct
    // the resultant text
    string result;
 
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
 
        // place the marker
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
 
        // find the next row using direction flag
        dir_down?row++: row--;
    }
    return result;
}
 
//driver program to check the above functions
int main()
{
    
    string processed_message;
    string word;

    while (cin >> word) {

            string formatted_word;

            for (char c: word) {
                formatted_word += tolower(c);
            }

            processed_message += formatted_word;
    }

    string sub_string;
    unsigned int n = processed_message.length() / 100;
    unsigned int i = 0;

    for ( ; i<n; ++i) {

        sub_string = processed_message.substr(i * 100, 100);

        std::cout << encryptRailFence(sub_string, 3);
    }

    sub_string = processed_message.substr(i * 100, processed_message.length() % 100);

    std::cout << decryptRailFence(sub_string, 3) << endl;
 
    return 0;
}