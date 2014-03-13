/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "HiggsAnalysis/CombinedLimit/interface/RooOneParameterModelScaling.h" 

#include <math.h> 
#include "TMath.h" 
#include "RooFormulaVar.h"
#include "RooRealVar.h"
#include "RooFit.h"

#include "TFile.h"

ClassImpUnique(RooOneParameterModelScaling,MAGICWORDOFSOMESORT) 


  RooOneParameterModelScaling::RooOneParameterModelScaling() :
    P(0)
{
  initialize_histograms();
}

RooOneParameterModelScaling::RooOneParameterModelScaling(const char *name, 
					     const char *title,
					     RooAbsReal& _param,
					     const char * FILENAME, 
					     const char * NAME) :
   RooAbsReal(name,title),
   param("param","param",this,_param),
   th2d_filename(FILENAME),
   th2d_name(NAME),
   P(0)
{ 
  initialize_histograms();

} 

void RooOneParameterModelScaling::read_histograms() const
{

  TFile * f = new TFile(th2d_filename);

  assert(f);
  assert(P);

  P[0] = (TH1D*)f->Get(th2d_name);

  assert(P[0]);

}

void RooOneParameterModelScaling::initialize_histograms() {

  P = new TH1D*[1]();

}


RooOneParameterModelScaling::
RooOneParameterModelScaling(const RooOneParameterModelScaling& other, 
		      const char* name) :  
  RooAbsReal(other,name),
  param("param",this,other.param),
  th2d_filename(other.th2d_filename),
  th2d_name(other.th2d_name),
  P(0)
{ 
  initialize_histograms();
} 


RooOneParameterModelScaling::~RooOneParameterModelScaling() {
  
  if (P[0])
    delete P[0];

  delete [] P;
}

Double_t RooOneParameterModelScaling::evaluate() const 
{ 

  double v(param);

  if (!P || !P[0]) {
    std::cout << "P not initialized ---> initializing it" << std::endl;
    read_histograms();
  }

  if (v < P[0]->GetXaxis()->GetXmin())
    v = P[0]->GetXaxis()->GetXmin();
  if (v > P[0]->GetXaxis()->GetXmax())
    v = P[0]->GetXaxis()->GetXmax();

  return P[0]->Interpolate(v);
}
