
//Acest program modeleaza un club de fitness ce contine echipamente si membri.
//Mesajele de debugging (constructor, destructor, etc.) sunt incluse, dar momentan nu au un rol functional in aplicatie,
//dar demonstreaza "ciclul de viata" al obiectelor


#include <iostream>
#include <string>
#include <vector>
//#include <Helper.h>
class Equipment
{
private:
    std::string type;
    bool inUse;
    int usageTimeRemaining;
    std::string currentUser;
public:
    explicit Equipment(const std::string& type_)
        : type{type_}, inUse{false}, usageTimeRemaining{0}, currentUser("")
    {
        std::cout << "Equipment created: " << type << "\n";
    }
    //constructor copiere
    Equipment(const Equipment& other)
        : type{other.type}, inUse{other.inUse}, usageTimeRemaining{other.usageTimeRemaining}, currentUser{other.currentUser}
    {
        std::cout << "Equipment copy constructed: " << type << "\n";
    }
    // operator atribuire
    Equipment& operator=(const Equipment& other)
    {
        if (this != &other)
        {
            type = other.type;
            inUse = other.inUse;
            usageTimeRemaining = other.usageTimeRemaining;
            currentUser = other.currentUser;
            std::cout << "Equipment copy assigned: " << type << "\n";
        }
        return *this;
    }
    //destructor
    ~Equipment()
    {
        std::cout << "Equipment destroyed: " << type << "\n";
    }
    // start echip + timp
    void startUsage(int duration, const std::string& user)
    {
        if (!inUse)
        {
            inUse = true;
            usageTimeRemaining = duration;
            currentUser = user;
            std::cout << "Equipment " << type << " started usage by " << user
                      << " for " << duration << " steps.\n";
        }
        else
        {
            std::cout << "Equipment " << type << " is already in use by " << currentUser << ".\n";
        }
    }
    // actualizare timp utilizare+ disponibil cand 0
    void update()
    {
        if (inUse && usageTimeRemaining > 0)
        {
            usageTimeRemaining--;
            if (usageTimeRemaining == 0)
            {
                inUse = false;
                currentUser = "";
                std::cout << "Equipment " << type << " is now available.\n";
            }
        }
    }

    const std::string& getType() const
    {
        return type;
    }
    // operatorul << pentru afisarea starii echipamentului
    friend std::ostream& operator<<(std::ostream& os, const Equipment& eq)
    {
        os << "Equipment: " << eq.type << " | Status: "
           << (eq.inUse ? "In Use" : "Available");
        if (eq.inUse)
            os << " | Remaining: " << eq.usageTimeRemaining << " | Used by: " << eq.currentUser;
        return os;
    }
};



//clasa membru



class Member
{
private:
    std::string name;
    int membershipID;
public:
    // constructor nume +ID
    Member(const std::string& name_, int id)
        : name{name_}, membershipID{id}
    {
        std::cout << "Member created: " << name << " (ID: " << membershipID << ")\n";
    }

    // constructor copiere
    Member(const Member& other)
        : name{other.name}, membershipID{other.membershipID}
    {
        std::cout<<"Member copy constructed: "<<name<<"\n";
    }
    // operator atribuire
    Member& operator=(const Member& other)
    {
        if (this!= &other)
        {
            name=other.name;
            membershipID = other.membershipID;
            std::cout<<"Member copy assigned: "<<name<<"\n";
        }
        return *this;
    }

    //destructor
    ~Member()
    {
        std::cout << "Member destroyed: " << name << "\n";
    }
    const std::string& getName() const
    {
        return name;
    }
    int getID() const
    {
        return membershipID;
    }
    // operatorul << pentru afisarea informatiilor despre membru
    friend std::ostream& operator<<(std::ostream& os, const Member& m)
    {
        os << "Member: " << m.name << " (ID: " << m.membershipID << ")";
        return os;
    }
};


//clasa sala


