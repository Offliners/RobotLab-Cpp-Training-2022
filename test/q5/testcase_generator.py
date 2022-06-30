import random
import math

class Expression(object):
    OPS = ['+', '-', '*', '/', '%']

    GROUP_PROB = 0.1

    MIN_NUM, MAX_NUM = 1, 20

    def __init__(self, maxNumbers, _maxdepth=None, _depth=0):
        """
        maxNumbers has to be a power of 2
        """
        if _maxdepth is None:
            _maxdepth = math.log(maxNumbers, 2) - 1

        if _depth < _maxdepth and random.randint(0, _maxdepth) > _depth:
            self.left = Expression(maxNumbers, _maxdepth, _depth + 1)
        else:
            self.left = random.randint(Expression.MIN_NUM, Expression.MAX_NUM)

        if _depth < _maxdepth and random.randint(0, _maxdepth) > _depth:
            self.right = Expression(maxNumbers, _maxdepth, _depth + 1)
        else:
            self.right = random.randint(Expression.MIN_NUM, Expression.MAX_NUM)

        self.grouped = random.random() < Expression.GROUP_PROB
        self.operator = random.choice(Expression.OPS)

    def __str__(self):
        s = '{0!s}{1}{2!s}'.format(self.left, self.operator, self.right)
        if self.grouped:
            return '({0})'.format(s)
        else:
            return s


equ = Expression(256)

print(equ)

print(eval(str(equ)))

