int renderScanline(int x, int cursor_x, int ma, int ra, unsigned char m_p_videoram[]) {
  // Calculate the memory address for the current scanline
  int mem = ma + (x >> 3) + (ra << 3);

  // Extract the character data from video memory
  unsigned char chr = m_p_videoram[mem];

  // Calculate the graphics data for the current scanline
  int gfx = (chr >> (7 - ra)) & 1;

  // Check if the current scanline is the cursor
  if (x == cursor_x) {
    gfx = 1;
  }

  return gfx;
}
