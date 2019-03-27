tamaño=int(input())
cad1=input()
cad2=input()
i=0
j=-1
control=1
shifts=-1
max1=0
sig=[]
#Generando tabla KMP
while(control==1):
	sig.append(j)
	while(j>=0 and cad1[i]!=cad1[j]):
		j=sig[j]
	i+=1
	j+=1
	if(i>=tamaño):
		control=-1
print(sig)
#Genramos una cadena con la cadena 2 repetida
cad2=cad2+cad2
i=0
j=0
print(cad1)
print(cad2)
#Checamos cada caracter hasta encontrar el -1 en la tabla
while(j<tamaño and i<2*tamaño):
	while (j >= 0 and cad2[i] != cad1[j]):
		if (j > max1):
			max1 = j
			shifts = (i-j)
		j = sig[j]
	j+=1
	i+=1
print(shifts)