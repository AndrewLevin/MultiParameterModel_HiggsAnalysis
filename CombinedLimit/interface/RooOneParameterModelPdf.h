// -*- mode: c++ -*-

#ifndef ROOONEPARAMETERMODELPDF
#define ROOONEPARAMETERMODELPDF

#include "RooRealProxy.h"
#include "RooAbsPdf.h"
#include "TProfile2D.h"
#include "TString.h"
  
class RooOneParameterModelPdf : public RooAbsPdf {
public:
  
  RooOneParameterModelPdf ();
  RooOneParameterModelPdf (const char * name, const char * title,
			  RooAbsReal& _x, 
			  RooAbsReal& _param, 
			   RooAbsReal& _SM_shape,
			  const char * parFilename);
  RooOneParameterModelPdf (const RooOneParameterModelPdf& other, const char * name);
  virtual TObject * clone(const char * newname) const { 
    return new RooOneParameterModelPdf(*this, newname);
    }
  
  virtual ~RooOneParameterModelPdf ();
  
  Int_t getAnalyticalIntegral(RooArgSet& allVars, 
			    RooArgSet& analVars, 
			    const char* rangeName = 0) const;

  Double_t analyticalIntegral(Int_t code, const char* rangeName = 0) const;
  void readProfiles(std::vector<double> bins,TDirectory& dir) const ;

  TString getProfileFilename() const { return profileFilename; }
  
protected:
  
  RooRealProxy x;
  RooRealProxy param;
  RooRealProxy SM_shape;
  
  mutable std::map<std::string,std::vector<double> > integral_basis;

  mutable std::vector<double> bins; // imporatant to be mutable!!!



  TString profileFilename;
  
  TH1D ** P; //!
  
  void initializeProfiles();
  void initializeBins(const RooAbsReal& shape) const;
  void initializeNormalization(const std::string& rName,
			       const RooAbsReal& dep,
			       const RooAbsReal& shape) const;
  
  void readProfiles(RooOneParameterModelPdf const& other);

  virtual double evaluate() const ;
  
private:
  
  ClassDef(RooOneParameterModelPdf, 4) 
};

#endif
