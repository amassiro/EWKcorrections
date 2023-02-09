

void drawVBSssWWEWK() {
  
  std::string name = "VBSssWW_QCDEWK_NLO_LO_CMS_mjj.txt";
  std::cout << "name = " << name << std::endl;
  std::ifstream file (name); 
  
  std::string buffer;
  int num;
  float value;
  
  float x_min[100];
  float x_max[100];
  float x_mean[100];
  float x_err[100];
  float k_fact[100];
  float k_fact_up[100];
  float k_fact_down[100];
  
  
  
  while(!file.eof()) {
    getline(file,buffer);
    std::cout << "buffer = " << buffer << std::endl;
    if (buffer != "" && buffer[0] != '#'){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      line >> x_min[num]; 
      line >> x_max[num]; 
      line >> k_fact[num];
      line >> k_fact_down[num];
      line >> k_fact_up[num];
      num++;
    } 
  }
  
  for (int i=0; i<num; i++) {
    x_mean[i] = 0.5 * (x_min[i] + x_max[i]);
    x_err[i] = 0;
  }
  
  //   (n,x,y,exl,exh,eyl,eyh);
  TGraphAsymmErrors *plot = new TGraphAsymmErrors(num, x_mean, k_fact, x_err, x_err, k_fact_down, k_fact_up); 
  plot->SetMarkerColor(kBlue);
  plot->SetMarkerStyle(20);
  plot->SetMarkerSize(2);  
  plot->SetLineColor(kBlue);
  
  plot->Draw("APL");
  plot->GetXaxis()->SetTitle("m_{jj} [GeV]");
  plot->GetYaxis()->SetTitle("NLO/LO EWK");
  
  gPad->SetGrid();
  
  
   
}