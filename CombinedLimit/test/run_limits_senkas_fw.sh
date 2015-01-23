operators_and_ranges="\
1,-90,90
2,-200,200
3,-70,70
4,-100,100
9,-100,100
10,-150,150
11,-10,10
12,-4.5,4.5
13,-13,13
"

for operator_and_range in $operators_and_ranges
do

operator=`echo $operator_and_range | awk -F, '{print $1}'`
lower=`echo $operator_and_range | awk -F, '{print $2}'`
upper=`echo $operator_and_range | awk -F, '{print $3}'`


cp /home/anlevin/senka_anom_fw/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/aQGC_grids_${operator}_2d_renamed.root /home/anlevin/senka_anom_fw/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/signal_WV_channel1.root
python2.6 buildWorkspace.py --config=/home/anlevin/wwscattering_senkas_fw/histo_limits_wwssll_nsign0_shape_8TeV.txt
text2workspace.py -m 126 wv_semil_channel1boosted.txt -o Example_ZZ_SMasBKG.root -P CombinedEWKAnalysis.CommonTools.HagiwaraAndZeppenfeldTwoDimensionalModel_wz:dkglZModel_wz --PO channels=channel1 --PO range_lZ=${lower},${upper} --PO range_dkg=-50,50
combine Example_ZZ_SMasBKG.root -M MultiDimFit -P lZ --floatOtherPOIs=0 --algo=grid --points=10000 --minimizerStrategy=2 -t -1 --expectSignal=1 >& /dev/null
python build1DInterval.py -50 50 higgsCombineTest.MultiDimFit.mH120.root lZ

done