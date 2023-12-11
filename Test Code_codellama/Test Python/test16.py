import wx

class DrawingCanvas(wx.Panel):
    def __init__(self, parent):
        super().__init__(parent)
        self._buffer = None
        self._size = (600, 400)
        self._pen = None
        self._brush = None
        self._draw_event = wx.EventType(-1)
        self._bind('<LeftDown>', self._handle_leftdown)
        self._bind('<RightUp>', self._handle_rightup)
        self._bind('<MouseMove>', self._handle_mousemove)
        self._bind('<Erase>', self._handle_erase)
        self._bind('<Clear>', self._handle_clear)
        self._bind('<Redraw>', self._redraw)
        self._bind('<Resize>', self._resize)
        self._set_properties()

    def _set_properties(self):
        self.SetBackgroundColour("#ffffff")
        self.SetFont(wx.SystemFont(wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.SetDoubleBuffered(True)
        self.SetMinimumSize(self._size)
        self.SetMaximumSize(self._size)
        self.SetClientRect(self._size)
        self.Bind(self._draw_event, self._on_draw)
        self.Bind(self._resize_event, self._on_resize)
        self.Bind(self._paint_event, self._on_paint)

    def _get_dc(self):
        dc = wx.DCFromWindow(self)
        if dc is None:
            dc = wx.GetDC(self.Parent)
        return dc

    def _create_buffer(self):
        width, height = self._size
        bmp = wx.Bitmap(width, height)
        dc = wx.DCFromImage(bmp)
        dc.SetBrushColor("#ffffff")
        dc.FillRectangle(0, 0, width, height)
        dc.ResetBrush()
        dc.SetPenColor("#000000")
        dc.SetPenWidth(2)
        dc.SetLineStyle(wx.LINESTYLE_SOLID)
        dc.StrokeRectangle(0, 0, width, height)
        dc.Save()
        self._buffer = bmp

    def _make_new_buffer(self):
        if self._buffer is None:
            self._create_buffer()
        else:
            self._buffer.Delete()
            self._buffer = None
            self._create_buffer()

    def _redraw(self, event=None):
        self._make_new_buffer()
        self.Invalidate()

    def _resize(self, event=None):
        size = event.GetSize()
        self._size = size
        self._make_new_buffer()
        self.Refresh()

    def _handle_leftdown(self, event):
        pos = event.GetPosition()
        self._start_pos = pos
        self._end_pos = pos
        self._is_drawing = True
        self._make_new_buffer()

    def _handle_rightup(self, event):
        if self._is_drawing:
            self._stop_pos = event.GetPosition()
            self._is_drawing = False
            self._connect_points()
            self._redraw()

    def _handle_mousemove(self, event):
        if self._is_drawing:
            self._end_pos = event.GetPosition()

    def _handle_erase(self, event):
        self._is_drawing = False
        self._redraw()

    def _handle_clear(self, event):
        self._is_drawing = False
        self._redraw()

    def _connect_points(self):
        start_x, start_y = self._start_pos
        end_x, end_y = self._end_pos