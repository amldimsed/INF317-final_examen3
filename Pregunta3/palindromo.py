from multiprocessing import Pool

def mensaje(pala):
    #pala = pala.lower()  # cambia a minusculas la palabra
    if str(pala) == str(pala)[::-1] :
        return "Verdad"
    else:
        return "Falso"

print(Pool().map(mensaje, ['oso','carlos','oruro','gogo']))