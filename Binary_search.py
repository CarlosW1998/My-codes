def bynari_search(lista, i, f, element, end) :
  midle = (i+f)//2
  if i > f  or i >= end:
    return -1;
  if int(lista[midle]) == element :
    return element;
  if int(lista[midle]) > element :
    return bynari_search(lista, i, midle-1, element, end);
  if int(lista[midle]) < element :
    return bynari_search(lista, midle+1, f, element, end);
