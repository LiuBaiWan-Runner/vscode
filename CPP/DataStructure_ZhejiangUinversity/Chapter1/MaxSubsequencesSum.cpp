   /*
   * @file    :MaxSubsequencesSum.cpp
   * @author  :LiuBaiWan-Runner
   * @version :V1.0.0
   * @date    :2022-12-14
   * @brief   :Find the maximum subsequence sum,
   *           Including brute force algorithm, optimized brute force algorithm, 
   *           divide and conquer algorithm and dynamic programming algorithm.
   */


#include <iostream>

using namespace std;

/************************************Function declaration************************************/
int MaxSubSum_BF(int List[],int N);
int MaxSubSum_OptimizedBF(int List[], int N);
int MaxIn3(int A, int B, int C);
int DivideAndConquer(int List[], int left, int right);
int MaxSubSum_DivAndCon(int List[], int N);
int MaxSubSum_Dynamic(int List[], int N);



int main()
{
    int N;
    cin>>N;
    char a;
    int List[N];

/************************************Normal method************************************/

    // for(int i=0; i<N; i++){
    //     cin>>List[i]>>a;
    // }
    // cout<<MaxSubSum_BF(List, N)<<endl;
    // cout<<MaxSubSum_OptimizedBF(List, N)<<endl;
    // cout<<MaxSubSum_DivAndCon(List, N)<<endl;

/************************************************************************/



/************************************Dynamic programming method************************************/
    int i;
    int ThisSum, MaxSum;
    

    for(i=0; i<N; i++){
        cin>>List[i]>>a;
        ThisSum+=List[i];
        if(ThisSum>MaxSum){
            MaxSum=ThisSum;
        }
        else if(ThisSum<0){
            ThisSum=0;
        }
    }
    cout<<MaxSum<<endl;

/************************************************************************/

    return 0;
}

int MaxSubSum_BF(int List[],int N){
    int i , j , k;
    int ThisSum , MaxSum=0;
    for(i=0 ; i<N ; i++){
        for(j=i; j<N; j++){
            ThisSum=0;
            for(k=i; k<=j; k++){
                ThisSum+=List[k];
                if(ThisSum>MaxSum){
                    MaxSum=ThisSum;
                }
            }
        }
    }
    return MaxSum;
}

int MaxSubSum_OptimizedBF(int List[], int N){
    int i, j;
    int ThisSum, MaxSum=0;
    for(i=0; i<N; i++){
        ThisSum=0;
        for(j=i; j<N; j++){
            ThisSum += List[j];
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxIn3(int A, int B, int C){
    return A>B ? A>C ? A : C : B>C ? B : C;
}

int DivideAndConquer(int List[], int left, int right){
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if(left==right){
        if(List[left]>0){
            return List[left];
        }
        else
            return 0;
    }

    center=(left+right)/2;

    MaxLeftSum= DivideAndConquer(List, left, center);
    MaxRightSum= DivideAndConquer(List, center+1, right);

    MaxLeftBorderSum=0, LeftBorderSum=0;
    for(i=center; i>=left; i--){
        LeftBorderSum+=List[i];
        if(LeftBorderSum>MaxLeftBorderSum){
            MaxLeftBorderSum=LeftBorderSum;
        }
    }

    MaxRightBorderSum=0, RightBorderSum=0;
    for (i=center+1;i<=right;i++){
        RightBorderSum+=List[i];
        if(RightBorderSum>MaxRightBorderSum){
            MaxRightBorderSum=RightBorderSum;
        }
    }
    
    return MaxIn3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);

}

int MaxSubSum_DivAndCon(int List[], int N){
    return DivideAndConquer(List, 0, N-1);
}

int MaxSubSum_Dynamic(int List[], int N){
    int i;
    int ThisSum, MaxSum;

    for(i=0; i<N; i++){
        ThisSum+=List[i];
        if(ThisSum>MaxSum){
            MaxSum=ThisSum;
        }
        else if(ThisSum<0){
            ThisSum=0;
        }
    }
    return MaxSum;
}