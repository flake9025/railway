//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Fonctions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#pragma hdrstop
#include <fstream.h>
#include "Unit1.h"
#include "Unit7.h"
#pragma package(smart_init)

//---------------------------------------------------------------------------
//Fonction Cr�ation d'un m�mo
//Param�tres :  Position en pixels � partir de la gauche
//              Position en pixels � partir du haut
//              Form sur laquelle afficher
//---------------------------------------------------------------------------
TMemo* creerMemo(int left,int top,TForm *form)
{
        TMemo *m=new TMemo(form);
        m->Parent=form;
        m->Left=left;
        m->Top=top;
        m->Width=100;
        m->Height=120;
        m->Alignment=taCenter;
        return m;
}

//---------------------------------------------------------------------------
//Fonction Cr�ation d'un label
//Param�tres :  Position � partir de la gauche
//              Position � partir du haut
//              Libell�
//              Form sur laquelle afficher
//---------------------------------------------------------------------------
TLabel* creerLabel(int left,int top,AnsiString caption,TForm *form)
{
        TLabel *l=new TLabel(form);
        l->Parent=form;
        l->Left=left;
        l->Top=top;
        l->Caption=caption;
        return l;
}

//---------------------------------------------------------------------------
//Fonction Effacer un memo
//---------------------------------------------------------------------------
void effaceMemo(TMemo *m)
{
        if(m!=NULL)
        {
                m->Visible=false;
                m=NULL;
        }
}

//---------------------------------------------------------------------------
//Fonction Effacer un label
//---------------------------------------------------------------------------
void effaceLabel(TLabel *l)
{
        if(l!=NULL)
        {
                l->Visible=false;
                l=NULL;
        }
}

//---------------------------------------------------------------------------
//Fonction lire texte Memo depuis fichier
//Param�tres :  Memo qui recevra le texte
//              Fichier � lire
//---------------------------------------------------------------------------
void lireTexteMemo(TMemo *m,fstream *f)
{
        int lignesVides=0;
        char ligne[255];
        do
        {
                (*f).getline(ligne,255);
                if(strcmp(ligne,"\r\n")==0)
                {
                        lignesVides++;
                        m->Text=m->Text+"\r\n";
                }else{
                        if(strcmp(ligne,"*%*%*")!=0)
                                m->Text=m->Text+ligne+"\r\n";
                        lignesVides=0;
                }
        }while(strcmp(ligne,"*%*%*")!=0 && lignesVides<5);
}

//---------------------------------------------------------------------------
//Fonction Cr�ation d'un m�mo de couverture
//Param�tres :  Position � partir de la gauche
//              Position � partir du haut
//              Bool�en de couverture active (coch�e)
//              Bool�en d'ouverture de projet depuis un fichier
//              Fichier � lire
//              Label associ� � la couverture
//              Form sur laquelle afficher
//---------------------------------------------------------------------------
TMemo* creerMemoCouv(int left,int top,bool *active,bool *fromFile,fstream *f,TLabel *l,TForm *form)
{
        //Creation du m�mo
        TMemo *m=creerMemo(left,top,form);
        //Cr�ation du label
        if(*active)
        {
                if(*fromFile)
                        lireTexteMemo(m,f);
        }else{
                m->Visible=false;
                l->Visible=false;
        }
        return m;
}

//---------------------------------------------------------------------------
//Fonction Ecrire Memo dans un fichier
//Param�tres :  Fichier de sauvegarde
//              Memo
//---------------------------------------------------------------------------
void ecrireMemo(std::ofstream *f,TMemo *m)
{
        *f<<m->Text.c_str()<<"\n";
        *f<<"*%*%*"<<"\n";
}

//---------------------------------------------------------------------------
//Fonction Ecrire bool�en dans un fichier
//Param�tres :  Fichier de sauvegarde
//              Bool�en
//---------------------------------------------------------------------------
void ecrireBooleen(std::ofstream *f,bool *b)
{
       if(*b)
                *f<<"1"<<"\n";
       else
                *f<<"0"<<"\n";
}

