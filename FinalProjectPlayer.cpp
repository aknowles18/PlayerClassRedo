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
            std::string color;
            int pettype;
            //string pettype
            //stringpetcolor
            //string accessory??????(not sure how to use this yet)
        public:
            pet();
            int gethunger();
            std::string getpetname();
            void setpetname(std::string petname);
            void setpettype(int petnumber);
            int getpettype();
            //void getpetcolor();
            //void setpetcolor()
            //void getstudyreward();
            //void getaccessory();
            //void setaccesory();
            //~pet();
        };
      Player();
      void setusername(std::string username);
      std::string getusername();
      void setpetnumber(int petnumber);
      int getpetnumer();
      pet* createpet();
      pet* loadpet(std::string a);
      //~Player()
    };
//Player and pet
  int Player::pet::gethunger()
    {
      return hungerlevel;
    }
  Player::pet::pet()
    {
      hungerlevel = 100;
      petname = "";
      color = "";
      pettype = 0;
      //personalitytype = "";
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
  Player::pet* Player::loadpet(std::string a)
    {
      pet * pp = new pet;
      pp->setpetname(a);
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
          Player::pet* p = returninguser->loadpet(userdata[2]);
          std::cout << "You already have one pet" << std::endl;
          std::cout << "as I recall their name is " << p->getpetname() << std::endl;
          exitthegame(returninguser, p);

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
        }
    }
