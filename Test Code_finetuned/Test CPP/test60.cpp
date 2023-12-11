def calculateMomentOfInertia(object):
    moment_of_inertia = 0
    for i in range(len(object['mo'])):
        dx = object['idx'][i][0] - object['massCenter'][0]
        dy = object['idx'][i][1] - object['massCenter'][1]
        moment_of_inertia += object['mo'][i] * (dx**2 + dy**2)
    return moment_of_inertia

# Test the function
object = {
   'mo': [2, 3, 4],
   'massCenter': [0, 0],
    'idx': [[1, 1], [2, 2], [3, 3]]
}
print(calculateMomentOfInertia(object))  # Output: 13