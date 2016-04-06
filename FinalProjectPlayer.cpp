#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Player
  {
    private:
    //accountclass
    //shopclass
    //clockclass
    int petnumber;
    std::string username;
    public:
      class pet
        {
        private:
            int hungerlevel;
            int happinesslevel;
            std::string petname;
            int pettype;
            //stringpetcolor
            //string accessory??????(not sure how to use this yet)
        public:
            pet();
            int gethunger();
            void sethunger(int hungerlevel);
            std::string getpetname();
            void setpetname(std::string petname);
            void setpettype(int petnumber);
            int getpettype();
            int gethappinesslevel();
            void sethappinesslevel(int happinesslevel);
            //void getpetcolor();
            //void setpetcolor()
            //void getstudyreward();
            //~pet();
        };
      Player();
      void setusername(std::string username);
      std::string getusername();
      void setpetnumber(int petnumber);
      int getpetnumer();
      pet* createpet();
      pet* loadpet(std::string petnumber,int pettype);
      //~Player()
    };
//Player and pet
  Player::pet::pet()
    {
      hungerlevel = 70;
      happinesslevel = 70;
      petname = "";
      pettype = 0;
    }
  int Player::pet::gethunger()
    {
        return hungerlevel;
    }
  void Player::pet::sethunger(int hungerlevel)
    {
      this->hungerlevel = hungerlevel;
    }
  std::string Player::pet::getpetname()
    {
        return petname;
    }
  void Player::pet::setpetname(std::string petname)
    {
        this->petname=petname;
    }
  void Player::pet::setpettype(int pettype)
      {
        this->pettype = pettype;
      }
    int Player::pet::getpettype()
      {
        return pettype;
      }
  void Player::pet::sethappinesslevel(int happinesslevel)
    {
      this->happinesslevel = happinesslevel;
    }
  int Player::pet::gethappinesslevel()
    {
      return happinesslevel;
    }
  //Player only
  Player::Player()
    {
      petnumber = 0;
      username = "";
    }
  //Sets the username
  void Player::setusername(std::string username)
    {
      this->username = username;
    }
  //returns the players username
  std::string Player::getusername()
    {
      return username;
    }

  void Player::setpetnumber(int petnumber)
    {
        this->petnumber = petnumber;
    }

  int Player::getpetnumer()
    {
      return petnumber;
    }

  Player::pet* Player::createpet()
    {
      pet * pp = new pet;
      petnumber++;
      std::cout << "Making a pet is really easy! We just need to ask you a few questions!!!" << std::endl;
      std::cout << "Question 1: What is your pets name?" << std::endl;
      std::string petname;
      std::cin >> petname;
      pp->setpetname(petname);
      std::cout << "Question 2: What type of pet do you want?" << std::endl;
      std::cout << "Please enter an int 1-10" << std::endl;
      int i = 0;
      std::cin >> i;
      pp->setpettype(i);
      std::cout << "Your pets name is "<< pp->getpetname() << "and it is type " << pp->getpettype() << std::endl;
      return pp;
    }
  Player::pet* Player::loadpet(std::string petname, int pettype)
    {
      pet * pp = new pet;
      pp->setpetname(petname);
      pp->setpettype(pettype);
      return pp;
    }
//Turns strings into ints This is very helpful for loading players data
  int stringtoint(std::string a)
    {
      int b = 0;
      int c = 0;
      for(int i = 0; i < a.size(); i++)
        {
          b = a[i]-'0';
          c += b;
          if(i<(a.size()-1))
          {
            c = (c*10);
          }
        }
        return c;
      }
//menus are below

  Player* loadplayer(std::vector<std::string> userdata)
    {
      Player * returninguser = new Player;
      returninguser->setusername(userdata[0]);
      returninguser->setpetnumber(stringtoint(userdata[1]));
      if(returninguser->getpetnumer()==1)
        {
          std::cout << "Welcome back you have one pet" << std::endl;
        }
      return returninguser;
    }
