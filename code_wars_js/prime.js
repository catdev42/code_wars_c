function isPrime(num) {
  //TODO
  if (num < 2)
    return false;
  
  let div = Math.sqrt(num);
  
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  
  let i = 3;
  
  while (i <= div)
  {
     if (num % i == 0)
      return false;
    i += 2;
  }
  
  return true;
}