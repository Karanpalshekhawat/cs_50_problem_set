import csv
import sys
import pandas as pd
import re

def read_csv(filename):
    dna = []
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            dna.append(row)
    return dna


def read_text(filename):
    with open(filename, "r") as file:
        txt = file.read()
    return txt


def check_pattern(name_list, text):
    dna_name_list = list(name_list[0].keys())[1:]
    text_length = len(text)
    counter = {}
    for name in dna_name_list:
        flag = len(name)
        counter[name] = 0
        find_idx = re.finditer(name, text)
        indexes = [[match.start(), match.end()] for match in find_idx]
        end_index = -1
        repeat = 1
        only_one_repeat = False
        for idx in indexes:
            start_index = idx[0]
            if end_index == start_index and not only_one_repeat:
                repeat+=1
            else:
                only_one_repeat = False
                if repeat > 1:
                    break
            end_index = idx[1]
        counter[name] = repeat

    return counter


def check_whose_dna(name_list, count_dict):
    for dc in name_list:
        flag = 0
        for key in dc.keys():
            if key!= 'name':
                if int(dc[key]) == count_dict[key]:
                    flag +=1
                    if flag == len(count_dict):
                        return dc['name']



if __name__=='__main__':
    if len(sys.argv) != 3:
        sys.exit("Usage: Python dna.py databases/csv_file sequences/txt_file")
    name_list = read_csv(sys.argv[1])
    text = read_text(sys.argv[2])
    count_dict = check_pattern(name_list, text)
    person_name = check_whose_dna(name_list, count_dict)
    if person_name == None:
        print("No match")
    else:
        print(person_name)