//The 4 different exit the games based on the amount of pets the player has
  void exitthegame(Player * user)
    {
      std::ofstream userinfo;
      std::string i = user->getusername();
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << user->getusername();
      userinfo<< "\n";
      userinfo<< user->getpetnumer();
      userinfo.close();
    }

  void exitthegame(Player * user, Player::pet * a)
    {
      std::ofstream userinfo;
      std::string i = user->getusername();
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << user->getusername();
      userinfo<< "\n";
      userinfo<< user->getpetnumer();
      userinfo<<"\n";
      userinfo<< a->getpetname();
      userinfo<<"\n";
      userinfo<< a->getpettype();
      userinfo.close();
    }

  void exitthegame(Player * user, Player::pet * a, Player::pet * b)
    {
      std::ofstream userinfo;
      std::string i = user->getusername();
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << user->getusername();
      userinfo<< "\n";
      userinfo<< user->getpetnumer();
      userinfo<<"\n";
      userinfo<< a->getpetname();
      userinfo<<"\n";
      userinfo<< a->getpettype();
      userinfo<<"\n";
      userinfo<< b->getpetname();
      userinfo<<"\n";
      userinfo<<b->getpettype();
      userinfo.close();
    }

  void exitthegame(Player * user, Player::pet * a, Player::pet * b, Player::pet *c)
    {
      std::ofstream userinfo;
      std::string i = user->getusername();
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << user->getusername();
      userinfo<< "\n";
      userinfo<< user->getpetnumer();
      userinfo<<"\n";
      userinfo<< a->getpetname();
      userinfo<<"\n";
      userinfo<< a->getpettype();
      userinfo<<"\n";
      userinfo<< b->getpetname();
      userinfo<<"\n";
      userinfo<<b->getpettype();
      userinfo<<"\n";
      userinfo<<c->getpetname();
      userinfo<<"\n";
      userinfo<<c->getpettype();
      userinfo.close();
    }

