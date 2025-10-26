function countPositivesSumNegatives(input) {
  // your code here
  if (input == null || input.length === 0)
    return [];
  let arr = [0,0];
  for (let i of input)
  {
//     console.log(i);
    if (i>0)
      arr[0]++;
    else if (i <0)
      arr[1]+= i;
  }
  return arr;
}