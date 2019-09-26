#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "TFile.h"
#include "TChain.h"
#include "TH2F.h"
#include "TTree.h"
#include "TString.h"
#include "TCanvas.h"
#include "TStyle.h"
using namespace std;

int main(int argc, char** argv) {

	TString File_Name = argv[1];

	double Mjjcut = atof(argv[2]);

	TChain* inChain = new TChain("tree");

	inChain->Add("Ntuple/"+File_Name+".root");

	double Mjj;
	double Delta_eta;
	double Zeppenfeld;

	inChain->SetBranchAddress("Mjj",&Mjj);
	inChain->SetBranchAddress("Delta_eta",&Delta_eta);
	inChain->SetBranchAddress("Zeppenfeld",&Zeppenfeld);

	TFile *outfile = new TFile("2D_Histogram/"+File_Name+"_2D_Hist.root","recreate");

	TH2F* N_Event = new TH2F("N_Event","N_Event",20,0,10,20,0,10);

	for(int k = 0; k<inChain->GetEntries(); k++){

		inChain->GetEntry(k);

		if(Mjj<Mjjcut)continue;

		for(int i=0; i<20; i++) {

			int flag=0;

			for(int j=0; j<20; j++) {

				double cutDEta = i*0.5;
				double cutZepp = j*0.5;

				if(Delta_eta>cutDEta && Zeppenfeld>cutZepp){
					N_Event->Fill(cutDEta,cutZepp);flag=1;
				}
				else{
					break;
				}

			if(flag==0)break;

			}

		}

	}

	outfile->Write();
	return 0;

}
