#include <bits/stdc++.h>
using namespace std;


int main() {
  int A,B,rare;
  double Awincount;
  std::cout << "A君とB君がじゃんけんします。A君の勝率を見ていきます" << '\n';
  srand((unsigned int)time(NULL));  //時間による乱数の種の生成

  for(int i=0;i<100000;i++){
    A=rand()%3;
    B=rand()%3;
    rare=rand()%100;
    if(A==B){
      // std::cout << "あいこだった！" << '\n';
    }
    else if((A+2)%3==B){
      // std::cout << "A win!!" << '\n';
      Awincount++;
    }
    else if((B+2)%3==A){
      // std::cout << "B win!!" << '\n';
    }
    if(i%11111==0){
      std::cout << "A君の勝率は" << Awincount/(i+1.0) << '\n';
    }
  }
  return 0;
}
