#include <iostream>
#include "TClonesArray.h"
#include "TFile.h"
#include "TChain.h"
#include "TMath.h"
#include "/home/taebh/workspace/Delphes3.4.2/classes/DelphesClasses.h" //-Edit path  Delphes_Directory_location/classes/DelphesClasses.h


int main(int argc, char **argv){

	using namespace std;

	TString dirname =argv[1];

	TChain* inChain = new TChain("Delphes");
	inChain->Add("/x3/cms/jelee/DATA/"+dirname+"/*.root");

        TClonesArray* eTCA = new TClonesArray("Electron");inChain->SetBranchAddress("Electron",&eTCA);
        TClonesArray* vTCA = new TClonesArray("MissingET");inChain->SetBranchAddress("MissingET",&vTCA);
        TClonesArray* jTCA = new TClonesArray("Jet");inChain->SetBranchAddress("Jet",&jTCA);

	TFile *outfile = new TFile("Ntuple/"+dirname+".root","recreate");

	TTree *mytree = new TTree("tree","tree");
	
  	double Mjj;
  	double Delta_eta;
  	double Zeppenfeld;

	mytree-> Branch("Mjj",&Mjj);
	mytree-> Branch("Delta_eta",&Delta_eta);
	mytree-> Branch("Zeppenfeld",&Zeppenfeld);

	int totalN = inChain->GetEntries();

	for(int eventLoop=0 ; eventLoop<totalN; eventLoop++){
	
		TLorentzVector eleVec(0.0,0.0,0.0,0.0);
                TLorentzVector nueVec(0.0,0.0,0.0,0.0);
		TLorentzVector wVec(0.0,0.0,0.0,0.0);
		TLorentzVector jet1Vec(0.0,0.0,0.0,0.0);
                TLorentzVector jet2Vec(0.0,0.0,0.0,0.0);
		TLorentzVector jjVec(0.0,0.0,0.0,0.0);

		inChain->GetEntry(eventLoop);

		if(eTCA->GetEntries()==0)continue;

		Electron* ePtr = (Electron*)eTCA->At(0);

		if(ePtr->PT<=200)continue;
		if(fabs(ePtr->Eta)>=2.5)continue;
		eleVec = ePtr->P4();

		if(eTCA->GetEntries()>=2){
			Electron* ePtr2 = (Electron*)eTCA->At(1);
			if(ePtr2->PT>=25)continue;
		}

		MissingET* vPtr = (MissingET*)vTCA->At(0);

		if(vPtr->MET<=150)continue;
		nueVec = vPtr->P4();

		wVec = eleVec+nueVec;

		int jcnt = 0;

                for(int jLoop=0; jLoop<jTCA->GetEntries();jLoop++){

                        Jet* jPtr = (Jet*)jTCA->At(jLoop);

                        if(jPtr->BTag==0){
                                if(jet1Vec.E()==0.0){jet1Vec = jPtr->P4();jcnt++;continue;}
                                if(jet2Vec.E()==0.0){jet2Vec = jPtr->P4();jcnt++;break;}
                        }
                }

		if(jcnt!=2)continue;

		jjVec=jet1Vec+jet2Vec;

		if(jet1Vec.Pt()<=60)continue;
		if(jet2Vec.Pt()<=50)continue;
		if(fabs(jet1Vec.Eta())>=4.7)continue;
		if(fabs(jet2Vec.Eta())>=4.7)continue;
		if(jet1Vec.Eta()*jet2Vec.Eta()>=0)continue;

		Mjj=jjVec.M();
		Delta_eta=fabs(jet1Vec.Eta()-jet2Vec.Eta());
		Zeppenfeld=fabs(wVec.Eta()-(jet1Vec.Eta()+jet2Vec.Eta())/2);

		mytree->Fill();
	}

	outfile->Write();

}
