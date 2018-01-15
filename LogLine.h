/*************************************************************************
 LogLine  -  description
 -------------------
 start                : 15 janv. 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Interface of the class <LogLine> (fichier LogLine.h) ------
#if ! defined ( LOGLINE_H_ )
#define LOGLINE_H_

//--------------------------------------------------- Used interfaces
#include <string>

using namespace std;
//------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types


typedef struct Request
{
    string Method;
    string URL;
    string HTTPVersion;
} Request;

typedef struct Date
{
    int Representation;
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Second;
    int Zone;
} Date;

typedef struct LogLine
{
    string IP;
    struct Date Date;
    struct Request Request;
    int Status;
    int ContentSize;
    string Referer;
    string Client;
} LogLine;



#endif // LOGLINE_H_
