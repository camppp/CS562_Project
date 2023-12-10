python
def simulateLightPattern(light_rider, delay_time, initial_index):
    index = initial_index
    while True:
        shift_out(MSB_FIRST, light_rider[index])
        delay(delay_time)
        index = (index + 1) % 14  # Increment the index and wrap around if it exceeds 13
