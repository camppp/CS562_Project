python
def maxRectangleArea(heights):
    stack = []
    maxArea = 0
    i = 0
    while i < len(heights):
        if not stack or heights[i] >= heights[stack[-1]]:
            stack.append(i)
            i += 1
        else:
            top = stack.pop()
            width = i if not stack else i - stack[-1] - 1
            maxArea = max(maxArea, heights[top] * width)
    while stack:
        top = stack.pop()
        width = i if not stack else len(heights) - stack[-1] - 1
        maxArea = max(maxArea, heights[top] * width)
    return maxArea
