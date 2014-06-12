python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_1.root aQGC_grids_1_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-90,90] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_1_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.1.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_2.root aQGC_grids_2_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-275,275] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_2_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.2.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_3.root aQGC_grids_3_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-70,70] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_3_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.3.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_4.root aQGC_grids_4_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-100,100] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_4_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.4.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_9.root aQGC_grids_9_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-100,100] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_9_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.9.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_10.root aQGC_grids_10_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-150,150] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_10_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.10.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_11.root aQGC_grids_11_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-10,10] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_11_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.11.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_12.root aQGC_grids_12_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-4.5,4.5] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_12_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.12.root

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_13.root aQGC_grids_13_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll_unblinded.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-13,13] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_13_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.observed.13.root
