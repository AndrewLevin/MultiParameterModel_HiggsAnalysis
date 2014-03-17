from ROOT import *
from array import array
import sys
import time
from ROOT import TGraph

#gStyle.SetFillStyle(0)
#gStyle.SetLegendBorderSize(0);
gROOT.ForceStyle()

if (len(sys.argv) != 2):
    print "format: python.py draw_1d_limt_plot.py input_file_name"
    print "exiting"
    sys.exit(0)

f=TFile(sys.argv[1],"r")
limit=f.Get("limit")

deltaNLL=array("f",[0])
param=array("f",[0])

limit.SetBranchAddress("deltaNLL", deltaNLL);
limit.SetBranchAddress("param",param)

graph=TGraph()

for j in range(1,limit.GetEntries()-1):
    limit.GetEntry(j)
    if j == 1:
        min_parval = param[0]
    if j == limit.GetEntries()-2:
        max_parval = param[0]
    #print param[0]
    #print deltaNLL[0]
    graph.SetPoint(j-1,param[0],2*deltaNLL[0])

deltaNLL_95=ROOT.Math.chisquared_quantile_c(1-0.95,1)

npts=1000

for i in range(0,npts):
    parval = min_parval + i*(max_parval-min_parval)/npts
    if deltaNLL_95 > graph.Eval(parval):
        param_95_neg=parval
        break

for i in range(0,npts):
    parval = min_parval + i*(max_parval-min_parval)/npts
    if deltaNLL_95 > graph.Eval(parval):
        param_95_pos=parval        

print "95% confidence limits:"
print "["+str(param_95_neg)+","+str(param_95_pos)+"]"

#graph.GetXaxis().SetRangeUser(-0.5,0.5)
#graph.GetYaxis().SetRangeUser(0,20)
graph.GetXaxis().SetTitle("F_{T1} / #Lambda^{4} (10 TeV^{-4})")
graph.GetYaxis().SetTitle("2*deltaNLL")
graph.Draw("AC")

l95_neg = TLine(param_95_neg,0,param_95_neg,80);
l95_neg.SetLineColor(kRed)
l95_neg.SetLineWidth(3)
l95_neg.Draw();

l95_pos = TLine(param_95_pos,0,param_95_pos,80);
l95_pos.SetLineColor(kRed)
l95_pos.SetLineWidth(3)
l95_pos.Draw();

leg=TLegend(0.6,0.6,0.85,0.8)
leg.AddEntry(l95_neg,"95% confidence limit","l")
leg.SetTextSize(0.03)
leg.SetFillColor(0)
leg.Draw()

c1.Update()

c1.SaveAs("deltaNLL.png")

#raw_input()
