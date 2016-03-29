class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0,item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

num = []
num.append(1)
q = Queue()
cur_num = 1
while cur_num < 20000:
    # print cur_num
    cur_num_0 = int(str(cur_num)+'0')
    cur_num_1 = int(str(cur_num)+'1')
    q.enqueue(cur_num_0)
    q.enqueue(cur_num_1)
    cur_num = q.dequeue()


t = input()
while t:
    sankhya = input()
    for value in num:
        cur_num = value
        if(value >= sankhya):
            break
    q = Queue()
    while cur_num % sankhya != 0:
        cur_num_0 = int(str(cur_num)+'0')
        cur_num_1 = int(str(cur_num)+'1')
        q.enqueue(cur_num_0)
        q.enqueue(cur_num_1)
        cur_num = q.dequeue()
    print cur_num
    t = t-1
