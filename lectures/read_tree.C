TCanvas *CreateC(Int_t i) {
  TString cName = "c";
  TString cTitle = "Tree examples ";
  TCanvas *c;
  c = new TCanvas(cName + i, cTitle + i, 200, 10, 600, 400);
  return c;
}

void readTree() {
  // TH1::AddDirectory(kFALSE);

  TCanvas *c[10];

  TFile *file = new TFile("testTree.root");  // opening the root file
  file->ls();                                // listing the file content

  TTree *Tout = (TTree *)file->Get("T");  // getting the Tree

  Tout->Print();  // listing the Tree content

  Int_t nentries = Tout->GetEntries();  // number of entries in the Tree
  cout << " nentries in tree = " << nentries << endl;

  // Drawing the Tree variables (automatic loop on Tree entries done by ROOT)

  int i = 0;

  CreateC(i)->cd();
  i++;
  Tout->Draw("x");  // Drawing x looping over all entries, on a temporary histo

  CreateC(i)->cd();
  i++;
  Tout->Draw("x", "", "", 1000,
             nentries - 1000);  // same as above, but for the last 1000 entries

  CreateC(i)->cd();
  i++;
  Tout->Draw(
      "y:x");  // Drawing y vs x, looping over all entries, on a temporary histo

  TH1F *h1 = new TH1F("h1", "x distribution", 200, -10., 10.);
  CreateC(i)->cd();
  i++;
  Tout->Draw("x>>h1", "y>10.");  // Drawing x over a predefined histo h1 and
                                 // apply a selection on y.

  CreateC(i)->cd();
  i++;
  Tout->Draw("sqrt(x**2+y**2)", "log(y)>1.");  // you may use functions

  CreateC(i)->cd();
  i++;
  Tout->Draw("sqrt(x**2+y**2):log(z)",
             "y>1 && x<0");  // correlation plot with selection

  // in this mode, the user loops explicitly over the tree and can
  // recover/select each of the entries

  Float_t x, y, z;

  // connecting local variables x,y,z to the tree variables

  Tout->SetBranchAddress("x", &x);
  Tout->SetBranchAddress("y", &y);
  Tout->SetBranchAddress("z", &z);

  for (Int_t i = 0; i < nentries; i++) {
    if (i % 10000 == 0) {
      Tout->GetEntry(i);
      cout << " x = " << x << " y = " << y << " z = " << z << endl;
    }
  }
  file->Close();  // closing the file
}
