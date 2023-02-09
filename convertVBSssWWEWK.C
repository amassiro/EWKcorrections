
void convertVBSssWWEWK() {

  TFile* input_file = new TFile ("VV_NLO_LO_CMS_mjj.root", "READ");
  
  TH1F* hWW_KF_CMS   = (TH1F*) input_file->Get("hWW_KF_CMS");
  TH1F* hWW_KF_CMSUp   = (TH1F*) input_file->Get("hWW_KF_CMSUp");
  TH1F* hWW_KF_CMSDown = (TH1F*) input_file->Get("hWW_KF_CMSDown");
  
  #include <iostream>
  #include <fstream>
  
  ofstream myfile;
  myfile.open ("VBSssWW_QCDEWK_NLO_LO_CMS_mjj.txt");
  myfile << "# BEGIN HISTO1D hWW_KF_CMS\n";
  myfile << "# xlow   xhigh   val   errminus  errplus\n";
  
  for (int iBin=0; iBin<hWW_KF_CMS->GetNbinsX(); iBin++) {
    // to avoid unphysical bin 
    if (hWW_KF_CMS->GetBinLowEdge(iBin+1) < 1920) {
      myfile << hWW_KF_CMS->GetBinLowEdge(iBin+1);
      myfile << "  " ;
      myfile << hWW_KF_CMS->GetBinLowEdge(iBin+1) + hWW_KF_CMS->GetBinWidth(iBin+1);
      myfile << "  " ;
      myfile << hWW_KF_CMS->GetBinContent(iBin+1);
      myfile << "  " ;
      myfile << hWW_KF_CMS->GetBinContent(iBin+1) - hWW_KF_CMSDown->GetBinContent(iBin+1);
      myfile << "  " ;
      myfile << hWW_KF_CMSUp->GetBinContent(iBin+1) - hWW_KF_CMS->GetBinContent(iBin+1);
      myfile <<" \n";    
    }
  }  
  myfile.close(); 
  


  ofstream myfile_forPython;
  myfile_forPython.open ("VBSssWW_QCDEWK_NLO_LO_CMS_mjj_forPython.txt");

  //   x y err_y
  //  
  for (int iBin=0; iBin<hWW_KF_CMS->GetNbinsX(); iBin++) {
    // to avoid unphysical bin 
    if (hWW_KF_CMS->GetBinLowEdge(iBin+1) < 1920) {
      myfile_forPython << hWW_KF_CMS->GetBinLowEdge(iBin+1) + hWW_KF_CMS->GetBinWidth(iBin+1)/2.;
      myfile_forPython << "  " ;
      myfile_forPython << hWW_KF_CMS->GetBinContent(iBin+1);
//       myfile_forPython << "  " ;
//       myfile_forPython << (hWW_KF_CMSUp->GetBinContent(iBin+1) - hWW_KF_CMSDown->GetBinContent(iBin+1)) / 2.;
      myfile_forPython <<" \n";    
    }
  }  
  myfile_forPython.close(); 


  
  TCanvas* cc = new TCanvas ("cc", "cc", 800, 600);
  hWW_KF_CMS -> SetLineColor(kRed);
  hWW_KF_CMS -> Draw("h");
  hWW_KF_CMSUp -> SetLineColor(kBlue);
  hWW_KF_CMSUp -> Draw("h same");
  hWW_KF_CMSDown -> SetLineColor(kBlue-4);
  hWW_KF_CMSDown -> Draw("h same");
  
  
  
  
  
}



