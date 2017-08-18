def check(lista, ic, fc, il, fl) :
  #print(" ",ic, fc, il, fl);
  for a in range(il, fl) :
    for b in range (ic, fc) :
      if lista[il][ic] != lista[a][b] :
        return 1;
  return 0;
  
  
def bmp(lista, ic, fc, il, fl, endc, endl, pog) :
  if ic >= fc or il >= fl or ic > endc or il > fl:
  	return ;
  pog[0] += 1;
  if(check(lista, ic, fc, il, fl)) :
    print("D", end = '');
    if pog[0]%50 == 0 :
    	print("");
    linha_media = (il+fl)//2;
    coluna_media = (ic+fc)//2;
    i = (fl-il)%2;
    j = (fc-ic)%2;
    bmp(lista, ic, coluna_media+j, il, linha_media+i, endc, endl, pog);
    bmp(lista, coluna_media+j, fc, il,linha_media+i, endc, endl, pog);
    bmp(lista, ic, coluna_media+j, linha_media+i, fl, endc, endl, pog);
    bmp(lista, coluna_media+j, fc, linha_media+i, fl, endc, endl, pog);
    return ;
  
  print(lista[il][ic], end = '') ;
  if pog[0]%50 == 0 :
  	print("");
  return ;
  

n = int(input());

for z in range(n) :
  k = 0;
  size = input();
  size = size.split(" ");
  lista = [];
  for i in range(int(size[0])) :
    lista.append(input());
  pog = [0];
  bmp(lista, 0, int(size[1]), 0, int(size[0]), int(size[1]), int(size[0]), pog);
  print("");
  #print(pog[0]);
