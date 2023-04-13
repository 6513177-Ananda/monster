#include <iostream>
using namespace std;
#include"NODE.h"

#define atk 40
#define healing 50

enum checking
{
      Error, correct
};

NODE::NODE(string x, int y, int z)
{
      name=x;
      hp = y;
      potion =z;
      next=NULL;
      cout<<"adding "<< x<<endl;
}
NODE:: ~NODE()
{
      cout<<"Node "<<name<<" is being deleted"<<endl;
}
NODE* NODE::move_next()
{
      return next;
}
void  NODE::show_node()
{
      std::string is_dead = hp <= 0 ? "Dead" : "Alive";
      cout << "Node data: "<< name << endl;
      cout << "[\n    hp left " << hp <<endl;
      cout << "    potion left " << potion << endl;
      cout << "    Status: " << is_dead << endl << "]"<< endl;
}

void NODE::show_dead()
{
      if (hp <= 0) cout << "This monster is dead: " << name << endl;
}

void NODE::insert(NODE*& x)
{
     x->next=this;
}

NODE* NODE::find_node(string n) //linear search ** must be init on hol
{
      if (this == NULL) return NULL;
      return n == name ? this : this->next->find_node(n);
}

int NODE::attack(string n)
{
      NODE* mon = find_node(n);
      if (!mon) 
      {
            cout << "Monster Not found" << endl;
            return Error;
      }
      if (mon == this)
      {
            cout << "You can't hit yourself" << endl;
            return Error;
      }
      if (mon->hp <= 0)
      {
            cout << "This Monster is already dead" << endl;
            return Error;
      }
      mon->hp -= atk;
      cout << mon->name << " was attacked by " << name << endl;
      return correct;
}

int NODE::heal(string n)
{
      NODE* mon = find_node(n);
      if (!mon) return Error;
      if (mon->hp <= 0)
      {
            cout << "This monster is already dead" << endl;
            return Error;
      }
      if (mon->potion) mon->hp += healing;
      else
      {
            cout << mon->name << " ran out of potion" << endl;
            return Error;
      }
      mon->potion--;
      return correct;
}

void NODE::attack_boss(NODE* &boss)
{
      if (hp > 0)
      {
            cout << boss->name << " was attacked by " << name << endl;
            boss->hp -= atk;
      }
}

bool NODE::character_dead()
{
      return hp <= 0 ? true : false;
}