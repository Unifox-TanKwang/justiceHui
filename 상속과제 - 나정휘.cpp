#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace isA{ //isA, 단일 상속 
	class Shape{
		protected:
			bool map[100][100];
			int angle;
			void print(){
				for(int i=0; i<100; i++){
					for(int j=0; j<100; j++){
						if(map[i][j]) cout << "*";
						else cout << " ";
					}
					cout << "\n";
				}
			}
		public:
			Shape(){
				memset(map, 0, sizeof(map));
			}
			virtual void draw() = 0;
	}; 
	
	class Square : public Shape{
		public:
			Square(){
				angle = 4;
			}
			void draw(){
				for(int i=0; i<100; i++){
					if(i==0 || i==99){
						for(int j=0; j<100; j++) map[i][j] = true;
					}else{
						map[i][0] = map[i][99] = true;
					}
				}
				print();
			}
	};
	
	class Triangle : public Shape{ 
		public:
			Triangle(){
				angle = 3;
			}
		void draw(){
			for(int i=0; i<100; i++){
				map[i][0] = true;
				map[i][i] = true;
				map[99][i] = true;
			}
			print();
		}
	};
}

namespace hasA{ //hasA, 다중 상속 
	class K2{
		private:
			string name;
			int price;
			int MOA;
			int cnt = 0;
		
		public:
			K2(){
				name = "K2";
				price = 650000;
				MOA = 3;
				cnt = 0;
			}
			
		protected:	
			void bang(){
				if(cnt <= 3) cout << "Bang ";
				else cout << "빵야 ";
				if(cnt == 6) cout << "\n";
				cnt++;
				if(cnt > 6) cnt = 0;
			}
	};
	
	class Contactor{
		protected:
			void send(string str){
				cout << str << "\n";
			}
	};
	
	class ROKA : public K2, public Contactor{
		public:
			void shooting(){ bang(); }
			void say(string str){ send(str); }
	};
}

namespace triple{ //삼중 
	class StarCraftObject{
		protected:
			int hp;
			int def;
			string race;
		public:
			StarCraftObject(int _hp, int _def, string _race){
				hp = _hp;
				def = _def;
				race = _race;
			}
			StarCraftObject(){
				hp = def = 0;
				race = "";
			}
	};
	
	class Unit : public StarCraftObject{
		protected:
			int atk;
		public:
			Unit(int _hp, int _atk, int _def, string _race){
				hp = _hp;
				atk = _atk;
				def = _def;
				race = _race;
			}
			Unit(){
				hp = atk = def = 0;
				race = "";
			}
	};
	
	class Marine : public Unit{
		private:
			string role;
			string weapon;
		public:
			Marine(){
				hp = 40;
				atk = 6;
				def = 0;
				race = "Terran";
				role = "Armored Infantry Trooper";
				weapon = "8mm C-14 가우스 관통 소총";
				srand(time(NULL));
			}
			
			void shoot(){
				string arr[] = {
					"Go go go!",
					"Let's move!",
					"Outstanding!",
					"Rock & Roll!",
					"Ah! That's the stuff!"
				};
				cout << arr[rand()%5] << "\n";
			}
	};
}

int main(){
	isA::Square sq;
	sq.draw();
	isA::Triangle tri;
	tri.draw();
	
	hasA::ROKA p;
	p.shooting(); p.shooting(); p.shooting(); p.shooting(); p.shooting(); p.shooting();
	p.say("Hello World!");
	
	triple::Marine m;
	m.shoot();
  
  return 0;
}
