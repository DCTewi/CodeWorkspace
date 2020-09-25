import numpy as np
 
def define_area(point1, point2, point3):
    """
    法向量    ：n={A,B,C}
    空间上某点：p={x0,y0,z0}
    点法式方程：A(x-x0)+B(y-y0)+C(z-z0)=Ax+By+Cz-(Ax0+By0+Cz0)
    https://wenku.baidu.com/view/12b44129af45b307e87197e1.html
    :param point1:
    :param point2:
    :param point3:
    :param point4:
    :return:（Ax, By, Cz, D）代表：Ax + By + Cz + D = 0
    """
    point1 = np.asarray(point1)
    point2 = np.asarray(point2)
    point3 = np.asarray(point3)
    AB = np.asmatrix(point2 - point1)
    AC = np.asmatrix(point3 - point1)
    N = np.cross(AB, AC)  # 向量叉乘，求法向量
    # Ax+By+Cz
    Ax = N[0, 0]
    By = N[0, 1]
    Cz = N[0, 2]
    D = -(Ax * point1[0] + By * point1[1] + Cz * point1[2])
    return Ax, By, Cz, D
 
 
def point2area_distance(point1, point2, point3, point4):
    """
    :param point1:数据框的行切片，三维
    :param point2:
    :param point3:
    :param point4:
    :return:点到面的距离
    """
    Ax, By, Cz, D = define_area(point1, point2, point3)
    mod_d = Ax * point4[0] + By * point4[1] + Cz * point4[2] + D
    mod_area = np.sqrt(np.sum(np.square([Ax, By, Cz])))
    d = abs(mod_d) / mod_area
    return d
 
 
import random

def sphereNormalPoint(self):
    for i in range(100):
        x = random.normalvariate(0,1) # 服从标准正态分布的随机数
        y = random.normalvariate(0,1)
        z = random.normalvariate(0,1)
        r = (x * x + y * y + z * z) ** (1/2)
        print('x = ', x/r, 'y = ', y/r, 'z = ', z/r)
        return [x/r, y/r, z/r]

""" 
if __name__ == '__main__':
    # 初始化数据
    point1 = [2, 3, 1]
    point2 = [4, 1, 2]
    point3 = [6, 3, 7]
    point4 = [-5, -4, 8]
    # 计算点到面的距离
    d1 = point2area_distance(point1, point2, point3, point4)
"""
