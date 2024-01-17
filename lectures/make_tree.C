void makeTree() {
  TFile *file = new TFile("testTree.root", "recreate");  // opening the ROOT
                                                         // file
  TTree *T = new TTree("T", "test tree");  // creating the Tree

  Float_t x, y, z;  // local variables

  // Defining the branches
  T->Branch("x", &x, "x/F");
  T->Branch("y", &y, "y/F");
  T->Branch("z", &z, "z/F");

  for (Int_t i = 0; i < 100000; i++) {
    x = gRandom->Gaus(3, 2);   // gaussian
    y = gRandom->Gaus(10, 3);  // gaussian
    z = gRandom->Exp(3.);      // expo
    T->Fill();                 // filling the Tree
  }

  T->Write();     // writing the Tree on the ROOT file
  file->Close();  // closing the ROOT file
}
