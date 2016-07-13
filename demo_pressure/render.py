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
        self.canvas.paintBackground()
        self.window.mainloop()

render = Render()

render.canvas.bind('<Button-1>', render.canvas.addNewPoint)

render.createWindow()
        
