"""
(a1+b1i+c1j+d1k)(a2+b2i+c2j+d2k)
= a1a2+a1b2i+a1c2j+a1d2k+b1a2i-b1b2+b1c2k-b1d2j+c1a2j-c1b2k-c1c2+c1d2i+d1a2k+d1b2j-d1c2i-d1d2
i component: a1b2+b1a2+c1d2-d1c2
j component: a1c2-b1d2+c1a2+d1b2
k component: a1d2+b1c2-c1b2+d1a2
scalar component: a1a2-b1b2-c1c2-d1d2
"""
import math
class Quaternion:
    def __init__(self, a, b, c, d):
        self.a = a
        self.b = b
        self.c = c
        self.d = d

    def __add__(self, other):
        return Quaternion(self.a + other.a, self.b + other.b, self.c + other.c, self.d + other.d)

    def __sub__(self, other):
        return Quaternion(self.a - other.a, self.b - other.b, self.c - other.c, self.d - other.d)

    def __mul__(self, other):
        if (type(other) == int or type(other) == float):
            return Quaternion(self.a * other, self.b * other, self.c * other, self.d * other)
        a = self.a * other.a - self.b * other.b - self.c * other.c - self.d * other.d
        b = self.a * other.b + self.b * other.a + self.c * other.d - self.d * other.c
        c = self.a * other.c - self.b * other.d + self.c * other.a + self.d * other.b
        d = self.a * other.d + self.b * other.c - self.c * other.b + self.d * other.a
        return Quaternion(a, b, c, d)
    def __str__(self):
        return f"{self.a}+{self.b}i+{self.c}j+{self.d}k"
    def __len__(self):
        return math.sqrt(self.a**2 + self.b**2 + self.c**2 + self.d**2)
    def normalized(self):
        length = self.__len__()
        return Quaternion(self.a / length, self.b / length, self.c / length, self.d / length)
    def i_component(self):
        return self.b
    def j_component(self):
        return self.c
    def k_component(self):
        return self.d
    def scalar_component(self):
        return self.a
if __name__=="__main__":
    x = Quaternion(0,1,1,0)
    y = Quaternion(0,0,0,1)
    print(x+y)
    print(x-y)
    print(x*y)
    print(y*x)
    print(x.normalized() * y)
    print(x * 3)
