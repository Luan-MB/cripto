from curses.ascii import isalpha, islower

MIN_UPPER = 65
MAX_UPPER = 91
MIN_LOWER = 97
MAX_LOWER = 122

string = input()

def encode(string, previous_word):

    base = len(string) + previous_word
    r_word = ""

    for char in string:
        if (isalpha(char)):
            if (islower(char)):
                char_value = ord(char)
                r_word += chr(MIN_LOWER + ((char_value + base - MIN_LOWER) % 26))
            else:
                char_value = ord(char)
                r_word += chr(MIN_UPPER + ((char_value + base - MIN_UPPER) % 26))
        else:
            r_word += char

    return r_word

def decode(string, previous_word):

    base = len(string) + previous_word
    r_word = ""

    for char in string:
        if (isalpha(char)):
            if (islower(char)):
                char_value = ord(char)
                r_word += chr(MIN_LOWER + ((char_value - base - MIN_LOWER) % 26))
            else:
                char_value = ord(char)
                r_word += chr(MIN_UPPER + ((char_value - base - MIN_UPPER) % 26))
        else:
            r_word += char

    return r_word

s_string = string.split()

r_string = ""
prev_word = ""

for word in s_string:
    r_string += decode(word, len(prev_word)) + " "
    prev_word = word

print(r_string)