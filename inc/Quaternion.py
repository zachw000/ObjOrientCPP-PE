class Quaternion:
     def __init__(self):
         self.a = 0
         self.b = 0
         self.c = 0
         self.d = 0
     def __init__(self, a, b, c, d):
         self.a = a
         self.b = b
         self.c = c
         self.d = d
     def __add__(self, other):
         if (type(other) == int or type(other) == float):
            return Quaternion(self.a + other, self.b, self.c, self.d)
         return Quaternion(self.a + other.a, self.b + other.b, self.c + other.c, self.d + other.d)
     def __str__(self):
        return f"{self.a}{"+" if self.b >= 0 else ""}{self.b}i{"+" if self.c >= 0 else ""}{self.c}j{"+" if self.d >= 0 else ""}{self.d}k"
     def __mul__(self, other):
        if (type(other) == int or type(other) == float):
            return Quaternion(self.a * other, self.b * other, self.c * other, self.d * other)
        a = self.a * other.a - self.b * other.b - self.c * other.c - self.d * other.d
        b = self.a * other.b + self.b * other.a + self.c * other.d - self.d * other.c
        c = self.a * other.c - self.b * other.d + self.c * other.a + self.d * other.b
        d = self.a * other.d + self.b * other.c - self.c * other.b + self.d * other.a
        return Quaternion(a,b,c,d)
     def __sub__(self, other):
        if (type(other) == int or type(other) == float):
            return Quaternion(self.a - other, self.b, self.c, self.d)
        return Quaternion(self.a - other.a, self.b - other.b, self.c - other.c, self.d - other.d)
     def __len__(self):
         import math
         return math.sqrt(self.a**2 + self.b**2 + self.c**2 + self.d**2)
     def normal(self):
         length = self.__len__()
         return Quaternion(self.a / length, self.b / length, self.c / length, self.d / length)
     def r_component(self):
         return self.a
     def i_component(self):
         return self.b
     def j_component(self):
         return self.c
     def k_component(self):
         return self.d
     def set_i(self, i):
         self.b = i
     def set_r(self, r):
         self.a = r
     def set_j(self, j):
         self.c = j
     def set_k(self, k):
         self.d = k
     def magnitude(self):
         return len(self)
x = Quaternion(0,0,1,0)
y = Quaternion(0,0,0,1)
print(x*y)
print(y*x)
print(x*3)
print(y*3)