class Gym
{
private:
    std::string name;
    std::vector<Equipment> equipments;
    std::vector<Member> members;
public:
    //constructor explicit, nume
    explicit Gym(const std::string& name_): name{name_}
    {
        std::cout << "Gym created: " << name << "\n";
    }
    //constructor de copiere
    Gym(const Gym& other): name{other.name}, equipments{other.equipments}, members{other.members}
    {
        std::cout << "Gym copy constructed: " << name << "\n";
    }
    //operator
    Gym& operator=(const Gym& other)
    {
        if (this != &other)
        {
            name = other.name;
            equipments = other.equipments;
            members = other.members;
            std::cout << "Gym copy assigned: " << name << "\n";
        }
        return *this;
    }

    //destrusctor
    ~Gym()
    {
        std::cout << "Gym destroyed: " << name << "\n";
    }
    // +echip
    void addEquipment(const Equipment& eq)
    {
        equipments.push_back(eq);
        std::cout << "Added equipment: " << eq.getType() << "\n";
    }
    // +membru
    void addMember(const Member& m)
    {
        members.push_back(m);
        std::cout << "Added member: " << m.getName() << "\n";
    }
    // update stare
    void updateEquipments()
    {
        for(auto& eq: equipments) eq.update();
    }
    // start utilizare echip
    void startEquipmentUsage(int eqIndex, int duration, int memberIndex)
    {
        if(eqIndex < 0 || eqIndex >= static_cast<int>(equipments.size()))
        {
            std::cout<<"Invalid equipment index.\n";
            return;
        }
        if(memberIndex < 0 || memberIndex >= static_cast<int>(members.size()))
        {
            std::cout<<"Invalid member index.\n";
            return;
        }
        equipments[eqIndex].startUsage(duration, members[memberIndex].getName());
    }
    // status sala
  void printStatus() const {
    std::cout<<"\nGym: "<<name<<"\nEquipments:\n";
    for (size_t i=0;i<equipments.size(); i++) {
        std::cout<<" [" << i << "] "<<equipments[i]<<"\n";
    }
    std::cout<<"Members:\n";
    for (const auto& m : members) {
        std::cout<<" "<<m<<" - ID: "<<m.getID()<<"\n";
    }
}

};

int main()
{
    std::string gymName;
    std::cout<<"Enter gym name: ";
    std::getline(std::cin, gymName);
    Gym gym(gymName);

    int numEquipments;
    std::cout<<"Enter number of equipments: ";
    std::cin>>numEquipments;
    std::cin.ignore();

    for(int i=0; i<numEquipments; i++)
    {
        std::string eqType;
        std::cout<<"Enter equipment type "<<i+1<<": ";
        std::getline(std::cin, eqType);
        gym.addEquipment(Equipment(eqType));
    }

    int numMembers;
    std::cout<<"Enter number of members: ";
    std::cin>>numMembers;
    std::cin.ignore();

    for(int i=0; i<numMembers; i++)
    {
        std::string memberName;
        int memberID;
        std::cout<<"Enter member name "<<i+1<<": ";
        std::getline(std::cin, memberName);
        std::cout<<"Enter member ID "<<i+1<<": ";
        std::cin>>memberID;
        std::cin.ignore();
        gym.addMember(Member(memberName, memberID));
    }

    int choice=-1;
    while(choice!=0)
    {
        std::cout<<"\nMenu:\n1. Update equipments\n2. Start equipment usage\n3. Display gym status\n0. Exit\nChoose an option: ";
        std::cin>>choice;
        std::cin.ignore();
        switch(choice)
        {
        case 1:
            gym.updateEquipments();
            std::cout<<"Equipments updated.\n";
            break;
        case 2:
        {
            int eqIndex, duration, memberIndex;
            std::cout<<"Enter equipment index: ";
            std::cin>>eqIndex;
            std::cout<<"Enter usage duration: ";
            std::cin>>duration;
            std::cout<<"Enter member index: ";
            std::cin>>memberIndex;
            std::cin.ignore();
            gym.startEquipmentUsage(eqIndex, duration, memberIndex);
            break;
        }
        case 3:
            gym.printStatus();
            break;
        case 0:
            std::cout<<"Exiting...\n";
            break;
        default:
            std::cout<<"Invalid option. Try again.\n";
        }
    }
    return 0;
}
