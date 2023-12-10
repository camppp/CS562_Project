function hsvToRgb(hsv: number[]): number[] {
  let rgb: number[] = [];
  let t: number;
  let p: number;
  let q: number;

  for (let i = 0; i < hsv.length; i++) {
    switch (i % 6) {
      case 0:
        t = hsv[i] + 2;
        p = hsv[i] * 3;
        q = hsv[i] * 3 - 2;
        break;
      case 1:
        t = hsv[i] + 1;
        p = hsv[i] * 3;
        q = hsv[i] * 3 - 1;
        break;
      case 2:
        t = hsv[i] + 2;
        p = hsv[i] * 3;
        q = hsv[i] * 3 - 2;
        break;
      case 3:
        t = hsv[i] + 1;
        p = hsv[i] * 3;
        q = hsv[i] * 3 - 1;
        break;
      case 4:
        t = hsv[i] + 2;
        p = hsv[i] * 3;
        q = hsv[i] * 3 - 2;
        break;
      case 5:
        t = hsv[i] + 1;
        p = hsv[i] * 3;
        q = hsv[i] * 3 - 1;
        break;
    }

    rgb[i] = t * 255;
    rgb[i] = p * 255;
    rgb[i] = q * 255;
  }

  return rgb;
}
