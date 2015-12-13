/*
 * Tools.h
 *
 *  Created on: Sep 2, 2015
 *      Author: local1
 */

#ifndef FOCALCODE_TOOLS_H_
#define FOCALCODE_TOOLS_H_

#include <vector>
#include <TObject.h>
#include "Hit.h"
#include "Cluster.h"

class TGraph;

using namespace std;

Bool_t isItemInVector(Int_t i, vector<Int_t> *v);
Float_t diffmm(Cluster *p1, Cluster *p2);
Float_t diffmm(Hit *h1, Hit *h2);
Bool_t existsEnergyFile(Int_t energy);
Double_t fitfunc_DBP(Double_t *v, Double_t *par);
char * getMaterialChar();
char * getDataTypeChar(Int_t dataType);
Int_t getMinimumTrackLength(Int_t energy);


#endif /* FOCALCODE_TOOLS_H_ */