import os
import csv
import random
from cfg import q2_cfg

seed = q2_cfg['seed']
random.seed(seed)

def gen(M):
    english_voc = []
    file_known = open(q2_cfg['7000_voc_csv'], 'r', encoding=q2_cfg['encoding'])
    csvreader = csv.reader(file_known)
    for row in csvreader:
        english_voc.append(row[0].lower())
    
    file_known.close()

    with open(q2_cfg['unknown_txt'], 'r', encoding=q2_cfg['encoding']) as f:
        for line in f.readlines():
            english_voc.append(line.strip())

    word_num = len(english_voc)
    selects = random.sample(range(1, word_num), M)
    for select in selects:
        K = random.randint(0, len(english_voc[select]) - 1)
        Kset = random.sample(range(len(english_voc[select])), K)

        if Kset:
            new_word = english_voc[select]
            for k in Kset:
                num = random.randint(0, 9)
                new_word = new_word[:k] + str(num) + new_word[k+1:]

            english_voc.append(new_word)

    word_num = len(english_voc)
    selects = random.sample(range(1, word_num), M)

    test_cases = []
    for select in selects:
        K = random.randint(0, len(english_voc[select]))
        Kset = random.sample(range(len(english_voc[select])), K)

        if Kset:
            new_word = english_voc[select]
            for k in Kset:
                new_word = new_word[:k] + new_word[k].upper() + new_word[k+1:]

            test_cases.append(new_word)
        else:
            test_cases.append(english_voc[select])

    return test_cases

def sol(in_path, out_path):
    file = open(q2_cfg['7000_voc_csv'], 'r', encoding=q2_cfg['encoding'])
    csvreader = csv.reader(file)

    english_voc = []
    meanings = []
    for row in csvreader:
        english_voc.append(row[0].lower())
        
        split_pos = row[1].rfind('.') + 1
        part, chinese_voc = row[1][:split_pos], row[1][split_pos:]

        meanings.append([part, chinese_voc])
    
    file.close()

    with open(in_path, 'r') as f:
        words = []
        for line in f.readlines():
            try:
                M = int(line)
            except:
                words.append(line.strip().lower())
        
    with open(out_path, 'w', encoding=q2_cfg['encoding']) as f:
        for word in words:
            try:
                index = english_voc.index(word)
                f.writelines(f'{meanings[index][0]} {meanings[index][1]}\n')
            except:
                f.writelines('Unknown\n')


N = q2_cfg['N']
save_path = q2_cfg['save_path']
os.makedirs(save_path, exist_ok=True)

for i in range(N):
    with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
        M_lower = q2_cfg['M_lower']
        M_upper = q2_cfg['M_upper']
        M = random.randint(M_lower, M_upper)
        cases = gen(M)

        f.writelines(f'{M}\n')
        for case in cases:
            f.writelines(f'{case}\n')

    sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))