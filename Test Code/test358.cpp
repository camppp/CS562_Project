python
import itertools

def aggregate_generators(gen1, gen2, min_size, max_size):
    gen1_values = iter(gen1)
    gen2_values = iter(gen2)

    aggregated_values = []
    while len(aggregated_values) < min_size:
        try:
            aggregated_values.append(next(gen1_values))
        except StopIteration:
            break
        try:
            aggregated_values.append(next(gen2_values))
        except StopIteration:
            break

    remaining_size = max_size - len(aggregated_values)
    if remaining_size > 0:
        remaining_values = list(itertools.islice(itertools.chain(gen1_values, gen2_values), remaining_size))
        aggregated_values.extend(remaining_values)

    return aggregated_values
