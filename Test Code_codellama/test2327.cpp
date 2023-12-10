void simulateLightPattern(int light_rider[], int delay_time, int index) {
  while (true) {
    shift_out(MSB_FIRST, light_rider[index]);
    delay(delay_time);
    index++;
    if (index > 13) {
      index = 0;
    }
  }
}
