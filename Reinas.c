
#include <stdio.h>
#define N 8

void imprimir(int t[N][N]) {
   int i, j;
   for(i=0; i<N; i++) {
      for(j=0; j<N; j++) {
         if(t[i][j]==0 )
            printf(" #");
         else
            printf("% d", t[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}
//Validar posiciones
int Valido(int f, int c, int tablero[N][N]){
    int i;
    //validar fila o columna
    for(i=0; i<N; i++){
       if(tablero[f][i]!=0 || tablero[i][c]!=0)
         return 1; 
    }
   //validar diagonales superiores
   for(i=0; f-i>=0 && c-i>=0; i++){
      if(tablero[f-i][c-i]!=0)
         return 1;
   }
   for(i=0; f-i>=0 && c+i<N; i++){
      if(tablero[f-i][c+i]!=0)
         return 1;
   }

   //Validar diagonales inferiores
   for(i=0; f+i<N && c-i>=0; i++){
      if(tablero[f+i][c-i]!=0)
         return 1;
   }
   //diagonal abajo-der
   for(i=0; f+i<N && c+i<N; i++){
      if(tablero[f+i][c+i]!=0)
         return 1;
   }
   return 0;
}
//Backtracking
int Reinas(int tablero[N][N], int c){
     int f;
     if(c==N){
	return 1;
     }
     else{
         for(f=0; f<N; f++){
            if(Valido(f, c, tablero)==0){
   	       tablero[f][c]= c+1;
	       if(Reinas(tablero, c+1)==1){
	  	   return 1;
 	       }
 	       else{
  	           tablero[f][c]=0;
   	       }
	    }
	 }
       	 return 0;
     }
}

int main(){
   int tablero[N][N];
   int i, j;
   for(i=0; i<N; i++) {
      for(j=0; j<N; j++){
         tablero[i][j]=0; 
      }
   }
   Reinas(tablero,0);
   imprimir(tablero);
   return 0;
}
