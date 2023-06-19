from multiprocessing import Pool
import functools
from decimal import Decimal
from decimal import getcontext
"""
getcontext().prec=x+1
  return sum(Decimal(1/(16)**k * 
        ((4)/(8*k+1) - 
         (2)/(8*k+4) - 
         (1)/(8*k+5) -
         (1)/(8*k+6))) for k in range (x+1))
"""
def cuadrado(k):

  return (1/(16)**k * 
        ((4)/(8*k+1) - 
         (2)/(8*k+4) - 
         (1)/(8*k+5) -
         (1)/(8*k+6)))

 
if __name__ == '__main__':
  valor = input()
  m = int(valor)
  verdadero = 0
  procesos = [Pool().apply_async(cuadrado, args=(x,)) for x in range(m)]
  resultado = [proceso.get() for proceso in procesos]

  getcontext().prec=m
  for pol in resultado:
     verdadero = Decimal(verdadero) + Decimal(pol);
  
  print(Decimal(verdadero))