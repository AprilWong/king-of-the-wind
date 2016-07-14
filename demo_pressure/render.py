from PIL import Image
from paint import *
import math


class Render:
    def __init__(self):
        self.window = Window(None)
        self.window.title = ("demo_pressure")
        self.window.geometry("512x512")
        self.window.resizable(width = False, height = False)
        self.canvas = Canvas(self.window,width = 512, height = 512)
        self.canvas.set(512, 512)
        self.canvas.pack()
        
    def createWindow(self):
        self.canvas.paint()
        
    def addNewPoint(self, event):
        self.canvas.addNewPoint(event)
        self.canvas.update()
        self.canvas.delete("all")
        self.canvas.paint()

render = Render()

render.canvas.bind('<Button-1>', render.addNewPoint)

render.createWindow()

render.window.mainloop()