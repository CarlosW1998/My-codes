def bynari_search_shortest(lista, i, f, element, end, a) :
  midle = (i+f)//2
  if i > f  or i >= end:
   if int(lista[a]) < element :
     return lista[a];
   if a > 0 :
     return lista[a-1];
   return lista[a];
  if int(lista[midle]) == element :
    if midle-1 >= 0 :
      return lista[midle-1];
    return element;
  if int(lista[midle]) < element :
    return bynari_search_shortest(lista, midle+1, f, element, end, midle);
  if int(lista[midle]) > element :
    return bynari_search_shortest(lista, i, midle-1, element, end, midle);
    

def bynari_search_talltest(lista, i, f, element, end, a) :
  midle = (i+f)//2
  if i > f  or i >= end:
   print("buia2");
   if int(lista[a]) > element :
     return lista[a];
   if a < end-1 :
     return lista[a+1];
   return lista[a];
   
   
   
  if int(lista[midle]) == element :
    if midle+1 > end :
      return lista[midle+1];
    return lista[a];
    
  
  if int(lista[midle]) < element :
    return bynari_search_shortest(lista, midle+1, f, element, end, midle);
  if int(lista[midle]) > element :
    return bynari_search_shortest(lista, i, midle-1, element, end, midle);


i = int(input());
k = input();
k = k.split(" ")

for a in range(10) :
  w = int(input());
  shotest = bynari_search_shortest(k, 0, i, w, i, -1);
  talltest = bynari_search_talltest(k, 0, i, w, i, -1);
  
  print(shotest, talltest);
