EWK NLO corrections to different processes
====

Processes available:
- NLO EWK VBS WZ
- NLO EWK + NLO QCD VBS same sign WW
- NLO EWK VBS W+/-W-/+ (a.k.a. os WW)


NLO EWK VBS WZ
---

From Matthieu Pellen 
    https://inspirehep.net/literature/1727600

Guillelmo Gomez Ceballos: https://github.com/GuillelmoGomezCeballos/MitAnalysisRunII/blob/master/data/90x/theory/VV_NLO_LO_CMS_mjj.root

    r00t convertVBSWEEWK.C
    
    r00t drawVBSWEEWK.C
    
    
NLO EWK + NLO QCD VBS ssWW (same sign WW)
---

From Matthieu Pellen 
    https://inspirehep.net/literature/1738518

Guillelmo Gomez Ceballos: https://github.com/GuillelmoGomezCeballos/MitAnalysisRunII/blob/master/data/90x/theory/VV_NLO_LO_CMS_mjj.root
based on  https://arxiv.org/abs/1708.00268


    r00t convertVBSssWWEWK.C
    
    r00t drawVBSssWWEWK.C



NLO EWK VBS osWW
---

From Matthieu Pellen (email exchange)
    https://inspirehep.net/literature/2037249


    r00t convertVBSosWWEWK.C
    
    r00t drawVBSosWWEWK.C


Semileptonic final state
---

Apply approximation on-shell, double pole approximation (DPA), good within 1%

    https://inspirehep.net/literature/1496632
    
Test: use same corrections as above, according to the final state osWW, WZ, ssWW

