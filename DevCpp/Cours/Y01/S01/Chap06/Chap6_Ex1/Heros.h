#include <string>

struct SHeros
{
    int x; 
    int y; 
    std::string strHeros;

    void Init(std::string strImage);
    void Deplacer(int xDeplacement, int yDeplacement); 
    void Afficher();
};