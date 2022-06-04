import os
import random
from cfg import *

seed = q4_cfg['seed']
random.seed(seed)

def gen():
    round_lower = q4_cfg['round_lower']
    round_upper = q4_cfg['round_upper']
    rounds = random.randint(round_lower, round_upper)

    records = []
    bottle_lower = q4_cfg['bottle_lower']
    bottle_upper = q4_cfg['bottle_upper']
    for round in range(1, rounds + 1):
        knock_1 = random.randint(bottle_lower, bottle_upper)

        if round < 10:
            if knock_1 < 10:
                knock_2 = random.randint(bottle_lower, bottle_upper - knock_1)

                if knock_1 + knock_2 == 10:
                    knock_2 = '/'
            else:
                knock_1 = 'x'
                knock_2 = '-'
            
            records.append(f'{knock_1} {knock_2}')
        else:
            if knock_1 == 10:
                knock_1 = 'x'
                knock_2 = random.randint(bottle_lower, bottle_upper)

                if knock_2 == 10:
                    knock_2 = 'x'
                    knock_3 = random.randint(bottle_lower, bottle_upper)

                    if knock_3 == 10:
                        knock_3 = 'x'
                else:
                    knock_3 = random.randint(bottle_lower, bottle_upper - knock_2)

                    if knock_2 + knock_3 == 10:
                        knock_3 = '/'
            else:
                knock_2 = random.randint(bottle_lower, bottle_upper - knock_1)
                
                if knock_1 + knock_2 == 10:
                    knock_2 = '/'
                    knock_3 = random.randint(bottle_lower, bottle_upper)

                    if knock_3 == 10:
                        knock_3 = 'x'
                else:
                    knock_3 = '-'
                
                records.append(f'{knock_1} {knock_2} {knock_3}')
    
    testcase = ''
    for record in records:
        testcase += record + ' '
    
    return testcase

def convert(records ,index):
    if records[index] == 'x':
        score = 10
    elif records[index] == '/':
        score = 10 - int(records[index-1])
    else:
        score = int(records[index])
    
    return score

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        records = f.readlines()[0].split()
        
        remove_item = '-'
        while records.count(remove_item):
            records.remove(remove_item)

        total = 0
        count_spare = 0
        count_strike = 0
        for i in range(len(records)):
            if records[i] == 'x':
                count_strike += 1
                total += 10

                if i < len(records) - 3:
                    total += convert(records, i+1)
                
                if i < len(records) - 3:
                    total += convert(records, i+2)
            elif records[i] == '/':
                count_spare += 1
                total += convert(records, i)

                if i < len(records) - 2:
                    total += convert(records, i+1)
            else:
                total += convert(records, i)
        
        reward = q4_cfg['reward']
        reward = round(reward * 1.1**count_spare * 1.2**count_strike)

        with open(out_path, 'w') as f:
            f.writelines(f'{total}\n')
            f.writelines(f'{reward}\n')


N = q4_cfg['N']
save_path = q4_cfg['save_path']
os.makedirs(save_path, exist_ok=True)

for i in range(N):
    with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
        cases = gen()
        f.writelines(cases + '\n')
    
    sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))