// THIS FILE IS AUTOGENERATED //
#ifndef JetGraphTree_H
#define JetGraphTree_H
// STARTCUSTOM HEADER

#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"
#include "TString.h"
#include "genericTree.h"
#include <map>

// ENDCUSTOM
#define NNODE 100
class JetGraphTree : public genericTree {
  public:
    JetGraphTree();
    ~JetGraphTree();
    void WriteTree(TTree* t);
    void ReadTree(TTree* t);
    void Fill() { treePtr->Fill(); }
    void Reset();
    void SetAuxTree(TTree*);
// STARTCUSTOM PUBLIC
  bool adj[NNODE][NNODE];
// ENDCUSTOM
  private:
// STARTCUSTOM PRIVATE
// ENDCUSTOM
  public:
  int runNumber;
  int lumiNumber;
  ULong64_t eventNumber;
  int jetIdx;
  float jetTau32;
  float jetTau21;
  float jetMSD;
  float jetPt;
  float jetEta;
  float jetPhi;
  float jetM;
  int jetPdgId;
  float nodePt[100];
  float nodeEta[100];
  float nodePhi[100];
  float nodeE[100];
  float nodeIsFinal[100];
  float nodeIsRoot[100];
};
#endif