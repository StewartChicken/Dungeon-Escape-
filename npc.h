#include <iostream>
class npc{
    private:
    std::string intro;
    std::string name;

    public:
    npc();
    std::string getIntro();
    void setIntro(std::string inputIntro);
    std::string getName();
    void setName(std::string inputName);
};