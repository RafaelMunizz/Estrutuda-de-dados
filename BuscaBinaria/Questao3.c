#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[], int ini, int fim, int num) {
    int meio;
    if (ini > fim)
        return -1;
    else {
        meio = (ini+fim)/2;
        if (l[meio] == num)
            return meio;
        else
            if (num < l[meio])
                return buscaBin(l,ini,meio-1, num);
            else
                return buscaBin(l,meio+1,fim, num);
    }
}

int main(){
  int l[] = {1,3,5,7,9,11}, tam = 6;
  
  int ini = 0, fim = 6;

  printf("\nAchei 3 em %d \n",buscaBin(l, ini, fim, 3));
  printf("Achei 9 em %d \n",buscaBin(l, ini, fim, 9));
  
  return 0;
}