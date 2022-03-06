#include<stdio.h>
#include<stdlib.h>

int sentinel(void* e){
  return *(int*)e < 0;
}

int count(void* t, size_t esize){
  //int* t=(int*)t2;//si $1 est specifie suivant l'identificateur
  //de variable:: t2.///
  int len=0;
  while(!sentinel(t)){
    len++;
    t+=esize;
  }
  return len;
}

void afficher(void* t){
  for(int i=0;*((int*)t+i)>=0;i++){
    printf("%d\t",*((int*)t+i));
  }
  printf("\n");
}

int count2(void* t, size_t esize, int(*sentinel_detector)(void*)){
  int len=0;
  while(!sentinel_detector(t)){
    len++;
    t+=esize;
  }
  return len;
}

int main(){
  int t[]={1,2,3,-1};
  printf("%ld\n",sizeof(t[0]));
  afficher(t);
  afficher(t);
  printf("%d\n",count(t,4));
  int sentinel2(void* e){
    return *(int*)e < 0;
  }
  printf("%d\n",count2(t,4,sentinel2));
  afficher(t);
  return 0;
}
