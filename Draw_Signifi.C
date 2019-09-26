#include <math.h>
using namespace std;

void Draw_Signifi(){

/*Physics Parameters*/
double Lumi = 1000000.0;

TString signalname="wprime1000";long double xsecSignal=7.86413203891e-03;
//TString signalname="wprime2000";long double xsecSignal=6.02158250669e-04;
//TString signalname="wprime3000";long double xsecSignal=8.0034493626e-05; 
//TString signalname="wprime4000";long double xsecSignal=1.21682024511e-05;
//TString signalname="wprime5000";long double xsecSignal=1.89757563679e-06;
//TString signalname="wprime6000";long double xsecSignal=2.88776020804e-07;

long double xsecw2j100to500=22.4645492;
long double xsecw2j500to1000=0.220401086;
long double xsecw2j1000to2000=0.00847007776;
long double xsecw2j2000to3000=6.160953643e-05;
long double xsecw2j3000to4000=6.5935273893e-07;
long double xsecw2j4000to5000=5.62906155243e-09;
long double xsecw2j5000to6000=2.39018329425e-11;
long double xsecw2j6000toinf=7.29251198043e-15;
long double xsecdyj500to1000=0.06330488358;
long double xsecdyj1000to2000=0.0006443013632;
long double xsecdyj2000to3000=2.1313039773e-06;
long double xsecdyj3000to4000=1.69785167796e-08;
long double xsecdyj4000to5000=9.62487637963e-11;
long double xsecdyj5000to6000=3.75148578579e-13;
long double xsecdyj6000toinf=1.08379983134e-16;
long double xsecttbar100to500=74.87806729;
long double xsecttbar500to1000=0.7728554266;
long double xsecttbar1000to2000=0.06201158626;
long double xsecttbar2000to3000=0.00059462459669;
long double xsecttbar3000toinf=3.5530598753e-06;
long double xsecwwj500to1000 =0.0542039459682;
long double xsecwwj1000to2000=0.00247035497955;
long double xsecwwj2000to3000=2.24114241529e-05;
long double xsecwwj3000to4000=2.8090241982e-07;
long double xsecwwj4000to5000=3.06446059341e-09;
long double xsecwwj5000to6000=1.91727999019e-11;
long double xsecwzj500to1000 =0.0205914536811;
long double xsecwzj1000to2000=0.000993110535284;
long double xsecwzj2000to3000=9.32763066939e-06;
long double xsecwzj3000to4000=1.17310295316e-07;
long double xsecwzj4000to5000=1.11700659651e-09;
long double xsecwzj5000to6000=5.13958998078e-12;
long double xsecwzj6000toinf =1.41889367301e-15;

int NSignal         =1000000;

int Nw2j100to500    =1000000;
int Nw2j500to1000   =1000000;
int Nw2j1000to2000  =1000000;
int Nw2j2000to3000  =1000000;
int Nw2j3000to4000  =1000000;
int Nw2j4000to5000  =1000000;
int Nw2j5000to6000  =1000000;
int Nw2j6000toinf   =1000000;
int Ndyj500to1000   =1000000;
int Ndyj1000to2000  =1000000;
int Ndyj2000to3000  =1000000;
int Ndyj3000to4000  =1000000;
int Ndyj4000to5000  =997694;
int Ndyj5000to6000  =1000000;
int Ndyj6000toinf   =1000000;
int Nttbar100to500  =1000000;
int Nttbar500to1000 =993750;
int Nttbar1000to2000=987500;
int Nttbar2000to3000=639730;
int Nttbar3000toinf =477378;
int Nwwj500to1000   =1000000;
int Nwwj1000to2000  =1000000;
int Nwwj2000to3000  =1000000;
int Nwwj3000to4000  =1000000;
int Nwwj4000to5000  =980000;
int Nwwj5000to6000  =980000;
int Nwzj500to1000   =1000000;
int Nwzj1000to2000  =1000000;
int Nwzj2000to3000  =1000000;
int Nwzj3000to4000  =1000000;
int Nwzj4000to5000  =1000000;
int Nwzj5000to6000  =1000000;
int Nwzj6000toinf   =997691;

TString dataname = "2D_Hist";

TFile* fSignal        = TFile::Open("2D_Histogram/"+signalname+"_"+dataname+".root");

TFile* fw2j100to500     = TFile::Open("2D_Histogram/wjets100-500_"+dataname+".root");
TFile* fw2j500to1000    = TFile::Open("2D_Histogram/wjets500-1000_"+dataname+".root");
TFile* fw2j1000to2000   = TFile::Open("2D_Histogram/wjets1000-2000_"+dataname+".root");
TFile* fw2j2000to3000   = TFile::Open("2D_Histogram/wjets2000-3000_"+dataname+".root");
TFile* fw2j3000to4000   = TFile::Open("2D_Histogram/wjets3000-4000_"+dataname+".root");
TFile* fw2j4000to5000   = TFile::Open("2D_Histogram/wjets4000-5000_"+dataname+".root");
TFile* fw2j5000to6000   = TFile::Open("2D_Histogram/wjets5000-6000_"+dataname+".root");
TFile* fw2j6000toinf    = TFile::Open("2D_Histogram/wjets6000-inf_"+dataname+".root");
TFile* fdyj500to1000    = TFile::Open("2D_Histogram/dyjet500-1000_"+dataname+".root");
TFile* fdyj1000to2000   = TFile::Open("2D_Histogram/dyjet1000-2000_"+dataname+".root");
TFile* fdyj2000to3000   = TFile::Open("2D_Histogram/dyjet2000-3000_"+dataname+".root");
TFile* fdyj3000to4000   = TFile::Open("2D_Histogram/dyjet3000-4000_"+dataname+".root");
TFile* fdyj4000to5000   = TFile::Open("2D_Histogram/dyjet4000-5000_"+dataname+".root");
TFile* fdyj5000to6000   = TFile::Open("2D_Histogram/dyjet5000-6000_"+dataname+".root");
TFile* fdyj6000toinf    = TFile::Open("2D_Histogram/dyjet6000-inf_"+dataname+".root");
TFile* fttbar100to500   = TFile::Open("2D_Histogram/ttbarjet100-500_"+dataname+".root");
TFile* fttbar500to1000  = TFile::Open("2D_Histogram/ttbarjet500-1000_"+dataname+".root");
TFile* fttbar1000to2000 = TFile::Open("2D_Histogram/ttbarjet1000-2000_"+dataname+".root");
TFile* fttbar2000to3000 = TFile::Open("2D_Histogram/ttbarjet2000-3000_"+dataname+".root");
TFile* fttbar3000toinf  = TFile::Open("2D_Histogram/ttbarjet3000-inf_"+dataname+".root");
TFile* fwwj500to1000    = TFile::Open("2D_Histogram/wwjet500-1000_"+dataname+".root");
TFile* fwwj1000to2000   = TFile::Open("2D_Histogram/wwjet1000-2000_"+dataname+".root");
TFile* fwwj2000to3000   = TFile::Open("2D_Histogram/wwjet2000-3000_"+dataname+".root");
TFile* fwwj3000to4000   = TFile::Open("2D_Histogram/wwjet3000-4000_"+dataname+".root");
TFile* fwwj4000to5000   = TFile::Open("2D_Histogram/wwjet4000-5000_"+dataname+".root");
TFile* fwwj5000to6000   = TFile::Open("2D_Histogram/wwjet5000-6000_"+dataname+".root");
TFile* fwzj500to1000    = TFile::Open("2D_Histogram/wzjet500-1000_"+dataname+".root");
TFile* fwzj1000to2000   = TFile::Open("2D_Histogram/wzjet1000-2000_"+dataname+".root");
TFile* fwzj2000to3000   = TFile::Open("2D_Histogram/wzjet2000-3000_"+dataname+".root");
TFile* fwzj3000to4000   = TFile::Open("2D_Histogram/wzjet3000-4000_"+dataname+".root");
TFile* fwzj4000to5000   = TFile::Open("2D_Histogram/wzjet4000-5000_"+dataname+".root");
TFile* fwzj5000to6000   = TFile::Open("2D_Histogram/wzjet5000-6000_"+dataname+".root");
TFile* fwzj6000toinf    = TFile::Open("2D_Histogram/wzjet6000-inf_"+dataname+".root");

TString histname = "N_Event";

TH2F* hSignal        = (TH2F*)fSignal       ->Get(histname); hSignal      ->Scale(xsecSignal*Lumi/NSignal);
TH2F* hw2j100to500   = (TH2F*)fw2j100to500  ->Get(histname); hw2j100to500  ->Scale(xsecw2j100to500*Lumi/Nw2j100to500);
TH2F* hw2j500to1000  = (TH2F*)fw2j500to1000 ->Get(histname); hw2j500to1000 ->Scale(xsecw2j500to1000*Lumi/Nw2j500to1000);
TH2F* hw2j1000to2000 = (TH2F*)fw2j1000to2000->Get(histname); hw2j1000to2000->Scale(xsecw2j1000to2000*Lumi/Nw2j1000to2000);
TH2F* hw2j2000to3000 = (TH2F*)fw2j2000to3000->Get(histname); hw2j2000to3000->Scale(xsecw2j2000to3000*Lumi/Nw2j2000to3000);
TH2F* hw2j3000to4000 = (TH2F*)fw2j3000to4000->Get(histname); hw2j3000to4000->Scale(xsecw2j3000to4000*Lumi/Nw2j3000to4000);
TH2F* hw2j4000to5000 = (TH2F*)fw2j4000to5000->Get(histname); hw2j4000to5000->Scale(xsecw2j4000to5000*Lumi/Nw2j4000to5000);
TH2F* hw2j5000to6000 = (TH2F*)fw2j5000to6000->Get(histname); hw2j5000to6000->Scale(xsecw2j5000to6000*Lumi/Nw2j5000to6000);
TH2F* hw2j6000toinf  = (TH2F*)fw2j6000toinf ->Get(histname); hw2j6000toinf ->Scale(xsecw2j6000toinf*Lumi/Nw2j6000toinf);
TH2F* hdyj500to1000    = (TH2F*)fdyj500to1000   ->Get(histname); hdyj500to1000   ->Scale(xsecdyj500to1000/Ndyj500to1000*Lumi);
TH2F* hdyj1000to2000   = (TH2F*)fdyj1000to2000  ->Get(histname); hdyj1000to2000  ->Scale(xsecdyj1000to2000/Ndyj1000to2000*Lumi);
TH2F* hdyj2000to3000   = (TH2F*)fdyj2000to3000  ->Get(histname); hdyj2000to3000  ->Scale(xsecdyj2000to3000/Ndyj2000to3000*Lumi);
TH2F* hdyj3000to4000   = (TH2F*)fdyj3000to4000  ->Get(histname); hdyj3000to4000  ->Scale(xsecdyj3000to4000/Ndyj3000to4000*Lumi);
TH2F* hdyj4000to5000   = (TH2F*)fdyj4000to5000  ->Get(histname); hdyj4000to5000  ->Scale(xsecdyj4000to5000/Ndyj4000to5000*Lumi);
TH2F* hdyj5000to6000   = (TH2F*)fdyj5000to6000  ->Get(histname); hdyj5000to6000  ->Scale(xsecdyj5000to6000/Ndyj5000to6000*Lumi);
TH2F* hdyj6000toinf    = (TH2F*)fdyj6000toinf   ->Get(histname); hdyj6000toinf   ->Scale(xsecdyj6000toinf/Ndyj6000toinf*Lumi);
TH2F* httbar100to500   = (TH2F*)fttbar100to500  ->Get(histname); httbar100to500  ->Scale(xsecttbar100to500/Nttbar100to500*Lumi);
TH2F* httbar500to1000  = (TH2F*)fttbar500to1000 ->Get(histname); httbar500to1000 ->Scale(xsecttbar500to1000/Nttbar500to1000*Lumi);
TH2F* httbar1000to2000 = (TH2F*)fttbar1000to2000->Get(histname); httbar1000to2000->Scale(xsecttbar1000to2000/Nttbar1000to2000*Lumi);
TH2F* httbar2000to3000 = (TH2F*)fttbar2000to3000->Get(histname); httbar2000to3000->Scale(xsecttbar2000to3000/Nttbar2000to3000*Lumi);
TH2F* httbar3000toinf  = (TH2F*)fttbar3000toinf ->Get(histname); httbar3000toinf ->Scale(xsecttbar3000toinf/Nttbar3000toinf*Lumi);
TH2F* hwwj500to1000    = (TH2F*)fwwj500to1000   ->Get(histname); hwwj500to1000   ->Scale(xsecwwj500to1000/Nwwj500to1000*Lumi);
TH2F* hwwj1000to2000   = (TH2F*)fwwj1000to2000  ->Get(histname); hwwj1000to2000  ->Scale(xsecwwj1000to2000/Nwwj1000to2000*Lumi);
TH2F* hwwj2000to3000   = (TH2F*)fwwj2000to3000  ->Get(histname); hwwj2000to3000  ->Scale(xsecwwj2000to3000/Nwwj2000to3000*Lumi);
TH2F* hwwj3000to4000   = (TH2F*)fwwj3000to4000  ->Get(histname); hwwj3000to4000  ->Scale(xsecwwj3000to4000/Nwwj3000to4000*Lumi);
TH2F* hwwj4000to5000   = (TH2F*)fwwj4000to5000  ->Get(histname); hwwj4000to5000  ->Scale(xsecwwj4000to5000/Nwwj4000to5000*Lumi);
TH2F* hwwj5000to6000   = (TH2F*)fwwj5000to6000  ->Get(histname); hwwj5000to6000  ->Scale(xsecwwj5000to6000/Nwwj5000to6000*Lumi);
TH2F* hwzj500to1000    = (TH2F*)fwzj500to1000   ->Get(histname); hwzj500to1000   ->Scale(xsecwzj500to1000/Nwzj500to1000*Lumi);
TH2F* hwzj1000to2000   = (TH2F*)fwzj1000to2000  ->Get(histname); hwzj1000to2000  ->Scale(xsecwzj1000to2000/Nwzj1000to2000*Lumi);
TH2F* hwzj2000to3000   = (TH2F*)fwzj2000to3000  ->Get(histname); hwzj2000to3000  ->Scale(xsecwzj2000to3000/Nwzj2000to3000*Lumi);
TH2F* hwzj3000to4000   = (TH2F*)fwzj3000to4000  ->Get(histname); hwzj3000to4000  ->Scale(xsecwzj3000to4000/Nwzj3000to4000*Lumi);
TH2F* hwzj4000to5000   = (TH2F*)fwzj4000to5000  ->Get(histname); hwzj4000to5000  ->Scale(xsecwzj4000to5000/Nwzj4000to5000*Lumi);
TH2F* hwzj5000to6000   = (TH2F*)fwzj5000to6000  ->Get(histname); hwzj5000to6000  ->Scale(xsecwzj5000to6000/Nwzj5000to6000*Lumi);

TH2F* hSignificance = new TH2F("hSignificance","Significance",20,0,10,20,0,10);

long double Ns,Nbg,significance;
long double significance_Max=0;
float X_Max,Y_Max;

for(int i=0; i<20; i++){
	for(int j=0; j<20; j++){

		Ns=hSignal->Integral(i,i,j,j);
		Nbg=hw2j100to500     ->Integral(i,i,j,j);
		Nbg+=hw2j500to1000   ->Integral(i,i,j,j);
		Nbg+=hw2j1000to2000  ->Integral(i,i,j,j);
		Nbg+=hw2j2000to3000  ->Integral(i,i,j,j);
		Nbg+=hw2j3000to4000  ->Integral(i,i,j,j);
		Nbg+=hw2j4000to5000  ->Integral(i,i,j,j);
		Nbg+=hw2j5000to6000  ->Integral(i,i,j,j);
		Nbg+=hw2j6000toinf   ->Integral(i,i,j,j);
		Nbg+=hdyj500to1000   ->Integral(i,i,j,j);
		Nbg+=hdyj1000to2000  ->Integral(i,i,j,j);
		Nbg+=hdyj2000to3000  ->Integral(i,i,j,j);
		Nbg+=hdyj3000to4000  ->Integral(i,i,j,j);
		Nbg+=hdyj4000to5000  ->Integral(i,i,j,j);
		Nbg+=hdyj5000to6000  ->Integral(i,i,j,j);
		Nbg+=hdyj6000toinf   ->Integral(i,i,j,j);
		Nbg+=httbar100to500  ->Integral(i,i,j,j);
		Nbg+=httbar500to1000 ->Integral(i,i,j,j);
		Nbg+=httbar1000to2000->Integral(i,i,j,j);
		Nbg+=httbar2000to3000->Integral(i,i,j,j);
		Nbg+=httbar3000toinf ->Integral(i,i,j,j);
		Nbg+=hwwj500to1000   ->Integral(i,i,j,j);
		Nbg+=hwwj1000to2000  ->Integral(i,i,j,j);
		Nbg+=hwwj2000to3000  ->Integral(i,i,j,j);
		Nbg+=hwwj3000to4000  ->Integral(i,i,j,j);
		Nbg+=hwwj4000to5000  ->Integral(i,i,j,j);
		Nbg+=hwwj5000to6000  ->Integral(i,i,j,j);
		Nbg+=hwzj500to1000   ->Integral(i,i,j,j);
		Nbg+=hwzj1000to2000  ->Integral(i,i,j,j);
		Nbg+=hwzj2000to3000  ->Integral(i,i,j,j);
		Nbg+=hwzj3000to4000  ->Integral(i,i,j,j);
		Nbg+=hwzj4000to5000  ->Integral(i,i,j,j);
		Nbg+=hwzj5000to6000  ->Integral(i,i,j,j);

		significance=sqrt(Ns/(Ns+Nbg));

		if(Ns+Nbg!=0){

			if(significance_Max<significance){
				significance_Max=significance;X_Max=i*0.5;Y_Max=j*0.5;
			}

			hSignificance->SetBinContent(i,j,significance);

		}

	}

}

cout << "X value of Maximum significance : " << X_Max << endl;
cout << "Y value of Maximum significance : " << Y_Max << endl;
cout << "Maximum significance : " << significance_Max << endl;

hSignificance->GetXaxis()->SetTitle("#Delta#Eta Cut");
hSignificance->GetYaxis()->SetTitle("Zeppenfeld Cut");

TCanvas* c1 = new TCanvas();
gStyle->SetOptStat(0);
hSignificance->Draw("colz text");

c1->Print("Significance.png");
}
