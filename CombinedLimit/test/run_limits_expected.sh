operators_and_ranges="\
1,-90,90
2,-275,275
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

combineCards.py /home/anlevin/ww_scattering/histo_limits_wwssll_nsign0_shape_8TeV_Bin0_${operator}.txt /home/anlevin/ww_scattering/histo_limits_wwssll_nsign0_shape_8TeV_Bin1_${operator}.txt /home/anlevin/ww_scattering/histo_limits_wwssll_nsign0_shape_8TeV_Bin2_${operator}.txt /home/anlevin/ww_scattering/histo_limits_wwssll_nsign0_shape_8TeV_Bin3_${operator}.txt >& ss_ww_datacard_mll_${operator}.txt
python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_${operator}.root aQGC_grids_${operator}_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_${operator}.txt -o ws_mll_${operator}.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[${lower},${upper}] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_${operator}_refined.root
combine ws_mll_${operator}.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.expected.${operator}.root

done

