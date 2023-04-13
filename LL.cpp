#include <iostream>
#include"NODE.h"
#include"LL.h"
using namespace std;
LL::LL(){
       hol=NULL;
       size=0;
}

LL::~LL(){
     NODE* t = hol;
     NODE* tmp = t;
     int i;
     for(i=0;i<size;i++)
     {   
          tmp = t;
          t = t->move_next();
          delete tmp;
     }
          //clear all nodes
}

void LL::show_all(){
     NODE* t=hol;
     int i;
     for(i=0;i<size;i++)
     {
          t->show_node();
          t = t->move_next();
     }
}
void LL::add_node(NODE *&A)
{
     hol->insert(A);
     hol=A;
     size++;
}

void LL::show_all_dead()
{
     NODE* t=hol;
     int i;
     for(i=0;i<size;i++)
     {
          t->show_dead();
          t = t->move_next();
     }
}


void LL::attack_all(NODE* &boss)
{
     NODE* t=hol;
     int i;
     for(i=0;i<size-1;i++)
     {
          if (t == boss)
          {
               t = t->move_next();
               continue;
          }
          t->attack_boss(boss);
          t = t->move_next();
     }

}