function twoSum(numbers, target) {
    
  let i = 0;
  while (i < numbers.length-1)
  {
    let j = i+1;
    while (j < numbers.length)
    {
      if (numbers[i]+numbers[j] == target)
        return [i,j];
      j++;    
    }
    i++; 
  }
  return [];
}
