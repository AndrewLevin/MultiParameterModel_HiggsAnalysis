from ROOT import *
from array import array
import sys
import time
from ROOT import TGraph

#gStyle.SetFillStyle(0)
#gStyle.SetLegendBorderSize(0);
gROOT.ForceStyle()

gStyle.SetOptStat       ("")
#gStyle.SetOptTitle       (0)
#gStyle.SetPaletteTitle  (1)
gStyle.SetPadRightMargin  (0.18);

#gStyle.SetPadRightMargin(0.68)

if (len(sys.argv) != 5):
    print "format: python2.6 draw_2d_limt_plot.py output_file_name x_axis_label y_axis_label input_file_name"
    print "exiting"
    sys.exit(0)

f=TFile(sys.argv[4],"r")
x_axis_label=sys.argv[2]
y_axis_label=sys.argv[3]
output_file_name=sys.argv[1]
limit=f.Get("limit")

limit.Draw("deltaNLL:param1:param2 >> h","deltaNLL < 4","prof,colz")

#gPad.Update()

thprof2d=gDirectory.Get("h")

thprof2d.GetXaxis().SetTitle(x_axis_label)
thprof2d.GetYaxis().SetTitle(y_axis_label)
thprof2d.GetZaxis().SetTitle("deltaNLL")
thprof2d.GetXaxis().CenterTitle()
thprof2d.GetYaxis().CenterTitle()
thprof2d.GetZaxis().CenterTitle()
thprof2d.SetTitle("")

print type(thprof2d)

#c3=TCanvas("c3")

c1.Update()
c1.ForceUpdate()
c1.Modified()
gPad.Update()
gPad.ForceUpdate()
gPad.Modified()

thprof2d.Draw("colz")

#c1.SaveAs(output_file_name)

thprof2d.SaveAs("delete_this.root")

raw_input()

