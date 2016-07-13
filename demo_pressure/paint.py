import tkinter

def hsl2rgb(h, s, l):
    h = h / 360
    s = s / 100
    l = l / 100
    r = g = b = l
    if s == 0:
        r = g = b = l
    else:
        def hue2rgb(p, q, t):
            if(t < 0):
                t += 1
            if(t > 1):
                t -= 1
            if(t < 1/6):
                return p + (q - p) * 6 * t
            if(t < 1/2):
                return q
            if(t < 2/3):
                return p + (q - p) * (2/3 - t) * 6
            return p
        q = l * (1 + s) if l < 0.5 else l + s - l * s
        p = 2 * l - q
        r = hue2rgb(p, q, h + 1/3)
        g = hue2rgb(p, q, h)
        b = hue2rgb(p, q, h - 1/3)
    return "#%02x%02x%02x" % (int(r * 255), int(g * 255), int(b *  255))

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
        
    def paintBackground(self):
        for i in range(self.width):
            for j in range(self.height):
                self.drawPoint(i, j, 180)
        
    def drawPoint(self, x, y, hue):
        
        rgb = hsl2rgb(hue,100,50)
    
        self.create_oval(x, y, x + 1, y + 1, fill = rgb, outline = rgb)    
    
    def addNewPoint(self, event):
        print ("haha from canvas", event.x, event.y)
          