#include "PKartei.h"
#include "PDaten.h"
PKartei::PKartei()
{
}
PKartei::~PKartei()
{
}
int PKartei::neuerMA(string n, int abtl)
{
    return 0;
}
bool PKartei::loescheMA(int pnr)
{
    return false;
}
bool PKartei::UrlaubsAntrag(int pnr)
{
    return false ;
}
void PKartei::UrlaubEnde(int pnr)
{
}
void PKartei::ausgeben()
{
}
PDaten* PKartei::gibDaten(int i){
    list<PDaten *>::iterator it = kartei.begin();
    bool gefunden = false;
    while (!gefunden && it != kartei.end())
    {
        gefunden = (*it)->gibPNr() == i;
        if(!gefunden) it++;
    }
    if (gefunden) return (*it);
    else return NULL;
}
Anmerkungen
