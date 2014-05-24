python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_1.root aQGC_grids_1_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-250,250] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_1_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.1.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.1.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.1.png "F_{S0} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_2.root aQGC_grids_2_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-500,500] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_2_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.2.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.2.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.2.png "F_{S1} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_3.root aQGC_grids_3_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-100,100] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_3_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.3.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.3.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.3.png "F_{M0} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_4.root aQGC_grids_4_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-100,100] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_4_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.4.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.4.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.4.png "F_{M1} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_9.root aQGC_grids_9_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-500,500] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_9_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.9.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.9.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.9.png "F_{M6} / #Lambda^{4} (TeV^{-4}")

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_10.root aQGC_grids_10_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-200,200] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_10_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.10.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.10.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.10.png "F_{M7} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_11.root aQGC_grids_11_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-10,10] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_11_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.11.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.11.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.11.png "F_{T0} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_12.root aQGC_grids_12_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-10,10] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_12_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.12.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.12.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.12.png "F_{T1} / #Lambda^{4} (TeV^{-4})"

python2.6 refine_grid_1d.py /home/anlevin/ww_scattering/aQGC_grids_13.root aQGC_grids_13_refined.root
text2workspace.py -m 126 ss_ww_datacard_mll.txt -o ws_mll.root -P MultiParameterModel_MiscellaneousStuff.CommonTools.OneParameterPhysicsModel:my_1d_model --PO range_param=[-50,50] --PO scaling_filename=/home/anlevin/nd_limit/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/test/aQGC_grids_13_refined.root
combine ws_mll.root -M MultiDimFit -P param --floatOtherPOIs=0 --algo=grid --points=5000 --minimizerStrategy=2 -t -1 --expectSignal=1
mv higgsCombineTest.MultiDimFit.mH120.root higgsCombineTest.MultiDimFit.mH120.13.root
python2.6 draw_1d_limit_plot.py higgsCombineTest.MultiDimFit.mH120.13.root /afs/cern.ch/user/a/anlevin/www/tmp/deltaNLL.13.png "F_{T2} / #Lambda^{4} (TeV^{-4})"
