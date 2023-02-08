
void convertVBSWEEWK() {

  TFile* input_file = new TFile ("VV_NLO_LO_CMS_mjj.root", "READ");
  
  TH1F* hWZ_KF_CMS   = (TH1F*) input_file->Get("hWZ_KF_CMS");
  TH1F* hWZ_KF_CMSUp   = (TH1F*) input_file->Get("hWZ_KF_CMSUp");
  TH1F* hWZ_KF_CMSDown = (TH1F*) input_file->Get("hWZ_KF_CMSDown");
  
  
  #include <iostream>
  #include <fstream>
  
  ofstream myfile;
  myfile.open ("VBSWZ_EWK_NLO_LO_CMS_mjj.txt");
  myfile << "# BEGIN HISTO1D hWZ_KF_CMS\n";
  myfile << "# xlow   xhigh   val   errminus  errplus\n";
  
  for (int iBin=0; iBin<hWZ_KF_CMS->GetNbinsX(); iBin++) {
    // to avoid unphysical bin 
    if (hWZ_KF_CMS->GetBinLowEdge(iBin+1) < 2950) {
      myfile << hWZ_KF_CMS->GetBinLowEdge(iBin+1);
      myfile << "  " ;
      myfile << hWZ_KF_CMS->GetBinLowEdge(iBin+1) + hWZ_KF_CMS->GetBinWidth(iBin+1);
      myfile << "  " ;
      myfile << hWZ_KF_CMS->GetBinContent(iBin+1);
      myfile << "  " ;
      myfile << hWZ_KF_CMS->GetBinContent(iBin+1) - hWZ_KF_CMSDown->GetBinContent(iBin+1);
      myfile << "  " ;
      myfile << hWZ_KF_CMSUp->GetBinContent(iBin+1) - hWZ_KF_CMS->GetBinContent(iBin+1);
      myfile <<" \n";    
    }
  }  
  myfile.close(); 
  


  ofstream myfile_forPython;
  myfile_forPython.open ("VBSWZ_EWK_NLO_LO_CMS_mjj_forPython.txt");

  //   x y err_y
  //  
  for (int iBin=0; iBin<hWZ_KF_CMS->GetNbinsX(); iBin++) {
    // to avoid unphysical bin 
    if (hWZ_KF_CMS->GetBinLowEdge(iBin+1) < 2950) {
      myfile_forPython << hWZ_KF_CMS->GetBinLowEdge(iBin+1) + hWZ_KF_CMS->GetBinWidth(iBin+1)/2.;
      myfile_forPython << "  " ;
      myfile_forPython << hWZ_KF_CMS->GetBinContent(iBin+1);
//       myfile_forPython << "  " ;
//       myfile_forPython << (hWZ_KF_CMSUp->GetBinContent(iBin+1) - hWZ_KF_CMSDown->GetBinContent(iBin+1)) / 2.;
      myfile_forPython <<" \n";    
    }
  }  
  myfile_forPython.close(); 


  
  TCanvas* cc = new TCanvas ("cc", "cc", 800, 600);
  hWZ_KF_CMS -> SetLineColor(kRed);
  hWZ_KF_CMS -> Draw("h");
  hWZ_KF_CMSUp -> SetLineColor(kBlue);
  hWZ_KF_CMSUp -> Draw("h same");
  hWZ_KF_CMSDown -> SetLineColor(kBlue-4);
  hWZ_KF_CMSDown -> Draw("h same");
  
  
  
  
  
}



