#!/usr/bin/env python3

import sys

upside_down = str.maketrans('abcdefghijklmnopqrstuvwxyz',
                            '\u0250q\u0254p\u01DD\u025F\u0183\u0265\u0131\u027E\u029E\u05DF\u026Fuodb\u0279s\u0287n\u028C\u028Dx\u028Ez')

upside_up = str.maketrans('\u0250q\u0254p\u01DD\u025F\u0183\u0265\u0131\u027E\u029E\u05DF\u026Fuodb\u0279s\u0287n\u028C\u028Dx\u028Ez',
                            'abcdefghijklmnopqrstuvwxyz')


def flip_text(text):
    return text.translate(upside_down)[::-1]

def unflip_text(text):
    return text.translate(upside_up)[::-1]

text = ""

for line in sys.stdin:
    words = line.split()

    for word in words:
        text += word.lower()

text = unflip_text(text)

def encryptRailFence(text, key):
 
    rail = [[' ' for i in range(len(text))]
                for j in range(key)]
     
    # to find the direction
    dir_down = False
    row, col = 0, 0
     
    for i in range(len(text)):
         
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down
         
        rail[row][col] = text[i]
        col += 1
         
        if dir_down:
            row += 1
        else:
            row -= 1

    result = []
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] != ' ':
                result.append(rail[i][j])
    return("" . join(result))

def decryptRailFence(cipher, key):
 
    rail = [[' ' for i in range(len(cipher))]
                for j in range(key)]
     
    dir_down = None
    row, col = 0, 0
     
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False
         
        rail[row][col] = '*'
        col += 1
         
        if dir_down:
            row += 1
        else:
            row -= 1
             
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if ((rail[i][j] == '*') and
            (index < len(cipher))):
                rail[i][j] = cipher[index]
                index += 1

    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
         
        # check the direction of flow
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False
             
        # place the marker
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
             
        # find the next row using
        # direction flag
        if dir_down:
            row += 1
        else:
            row -= 1
    return("".join(result))

substr = ""
n = len(text) // 100
index = 0

ciphered_text = ""

for i in range(n):
    substr = text[i*100: (i*100 + 100)]
    ciphered_text += decryptRailFence(substr, 3)
    index += 1

substr = text[index*100: (index*100 + (len(text) % 100))]
ciphered_text += decryptRailFence(substr, 3)

print(ciphered_text)
