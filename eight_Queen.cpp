#include <stdlib.h>
#include <stdio.h>

static final int MAX_NUM = 8;
int chessBoard[][] = new int[MAX_NUM][MAX_NUM];

//判断落点是否符合规范
boolean check(int x, int y)
{
  for(int i = 0; i < y; i++)
  {
    //检查纵向
    if(chessBoard[x][i] == 1)
    {
      return false;
    }

    //检查左侧倾斜 x-1,y-1就是x,y的左斜上方一个
    if(x-1-i >= 0 && chessBoard[x-1-i][y-1-i] == 1)
    {
      return false;
    }

    //检查左侧倾斜 x+1,y+1就是x,y的右斜上方一个
    if(x+1+i >= 0 && chessBoard[x+1+i][y+1+i] == 1)
    {
      return false;
    }
  }
  return true;
}


//递归回溯
boolean settleQueen(int y){
  //行数超过最大则已经找出答案
  if(y == MAX_NUM){
    return true;
  }

  //遍历当前行，逐一格子验证
  for(int i = 0; i < MAX_NUM; i++)
  {
    //把当前行全部置0，防止回溯的时候有脏数据
    for(int j = 0; j < MAX_NUM; j++)
    {
      chessBoard[i][j] == 0;
    }
    //检查落点是否符合，如果符合将落点置为1，并且继续下一轮递归
    if(check(i,y))
    {
      chessBoard[i][y] == 1;
      //如果下一层返回true那么就已经找到解法，无需再循环
      if(settleQueen[y+1])
      {
        return true;
      }
    }
  }
  return false;
}


//打印结果
void printChessBoard()
{
  for(int i = 0; i < MAX_NUM; i++)
  {
    for(int j = 0; j < MAX_NUM; j++)
    {
      cout<<chessBoard[i][j];
    }
    cout<<"\n";
  }
}





// int m[8][8] = {0};//表示棋盘，初始为0，表示未放置皇后
// int num = 0;//解数目
//
// //对于棋盘前row-1行已放置好皇后
// //检查在第row行、第column列放置一枚皇后是否可行
// bool check(int row,int column)
// {
//     if(row==1) return true;
//     int i,j;
//     //纵向只能有一枚皇后
//     for(i=0;i<=row-2;i++)
//     {
//         if(m[i][column-1]==1) return false;
//     }
//     //左上至右下只能有一枚皇后
//     i = row-2;
//     j = i-(row-column);
//     while(i>=0&&j>=0)
//     {
//         if(m[i][j]==1) return false;
//         i--;
//         j--;
//     }
//     //右上至左下只能有一枚皇后
//     i = row-2;
//     j = row+column-i-2;
//     while(i>=0&&j<=7)
//     {
//         if(m[i][j]==1) return false;
//         i--;
//         j++;
//     }
//     return true;
// }
//
// //当已放置8枚皇后，为可行解时，输出棋盘
// void output()
// {
//     int i,j;
//     num++;
//     printf("answer %d:\n",num);
//     for(i=0;i<8;i++)
//     {
//         for(j=0;j<8;j++) printf("%d ",m[i][j]);
//         printf("\n");
//     }
// }
//
// //采用递归函数实现八皇后回溯算法
// //该函数求解当棋盘前row-1行已放置好皇后，在第row行放置皇后
// void solve(int row)
// {
//     int j;
//     //考虑在第row行的各列放置皇后
//     for (j=0;j<8;j++)
//     {
//         //在其中一列放置皇后
//         m[row-1][j] = 1;
//         //检查在该列放置皇后是否可行
//         if (check(row,j+1)==true)
//         {
//             //若该列可放置皇后，且该列为最后一列，则找到一可行解，输出
//             if(row==8) output();
//             //若该列可放置皇后，则向下一行，继续搜索、求解
//             else solve(row+1);
//         }
//         //取出该列的皇后，进行回溯，在其他列放置皇后
//         m[row-1][j] = 0;
//     }
// }
//
// //主函数
// int main()
// {
//     //求解八皇后问题
//     solve(1);
//     return 0;
// }
