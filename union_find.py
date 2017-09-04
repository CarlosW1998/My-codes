def find(i, lista) :
  while lista[i] > 0 :
    i = lista[i];
  return i;
  
def union(i, j, lista) :
  i = find(i, lista)
  j = find(j, lista)
  if i == j :
    return 
  if lista[i] <= lista[j] :
    lista[i] -= 1
    lista[j] = i
  else :
    lista[j] -= 1
    lista[i] = j
  print(lista);