//the different control menus based off of how many pets are being player
  void controlmenucouts()
    {
      std::cout << "What would you like to do?" << std::endl;
      std::cout << "1. Create a pet" << std::endl;
      std::cout << "2. Set a timer" << std::endl;
      std::cout << "3. Go to the shop" << std::endl;
      std::cout << "4. View your pet stats" << std::endl;
      std::cout << "5. Go to your bank account" << std::endl;
      std::cout << "6. Exit the game" << std::endl;
    }

  void controlmenu(Player * user, Player::pet *a, Player::pet *b, Player::pet *c)
    {
      controlmenucouts();
      int selection = 0;
      std::cin >> selection;
      if(selection == 1)
        {
          std::cout << "Sorry, you cannot make more that 3 pets" << std::endl;
        }
      else if(selection == 2)
        {
          std::cout << "Set a time" << std::endl;
        }
      else if(selection == 3)
        {
          std::cout << "Go to the shop" << std::endl;
        }
      else if(selection == 4)
        {
          std::cout << "View Pet Stats" << std::endl;
          //need to create a pet stat view
        }
      else if(selection == 5)
        {
          std::cout << "View Your Bank Account" << std::endl;
        }
      else if(selection == 6)
        {
          std::cout << "Exit the game" << std::endl;
          exitthegame(user,a,b,c);
        }
      else
        {
          std::cout << "That is not a valid command" << std::endl;
        }
    }

  void controlmenu(Player * user, Player::pet *a, Player::pet *b)
    {
      controlmenucouts();
      int selection = 0;
      std::cin >> selection;
      if(selection == 1)
        {
          std::cout << "Create a pet" << std::endl;
          Player::pet *c = user->createpet();
          controlmenu(user,a,b,c);
        }
      else if(selection == 2)
        {
          std::cout << "Set a time" << std::endl;
        }
      else if(selection == 3)
        {
          std::cout << "Go to the shop" << std::endl;
        }
      else if(selection == 4)
        {
          std::cout << "View Pet Stats" << std::endl;
        }
      else if(selection == 5)
        {
          std::cout << "View Your Bank Account" << std::endl;
        }
      else if(selection == 6)
        {
          std::cout << "Exit the game" << std::endl;
          exitthegame(user,a,b);
        }
      else
        {
          std::cout << "That is not a valid command" << std::endl;
        }
    }

  void controlmenu(Player * user, Player::pet *a)
    {
      controlmenucouts();
      int selection = 0;
      std::cin >> selection;
      if(selection == 1)
        {
          std::cout << "Create a pet" << std::endl;
              Player::pet *b = user->createpet();
              controlmenu(user,a,b);
        }
      else if(selection == 2)
        {
          std::cout << "Set a time" << std::endl;
        }
      else if(selection == 3)
        {
          std::cout << "Go to the shop" << std::endl;
        }
      else if(selection == 4)
        {
          std::cout << "View Pet Stats" << std::endl;
          //need to create a pet stat view
        }
      else if(selection == 5)
        {
          std::cout << "View Your Bank Account" << std::endl;
        }
      else if(selection == 6)
        {
          std::cout << "Exit the game" << std::endl;
          exitthegame(user,a);
        }
      else
        {
          std::cout << "That is not a valid command" << std::endl;
        }
    }

  void startmenu(Player * returninguser,std::vector<std::string> userdata)
    {

      std::cout << "Welcome back " << returninguser->getusername() << std::endl;
      std::cout << "You have " << returninguser->getpetnumer()<<" pets" << std::endl;
      if(returninguser->getpetnumer()==0)
        {
          Player::pet* p = returninguser->createpet();
          exitthegame(returninguser, p);
        }
      else if(returninguser->getpetnumer()==1)
        {
          Player::pet* p = returninguser->loadpet(userdata[2],stringtoint(userdata[3]));
          std::cout << "You already have one pet" << std::endl;
          std::cout << "as I recall their name is " << p->getpetname() << std::endl;
          controlmenu(returninguser,p);
        }
      else if(returninguser->getpetnumer()==2)
        {
          Player::pet*a = returninguser->loadpet(userdata[2],stringtoint(userdata[3]));
          Player::pet*b = returninguser->loadpet(userdata[4],stringtoint(userdata[5]));
          std::cout << "their names are " << a->getpetname() << " and " << b->getpetname() << std::endl;
          controlmenu(returninguser,a,b);
        }
      else if(returninguser->getpetnumer()==3)
        {
           Player::pet*a = returninguser->loadpet(userdata[2],stringtoint(userdata[3]));
           Player::pet*b = returninguser->loadpet(userdata[4],stringtoint(userdata[5]));
           Player::pet*c = returninguser->loadpet(userdata[6],stringtoint(userdata[7]));
           std::cout << "You have 3 pets. Their names are " << a->getpetname() << " ," << b->getpetname() << " , and " << c->getpetname() << std::endl;
           std::cout << "They are types" << a->getpettype() << b->getpettype() << c->getpettype()<< std::endl;
        }
    }

  void newplayermenu(Player * p)
    {
      std::cout << "First please enter your username" << std::endl;
      std::string i;
      std::cin >> i;
      p->setusername(i);
      std::cout << "Your username is " << p->getusername()<< std::endl;
      std::ofstream userinfo;
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << p->getusername();
      userinfo<< "\n";
      userinfo<< p->getpetnumer();
      userinfo.close();
      std::cout << "A text file has been made containing your username and data" << std::endl;
      std::cout << "For your virtual pet to work DO NOT EDIT this file" << std::endl;
      std::cout << "The program will now close and you can recompile with your account information" << std::endl;

    }

  int main(int argc, char** argv)
    {
      if(argc<=1)
      {
        std::cout << "Hello and welcome to your pet adventure!" << std::endl;
        std::cout << "We see you tried to complie without a text file. Press one if you are a new player" << std::endl;
        int i = 0;
        std::cin >> i;
        if(i == 1)
        {
          std::cout << "Welcome!" << std::endl;
          Player *p = new Player;
          newplayermenu(p);
        }
        else
        {
          std::cout << "Not a new player? Hmm... Then try entering your .txt file name again" << std::endl;
        }
      }
      else
        {
          std::vector<std::string> userdata;
          std::ifstream userfile;
          std::string line;
          userfile.open(argv[1]);
          if(userfile.is_open())
          {
            while(!userfile.eof())
              {
                std::getline(userfile,line);
                std::cout << line << std::endl;
                userdata.push_back(line);
              }
            Player * returnplayer = loadplayer(userdata);
            startmenu(returnplayer, userdata);
          }
        else
          {
            std::cout << "We couldn't find that username, please try again" << std::endl;
          }
        }
    }
