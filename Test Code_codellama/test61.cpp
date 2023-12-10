function calculateMomentOfInertia(object) {
  const { mo, massCenter, idx } = object;
  let momentOfInertia = 0;
  for (let i = 0; i < mo.length; i++) {
    const particle = idx[i];
    const distance = Math.sqrt(Math.pow(particle[0] - massCenter[0], 2) + Math.pow(particle[1] - massCenter[1], 2));
    momentOfInertia += mo[i] * distance * distance;
  }
  return momentOfInertia;
}
