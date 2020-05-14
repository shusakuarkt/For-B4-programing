#include <bits/stdc++.h>
using namespace std;


int main() {
  int mine,enemy,rare;
  while(1){
    srand((unsigned int)time(NULL));  //時間による乱数の種の生成
    enemy=rand()%3;
    rare=rand()%100;
    while(1){
      std::cout << "じゃんけんします！何を出す？" << '\n';
      std::cout << "0.グー：1．パー：2．チョキ" << '\n';
      std::cin >> mine;
      if (mine==0||mine==1||mine==2) {
        break;
      }
      else{
        std::cout << "0,1,2から選んでください！" << '\n';
      }
    }
    switch (enemy) {
      case 0:
        std::cout << "相手はグーを繰り出した！" << '\n';
        break;
      case 1:
        std::cout << "相手はパーを繰り出した！" << '\n';
        break;
      case 2:
        std::cout << "相手はチョキを繰り出した！" << '\n';
        break;
    }
    if(rare<50){
      enemy=(mine+1)%3;
      std::cout << "相手：「まあ僕が負けるわけないんですけどね？」" << '\n';
    }
    else if(rare==60){
      mine=(enemy+1)%3;
      std::cout << "相手：「ちょっと待て殴り合いで解決しようとするんじゃあない！」" << '\n';
    }
    if(mine==enemy){
      std::cout << "あいこだった！" << '\n';
    }
    else if((mine+2)%3==enemy){
      std::cout << "You win!!" << '\n';
      break;
    }
    else if((enemy+2)%3==mine){
      std::cout << "You lose!!" << '\n';
      std::cout << "相手：「俺の勝ち！なんで負けたか次までに考えといてください。」" << '\n';
      break;
    }
  }
  return 0;
}
