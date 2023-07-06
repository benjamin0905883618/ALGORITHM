class heapnode:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
class heapsort:
    def __init__(self, root):
        self.root = heapnode(root)
        self.answer = []
    def recursive(self, cursor, val):
        if val < cursor.val:
            if cursor.left == None:
                cursor.left = heapnode(val)
                #print(val)
            else:
                #print(f'{cursor.val} bigger than {val}')
                return self.recursive(cursor.left, val)
        elif val >= cursor.val:
            if cursor.right == None:
                cursor.right = heapnode(val)
                #print(val)
            else:
                #print(f'{cursor.val} smaller than {val}')
                return self.recursive(cursor.right, val)
    def find_smaller(self, cursor):
        if cursor.left != None:
            self.find_smaller(cursor.left)
        self.answer.append(cursor.val)
        if cursor.right != None:
            self.find_smaller(cursor.right)
    def push(self, val):
        cursor = self.root
        self.recursive(cursor, val)
    def pop(self):
        cursor = self.root
        self.find_smaller(cursor)
        #return self.answer