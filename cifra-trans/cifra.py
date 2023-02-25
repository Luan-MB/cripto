#!/usr/bin/env python3

# Luan Machado Bernardt | GRR20190363
# Lucas Soni Teixeira   | GRR20190395

import sys

def flip_text(text):
    upside_down = str.maketrans('abcdefghijklmnopqrstuvwxyz',
                            '\u0250q\u0254p\u01DD\u025F\u0183\u0265\u0131\u027E\u029El\u026Fuodb\u0279s\u0287n\u028C\u028Dx\u028Ez')
    return text.translate(upside_down)[::-1]

def unflip_text(text):
    upside_up = str.maketrans('\u0250q\u0254p\u01DD\u025F\u0183\u0265\u0131\u027E\u029El\u026Fuodb\u0279s\u0287n\u028C\u028Dx\u028Ez',
                            'abcdefghijklmnopqrstuvwxyz')
    return text.translate(upside_up)[::-1]

def encryptRailFence(text, key):
 
    rail = [[' ' for i in range(len(text))]
                for j in range(key)]
     
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
         
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False
             
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
             
        if dir_down:
            row += 1
        else:
            row -= 1
    return("".join(result))

''' Main '''

decode = False

if len(sys.argv) > 1 and sys.argv[1] == "-d":
    decode = True

text = ""

for line in sys.stdin:
    words = line.split()

    for word in words:
        text += word.lower()

if decode == True:
    text = unflip_text(text)

substr = ""
n = len(text) // 100
index = 0
rail_value = 3
increasing_value = -1

ciphered_text = ""

if decode == True:
    for i in range(n):
        substr = text[i*100: (i*100 + 100)]

        ciphered_text += decryptRailFence(substr, rail_value)

        index += 1
        increasing_value  *= -1
        rail_value += increasing_value
else:
    for i in range(n):
        substr = text[i*100: (i*100 + 100)]

        ciphered_text += encryptRailFence(substr, rail_value)

        index += 1
        increasing_value  *= -1
        rail_value += increasing_value

substr = text[index*100: (index*100 + (len(text) % 100))]

if decode == True:
    ciphered_text += decryptRailFence(substr, rail_value)
else:
    ciphered_text += encryptRailFence(substr, rail_value)

if decode == False:
    ciphered_text = flip_text(ciphered_text)

print(ciphered_text)
