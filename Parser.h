/*************************************************************************
 Parser  -  description
 -------------------
 start                : 8 janv. 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Interface of the class <Parser> (fichier Parser.h) ------
#if ! defined ( PARSER_H_ )
#define PARSER_H_

//-------------------------------------------------------- Used interfaces
#include <fstream>

#include "Log.h"
#include "LogLine.h"
//------------------------------------------------------------- Constants

const string DOMAIN_NAME = "http://intranet-if.insa-lyon.fr";

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle of the class <Parser>
//
//
//------------------------------------------------------------------------

class Parser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods



//------------------------------------------------- Operator overload
    Parser & operator =(const Parser & unParser);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructors - destructor
    Parser(const Parser & unParser);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Parser(string filename);
    // Manual :
    // Takes the filename and prepare the parser for this file.
    // Contract : None
    //

    virtual ~Parser();
    // Mode d'emploi :
    //
    // Contrat :
    //

    LogLine NextLine(bool exclure = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    LogLine NextLine(string time, bool exclure = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool IsOk();
    // Mode d'emploi :
    //
    // Contrat :
    //

    LogLine ReadLine();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVATE

protected:
//----------------------------------------------------- Protected methods


//----------------------------------------------------- Protected attributes

    ifstream fs;
    int hour = -1;

};

//--------------------------- Other independant definitions for <Parser>

#endif // PARSER_H_
