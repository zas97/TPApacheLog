/*************************************************************************
 Log  -  description
 -------------------
 start                : 8 janv. 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Interface of the class <Log> (fichier Log.h) ------
#if ! defined ( LOG_H_ )
#define LOG_H_

//--------------------------------------------------- Used interfaces
#include <unordered_map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>
#include "LogLine.h"


using namespace std;
//------------------------------------------------------------- Constants

const unsigned int NB_TOP_ELEMENTS = 10;

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <Log>
//
//
//------------------------------------------------------------------------ 

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods

    void AddLine(LogLine);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void PrintMax();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void GenerateGraph(string nameFile);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Operator overload
	Log & operator =(const Log & unLog);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructors - destructor
	Log(const Log & unLog);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Log(bool = false);
	// Mode d'emploi :
	//
	// Contrat :
	//


	virtual ~Log();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods

//----------------------------------------------------- Protected attributes
	map<string, int> count;
    map<string, int> nodes;
	map<pair<int, int>, int> edges;

    bool createGraph;
    int nextKey;
};

//--------------------------- Other independant definitions for <Log>

#endif // LOG_H_
