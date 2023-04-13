class NODE{
      std::string name;
      int hp, potion;
      NODE* next;
public:
        NODE(std::string, int = 100, int = 1);
        void show_node();
        void insert(NODE*&);
        NODE* move_next();
        NODE* find_node(std::string);
        int attack(std::string);
        int heal(std::string);
        void show_dead();
        void attack_boss(NODE*&);
        bool character_dead();
        ~NODE();
      };
