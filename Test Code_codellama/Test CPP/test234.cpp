def maxRectangleArea(heights: List[int]) -> int:
    # Initialize variables
    max_area = 0
    current_area = 0
    stack = []

    # Iterate through the heights array
    for i in range(len(heights)):
        # If the current height is greater than the top of the stack,
        # push it to the stack
        if len(stack) == 0 or heights[i] > stack[-1]:
            stack.append(heights[i])
        # Otherwise, find the previous height that is less than or equal to the current height
        # and pop all buildings that are greater than that height
        else:
            while len(stack) > 0 and stack[-1] > heights[i]:
                stack.pop()
            stack.append(heights[i])

        # Calculate the current area
        current_area = len(stack)

        # Update the maximum area
        if current_area > max_area:
            max_area = current_area

    # Return the maximum area
    return max_area
