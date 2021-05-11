import sys
from cs50 import get_string


def final_output(fs):
    if fs < 1:
        print("Before Grade 1")
    elif fs >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {fs}")


if __name__=='__main__':
    text = get_string("Text: ")
    words = text.split(" ")
    number_of_words = len(words)
    text2 = text.replace("?", ".")
    text3 = text2.replace("!", ".")
    sentences = text3.split(".")
    number_of_sentences = len(sentences)
    number_of_letters = 0
    for txt in words:
        number_of_letters+=len(txt)
    var1 = number_of_letters / number_of_words
    var2 = number_of_sentences / number_of_words
    score = 5.88 * var1  - 29.6 * var2 - 15.8
    final_score = round(score)
    final_output(final_score)

