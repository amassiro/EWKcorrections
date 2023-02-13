
void convertVBSosWWEWK() {

//   
// 11 Invariant mass of leading jet pair (j_1, j_2)   
//   
//  
//  nlo_histogram.histo011.BB.dat
//  lo_histogram.histo011.BB.dat
//
  
  
  #include <iostream>
  #include <fstream>
  
  std::ifstream fileNLO ("nlo_histogram.histo011.BB.dat"); 
  std::ifstream fileLO  ("lo_histogram.histo011.BB.dat"); 
  
  std::string buffer;
  int num;
  float value;
  
  float x_min[400];
  float x_max[400];
  float x_mean[400];
  float value_NLO[400];
  float value_NLO_err[400];
  float value_LO[400];
  float value_LO_err[400];
  
  
  
  while(!fileNLO.eof()) {
    getline(fileNLO,buffer);
    std::cout << "buffer = " << buffer << std::endl;
    if (buffer != "" && buffer[0] != '#'){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      line >> num;
      num -=1;
      line >> x_min[num]; 
      line >> x_max[num];
      x_mean[num] = (x_min[num] + x_max[num])/2.;
      line >> value_NLO[num];
      line >> value_NLO_err[num];
    } 
  }
  
  while(!fileLO.eof()) {
    getline(fileLO,buffer);
//     std::cout << "buffer = " << buffer << std::endl;
    if (buffer != "" && buffer[0] != '#'){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      line >> num;
      num -=1;
      line >> x_min[num]; 
      line >> x_max[num];
      line >> value_LO[num];
      line >> value_LO_err[num];
    } 
  }
  
  std::cout << " ~~~~~~~~ " << std::endl;
  for (int i=0; i<num; i++) {
    std::cout << " value_NLO[i] + value_LO[i] = " << value_NLO[i] << " + " << value_LO[i] << std::endl;
    value_NLO[i] = value_NLO[i] + value_LO[i];
  }
  
  
  
  ofstream myfile;
  myfile.open ("VBSosWW_EWK_NLO_LO_CMS_mjj.txt");
  myfile << "# xlow   xhigh   val   errminus  errplus\n";
  
  for (int iBin=0; iBin<num; iBin++) {
    // to avoid unphysical bin 
    if (value_LO [iBin] != 0 && x_mean[iBin]<4000) {
      myfile << x_min[iBin];
      myfile << "  " ;
      myfile << x_max[iBin];
      myfile << "  " ;
      myfile << value_NLO[iBin] / value_LO [iBin];
      myfile << "  " ;
      myfile << value_NLO_err[iBin] / value_LO [iBin];
      myfile << "  " ;
      myfile << value_NLO_err[iBin] / value_LO [iBin];
      myfile <<" \n";    
    }
  }  
  myfile.close(); 
  


  ofstream myfile_forPython;
  myfile_forPython.open ("VBSosWW_EWK_NLO_LO_CMS_mjj_forPython.txt");

  //   x y
  //  
  for (int iBin=0; iBin<num; iBin++) {
    // to avoid unphysical bin 
    if (value_LO [iBin] != 0 && x_mean[iBin]<4000) {
      myfile_forPython << x_mean[iBin];
      myfile_forPython << "  " ;
      myfile_forPython << value_NLO[iBin] / value_LO [iBin];
      myfile_forPython <<" \n";   
    }
  }  
  myfile_forPython.close(); 


  
  
}



