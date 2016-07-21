#ifndef Track_h
#define Track_h

#include <TClonesArray.h>

#include "Classes/Cluster/Cluster.h"
#include "Classes/Track/conversionFunctions.h"

const Int_t MaxTrackLength = 40;
class TGraph;
class TGraphErrors;
class Clusters;

class Track : public TObject {

	private:
		TClonesArray track_;
		Float_t fitEnergy_;
		Float_t fitScale_;
		Float_t fitError_;

	public:

	Track() : track_("Cluster", MaxTrackLength) {
		fitEnergy_ = 0;
		fitScale_ = 0;
		fitError_ = 0;
	};

	Track(Cluster *cluster) : track_("Cluster", MaxTrackLength) { 
		appendCluster(cluster);
		fitEnergy_ = 0;
		fitScale_ = 0;
		fitError_ = 0;
	}

	virtual ~Track(); 

	virtual void setTrack(Track *copyTrack, Int_t startOffset = 0); // copy whole track
	virtual void appendCluster(Cluster *copyCluster, Int_t startOffset = 0); // copy cluster
	virtual void appendPoint(Float_t x, Float_t y, Int_t layer, Int_t size = -1, Int_t eventID = -1);

	virtual void clearTrack() { track_.Clear("C"); }
	virtual void Clear(Option_t * = "");

	virtual Int_t GetEntriesFast() { return track_.GetEntriesFast(); }
	virtual Int_t GetEntries() { return track_.GetEntries(); }
	
	virtual Float_t getX(Int_t i) { return At(i)->getX(); }
	virtual Float_t getY(Int_t i) { return At(i)->getY(); }
	virtual Int_t getLayer(Int_t i) { return At(i)->getLayer(); }
	virtual Int_t getSize(Int_t i) { return At(i)->getSize(); }
	virtual Int_t getEventID(Int_t i) { return At(i)->getEventID(); }
	virtual Int_t getError(Int_t i) { return At(i)->getError(); } 
	virtual Int_t getIdxFromLayer(Int_t i);
	virtual Float_t getDepositedEnergy(Int_t i) {return At(i)->getDepositedEnergy(); }
	virtual Float_t getDepositedEnergyError(Int_t i) {return At(i)->getDepositedEnergyError(); }
	virtual Float_t getPreEnergyLoss();
	virtual Float_t getPreWEPL();
	virtual Float_t getPreTL();
	virtual Float_t getPreEnergyLossError();

	Int_t getClusterIdx(Float_t x, Float_t y, Int_t layer);
	Int_t getClusterIdx(Cluster * cluster);

	Clusters * getConflictClusters();
	Int_t getNumberOfConflictClusters();
	Bool_t isUsedClustersInTrack();
	Bool_t isUsed(Int_t i) { return At(i)->isUsed(); }
	Bool_t isOneEventID();
	Bool_t isFirstAndLastEventIDEqual();
	Int_t getEventIDMode();

	Bool_t isClusterInTrack(Cluster * cluster);

	// with dimensions
	Float_t getXmm(Int_t i) { return At(i)->getXmm(); }
	Float_t getYmm(Int_t i) { return At(i)->getYmm(); }
	Float_t getLayermm(Int_t i) { return At(i)->getLayermm(); }
	Float_t getTrackLengthmm();
	Float_t getTrackLengthmmAt(Int_t i);	// return length between two points in mm
	Float_t getTrackLengthWEPLmmAt(Int_t i);
	Float_t getRangemm();
	Float_t getRangemmAt(Int_t i);
	Float_t getRangeWEPLAt(Int_t i);

	Float_t getSinuosity();
	Float_t getProjectedRatio();
	Float_t getSlopeAngle();
	Float_t getSlopeAngleAtLayer(Int_t i);
	Float_t getSlopeAngleBetweenLayers(Int_t i);
	Float_t getSlopeAngleChangeBetweenLayers(Int_t i);
	Float_t getSlopeAngleDifferenceSum();
	Float_t getSlopeAngleDifferenceSumInTheta0();
	Float_t getMaximumSlopeAngleChange();
	Float_t getAbsorberLength(Int_t i);
	Float_t getSnakeness();
	Int_t	getNScintillators();
	Float_t getTrackScore();
	Float_t getMeanSizeToIdx(Int_t i);
	Float_t getStdSizeToIdx(Int_t toIdx);
	Float_t getEnergy();
	Float_t getFitParameterEnergy();
	Float_t getFitParameterScale();
	Float_t getFitParameterError();
	Float_t getWEPL();
	Float_t getEnergyStraggling();
	Bool_t isHitOnScintillatorH();
	Bool_t isHitOnScintillatorV();
	Bool_t isHitOnScintillators();

	Bool_t doesTrackEndAbruptly();
	Float_t getRiseFactor();
	
	Int_t getNMissingLayers();
	Int_t getLastLayer();
	Int_t getFirstLayer();
	Bool_t hasLayer(Int_t layer);

	Float_t getAverageCS();
   Float_t getAverageCSLastN(Int_t i);

	TGraphErrors * doFit();
	TGraphErrors * doRangeFit();
	
	virtual Cluster* At(Int_t i) { return ((Cluster*) track_.At(i)); }
	Int_t getClusterFromLayer(Int_t layer);
	Cluster * getInterpolatedClusterAt(Int_t layer);
	Cluster * getExtrapolatedClusterAt(Float_t mmBeforeDetector);
	virtual Cluster* Last() { return ((Cluster*) track_.At(GetEntriesFast()-1)); }

	virtual TObject* removeClusterAt(Int_t i) { return track_.RemoveAt(i); }
	virtual void removeCluster(Cluster *c) { track_.Remove((TObject*) c); }

	virtual void extrapolateToLayer0();

   friend ostream& operator<<(ostream &os, Track& t);

   ClassDef(Track,5);
};
#endif