#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int circular(int M, int x){
    if (x<0)
        return x+M;
    if(x >= M)
        return x-M;
    return x;
 }


int main(){

    int m=4,n=3,toplam=0;
    int F[m][n];
    int G[m][n];
    int V[3][3];

    //1. Adım F[m][n] 2boyutlu dızıye 0-255 arasına rasgele sayı at
    srand(time(0));
    for (int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++ ) {
            F[y][x]=rand()%255;
        }
    }
    /*
    for (int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++ ) {
            printf("F[%d][%d] = %d\n", y, x, F[y][x]);
        }
        printf("\n");
    }
    */
    //2.Adım G[m][n] matrisini sıfırlama  yapıyoruz.
    for (int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++ ) {
            G[y][x]=0;
        }
    }
    
    //3.Adım V[3][3] dizisini kullanıcıdan al
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            printf("V[%d][%d] = ",y,x);
            scanf("%d",&V[y][x]); 
        } 
    }
  
    //4.Adym F[m][n] yle V[3][3] kullanarak G[m][n] olustur.
    for(int y = 1; y < m - 1; y++){
        for(int x = 1; x < n- 1; x++){
            toplam = 0.0;
            for(int k = -1; k <= 1;k++){
                for(int j = -1; j <=1; j++){
                    toplam = toplam + V[j+1][k+1]*F[y - j][x- k];
                }
            }
            G[y][x] = toplam;
        }
    }
    printf("\n");
    // A Durumu G matrisi
    for (int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++ ) {
            printf("%d\t",G[y][x]);
        }
        printf("\n");
    }
    // 5.Adım Kenar durumları olmadan bul
    int x1=0,y1=0;
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            toplam=0;
            for(int k=-1;k <= 1; k++){
                for(int j=-1;j <= 1; j++ ){

                    y1 = circular(m, y - k);
                    x1 = circular(n, x - j);
                   
                                         //y1 x1
                    toplam+=V[j+1][k+1]*F[y1][x1];
                }
            }
            G[y][x]=toplam;
        }
    }
    printf("\n");

    // B Durumu G matrisi
    for (int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++ ) {
            printf("%d\t",G[y][x]);
        }
        printf("\n");
    }


return 0;
}
