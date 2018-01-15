/*************************************************************************
 Parser  -  description
 -------------------
 start                : 8 janv. 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Réalisation of the class <Parser> (fichier Parser.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- System include
using namespace std;
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------ Personal include
#include "Parser.h"

//--------------------------------------------------------------  Constants

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Public methods
// type Parser::Method ( liste des paramètres )
// Algorithm :
//
//{
//} //----- End of Méthode

/*//------------------------------------------------- Operator overload
Parser & Parser::operator =(const Parser & unParser)
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructors - destructor
Parser::Parser(const Parser & unParser)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Calling copy constructor of <Parser>" << endl;
#endif
} //----- Fin de Parser (constructeur de copie)
*/
Parser::Parser(string filename)
// Algorithme :
//
{
#ifdef MAP
    cout << "Calling constructor of <Parser>" << endl;
#endif

    fs.open(filename.c_str());
    if (! fs)
        cerr << "Error opening file " << filename << endl;
} //----- Fin de Parser

Parser::~Parser()
// Algorithme :
//
{
#ifdef MAP
    cout << "Calling destructor of <Parser>" << endl;
#endif
} //----- End of ~Parser

bool Parser::IsOk()
// Algorithme :
//
{
    return !fs.eof();
}

LogLine Parser::ReadLine()
// Algorithme :
//
{
    string line;
    getline(fs, line);

    LogLine l;

    istringstream ss(line);

    string current;

    getline(ss, l.IP, ' ');
    getline(ss, current, ' ');
    getline(ss, current, '[');

    getline(ss, current, '/');
    l.Date.Day = atoi(current.c_str());
    getline(ss, current, '/');
    l.Date.Month = atoi(current.c_str());
    getline(ss, current, ':');
    l.Date.Year = atoi(current.c_str());
    getline(ss, current, ':');
    l.Date.Hour = atoi(current.c_str());
    getline(ss, current, ':');
    l.Date.Minute = atoi(current.c_str());
    getline(ss, current, ' ');
    l.Date.Second = atoi(current.c_str());
    getline(ss, current, ']');
    l.Date.Zone = atoi(current.c_str());

    getline(ss, current, '"');
    getline(ss, l.Request.Method, ' ');
    getline(ss, l.Request.URL, ' ');
    getline(ss, l.Request.HTTPVersion, '"');
    getline(ss, current, ' ');
    getline(ss, current, ' ');
    l.Status = atoi(current.c_str());
    getline(ss, current, ' ');
    l.ContentSize = atoi(current.c_str());
    getline(ss, current, '"');
    getline(ss, l.Referer, '"');

    // https://stackoverflow.com/questions/1878001/how-do-i-check-if-a-c-string-starts-with-a-certain-string-and-convert-a-sub
    if (strncmp(l.Referer.c_str(), DOMAIN_NAME.c_str(), DOMAIN_NAME.size()) == 0)
        l.Referer = l.Referer.substr(DOMAIN_NAME.size());

    getline(ss, current, '"');
    getline(ss, l.Client, '"');

    return l;
}


//----------------------------------------------------------------- PRIVATE

//----------------------------------------------------- Protected methods
