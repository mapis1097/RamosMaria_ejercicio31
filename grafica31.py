import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("oscilador.dat")
    
    
plt.figure(figsize=(25,4))
    
plt.subplot(1,3,1)
s = np.shape(data)
print(s)
n_x = s[1]
n_t = s[0]
deltaX = s[1]
deltaT = s[0]
plt.imshow(data)
plt.colorbar(label="primera grafica")
plt.xlabel("X")
plt.ylabel("T")


plt.subplot(1,3,2)
x = np.linspace(0,1,deltaX)
delta_t = 1.0/deltaT
for i in range(n_t):
    if i%(n_t//9) == 0:
        plt.plot(x, data[i,:], label="t={:.02f}".format(i*delta_t))
    plt.legend(loc=1)
    plt.xlabel("X")
    plt.ylabel("phi")
            
plt.subplot(1,3,3)
t = np.linspace(0,1,n_t)
plt.plot(t, data[:,n_x//4], alpha=i/n_t, color='black')
plt.xlabel("Tiempo")
plt.ylabel("$\psi$(x=0)")


plt.savefig("grafica_final.png")