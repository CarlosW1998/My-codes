def separa (lista, i, f) :
  a = i-1;
  b = i;
  pv = f-1;
  for k in range(f-1) :
    if lista[b] > lista[pv] :
      b += 1;
    elif lista[b] < lista[pv] :
      a += 1;
      lista[a], lista[b] = lista[b], lista[a];
      b += 1;
  lista[a+1], lista[pv] = lista[pv], lista[a+1];
  return a+1;

def q_sort(lista, i, f) :
  if(i < f) :
    print(lista);
    pv = separa(lista, i, f);
    #print(pv);
    q_sort(lista, i, pv);
    q_sort(lista, pv+1, f);
    
