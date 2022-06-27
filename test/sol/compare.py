import os
import time
import subprocess
from cfg import cfg

questions = cfg['questions']

def check_file_exist(path):
    if os.path.isfile(path):
        return True
    else:
        return False

def check_folder_exist(path):
    if os.path.isdir(path):
        return True
    else:
        return False

N = cfg['N']
for question in questions:
    os.makedirs(f'./{question}_output', exist_ok=True)

    testcase_path = f'{question}_testcase'
    if not check_folder_exist(testcase_path):
        print(f'{question} testcase folder does not exist!')
    else:
        print(f'{question} testcase folder found!')

    sol_exec_path = f'build/{question}/{question}'
    if not check_file_exist(sol_exec_path):
        print(f'{question} does not be built!')
    else:
        print(f'{question} found!')

    flag = 0
    err_count = 0
    runtimes = []

    for i in range(N):
        start_time = time.time()
        p = subprocess.Popen(f'./{sol_exec_path} < {testcase_path}/{i}.in > {question}_output/{i}.out', shell=True)
        end_time = time.time()
        
        p.communicate()
        runtimes.append(round((end_time - start_time) * 1000))

    print('\n{:^10s}{:^10s}{:^10s}'.format('Testcase', 'Result', 'Runtime'))
    print('=' * 30)

    wa_count = 0
    for i in range(N):
        with open(f'{testcase_path}/{i}.out', 'r') as f:
            ans = f.readlines()

        with open(f'{question}_output/{i}.out', 'r') as f:
            ans_gt = f.readlines()

        if ans != ans_gt:
            if question == 'q1':
                if float(ans[0]) != float(ans_gt[0]):
                    result = 'WA'
                    wa_count += 1
                else:
                    result = 'AC'
        else:
            result = 'AC'

        print('{:^10s}{:^10s}{:^10s}'.format('#' + str(i), result, str(runtimes[i]) + 'ms'))

    print('\n======={:^10s}======='.format('Result'))
    print('{:<9s}:   {:>3s} %'.format('AC Rate', str(round((1 - wa_count / N) * 100))))
    print('{:<9s}:   {:>3s} ms'.format('Runtime', str(round(sum(runtimes) / N))))