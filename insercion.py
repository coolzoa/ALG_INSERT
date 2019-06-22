import random
import tkinter
from tkinter import Label,Button,Entry,messagebox
import datetime




#funcion para devolver un vector de valores aleatorios
def llenarLista(n):
    lista = list()
    if n <= 1:
        messagebox.showerror(None,"Debe ingresar un numero entero mayor o igual a 2")
    else:
        for i in range(0,n):
            lista.insert(i,random.randint(1,n))
        return lista

#funcion de ordenamiento usando algoritmo de insercion
def insercion(vector):
    antes = datetime.datetime.now()
    largo = len(vector)
    for j in range(1, largo):
        k = vector[j]
        i = j - 1;
        while i >= 0 and vector[i] > k:
            vector[i + 1] = vector[i]
            i = i - 1
        vector[i + 1] = k
    despues = datetime.datetime.now()
    salida.config(text="Tiempo: " + str(despues-antes))

def insercionNormal():
    try:
        elementos = int(entrada.get())
        vector = llenarLista(elementos)
        insercion(vector)
        return
    except ValueError:
        messagebox.showerror(None,"Debe ingresar un numero entero")
        return

def insercionOrdenado():
    try:
        elementos = int(entrada.get())
        vector = llenarLista(elementos)
        vector.sort()
        insercion(vector)
    except ValueError:
        messagebox.showerror(None,"Debe ingresar un numero entero")
        return

def insercionAlreves():
    try:
        elementos = int(entrada.get())
        vector = llenarLista(elementos)
        vector.sort()
        vector.reverse()
        insercion(vector)
        return
    except ValueError:
        messagebox.showerror(None,"Debe ingresar un numero entero")
        return
                  

app = tkinter.Tk()
app.geometry("300x300")
l = Label(app,text="Ingrese el numero de elementos del vector").pack()
entrada = Entry(app)
entrada.pack()

bnormal = Button(app,text="Insercion con vector aleatorio",command=insercionNormal)
bnormal.pack()

bordenado = Button(app,text="Insercion con vector ya ordenado",command=insercionOrdenado)
bordenado.pack()

breves = Button(app,text="Insercion con \n vector ordenado de mayor a menor",command=insercionAlreves)
breves.pack()

l2 = Label(app,text="--------------------").pack()
salida = Label(app)
salida.pack()

app.mainloop()

    
