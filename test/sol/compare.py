import os

from numpy import true_divide

questions = ['q1'] # , 'q2', 'q4'

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

N = 50
for question in questions:
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
    for i in range(N):
        test_ans = os.popen(f'./{sol_exec_path} < {testcase_path}/{i}.in').readlines()
        
        with open(f'{testcase_path}/{i}.out', 'r') as f:
            ans = f.readlines()
        
        if test_ans != ans:
            if float(test_ans[0]) == float(ans[0]):
                if len(test_ans) > 1 and len(ans) > 1:
                    if test_ans[1] == ans[1]:
                        continue
                else:
                    continue
            
            flag = 1
            err_count += 1
            print(f'====== {i} ======')
            print('Your answer is :')
            print(test_ans)

            print()

            print('Ground truth :')
            print(ans)
    
    print()
    print('Check Result :')
    if flag:
        print(f'There is something wrong in {question}!')
        print(f'AC rate : {round(err_count / N, 2) * 100}%')
    else:
        print('All Pass!')
