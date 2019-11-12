from numpy import *
from matplotlib.pylab import *

euler01 = loadtxt("euler01.txt")
euler001 = loadtxt("euler001.txt")
euler1 = loadtxt("euler1.txt")

implicita01 = loadtxt("imp01.txt")
implicita001 = loadtxt("imp001.txt")
implicita1 = loadtxt("imp1.txt")

w=0.1
t0=0
tf=4/w
h=0.1
pasos= int((tf - t0)/h)
t = [t0+h*i for i in range(pasos) ]

figure(figsize=(10,10))
subplot(3,2,1)
plot(t,euler01)
title("Metodo por Euler 01")

subplot(3,2,2)
plot(t,implicita01)
title("Metodo por Implicita 01")

h=0.01
pasos= int((tf - t0)/h)
t = [t0+h*i for i in range(pasos) ]

subplot(3,2,3)
plot(t,euler001)
title("Metodo por Euler 001")

subplot(3,2,4)
plot(t,implicita001)
title("Metodo por Implicita 001")

h=1
pasos= int((tf - t0)/h)
t = [t0+h*i for i in range(pasos) ]

subplot(3,2,5)
plot(t,euler1)
title("Metodo por Euler 1")

subplot(3,2,6)
plot(t,implicita1)
title("Metodo por Implicita 1")
savefig("primer_grado.png")
