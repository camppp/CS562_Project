typescript
function hsvToRgb(hsv: number[]): number[] {
  let h = hsv[0];
  let s = hsv[1];
  let v = hsv[2];
  let rgb: number[] = [0, 0, 0];

  let i = Math.floor(h * 6);
  let f = h * 6 - i;
  let p = v * (1 - s);
  let q = v * (1 - f * s);
  let t = v * (1 - (1 - f) * s);

  switch (i % 6) {
    case 0: rgb[0] = v, rgb[1] = t, rgb[2] = p; break;
    case 1: rgb[0] = q, rgb[1] = v, rgb[2] = p; break;
    case 2: rgb[0] = p, rgb[1] = v, rgb[2] = t; break;
    case 3: rgb[0] = p, rgb[1] = q, rgb[2] = v; break;
    case 4: rgb[0] = t, rgb[1] = p, rgb[2] = v; break;
    case 5: rgb[0] = v, rgb[1] = p, rgb[2] = q; break;
  }

  return rgb;
}

// Test the function
console.log(hsvToRgb([0.5, 1, 1])); // Output: [1, 0, 0] (represents pure red in RGB color space)
