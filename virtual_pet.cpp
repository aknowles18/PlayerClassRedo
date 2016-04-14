#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

class Bank_Account
  {
  private:
    int tokennumber;
  public:
    Bank_Account();
    //~Bank_Account();        //won't let inheritance work for Shop class
    int getNumTokens();
    void setNumTokens(int newNumTokens);
    void addNumTokens(int newNumTokens);
    bool enoughTokens(int numNeeded);
    void subtractNumTokens(int numNeeded);
  };

Bank_Account::Bank_Account()
  {
    tokennumber = 200;
  }

int Bank_Account::getNumTokens()
  {
    //std::cout << "You have " << tokennumber << " tokens!" <<  std::endl;
    return tokennumber;
  }

void Bank_Account::setNumTokens(int newNumTokens)
  {
    tokennumber = newNumTokens;
    std::cout << "Your bank account now has " << newNumTokens << " tokens!" << std::endl;
  }

void Bank_Account::addNumTokens(int newNumTokens)
  {
    tokennumber+=newNumTokens;
  }

bool Bank_Account::enoughTokens(int numNeeded)
  {

    if(tokennumber >= numNeeded)
    {
      std::cout << "Purchase successful!" << std::endl;
      std::cout << "You current have " << (tokennumber-numNeeded) << " tokens left!" << std::endl;
      return true;
    }
    else
    {
      std::cout << "Purchase unsuccessful! You do not have enough tokens!" << std::endl;
      std::cout << "To make this purchase you need " << (-1)*(tokennumber-numNeeded) << " more tokens!" << std::endl;
      return false;
    }
  }

void Bank_Account::subtractNumTokens(int numNeeded)
  {
    tokennumber = tokennumber-numNeeded;
  }

