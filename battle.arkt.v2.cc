#include <bits/stdc++.h>
using namespace std;

class character{
private:
  int HP,Energy,SP,SPEED;
public:
  void sethp(int hp);
  void setenergy(int energy);
  void setsp(int sp);
  void setspeed(int speed);
  int gethp();
  int getenergy();
  int getsp();
  int getspeed();
  void dhp(int dhp);//differ hp
  void denergy(int denergy);
  void dsp(int dsp);
  void initialize(int hp,int energy,int sp,int speed);

};
  void character::sethp(int hp){
    HP=hp;
  };
  void character::setenergy(int energy){
    Energy=energy;
  };
  void character::setsp(int sp){
    SP=sp;
  };
  void character::setspeed(int speed){
    SPEED=speed;
  };
  int character::gethp(){
    return HP;
  };
  int character::getenergy(){
    return Energy;
  };
  int character::getsp(){
    return SP;
  };
  int character::getspeed(){
    return SPEED;
  };
  void character::dhp(int dhp){
    HP -=dhp;
  };
  void character::denergy(int denergy){
    Energy -=denergy;
  };
  void character::dsp(int dsp){
    SP += dsp;
  };
  void character::initialize(int hp,int energy,int sp,int speed){
    sethp(hp);
    setenergy(energy);
    setsp(sp);
    setspeed(speed);
  };

  //使う関数
  void attack(character *c,character *ctarget){
    int use=rand()%10;//使うenergy
    int damage=0;
    while(1){
      if(j%2==1){
        std::cout << c->atstr.at(0) << '\n';
        std::cin >>use;
      }
      if(use>50){
        std::cout << c->atstr.at(3) << '\n';
      }
      else if(use>energy){
        cout<<c->atstr.at(4)<<endl;
      }

      else {
        damage=use+rand()%50;
          std::cout << c->atstr.at(1) << damage<< c->atstr.at(2) << '\n';
        break;
      }
   }
   ctarget->dhp(damage);
   c->denergy(use);
   c->dsp(use);
 };
   //攻撃のダメージ計算
  void now(character *c){
  std::cout << c->nostr.at(0) <<  c->gethp() << c->nostr.at(1) <<  c->getenergy() << c->nostr.at(2) <<'\n';
};
   //現在のHPもしくは生存者の数
  void defeat(character *c){
 std::cout << c->a1 << '\n';
};
   //負け演出
  void spmove(character *c,character *ctarget){
  int damage;
  std::cout << c->a2 << '\n';
  damage=500+rand()%300;
  ctarget->dhp(damage);
  std::cout <<  damage << c->a3 << '\n';
  c->dsp(200);
};
   //必殺技
  void charge(character *c){
  std::cout << c->a4 << '\n';//パワーが切れてしまった！的なやつ
  c->denergy(10 + rand() % 90);
  std::cout << c->getenergy() << c-> a5 << '\n';//パワーが~~に回復した！的なやつ
};
   //energyを消費しきった時に貯め直す



class hero:public character{
private:

  int hp=100 + rand() % 200,
      energy=200 + rand() % 100,
      sp=0,
      speed=0+rand()%10,

public:
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
    initialize(hp,energy,sp,speed);
  }

};


class bakemono:public character{
private:

  int hp=600 + rand() % 400,
      energy=300 + rand() % 300,
      sp=0,
      speed=rand()%10;

public:
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
   bakemono(){
     initialize(hp,energy,sp,speed);
  }

};



int main() {
  srand((unsigned int)time(NULL));  //時間による乱数の種の生成
  hero *Hero = new hero();
  bakemono *Bakemono = new bakemono();

  int i=1,j=0,k=0;//ターン数,先攻後攻の判別とか諸々
std::cout << "怪獣が現れた！ヒーローを操作して怪獣を倒せ！" << '\n';
if(Hero->getspeed()>Bakemono->getspeed()){
  j=1,k=1;
}

  while (1){
    if(k)std::cout << i << "ターン目" << '\n';
    //ヒーローの攻撃
    if(j>0){
      if(Hero->getenergy()<10){
        charge(Hero);
      }
      else{
        if (Hero->getsp()<200){
          attack(Hero,Bakemono);
        }
        else{
          spmove(Hero,Bakemono);
        }
        if(Bakemono->gethp()<=0){
          defeat(Bakemono);
          break;
        }
      }
      j++;
    }
        if(k-1)std::cout << i << "ターン目" << '\n';

    //怪獣の攻撃
    if(Bakemono->getenergy()<10){
      charge(Bakemono);
    }
    else{
      if(Bakemono->getsp()<30){
          attack(Bakemono,Hero);
        }
        else{
          spmove(Bakemono,Hero);
        }
        if(Hero->gethp()<=0){
          defeat(Hero);
          break;
        }
    }
    j++;
    i++;
    now(Hero);

}
return 0;
}
