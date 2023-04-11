  /*
  * @file    :8_copy_1.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :Factorization
  *          :因数分解
  *          :
  */

#include<stdio.h>
int n,ans=0;
void dfs(int h,int z){
    //printf("%d , %d\n", h,z);
    if(h==1){
        ans++;
        //printf("%d\n", ans); 
        return;
    }
    else
    for(int i=z;i<=h;i++)
        if(h%i==0)
            dfs(h/i,i);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0;
        if(n==2){
            printf("1\n");
            continue;
        }
        dfs(n,2);
        printf("%d\n",ans);
    }
    return 0;
}
