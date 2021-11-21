
#include <iostream>
#include "structures/Liste.h"
#include "modeles/TrajetSimple.h"

using namespace std;

int main(int argc, char const *argv[])
{
    {
        Liste* liste = new Liste();

        liste->Ajouter(new TrajetSimple());
        liste->Ajouter(new TrajetSimple());

        delete liste;
    }
}