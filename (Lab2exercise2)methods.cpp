#include <iostream>
#include <vector>
#include <string>
#include "header.h"
using namespace std;

double Travel::allDist = 0.0;

Travel::Travel(string d, string s, string e){
    description = d;
    startP = s;
    endP = e;
}

Travel::Travel(const Travel&source){
    description = source.description;
    startP = source.startP;
    endP = source.endP;
}

void Travel::setDescription(string d){
    description = d;
}

string Travel::getDescription()const{
    return description;
}

void Travel::setDistance(double d){
    distance = d;
    allDist += d;
}

double Travel::getDistance()const{
    return distance;
}

void Travel::addViaPoint(string s){
    additionalPoints.push_back(s);
}

void Travel::removeViaPoint(string s){
    int c = 0;
    for(unsigned int i=0; i<additionalPoints.size(); ++i){
        if(s==additionalPoints[i]){
            additionalPoints[i] = additionalPoints[additionalPoints.size()-1];
            additionalPoints.pop_back();
            ++c;
        }
    }
    if(c==0){
        throw string("Item could not be found");
    }
}

int Travel::size(){
    int ans = additionalPoints.size();
    if(startP.size()>0){
        ++ans;
    }
    if(endP.size()>0){
        ++ans;
    }
    return ans;
}

double Travel::getSummaryDistance(){
    return allDist;
}

string &Travel::operator[](int index){
    if(index==1){
        return startP;
    }else if(index==(size())){
        return endP;
    }else if(index>1){
        return additionalPoints[index-2];
    }
    throw string("Index must be equal or greater 1");
}

ostream& operator<<(ostream& o, const Travel& t){
    o<<t.getDescription()<<": ";
    o<<t.getDistance()<<"\n";
    o<<t.startP<<" -> ";
    for(unsigned int i=0; i<t.additionalPoints.size(); ++i){
        o<<t.additionalPoints[i]<<" -> ";
    }
    o<<t.endP;
    return o;
}
