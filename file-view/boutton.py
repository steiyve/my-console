from tkinter import *

class TopBar:
    def __init__(self):
        self.wn = Tk()

    def frame1(self):
        self.exterieur = Frame(self.wn)
        self.exterieur.pack()

    def frame2(self):
        self.exterieur2 = Frame(self.exterieur, bg = "white")
        self.exterieur2.pack()

    def boutton(self):
        self.gros = Button(self.exterieur ,text = "help", command = self.help)
        self.text = Label(self.exterieur2, text= "hello world", bg = "white")
        self.text.pack()
        self.gros.pack()

    def help(self):
        print("help caled")

    def update(self):
        self.wn.mainloop()
        self.exterieur.mainloop()
        self.exterieur2.mainloop()
