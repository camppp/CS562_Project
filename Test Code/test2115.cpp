python
def simulateScheduler(processes, timeSlice):
    executionOrder = []
    queue = list(processes)
    while queue:
        currentProcess = queue.pop(0)
        executionOrder.append(currentProcess)
        if len(queue) > 0:
            queue.extend(queue[:timeSlice])
            del queue[:timeSlice]
    return executionOrder
