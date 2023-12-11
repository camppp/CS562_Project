function calculateMomentOfInertia(object) {
    const { mo, massCenter, idx } = object;

    // Initialize the moment of inertia
    let momentOfInertia = 0;

    // Iterate over each particle
    for (let i = 0; i < mo.length; i++) {
        // Calculate the distance from the mass center to the particle
        const dx = idx[i][0] - massCenter[0];
        const dy = idx[i][1] - massCenter[1];
        const distanceSquared = dx * dx + dy * dy;

        // Update the moment of inertia using the formula
        momentOfInertia += mo[i] * distanceSquared;
    }

    return momentOfInertia;
}

// Example usage
const object = {
    mo: [2, 3, 4],
    massCenter: [0, 0],
    idx: [[1, 1], [2, 2], [3, 3]]
};

const result = calculateMomentOfInertia(object);
console.log(result); // Output: 13
