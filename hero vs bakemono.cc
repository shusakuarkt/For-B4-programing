#include <bits/stdc++.h>
using namespace std;

class character{
public:
  vector<int> attack(vector<string> str,int j,int energy, int sp) ;
  void now(vector<string> str,int hp,int energy);
  void defeat(string a1);
  int spmove(string a1,string a2);
  void charge(string a1, string a2,int energy);
};
vector<int> character::attack(vector<string> str,int j,int energy, int sp){
    std::vector<int> v(3);//damage,energy,spの順で定義
    int use=rand()%10;//ここでだけ使うuse
    while(1){
      if(j%2==1){
        std::cout << str.at(0) << '\n';
        std::cin >>use;
      }
      if(use>50){
        std::cout << str.at(3) << '\n';
      }
      else if(use>energy){
        cout<<str.at(5)<<endl;
      }
      else {
        v.at(0)=use+rand()%50;

          std::cout << str.at(1) << v.at(0)<< str.at(2) << '\n';
          v.at(1) =energy- use;
        v.at(2) =sp+use;
        break;
      }
   }
   return v;
 };
   //攻撃のダメージ計算
void character::now(vector<string> str,int hp,int energy){
  std::cout << str.at(0) <<  hp << str.at(1) <<  energy << str.at(2) <<'\n';
};
  //現在のHPもしくは生存者の数
void character::defeat(string a1){
 std::cout << a1 << '\n';
};
//負け演出
int character::spmove(string a1,string a2){
  int damage;
 std::cout << a1 << '\n';
   damage=500+rand()%300;
 std::cout <<  damage << a2 << '\n';
 return damage;
};
//必殺技
void character::charge(string a1, string a2,int energy){
  std::cout << a1 << '\n';//パワーが切れてしまった！的なやつ
  energy+=10 + rand() % 90;
  std::cout << energy <<a2 << '\n';//パワーが~~に回復した！的なやつ
};
//energyを消費しきった時に貯め直す



class hero:public character{
  public:

  int hp=100 + rand() % 200,
      energy=200 + rand() % 100,
      sp=0,
      damage=0,
      position=0+rand()%6,
      speed=0+rand()%10,
      use=0;

         //セリフ集
   std::vector<string> atstr={
          "どれだけパワーを込める？上限は50",
          "ヒーローは",
          "ダメージ与えた！",
          "そんなに一気にパワーを使えない！",
          "パワーがそんなに残っていない！"
        };

   std::vector<string> nostr={
          "現在のHPは",
          "パワーは",
          "だ。"
        };


  string a1="ヒーローが倒されてしまった！世界は滅びました。",
         a2="ヒーローは必殺技を放った！　　「これで終わりだ！」",
         a3="ダメージあたえた！",
         a4="パワーが少ないので回復します。",
         a5="だけパワーが回復した！";

         //セリフ集終わり
//コンストラクタ(ヒーローのステータス公開)
   hero(){
    std::cout << "ヒーローのHPとパワーは" << hp << "," << energy << "だ。" << '\n';
  }

};


class bakemono:public character{
public:

  int hp=600 + rand() % 400,
      energy=300 + rand() % 300,
      sp=0,
      position=5+rand()%5,
      damage=0,
      speed=rand()%10,
      use=0;


   //セリフ集
std::vector<string> atstr={
    " ",
    "怪獣の攻撃！",
    "ダメージ受けた！",
    " ",
    " "
  };

std::vector<string> nostr={
    " ",
    " ",
    " "
  };


string a1="怪獣が倒された！Congraturations！！",
       a2="怪獣が必殺技を放った！　　「ーーーーーー！！！！！」",
       a3="ダメージ受けた！",
       a4="戦闘中にも関わらず昼寝しだした！",
       a5="だけパワーが回復した！";

   //セリフ集終わり
};
//一般人
// class genoralpeople:public character{
//   amount=100+rand()%100000;
//   hp=5;
//   energy=10;
//   sp=0;
//   position=0;
 // };


//余裕があればターンの動きのメンバ関数
// void turn(bakemono Bakemono,hero Hero, int j){
// }



int main() {
  srand((unsigned int)time(NULL));  //時間による乱数の種の生成
  hero Hero;
  bakemono Bakemono;
  vector<int> v(3);


  int i=1,j=0,k=0;//ターン数,先攻後攻の判別とか諸々
std::cout << "怪獣が現れた！ヒーローを操作して怪獣を倒せ！" << '\n';
if(Hero.speed>Bakemono.speed){
  j=1,k=1;
}

  while (1){
    //Hero.hp<0||Bakemono.hp<0

    if(k)std::cout << i << "ターン目" << '\n';
    //ヒーローの攻撃
    if(j>0){
      if(Hero.energy<10){
        Hero.charge(Hero.a4,Hero.a5,Hero.energy);
      }
      else{
        if (Hero.sp<200){
          v=Hero.attack(Hero.atstr,j,Hero.energy,Hero.sp);
          Bakemono.hp -=v.at(0);
          Hero.energy =v.at(1);
          Hero.sp =v.at(2);
        }
        else{
          Bakemono.hp -=Hero.spmove(Hero.a2,Hero.a3);
          Hero.sp -=200;
        }
        if(Bakemono.hp<0){
          Bakemono.defeat(Bakemono.a1);
          break;
        }
      }
      j++;
    }
        if(k-1)std::cout << i << "ターン目" << '\n';

    //怪獣の攻撃
    Bakemono.use=rand()%10;
    if(Bakemono.energy<10){
      Bakemono.charge(Bakemono.a4,Bakemono.a5,Bakemono.energy);
    }
    else{
      if(Bakemono.sp<30){
          v=Bakemono.attack(Bakemono.atstr,j,Bakemono.energy,Bakemono.sp);
          Hero.hp -=v.at(0);
          Bakemono.energy =v.at(1);
          Bakemono.sp =v.at(2);
        }
        else{
          Hero.hp -=Bakemono.spmove(Bakemono.a2,Bakemono.a3);
          Bakemono.sp -=200;
        }
        Hero.hp -=Bakemono.damage;
        if(Hero.hp<0){
          Hero.defeat(Hero.a1);
          break;
        }
    }
    j++;
    i++;
    Hero.now(Hero.nostr,Hero.hp,Hero.energy);

}
return 0;
}
