#this is for using senka's framework
#it takes a 1d histogram and makes it into a 2d histogram, with the second dimension constant 

from ROOT import *
import optparse

parser = optparse.OptionParser()
parser.add_option('-i', '--infilename', help='input file name',dest='infilename')
parser.add_option('-o', '--outfilename', help='output file name',dest='outfilename')
(options,args) = parser.parse_args()

#options.infilename="aQGC_grids_2.root"
#options.outfilename="aQGC_grids_2_2d.root"

infile=TFile(options.infilename,"read")
outfile=TFile(options.outfilename,'RECREATE')

for key in infile.GetListOfKeys():
    anom_th1d=key.ReadObj()
    if type(anom_th1d)!=TH1D:
        print "expecting a TH1D, exiting"
        sys.exit(0)
    nbins=anom_th1d.GetXaxis().GetNbins()
    xmin=anom_th1d.GetXaxis().GetXmin()
    xmax=anom_th1d.GetXaxis().GetXmax()    

    outfile.cd()

    anom_th2d=TH2D(anom_th1d.GetName(),anom_th1d.GetTitle(),nbins,xmin,xmax,10,-5,5)

    for xbin in range(1,anom_th2d.GetXaxis().GetNbins()):
        for ybin in range(1,anom_th2d.GetYaxis().GetNbins()):
            anom_th2d.SetBinContent(xbin,ybin,anom_th1d.GetBinContent(xbin))

    anom_th2d.Write()
