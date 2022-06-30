import os
import random
from cfg import q6_cfg

seed = q6_cfg['seed']
random.seed(seed)

class Customer():
    def __init__(self, group: int, id: int):
        self.group: int = group
        self.id: int = id
        self.next: Customer or None = None
        self.prev: Customer or None = None

    def __str__(self):
        return f"{self.id}"


class Counter():
    def __init__(self):
        self.head: Customer or None = None
        self.tail: Customer or None = None
        self.length: int = 0
        self.closed: bool = False

    def __len__(self):
        return self.length

    def __iter__(self):
        node = self.head
        while node != None:
            yield str(node)
            node = node.next

    def enter(self, customer: Customer):
        if self.length == 0:
            self.head = customer
            self.tail = customer
        else:
            g = customer.group
            t = self.tail
            while t != None and t.group != g:
                t = t.prev
            if t == None:
                customer.prev = self.tail
                customer.next = None
                self.tail.next = customer
                self.tail = customer
            else:
                customer.next = t.next
                customer.prev = t
                t.next = customer
                if customer.next != None:
                    customer.next.prev = customer
                else:
                    self.tail = customer
        self.length += 1

    def go(self):
        if self.length <= 0:
            return
        if self.length == 1:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.length -= 1

    def leave(self):
        x = None
        if self.length <= 0:
            return
        if self.length == 1:
            x = self.head
            self.head = self.tail = None
        else:
            x = self.tail
            self.tail = self.tail.prev
            self.tail.next = None
        self.length -= 1
        x.next = x.prev = None
        return x

    def close(self, n):
        if n == self:
            return
        while self.length >= 1:
            l = self.leave()
            n.enter(l)

    def __str__(self):
        x = ' '.join([('%s' % x) for x in self])
        if self.length > 0:
            return x + ' '
        return x


class McDonalds():
    def __init__(self, num):
        self.num: int = num
        self.b = [Counter() for _ in range(num)]

    def __str__(self):
        return '\n'.join(['%s' % x for x in self.b]) + '\n'

    def get_next(self, n):
        b = 0
        if n <= 0:
            b = self.num - 1
        else:
            b = n - 1
        if not self.b[b].closed:
            return b
        return self.get_next(b)

    def enter(self, group: int, id: int, counter_number: int):
        self.b[counter_number].enter(Customer(group, id))

    def go(self, counter_number: int):
        self.b[counter_number].go()

    def leave(self, counter_number: int):
        self.b[counter_number].leave()

    def close(self, n: int):
        counter = self.b[n]
        if self.b[n].closed == True:
            return
        
        counter.close(self.b[self.get_next(n)])
        self.b[n].closed = True

    def is_valid(self, command: str):
        c = command.split()
        counter = self.b[int(c[len(c) - 1])]
        if counter.closed:
            return False
        if c[0] == 'leave' or c[0] == 'go' and counter.length < 1:
            return False

        return True
    
    def execute(self, command:str):
        items = command.split(" ")
        if items[0] == 'enter':
            self.enter(int(items[1]), int(items[2]), int(items[3]))
        elif items[0] == 'leave':
            self.leave(int(items[1]))
        elif items[0] == 'go':
            self.go(int(items[1]))
        else:
            self.close(int(items[1]))


def main(in_path, out_path):
    output_file = open(out_path, 'w')
    input_file = open(in_path, 'w')

    counter_lower = q6_cfg['counter_lower']
    counter_upper = q6_cfg['counter_upper']
    num_counter = random.randint(counter_lower, counter_upper)

    situation_lower = q6_cfg['situation_lower']
    situation_upper = q6_cfg['situation_upper']
    num_situation = random.randint(situation_lower, situation_upper)

    group_lower = q6_cfg['group_lower']
    group_upper = q6_cfg['group_upper']
    num_group = random.randint(group_lower, group_upper)

    input_file.write(f'{num_counter} {num_situation} {num_group}' + '\n')
    x = McDonalds(num_counter)
    i = 0
    closed_counter = 0
    while i < num_situation:
        dice = random.randint(0, 3)
        command = ''
        if dice == 0:
            command += 'enter '
            command += (str(random.randint(0, num_group - 1)) + ' ')
            command += (str(i) + ' ')
            command += (str(random.randint(0, num_counter - 1)))
        elif dice == 1:
            command += 'go '
            command += (str(random.randint(0, num_counter - 1)))
        elif dice == 2:
            command += 'leave '
            command += (str(random.randint(0, num_counter - 1)))
        elif dice == 3:
            if closed_counter > num_counter // 2:
                continue
            command += 'close '
            command += (str(random.randint(0, num_counter - 1)))
        if not x.is_valid(command):
            continue
        input_file.write(command + '\n')
        i += 1
        if command[0] == 'c':
            closed_counter += 1

        x.execute(command)

    input_file.close()
    output_file.write(str(x))
    output_file.close()


N = q6_cfg['N']
save_path = q6_cfg['save_path']
os.makedirs(save_path, exist_ok=True)
for i in range(N):
    main(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))
