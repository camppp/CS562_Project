javascript
function calculateMomentOfInertia(object) {
  let momentOfInertia = 0;
  for (let i = 0; i < object.mo.length; i++) {
    let distanceSquared = Math.pow(object.idx[i][0] - object.massCenter[0], 2) + Math.pow(object.idx[i][1] - object.massCenter[1], 2);
    momentOfInertia += object.mo[i] * distanceSquared;
  }
  return momentOfInertia;
}

// Test
const object = {
  mo: [2, 3, 4],
  massCenter: [0, 0],
  idx: [[1, 1], [2, 2], [3, 3]]
};
console.log(calculateMomentOfInertia(object)); // Output: 13
