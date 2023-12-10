def aggregate_generators(gen1, gen2, min_size, max_size):
    # Initialize the aggregated sequence with the first value from gen1
    sequence = [next(gen1)]
    # Alternate between gen1 and gen2 until the minimum size is reached
    while len(sequence) < min_size:
        sequence.append(next(gen1) if len(sequence) % 2 == 0 else next(gen2))
    # Continue generating values from the remaining generator until the maximum size is reached
    while len(sequence) < max_size:
        sequence.append(next(gen1 if len(sequence) % 2 == 0 else gen2))
    return sequence
