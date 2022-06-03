import os
import random
from cfg import *

seed = q1_cfg['seed']
random.seed(seed)

def gen(M):
    grade_lower = q1_cfg['grade_lower']
    grade_upper = q1_cfg['grade_upper']
    credit_lower = q1_cfg['credit_lower']
    credit_upper = q1_cfg['credit_upper']

    test_cases = []
    for _ in range(M):
        grade = round(random.uniform(grade_lower, grade_upper), 3)

        if grade < 50:
            grade = 'W'
        elif grade < 60:
            grade = 'F'

        credit = random.randint(credit_lower, credit_upper)

        test_cases.append(f'{grade} {credit}\n')

    return test_cases

def grade_table(grade):
    grade = round(float(grade))
    if grade <= 62:
        grade = 1.7
    elif grade <= 66:
        grade = 2
    elif grade <= 69:
        grade = 2.3
    elif grade <= 72:
        grade = 2.7
    elif grade <= 76:
        grade = 3
    elif grade <= 79:
        grade = 3.3
    elif grade <= 84:
        grade = 3.7
    elif grade <= 89:
        grade = 4
    else:
        grade = 4.3
    
    return grade

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        grades = []
        credits = []
        credits_with_w = []
        for line in f.readlines():
            try:
                M = int(line)
            except:
                grade, credit = line.split()

                credits_with_w.append(int(credit))
                if grade == 'W':
                    M -= 1
                    continue
                elif grade == 'F':
                    grade = 0
                else:
                    grade = grade_table(grade)
                
                credits.append(int(credit))
                grades.append(grade)
    
    gpa = 0
    fail_credit = 0
    for i in range(M):
        gpa += grades[i] * credits[i]

        if grades[i] == 0:
            fail_credit += credits[i]
    
    if sum(credits) != 0:
        gpa = round(gpa / sum(credits), 2)
    else:
        gpa = 0
    
    with open(out_path, 'w') as f:
        f.writelines(f'{gpa}\n')

        if fail_credit > (sum(credits_with_w) / 2):
            f.writelines('flunk out\n')

N = q1_cfg['N']
save_path = q1_cfg['save_path']
os.makedirs(save_path, exist_ok=True)

for i in range(N):
    with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
        M_lower = q1_cfg['M_lower']
        M_upper = q1_cfg['M_upper']
        M = random.randint(M_lower, M_upper)
        cases = gen(M)

        f.writelines(f'{M}\n')
        for case in cases:
            f.writelines(case)
    
    sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))