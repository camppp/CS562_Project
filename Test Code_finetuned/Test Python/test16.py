import wx

class DrawingApp(wx.Frame):
    def __init__(self, parent, id, title):
        wx.Frame.__init__(self, parent, id, title, size=(600, 400))
        self.Bind(wx.EVT_SIZE, self.onSize)
        self.Bind(wx.EVT_PAINT, self.onPaint)
        self.buffer = None
        self.ReDraw()

    def ReDraw(self):
        if self.buffer is None:
            self.MakeNewBuffer()
        dc = wx.BufferedDC(wx.ClientDC(self), self.buffer)
        self.draw(dc)

    def onSize(self, event):
        self.ReDraw()
        event.Skip()

    def onPaint(self, event):
        self.ReDraw()

    def MakeNewBuffer(self):
        size = self.GetClientSize()
        self.buffer = wx.Bitmap(size.width, size.height)

    def draw(self, dc):
        dc.SetBackground(wx.Brush(wx.Colour(255, 255, 255)))
        dc.Clear()
        dc.DrawCircle(50, 50, 40)