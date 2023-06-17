#include <TCanvas.h>
#include <TF1.h>
#include <TH1F.h>
#include <TMath.h>
#include <TRandom.h>

Double_t fitFunction(Double_t *x, Double_t *par) {
  Double_t xx = x[0];
  Double_t val = par[0] * TMath::Exp(-(xx - par[1]) * (xx - par[1]) / 2. /
                                     par[2] / par[2]) +
                 par[3];
  return val;
}

void macro() {
  constexpr Int_t nGen = 1E4;
  TH1F *g = new TH1F("g", "Gauss", 500, 0., 5.);
  TH1F *u = new TH1F("u", "Uniform", 500, 0., 5.);

  Double_t x;
  for (Int_t i = 0; i < nGen; ++i) {
    x = gRandom->Gaus(2.5, 0.1);
    g->Fill(x);

    x = gRandom->Uniform(0., 5.);
    u->Fill(x);
  }

  TH1F *sum = new TH1F(*g);
  sum->SetName("sum");
  sum->SetTitle("Sum");
  sum->Add(g, u);

  TF1 *f = new TF1("f", fitFunction, 0, 5, 4);
  f->SetParameters(1, 1, 1, 1);

  TCanvas *canvas1 = new TCanvas("canvas1");
  sum->Fit(f);
  sum->Draw();

  TCanvas *canvas2 = new TCanvas("canvas2");
  canvas2->Divide(2, 1);
  canvas2->cd(1);
  g->Draw();
  canvas2->cd(2);
  u->Draw();

  TF1 *fitFunc = sum->GetFunction("f");
  Double_t hMean = sum->GetMean();
  Double_t hMeanErr = sum->GetMeanError();
  Double_t hRMS = sum->GetRMS();
  Double_t hRMSErr = sum->GetRMSError();
  Double_t par0 = fitFunc->GetParameter(0);
  Double_t par0Err = fitFunc->GetParError(0);
  Double_t par1 = fitFunc->GetParameter(1);
  Double_t par1Err = fitFunc->GetParError(1);
  Double_t par2 = fitFunc->GetParameter(2);
  Double_t par2Err = fitFunc->GetParError(2);
  Double_t par3 = fitFunc->GetParameter(3);
  Double_t par3Err = fitFunc->GetParError(3);
  Double_t chiSquare = fitFunc->GetChisquare();
  Double_t NDOF = fitFunc->GetNDF();

  std::cout << "Histogram mean: " << hMean << "+-" << hMeanErr << '\n'
            << "Histogram RMS: " << hRMS << "+-" << hRMSErr << '\n'
            << "par0: " << par0 << "+-" << par0Err << '\n'
            << "par1: " << par1 << "+-" << par1Err << '\n'
            << "par2: " << par2 << "+-" << par2Err << '\n'
            << "par3: " << par3 << "+-" << par3Err << '\n'
            << "Reduced chi square: " << chiSquare / NDOF << '\n';
}