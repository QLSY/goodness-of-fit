import numpy as np
from scipy.ndimage.interpolation import shift
def rho_value(expf,thef):

    x0,y0,error = np.loadtxt(expf,unpack=True)
    x1,y1 = np.loadtxt(thef,unpack=True)
    y = np.interp(x0,x1,y1)
    residual = (y-y0)/error
    chi2 = np.sum(residual*residual)
    rho_value = 1./chi2*np.sum(residual * shift(residual,-1,cval=0.0,prefilter=False))
    return (rho_value,chi2)


rho_value,chi2 = rho_value("exp.dat","the.dat")
print("chi2 {} , rho_value {}".format(chi2,rho_value))

