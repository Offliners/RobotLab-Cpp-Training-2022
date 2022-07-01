import os
import math
import random
from cfg import q5_cfg

seed = q5_cfg['seed']
random.seed(seed)

operators = ['+', '-', '*', '/']
parentheses_prob = q5_cfg['parentheses_prob']

num_lower = q5_cfg['num_lower']
num_upper = q5_cfg['num_upper']

class MathExpression(object):
    def __init__(self, maxNumbers, maxdepth_=None, depth_=0):
        if maxdepth_ is None:
            maxdepth_ = math.log(maxNumbers, 2) - 1

        if depth_ < maxdepth_ and random.randint(0, maxdepth_) > depth_:
            self.left = MathExpression(maxNumbers, maxdepth_, depth_ + 1)
        else:
            self.left = random.randint(num_lower, num_upper)

        if depth_ < maxdepth_ and random.randint(0, maxdepth_) > depth_:
            self.right = MathExpression(maxNumbers, maxdepth_, depth_ + 1)
        else:
            self.right = random.randint(num_lower, num_upper)

        self.grouped = random.random() < parentheses_prob
        self.operator = random.choice(operators)

    def __str__(self):
        s = '{0!s}{1}{2!s}'.format(self.left, self.operator, self.right)

        if self.grouped:
            return '({0})'.format(s)
        else:
            return s


def myeval(in_expr):
    if in_expr.find('/') != -1:
        exprs = in_expr.split('/')
        result = '//'.join(exprs)
    else:
        result = in_expr
    
    return eval(result)


def gen():
    continue_cal_prob = q5_cfg['continue_cal_prob']
    depth_lower = q5_cfg['depth_lower']
    depth_upper = q5_cfg['depth_upper']
    mod_prob = q5_cfg['mod_prob']
    prob_decay = q5_cfg['prob_decay']

    tree_depth = 2 ** (random.randint(depth_lower, depth_upper))
    equ = str(MathExpression(tree_depth))
    while random.random() < continue_cal_prob:
        equ += '='
        equ += random.choice(operators)

        tree_depth = 2 ** (random.randint(depth_lower, depth_upper))
        equ += str(MathExpression(tree_depth))

        if random.random() < mod_prob:
            exprs = equ.split('=')

            result = 0
            for i in range(len(exprs)):
                if i == 0:
                    result += myeval(exprs[i])
                else:
                    result += myeval(str(result) + exprs[i])

            if result > 0:
                mod_num = random.randint(num_lower, num_upper)
                equ += '%{0}'.format(mod_num)
        
        continue_cal_prob *= prob_decay
        
    if equ[-1] != '=':
        equ += '='

    return equ


def sol(in_path, out_path):
    results = []
    with open(in_path, 'r') as f:
        expr = f.readlines()[0].strip()

        exprs = expr.split('=')

        result = 0
        for i in range(len(exprs)):
            if exprs[i]:
                if i == 0:
                    result += myeval(exprs[i])
                elif exprs[i]:
                    result += myeval(str(result) + exprs[i])
            
                results.append(result)
        
    with open(out_path, 'w') as f:
        for ans in results:
            f.writelines(f'{ans}\n')



N = q5_cfg['N']
save_path = q5_cfg['save_path']
os.makedirs(save_path, exist_ok=True)
for i in range(N):
    with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
        expr = gen()
        f.writelines(expr + '\n')

    sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))
