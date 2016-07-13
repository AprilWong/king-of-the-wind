import tkinter

class Window(tkinter.Tk):
    def __init__(self, parent):
        tkinter.Tk.__init__(self, parent)
        self.parent = parent
        self.initialize()
    def initialize(self):
        pass
        
class Canvas(tkinter.Canvas):
    def set(self, width, height):
        self.width = width
        self.height = height
        
    def paint_background(self):
        for i in range(self.width):
            for j in range(self.height):
                self.draw_point(i, j, 255, 255, 255 )
        
    def draw_point(self, x, y, r, g, b):
        rgb = "#%02x%02x%02x" % (int(r), int(g), int(b))
        self.create_oval(x, y, x + 1, y + 1, fill = rgb, outline = rgb)
        