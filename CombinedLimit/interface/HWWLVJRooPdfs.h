/* -*- mode: c++ -*- *********************************************************
 * Project: RooFit                                                           *
 *                                                                           *
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef HWWLVJ_ROOPDF
#define HWWLVJ_ROOPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"


class RooErfExpPdf : public RooAbsPdf {
public:
  RooErfExpPdf() {} ; 
  RooErfExpPdf(const char *name, const char *title,
	       RooAbsReal& _x,
	       RooAbsReal& _c,
	       RooAbsReal& _offset,
	       RooAbsReal& _width,
	       Int_t _onOff = 1);
  RooErfExpPdf(const RooErfExpPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooErfExpPdf(*this,newname); }
  inline virtual ~RooErfExpPdf() { }

  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const ;
  Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const ;

  // Double_t indefIntegral(Double_t xval) const ;

  static Double_t ErfExp(Double_t x, Double_t c, Double_t offset, 
			 Double_t width, Int_t onOff = 1); // raw
  static Double_t ErfExp(Double_t x, Double_t x_min, Double_t x_max, 
			 Double_t c, Double_t offset, Double_t width,
			 Int_t onOff = 1); //normalized

  static Double_t ErfExpIndefIntegral(Double_t x, Double_t c, Double_t offset,
				      Double_t width, Int_t onOff = 1);
  static Double_t ErfIndefIntegral(Double_t x, Double_t offset,
				   Double_t width, Int_t onOff = 1);

protected:

  RooRealProxy x ;
  RooRealProxy c ;
  RooRealProxy offset ;
  RooRealProxy width ;
  Int_t onOff ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooErfExpPdf,1) // Your description goes here...
};


class RooAlpha : public RooAbsPdf {
	public:
		RooAlpha();
		RooAlpha(const char *name, const char *title,
					RooAbsReal& _x,
					RooAbsReal& _c,
					RooAbsReal& _offset,
					RooAbsReal& _width,
					RooAbsReal& _ca,
					RooAbsReal& _offseta,
					RooAbsReal& _widtha,
                    Double_t _xmin,
                    Double_t _xmax
				);
		RooAlpha(const RooAlpha& other, const char* name=0) ;
		virtual TObject* clone(const char* newname) const { return new RooAlpha(*this,newname); }
		inline virtual ~RooAlpha() { }
        Double_t xmin;
        Double_t xmax;

	protected:

		RooRealProxy x ;
		RooRealProxy c;
		RooRealProxy offset;
		RooRealProxy width;
		RooRealProxy ca;
		RooRealProxy offseta;
		RooRealProxy widtha;

		Double_t evaluate() const ;

	private:

		ClassDef(RooAlpha,1)
};


class RooAlphaExp : public RooAbsPdf {
	public:
		RooAlphaExp();
		RooAlphaExp(const char *name, const char *title,
					RooAbsReal& _x,
					RooAbsReal& _c,
					RooAbsReal& _ca,
                    Double_t _xmin,
                    Double_t _xmax
				);
		RooAlphaExp(const RooAlphaExp& other, const char* name=0) ;
		virtual TObject* clone(const char* newname) const { return new RooAlphaExp(*this,newname); }
		inline virtual ~RooAlphaExp() { }
        Double_t xmin;
        Double_t xmax;

	protected:

		RooRealProxy x ;
		RooRealProxy c;
		RooRealProxy ca;
		Double_t evaluate() const ;

	private:

		ClassDef(RooAlphaExp,1)
};


//////////////  RooBWRunPdf.h
class RooBWRunPdf : public RooAbsPdf {
public:
  RooBWRunPdf() {} ; 
  RooBWRunPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _mean,
	      RooAbsReal& _width);
  RooBWRunPdf(const RooBWRunPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooBWRunPdf(*this,newname); }
  inline virtual ~RooBWRunPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy mean ;
  RooRealProxy width ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooBWRunPdf,1) // Your description goes here...
};

////////////  RooErfPow2Pdf.h

Double_t  ErfPow2(Double_t x,Double_t c0, Double_t c1, Double_t offset, Double_t width);



class RooErfPow2Pdf : public RooAbsPdf {
public:
  RooErfPow2Pdf() {} ; 
  RooErfPow2Pdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _c0,
	      RooAbsReal& _c1,
	      RooAbsReal& _offset,
	      RooAbsReal& _width);
  RooErfPow2Pdf(const RooErfPow2Pdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooErfPow2Pdf(*this,newname); }
  inline virtual ~RooErfPow2Pdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy c0 ;
  RooRealProxy c1 ;
  RooRealProxy offset ;
  RooRealProxy width ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooErfPow2Pdf,1) // Your description goes here...
};
 

///////////////////////////////////////////////////////////////

class RooAlpha4ErfPow2Pdf : public RooAbsPdf {
public:
  RooAlpha4ErfPow2Pdf() {} ; 
  RooAlpha4ErfPow2Pdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _c0,
	      RooAbsReal& _c1,
	      RooAbsReal& _offset,
	      RooAbsReal& _width,
	      RooAbsReal& _c0a,
	      RooAbsReal& _c1a,
	      RooAbsReal& _offseta,
	      RooAbsReal& _widtha);
  RooAlpha4ErfPow2Pdf(const RooAlpha4ErfPow2Pdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooAlpha4ErfPow2Pdf(*this,newname); }
  inline virtual ~RooAlpha4ErfPow2Pdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy c0 ;
  RooRealProxy c1 ;
  RooRealProxy offset ;
  RooRealProxy width ;
  RooRealProxy c0a ;
  RooRealProxy c1a ;
  RooRealProxy offseta ;
  RooRealProxy widtha ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooAlpha4ErfPow2Pdf,1) // Your description goes here...
};



////////////  RooErfPowExpPdf.h

Double_t  ErfPowExp(Double_t x,Double_t c0, Double_t c1, Double_t offset, Double_t width);



class RooErfPowExpPdf : public RooAbsPdf {
public:
  RooErfPowExpPdf() {} ; 
  RooErfPowExpPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _c0,
	      RooAbsReal& _c1,
	      RooAbsReal& _offset,
	      RooAbsReal& _width);
  RooErfPowExpPdf(const RooErfPowExpPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooErfPowExpPdf(*this,newname); }
  inline virtual ~RooErfPowExpPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy c0 ;
  RooRealProxy c1 ;
  RooRealProxy offset ;
  RooRealProxy width ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooErfPowExpPdf,1) // Your description goes here...
};
 

///////////////////////////////////////////////////////////////

class RooAlpha4ErfPowExpPdf : public RooAbsPdf {
public:
  RooAlpha4ErfPowExpPdf() {} ; 
  RooAlpha4ErfPowExpPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _c0,
	      RooAbsReal& _c1,
	      RooAbsReal& _offset,
	      RooAbsReal& _width,
	      RooAbsReal& _c0a,
	      RooAbsReal& _c1a,
	      RooAbsReal& _offseta,
	      RooAbsReal& _widtha);
  RooAlpha4ErfPowExpPdf(const RooAlpha4ErfPowExpPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooAlpha4ErfPowExpPdf(*this,newname); }
  inline virtual ~RooAlpha4ErfPowExpPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy c0 ;
  RooRealProxy c1 ;
  RooRealProxy offset ;
  RooRealProxy width ;
  RooRealProxy c0a ;
  RooRealProxy c1a ;
  RooRealProxy offseta ;
  RooRealProxy widtha ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooAlpha4ErfPowExpPdf,1) // Your description goes here...
};


//////////////////////// RooErfPowPdf.h
Double_t  ErfPow(Double_t x,Double_t c, Double_t offset, Double_t width);



class RooErfPowPdf : public RooAbsPdf {
public:
  RooErfPowPdf() {} ; 
  RooErfPowPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _c,
	      RooAbsReal& _offset,
	      RooAbsReal& _width);
  RooErfPowPdf(const RooErfPowPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooErfPowPdf(*this,newname); }
  inline virtual ~RooErfPowPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy c ;
  RooRealProxy offset ;
  RooRealProxy width ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooErfPowPdf,1) // Your description goes here...
};
 

///////////////////////////////////////////////////////////////
class RooAlpha4ErfPowPdf : public RooAbsPdf {
public:
  RooAlpha4ErfPowPdf() {} ; 
  RooAlpha4ErfPowPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _c,
	      RooAbsReal& _offset,
	      RooAbsReal& _width,
	      RooAbsReal& _ca,
	      RooAbsReal& _offseta,
	      RooAbsReal& _widtha);
  RooAlpha4ErfPowPdf(const RooAlpha4ErfPowPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooAlpha4ErfPowPdf(*this,newname); }
  inline virtual ~RooAlpha4ErfPowPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy c ;
  RooRealProxy offset ;
  RooRealProxy width ;
  RooRealProxy ca ;
  RooRealProxy offseta ;
  RooRealProxy widtha ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooAlpha4ErfPowPdf,1) // Your description goes here...
};


///////////////////////  RooPow2Pdf.h
class RooPow2Pdf : public RooAbsPdf {
public:
  RooPow2Pdf() {} ; 
  RooPow2Pdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _p0,
	      RooAbsReal& _p1
          );
  RooPow2Pdf(const RooPow2Pdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooPow2Pdf(*this,newname); }
  inline virtual ~RooPow2Pdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy p0 ;
  RooRealProxy p1 ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooPow2Pdf,1) // Your description goes here...
};

/////////////////////////  RooPowPdf.h
class RooPowPdf : public RooAbsPdf {
public:
  RooPowPdf() {} ; 
  RooPowPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _p0);
  RooPowPdf(const RooPowPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooPowPdf(*this,newname); }
  inline virtual ~RooPowPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy p0 ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooPowPdf,1) // Your description goes here...
};

///////////////////////////////////////////RooQCDPdf.h
class RooQCDPdf : public RooAbsPdf {
public:
  RooQCDPdf() {} ; 
  RooQCDPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _p0,
	      RooAbsReal& _p1,
	      RooAbsReal& _p2);
  RooQCDPdf(const RooQCDPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooQCDPdf(*this,newname); }
  inline virtual ~RooQCDPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy p0 ;
  RooRealProxy p1 ;
  RooRealProxy p2 ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooQCDPdf,1) // Your description goes here...
};


/////////////////////////////////// RooUser1Pdf.h
class RooUser1Pdf : public RooAbsPdf {
public:
  RooUser1Pdf() {} ; 
  RooUser1Pdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _p0,
	      RooAbsReal& _p1
          );
  RooUser1Pdf(const RooUser1Pdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooUser1Pdf(*this,newname); }
  inline virtual ~RooUser1Pdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy p0 ;
  RooRealProxy p1 ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooUser1Pdf,1) // Your description goes here...
};




#endif