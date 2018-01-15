/*************************************************************************
 Log  -  description
 -------------------
 start                : 8 janv. 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Réalisation of the class <Log> (fichier Log.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- System include
using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <string>


using namespace std;
//------------------------------------------------------ Personal include
#include "Log.h"

//--------------------------------------------------------------  Constants

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Public methods
// type Log::Method ( liste des paramètres )
// Algorithm :
//
//{
//} //----- End of Méthode

//------------------------------------------------- Operator overload
Log & Log::operator =(const Log & unLog)
// Algorithme :
//
{
	return *this; // TODO
} //----- Fin de operator =

//-------------------------------------------- Constructors - destructor
Log::Log(const Log & unLog)
// Algorithme :
//
{
#ifdef MAP
	cout << "Calling copy constructor of <Log>" << endl;
#endif
} //----- Fin de Log (constructeur de copie)

Log::Log(bool graph)
// Algorithme :
//
{
#ifdef MAP
	cout << "Calling constructor of <Log>" << endl;
#endif
    createGraph = graph;
    nextKey = 0;
} //----- Fin de Log

Log::~Log()
// Algorithme :
//
{
#ifdef MAP
	cout << "Calling destructor of <Log>" << endl;
#endif
} //----- End of ~Log

void Log::AddLine(LogLine line) {
    string referer = line.Referer;
    string url = line.Request.URL;

    map<string, int>::iterator it;

    //update count depending on the document accesed
    it = count.find(url);
    if (it == count.end()) {
        count[url] = 1;
    } else {
        count[url]++;
    }

    if (createGraph) {
        //add the url and referer to the dictionary of nodes
        it = nodes.find(referer);
        if (it == nodes.end()) {
            nodes[referer] = nextKey;
            nextKey++;
        }


        it = nodes.find(url);
        if (it == nodes.end()) {
            nodes[url] = nextKey;
            nextKey++;
        }

        //update the dictionary with the edges
        pair<int, int> edge(nodes[referer], nodes[url]);
        map<pair<int, int>, int>::iterator it_edg;
        it_edg = edges.find(edge);
        if (it_edg == edges.end()) {
            edges[edge] = 1;
        } else {
            edges[edge]++;
        }


    }
}




struct compare{
    bool operator()(const pair<string,int> &p1,const pair<string,int> &p2) {
        return p1.second > p2.second;
    }
};

void Log::PrintMax()
{

    priority_queue< pair<string,int>,vector<pair<string,int>>, compare> highest;
    int i=0;
    map<string,int>::iterator it;
    for(it=count.begin();it!=count.end();it++){
        if(i<NB_TOP_ELEMENTS) {
            highest.emplace(*it);
            ++i;
        }
        else{
            if(it->second > highest.top().second) {
                highest.pop();
                highest.push(*it);
            }
        }
    }
    if(i==0){
        cout<<"Il y a pas des documents"<<endl;
    }
    pair<string,int> result[i];
    for(int j=0;j < NB_TOP_ELEMENTS && j < i;j++){
        result[j].first = highest.top().first;
        result[j].second = highest.top().second;
        highest.pop();
    }
    --i;
    for(;i>=0;i--){
        cout<<result[i].first<<"("<<result[i].second<<" hits)"<<endl;
    }

}

void Log::GenerateGraph(string nameFile)
{
    ofstream file;
    file.open(nameFile);
    file<<"digraph {"<<endl;
    map<string,int>::iterator it;
    for(it = nodes.begin();it!=nodes.end();it++){
        file<<"node"<<it->second<<" [label=\""<<it->first<<"\"];"<<endl;
    }
    map<pair<int,int>,int>::iterator ite;
    for(ite=edges.begin();ite!=edges.end();ite++){
        file<<"node"<<ite->first.first<<" -> node"<<ite->first.second;
        file<<" [label=\""<<ite->second<<"\"];"<<endl;
    }
    file<<"}";
    file.close();
}



//----------------------------------------------------------------- PRIVATE

//----------------------------------------------------- Protected methods