class Pet
  {
  private:
      int hungerlevel;
      int happinesslevel;
      std::string petname;
      int pettype;
      std::string personalitytype;
      //stringpetcolor
      //string accessory??????(not sure how to use this yet)
  public: //sweetie
      Pet();
      int gethunger();
      void sethunger(int hungerlevel);
      std::string getpetname();
      void setpetname(std::string petname);
      void setpettype(int petnumber);
      int getpettype();
      int gethappinesslevel();
      void sethappinesslevel(int happinesslevel);
      void addhappinesslevel(int happylevel);
      void addhungerlevel(int hungryness);
      void subtracthappinesslevel(int happylevel);
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

void Pet::addhappinesslevel(int happylevel)
  {
    happinesslevel += happylevel;
  }

void Pet::addhungerlevel(int hungryness)
  {
    hungerlevel += hungryness;
  }

void Pet::subtracthappinesslevel(int happylevel)
  {
    happinesslevel -= happylevel;
  }

class Player
  {
    private:
      int petnumber;
      std::string username;
    public:
      Player();
      //~Player();
      void setusername(std::string username);
      std::string getusername();
      void setpetnumber(int petnumber);
      int getpetnumer();
      void createpet();
      void loadpet(std::string petnumber,int pettype);
      std::vector<Pet*> pets;
      Bank_Account* useraccount;
  };
    // Player::~Player()
    //   {
    //     if(petnumber >= 1)
    //       {
    //         delete pets[0];
    //       }
    //     if(petnumber >= 2)
    //       {
    //         delete pets[1]
    //       }
    //     if(petnumber >= 3)
    //       {
    //         delete pets[2]
    //       }
    //       delete useraccount;
    //       delete pets;
    //   }

    Player::Player()
      {
        petnumber = 0;
        username = "";
        useraccount = new Bank_Account;
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

class Item
  {
	 private:
		  std::string nameOfItem;
		  int costOfItem;
      int matchingpettype;
		  std::string typeOfItem;
	public:
		  Item(std::string nameOfItem, int costOfItem, int matchingpettype, std::string typeOfItem);
      string getnameOfItem();
      int getCostOfItem();
      int getMatchingType();
    //  int randomhappinesslevel();
  };

Item::Item(std::string nameOfItem, int costOfItem, int matchingpettype, std::string typeOfItem)
  {
    this->nameOfItem = nameOfItem;
    this->costOfItem = costOfItem;
    this->matchingpettype = matchingpettype;
    this->typeOfItem = typeOfItem;
  }

int Item::getCostOfItem()
  {
    return costOfItem;
  }

string Item::getnameOfItem()
  {
    return nameOfItem;
  }

int Item::getMatchingType()
  {
    return matchingpettype;
  }

int randomhappinesslevel()
  {
    int happiness = 0;
    happiness = rand() % 20 + 1;
    return happiness;
  }

class Shop
  {
	private:
		Pet* petInside;
    Bank_Account * useraccount;
		std::vector<Item*> shopItems;
		//std::vector<Item*> petItems;
		void initializeFoodShop();
	public:
		Shop(Pet*, Bank_Account*, std::string);
    void shopmenu();
    void purchaseMenu();
		//void purchaseItemFromShop(Item*);
		//void sellItemToShop(Item*);
		//void listItemsAll();
		void listItemsNotOwned();
		//void listItemsOwned();
		//void listItemsByType(string);
};

Shop::Shop(Pet* petinside, Bank_Account* useraccount, std::string shopType)
  {
	   this->petInside = petinside;
     this->useraccount = useraccount;
	    if (shopType.compare("food") == 0)
      {
		      initializeFoodShop();
	    }
  }

void Shop::initializeFoodShop()
  {
    shopItems.push_back(new Item("Mush", 1, 0, "food"));
    shopItems.push_back(new Item("Kibble", 10, 1, "food"));
    shopItems.push_back(new Item("Bone", 25, 1, "food"));
    shopItems.push_back(new Item("Fish", 15, 2, "food"));
    shopItems.push_back(new Item("Dead Mouse", 30, 2, "food"));
    shopItems.push_back(new Item("Bird seed", 10, 3, "food"));
    shopItems.push_back(new Item("Mango", 25, 3, "food"));
    shopItems.push_back(new Item("Mackeral", 15, 4, "food"));
    shopItems.push_back(new Item("Cod", 20, 4,"food"));
    shopItems.push_back(new Item("Student tears", 15, 5,"food"));
    shopItems.push_back(new Item("Failed PA1", 30, 5, "food"));
    shopItems.push_back(new Item("Banana", 10, 6, "food"));
    shopItems.push_back(new Item("Pineapple", 25, 6, "food"));
    shopItems.push_back(new Item("Carrot", 15, 7, "food"));
    shopItems.push_back(new Item("Rabbit Pellets", 20, 7, "food"));
    shopItems.push_back(new Item("Pizza", 30, 8, "food"));
    shopItems.push_back(new Item("Burnt Bits", 10, 8, "food"));
    shopItems.push_back(new Item("Fish Flakes", 15, 9, "food"));
    shopItems.push_back(new Item("Fish Pellets", 20, 9, "food"));
    shopItems.push_back(new Item("Gatorade", 15, 10,"food"));
    shopItems.push_back(new Item("Nole's Fans", 1, 10,"food"));
    shopmenu();

  }

void Shop::shopmenu()
  {
  int shopChoice1 = 1;
  cout << "Welcome to the shop!! ";


  while(shopChoice1 != 2 && shopChoice1 < 6  && shopChoice1 > 0)
  {
    cout << "What would you like to?: " << endl;
    cout << "1. Purchase and Item" << endl;
    cout << "2. Exit" << endl;
    cin >> shopChoice1;
    switch(shopChoice1)
    {
      case 1:
      {
        cout << "\n" << endl;
        purchaseMenu();
        break;
      }
      // case 2:
      // {
      //   cout << "Choice two" << endl;
      //   break;
      // }
      // case 3:
      // {
      //   cout << "Choice three" << endl;
      //   break;
      // }
      // case 4:
      // {
      //   cout << "Choice four" << endl;
      //   break;
      // }
      case 2:
      {
        cout << "Exiting...." << endl;
        break;
      }
    }
  }
}

void Shop::purchaseMenu()
  {
    int purchChoice = 1;

    while(purchChoice !=22  && purchChoice < 22  && purchChoice > 0)
      {
        std::cout << "What would you like to buy?: " << std::endl;
        std::cout << "1. " << shopItems[0]->getnameOfItem() << "(" << shopItems[0]->getCostOfItem() << ")" << "\t";
        std::cout << "\t2. " << shopItems[1]->getnameOfItem()<< "(" << shopItems[1]->getCostOfItem() << ")" << "\t";
        std::cout << "3. " << shopItems[2]->getnameOfItem()<< "(" << shopItems[2]->getCostOfItem() << ")" << endl;
        std::cout << "4. " << shopItems[3]->getnameOfItem()<< "(" << shopItems[3]->getCostOfItem() << ")" << "\t";
        std::cout << "\t5. " << shopItems[4]->getnameOfItem() << "(" << shopItems[4]->getCostOfItem() << ")"<< "\t";
        std::cout << "6. " << shopItems[5]->getnameOfItem() << "(" << shopItems[5]->getCostOfItem() << ")"<< endl;
        std::cout << "7. " << shopItems[6]->getnameOfItem() << "(" << shopItems[6]->getCostOfItem() << ")"<< "\t";
        std::cout << "8. " << shopItems[7]->getnameOfItem() << "(" << shopItems[7]->getCostOfItem() << ")"<< "\t";
        std::cout << "9. " << shopItems[8]->getnameOfItem() << "(" << shopItems[8]->getCostOfItem() << ")"<< endl;
        std::cout << "10. " << shopItems[9]->getnameOfItem() << "(" << shopItems[9]->getCostOfItem() << ")"<< "\t";
        std::cout << "11. " << shopItems[10]->getnameOfItem() << "(" << shopItems[10]->getCostOfItem() << ")"<< "\t";
        std::cout << "12. " << shopItems[11]->getnameOfItem() << "(" << shopItems[11]->getCostOfItem() << ")"<< std::endl;
        std::cout << "13. " << shopItems[12]->getnameOfItem() << "(" << shopItems[12]->getCostOfItem() << ")"<< "\t";
        std::cout << "14. " << shopItems[13]->getnameOfItem() << "(" << shopItems[13]->getCostOfItem() << ")"<< "\t";
        std::cout << "15. " << shopItems[14]->getnameOfItem() << "(" << shopItems[14]->getCostOfItem() << ")"<< endl;
        std::cout << "16. " << shopItems[15]->getnameOfItem() << "(" << shopItems[15]->getCostOfItem() << ")"<< "\t";
        std::cout << "17. " << shopItems[16]->getnameOfItem() << "(" << shopItems[16]->getCostOfItem() << ")"<< "\t";
        std::cout << "18. " << shopItems[17]->getnameOfItem() << "(" << shopItems[17]->getCostOfItem() << ")"<< endl;
        std::cout << "19. " << shopItems[18]->getnameOfItem() << "(" << shopItems[18]->getCostOfItem() << ")"<< "\t";
        std::cout << "20. " << shopItems[19]->getnameOfItem() << "(" << shopItems[19]->getCostOfItem() << ")"<< "\t";
        std::cout << "21. " << shopItems[20]->getnameOfItem() << "(" << shopItems[20]->getCostOfItem() << ")"<< std::endl;
        std::cout << "22. Exit" << std::endl;
        std::cin >> purchChoice;

      bool success;
      int cost = 0;
      int randNum = 0;
    //  int happy = 0;
    //  int hunger = 0;
      int type = 0;
      randNum = randomhappinesslevel();
      type = petInside->getpettype();
      switch(purchChoice)
      {
        case 1:
        {   //sweetie
          cost = shopItems[0]->getCostOfItem();
          success = useraccount->enoughTokens(cost);

          if(success == true)
          {
            // max_happy = petInside->gethappinesslevel();
            // max_hunger = shopItems[0]->;
            petInside->addhungerlevel(5);
            petInside->addhappinesslevel(randNum);
            useraccount->subtractNumTokens(cost);
            cout << "Your pet likes " << shopItems[0]->getnameOfItem() << endl;
            cout << "You bought " << shopItems[0]->getnameOfItem() << endl;
          }
          else {

            cout << "Not enough money!" << endl;
          }
          break;
         }
        case 2:
        {
          cost = shopItems[1]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
          //  type = shopItems[1]->getMatchingType();
            if(type == 1) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[1]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[1]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 3:
        {
          cost = shopItems[2]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 1) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[2]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[2]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 4:
        {
          cost = shopItems[3]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 2) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[3]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[3]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 5:
        {
          cost = shopItems[4]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            type = shopItems[4]->getMatchingType();
            if(type == 2) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[4]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[4]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 6:
        {
          cost = shopItems[5]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 3) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[5]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[5]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 7:
        {
          cost = shopItems[6]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 3) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[6]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[6]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 8:
        {
          cost = shopItems[7]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 4) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[9]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[7]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 9:
        {
          cost = shopItems[8]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 4) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[8]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[8]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 10:
        {
          cost = shopItems[9]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 5) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[9]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[9]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 11:
        {
          cost = shopItems[10]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 5) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[10]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[10]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 12:
        {
          cost = shopItems[11]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 6) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[11]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[11]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 13:
        {
          cost = shopItems[12]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 6) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[12]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[12]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 14:
        {
          cost = shopItems[13]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 7) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[13]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[13]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 15:
        {
          cost = shopItems[14]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 7) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[14]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[14]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 16:
        {
          cost = shopItems[15]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 8) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[15]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[15]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 17:
        {
          cost = shopItems[16]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 8) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[16]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[16]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 18:
        {
          cost = shopItems[17]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 9) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[17]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[17]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 19:
        {
          cost = shopItems[18]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 9) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[18]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[18]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 20:
        {
          cost = shopItems[19]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 10) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[19]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[19]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 21:
        {
          cost = shopItems[20]->getCostOfItem();
          success = useraccount->enoughTokens(cost);
          if(success == true)
          {
            petInside->addhungerlevel(5);
            if(type == 10) //gains happiness +10
              {
                petInside->addhappinesslevel(randNum);
                cout << shopItems[20]->getnameOfItem() << " is your pet's favorite meal!" << endl;
              }
            else
              {   //loses -5 happiness
                petInside->subtracthappinesslevel(randNum);
              }
            useraccount->subtractNumTokens(cost);
            cout << "You bought " << shopItems[20]->getnameOfItem() << endl;
          }
          else {
            cout << "Not enough money!" << endl;
          }
          break;
        }
        case 22:
        {
          cout << "Exiting...." << endl;
          break;
        }
      }
      if(purchChoice != 22)
        {
          int cont=0;
          cout << "Would you like to buy anything else?" << endl;
          cout << "1. Yes" << endl;
          cout << "2. No" <<endl;
          cin >> cont;
          if(cont == 2)
            {
              purchChoice =22;
            }
          else
            {
              purchChoice=1;
            }
        }
    }
}

  Player* loadplayer(std::vector<std::string> userdata)
      {
        Player * returninguser = new Player;
        returninguser->setusername(userdata[0]);
        returninguser->useraccount->setNumTokens(stringtoint(userdata[1]));
        returninguser->setpetnumber(stringtoint(userdata[2]));
        if(returninguser->getpetnumer()==1)
          {
            std::cout << "Welcome back you have one pet" << std::endl;
          }
        return returninguser;
      }

  //The 4 different exit the games based on the amount of pets the player has

  void instructions()
    {
      std::cout << "Your virtual pet is deisgned to help you study. It has three main features" << std::endl;
      std::cout << "1. Study timer: Set this and begin studying with a pet. When you study, your pet gets happier" << std::endl;
      std::cout << "2. The Shop: Go here to buy food for your pet. Do not overfeed them though or they won't be happy" << std::endl;
      std::cout << "3. Pet Creator: Why stop at one pet? With up to three pets you will be even more motivated to study" << std::endl;
    }

  void exitthegame(Player * user)
    {
      std::ofstream userinfo;
      std::string i = user->getusername();
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << user->getusername();
      userinfo<< "\n";
      userinfo<< user->useraccount->getNumTokens();
      userinfo<<"\n";
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

  void petstats(Player * user)
    {
      if(user->getpetnumer() == 1)
        {
          std::cout << "You have 1 pet" << std::endl;
          std::cout << "Their name is " <<user->pets[0]->getpetname() << std::endl;
          std::cout << user->pets[0]->getpetname() << " is " << user->pets[0]->gethunger()<< " percent full" << std::endl;
          std::cout << user->pets[0]->getpetname() << " is " << user->pets[0]->gethappinesslevel()<< " percent happy"<< std::endl;
        }
      else if(user->getpetnumer() == 2)
        {
          std::cout << "You have 2 pets" << std::endl;
          std::cout << "Their names are " <<user->pets[0]->getpetname() << " and " << user->pets[1]->getpetname() << std::endl;
          std::cout << user->pets[0]->getpetname() << " is " << user->pets[0]->gethunger()<< " percent full" << std::endl;
          std::cout << user->pets[1]->getpetname() << " is " << user->pets[1]->gethunger()<< " percent full" << std::endl;
          std::cout << user->pets[0]->getpetname() << " is " << user->pets[0]->gethappinesslevel()<< " percent happy"<< std::endl;
          std::cout << user->pets[1]->getpetname() << " is " << user->pets[1]->gethappinesslevel()<< " percent happy"<< std::endl;
        }
      else if(user->getpetnumer() == 3)
        {
          std::cout << "You have 3 pets" << std::endl;
          std::cout << "Their names are " <<user->pets[0]->getpetname() << " , " << user->pets[1]->getpetname() << " and " << user->pets[2]->getpetname() << std::endl;
          std::cout << user->pets[0]->getpetname() << " is " << user->pets[0]->gethunger()<< " percent full" << std::endl;
          std::cout << user->pets[1]->getpetname() << " is " << user->pets[1]->gethunger()<< " percent full" << std::endl;
          std::cout << user->pets[2]->getpetname() << " is " << user->pets[2]->gethunger()<< " percent full" << std::endl;
          std::cout << user->pets[0]->getpetname() << " is " << user->pets[1]->gethappinesslevel()<< " percent happy"<< std::endl;
          std::cout << user->pets[1]->getpetname() << " is " << user->pets[0]->gethappinesslevel()<< " percent happy"<< std::endl;
          std::cout << user->pets[2]->getpetname() << " is " << user->pets[2]->gethappinesslevel()<< " percent happy"<< std::endl;
        }
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
      std::cout << "7. Help" << std::endl;
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
          new Shop(user->pets[0], user->useraccount, "food");
          controlmenu(user);
        }
      else if(selection == 4)
        {
          std::cout << "View Pet Stats" << std::endl;
          petstats(user);
          controlmenu(user);
          //need to create a pet stat view
        }
      else if(selection == 5)
        {
          std::cout << "\n";
          std::cout << "You currently have " << user->useraccount->getNumTokens() << " tokens"<< std::endl;
          std::cout << "\n" << std::endl;
          controlmenu(user);
        }
      else if(selection == 6)
        {
          std::cout << "Exit the game" << std::endl;
          exitthegame(user);
        }
      else if(selection == 7)
        {
          instructions();
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
      std::cout << "You have " << returninguser->useraccount->getNumTokens() << " tokens" <<std::endl;
      if(returninguser->getpetnumer()==0)
        {
          returninguser->createpet();
          exitthegame(returninguser);
        }
      else if(returninguser->getpetnumer()==1)
        {
          returninguser->loadpet(userdata[3],stringtoint(userdata[4]));
          std::cout << "You already have one pet" << std::endl;
          std::cout << "as I recall their name is " << returninguser->pets[0]->getpetname() << std::endl;
          controlmenu(returninguser);
        }
      else if(returninguser->getpetnumer()==2)
        {
          returninguser->loadpet(userdata[3],stringtoint(userdata[4]));
          returninguser->loadpet(userdata[5],stringtoint(userdata[6]));
          std::cout << "their names are " << returninguser->pets[0]->getpetname() << " and " << returninguser->pets[1]->getpetname() << std::endl;
          controlmenu(returninguser);
        }
      else if(returninguser->getpetnumer()==3)
        {
           returninguser->loadpet(userdata[3],stringtoint(userdata[4]));
           returninguser->loadpet(userdata[5],stringtoint(userdata[6]));
           returninguser->loadpet(userdata[7],stringtoint(userdata[8]));
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
      std::cout << "A bank account has been made for you, you will need this to buy food for your pet" << std::endl;
      std::cout << "You currently have" << p->useraccount->getNumTokens() << std::endl;
      //this code below is what creates the textfile
      std::ofstream userinfo;
      userinfo.open(std::string(i+".txt").c_str());
      userinfo << p->getusername();
      userinfo<< "\n";
      userinfo<<p->useraccount->getNumTokens();
      userinfo<<"\n";
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
                  std::cout << line << "****" << std::endl;
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
