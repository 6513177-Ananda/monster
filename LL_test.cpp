#include <iostream>
#include <cstdlib>
#include "NODE.h"
#include "LL.h"
using namespace std;

/*
    *** Please make sure you read the instruction first ***
*/

void game_start(NODE &main_character, LL A, NODE* &boss);

int main(int argc, char *argv[])
{
    LL A;
    int i;
    NODE *t, *boss;
    for(i=1;i<argc;i+=3) 
    {

        t = new NODE(argv[i], atoi(argv[i+1]), atoi(argv[i+2]));
        A.add_node(t);
    }
    boss = new NODE("ULTRA SUPER SAIYAN MEGA ALBAMA BOSS", 400, 0);
    game_start(*t, A, boss);

    
    exit(0);
}

void game_start(NODE &main_character, LL A, NODE* &boss)
{
    int choice;
    string monster;
    int counter = 0;
    while (true)
    {
        counter++;
        if (counter <= 5)
        {
            do
            {
                cout << endl;
                cout << "#################################" << endl;
                cout << "# If you want to attack press 1 #" << endl;
                cout << "# If you want to heal   press 2 #" << endl;
                cout << "# If you want to get hp press 3 #" << endl;
                cout << "# If you want to quit   press 0 #" << endl;
                cout << "############ round " << counter <<" ############" << endl;
                cout << endl;
                cout << "INPUT: ";
                cin >> choice;
                cout << endl;
            } while (choice < 0 && choice > 3);
        }
        else
        {

            do
            {
                cout << endl;
                cout << "#####################################" << endl;
                cout << "# If you want to attack     press 1 #" << endl;
                cout << "# If you want to heal       press 2 #" << endl;
                cout << "# If you want to get hp     press 3 #" << endl;
                cout << "# If you want to attack all press 4 #" << endl;
                cout << "# If you want to quit       press 0 #" << endl;
                cout << "############## round " << counter <<" ##############" << endl;
                cout << endl;
                cout << "INPUT: ";
                cin >> choice;
                cout << endl;
            } while (choice < 0 && choice > 3);

        }

        switch (choice)
        {
        case 1:
            cout << "Who you want to attack" << endl;
            cout << "Monster name: ";
            cin >> monster;
            while (!main_character.attack(monster))
            {
                cout << "There is no monster called: " << monster << endl;
                cout << "Please Enter new monster: ";
                cin >> monster;
            }
            break;
        case 2:
            cout << "Who you want to heal" << endl;
            cout << "Monster name: ";
            cin >> monster;
            while (!main_character.heal(monster))
            {
                cout << "Please Enter new monster: ";
                cin >> monster;
            }
            break;
        case 3:
            A.show_all();
            if (counter != 6) counter--;
            break;
        case 4:
            A.attack_all(boss);
            break;
        case 0:
            return;
        default:
            break;
        }
        if (counter == 5)
        {
            cout << "!!!!!!!! Boss is coming out !!!!!!!!" << endl;
            A.add_node(boss);
            cout << endl;
            A.show_all_dead();
            A.attack_all(boss);
        }

        if (main_character.character_dead())
        {
            cout << "Main character is dead" << endl;
            cout << "!!!!!!You LOSE!!!!!!" << endl;
            cout << "****Time for destructing****" << endl;
            break;
        }

        if (boss->character_dead())
        {
            cout << "Boss is dead" << endl;
            cout << "!!!!!!You WIN!!!!!!" << endl;
            cout << "****Time for destructing****" << endl;
            break;
        }
    }
}
