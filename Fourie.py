from scipy.fft import fft, ifft
import numpy as np
a = np.array([1,1,0,0,0,0,0,0])
b = np.array([1,0,0,1,0,0,0,0])

x = fft(a)
y = fft(b)

z = ifft(x*y)

for k in z:
    print(k)
