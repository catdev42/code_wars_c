function dBScale(intensity) {
  let ret = 10 * (Math.log10(intensity/Math.pow(10, -12)));
  return ret;
}