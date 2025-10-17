var isSquare = function(n){
  if (n < 0)
    return false;
  for (let i = 0; i*i <= n; i++)
    {
      if (i * i == n)
        return true;
    }
  return false;
}
