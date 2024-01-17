void setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}

// Gaussiana 1-D definita nella funzione utente
Double_t myFunction(Double_t *x, Double_t *par) {
  Double_t xx = x[0];
  Double_t val = par[0] * TMath::Exp(-(xx - par[1]) * (xx - par[1]) / 2. /
                                     par[2] / par[2]);
  return val;
}

void myMacro(Int_t nGen = 1E5) {
  gStyle->SetOptStat(2210);
  gStyle->SetOptFit(1111);

  TString histName = "h";
  TH1F *h[2];
  for (Int_t i = 0; i < 2; i++) {
    h[i] = new TH1F(histName + i, "test histogram", 100, -5, 5.);
    // cosmetics
    h[i]->SetMarkerStyle(20);
    h[i]->SetMarkerSize(0.5);
    h[i]->SetLineColor(1);
    h[i]->GetYaxis()->SetTitleOffset(1.2);
    h[i]->GetXaxis()->SetTitleSize(0.04);
    h[i]->GetYaxis()->SetTitleSize(0.04);
    h[i]->GetXaxis()->SetTitle("x");
    h[i]->GetYaxis()->SetTitle("Entries");
  }

  h[0]->SetFillColor(kBlue);
  h[1]->SetFillColor(kRed);

  // filling the histos with FillRandom

  h[0]->FillRandom("gaus", nGen);  // gaus predefined function (G(0,1))

  TF1 *f = new TF1("f", myFunction, -10, 10, 3);  // user defined function
  f->SetParameter(0, 1);
  f->SetParameter(1, 0);
  f->SetParameter(2, 1);
  h[1]->FillRandom("f", nGen);

  // drawing

  TCanvas *c1 = new TCanvas("c1", "TF1 examples", 200, 10, 600, 400);
  h[0]->Fit("gaus");
  h[0]->Draw("H");
  h[0]->Draw("E,P,SAME");

  TCanvas *c2 = new TCanvas("c2", "TF1 examples", 200, 10, 600, 400);
  f->SetParameter(0, 4000);
  f->SetParameter(1, 0);
  f->SetParameter(2, 1);
  //  f->SetParName(0,"A");
  //  f->SetParName(1,"#mu");
  //  f->SetParName(2,"#sigma");
  f->SetLineColor(kCyan);
  TFitResultPtr fRes = h[1]->Fit(f, "S", "");
  h[1]->Draw("H");
  h[1]->Draw("E,P,SAME");
  TLegend *leg = new TLegend(.1, .7, .3, .9, "test Fit ");
  leg->SetFillColor(0);
  leg->AddEntry(h[1], "Punti Sperimentali");
  leg->AddEntry(f, "Fit Gaussiano");
  leg->Draw("S");
  c2->Print("testFit.gif");
  c2->Print("testFit.C");
  c2->Print("testFit.root");

  TCanvas *c3 = new TCanvas("c3", "TF1 examples", 200, 10, 600, 400);
  c3->Divide(1, 2);
  for (Int_t i = 0; i < 2; i++) {
    c3->cd(i + 1);
    h[i]->Draw("H");
    h[i]->Draw("E,P,SAME");
  }
  c3->Print("testHisto.gif");
  c3->Print("testHisto.C");
  c3->Print("testHisto.root");

  /*----Writing out fit results ---*/

  TF1 *fitFunc = h[1]->GetFunction("f");
  Double_t mean = fitFunc->GetParameter(1);
  Double_t meanErr = fitFunc->GetParError(1);
  Double_t sigma = fitFunc->GetParameter(2);
  Double_t sigmaErr = fitFunc->GetParError(2);
  Double_t chiSquare = fitFunc->GetChisquare();
  Double_t nDOF = fitFunc->GetNDF();
  Double_t Prob = fitFunc->GetProb();
  cout << "Mean = " << mean << " +/- " << meanErr << endl;
  cout << "Sigma = " << sigma << " +/- " << sigmaErr << endl;
  cout << "ChiSquare = " << chiSquare << " , nDOF " << nDOF << endl;
  cout << "ChiSquare Probability= " << Prob << endl;

  // Covariance and Correlation matrices

  TMatrixD cov = fRes->GetCovarianceMatrix();
  TMatrixD cor = fRes->GetCorrelationMatrix();
  cov.Print();
  cor.Print();
}
