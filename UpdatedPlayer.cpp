#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Pet
  {
  private:
      int hungerlevel;
      int happinesslevel;
      std::string petname;
      int pettype;
      //stringpetcolor
      //string accessory??????(not sure how to use this yet)
  public:
      Pet();
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
  Pet::Pet()
    {
      hungerlevel = 70;
      happinesslevel = 70;
      petname = "";
      pettype = 0;
    }
  int Pet::gethunger()
    {
        return hungerlevel;
    }
  void Pet::sethunger(int hungerlevel)
    {
      this->hungerlevel = hungerlevel;
    }
  std::string Pet::getpetname()
    {
        return petname;
    }
  void Pet::setpetname(std::string petname)
    {
        this->petname=petname;
    }
  void Pet::setpettype(int pettype)
      {
        this->pettype = pettype;
      }
    int Pet::getpettype()
      {
        return pettype;
      }
  void Pet::sethappinesslevel(int happinesslevel)
    {
      this->happinesslevel = happinesslevel;
    }
  int Pet::gethappinesslevel()
    {
      return happinesslevel;
    }

class Player
  {
    private:
    //accountclass
    //clockclass
    int petnumber;
    std::string username;
    public:
      Player();
      void setusername(std::string username);
      std::string getusername();
      void setpetnumber(int petnumber);
      int getpetnumer();
      void createpet();
      void loadpet(std::string petnumber,int pettype);
      std::vector<Pet*> pets;
      //~Player()
    };

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

      void Player::createpet()
      {
        Pet* pp = new Pet;
        petnumber+=1;

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
        pets.push_back(pp);
      }
    void Player::loadpet(std::string petname, int pettype)
      {
        Pet * pp = new Pet;
        pp->setpetname(petname);
        pp->setpettype(pettype);
        pets.push_back(pp);
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
      if(user->getpetnumer()>0)
      {
      userinfo<<"\n";
      userinfo<< user->pets[0]->getpetname();
      userinfo<<"\n";
      userinfo<< user->pets[0]->getpettype();
      }
      if(user->getpetnumer()>1)
      {
      userinfo<<"\n";
      userinfo<< user->pets[1]->getpetname();
      userinfo<<"\n";
      userinfo<< user->pets[1]->getpettype();
      }
      if(user->getpetnumer()>2)
      {
      userinfo<<"\n";
      userinfo<<user->pets[2]->getpetname();
      userinfo<<"\n";
      userinfo<<user->pets[2]->getpettype();
      }

      userinfo.close();
    }

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

    void controlmenu(Player * user)
      {
        controlmenucouts();
        int selection = 0;
        std::cin >> selection;
        if(selection == 1)
          {
            if(user->getpetnumer()==3)
            {
            std::cout << "Sorry, you cannot make more that 3 pets" << std::endl;
            }
            else
            {
              user->createpet();
            }
            controlmenu(user);
          }
        else if(selection == 2)
          {
            std::cout << "Set a time" << std::endl;
            controlmenu(user);
          }
        else if(selection == 3)
          {
            std::cout << "Go to the shop" << std::endl;
            controlmenu(user);
          }
        else if(selection == 4)
          {
            std::cout << "View Pet Stats" << std::endl;
            controlmenu(user);
            //need to create a pet stat view
          }
        else if(selection == 5)
          {
            std::cout << "View Your Bank Account" << std::endl;
            controlmenu(user);
          }
        else if(selection == 6)
          {
            std::cout << "Exit the game" << std::endl;
            exitthegame(user);
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
            returninguser->createpet();
            exitthegame(returninguser);
          }
        else if(returninguser->getpetnumer()==1)
          {
            returninguser->loadpet(userdata[2],stringtoint(userdata[3]));
            std::cout << "You already have one pet" << std::endl;
            std::cout << "as I recall their name is " << returninguser->pets[0]->getpetname() << std::endl;
            controlmenu(returninguser);
          }
        else if(returninguser->getpetnumer()==2)
          {
            returninguser->loadpet(userdata[2],stringtoint(userdata[3]));
            returninguser->loadpet(userdata[4],stringtoint(userdata[5]));
            std::cout << "their names are " << returninguser->pets[0]->getpetname() << " and " << returninguser->pets[1]->getpetname() << std::endl;
            controlmenu(returninguser);
          }
        else if(returninguser->getpetnumer()==3)
          {
             returninguser->loadpet(userdata[2],stringtoint(userdata[3]));
             returninguser->loadpet(userdata[4],stringtoint(userdata[5]));
             returninguser->loadpet(userdata[6],stringtoint(userdata[7]));
             std::cout << "You have 3 pets. Their names are " << returninguser->pets[0]->getpetname() << " ," << returninguser->pets[1]->getpetname() << " , and " << returninguser->pets[2]->getpetname() << std::endl;
             std::cout << "They are types" << returninguser->pets[0]->getpettype() << returninguser->pets[1]->getpettype() << returninguser->pets[2]->getpettype()<< std::endl;
             controlmenu(returninguser);
          }
      }

  void newplayermenu()
    {
      //Set one create the instance of the player class
      Player * p = new Player;
      //Now they enter their username
      std::cout << "First please enter your username" << std::endl;
      std::string i;
      std::cin >> i;
      //now set the username they enters
      p->setusername(i);
      std::cout << "Your username is " << p->getusername()<< std::endl;
      //this code below is what creates the textfile
      std::ofstream userinfo;
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << p->getusername();
      userinfo<< "\n";
      userinfo<< p->getpetnumer();
      userinfo.close();
      //random couts
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
        //all of this is new player stuff
        if(i == 1)
        {
          std::cout << "Welcome!" << std::endl;
          newplayermenu();
        }
        //byron you probably won't need this
        else
        {
          std::cout << "Not a new player? Hmm... Then try entering your .txt file name again" << std::endl;
        }
      }
      else
        {
          //this is how I grab the user data everytime this log in
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
            //then you have to remake the player using the code below
            Player * returnplayer = loadplayer(userdata);
            //now load up the menu to generate the pets
            startmenu(returnplayer, userdata);
          }
        else
          {
            std::cout << "We couldn't find that username, please try again" << std::endl;
          }
        }
      return 0;
    }
