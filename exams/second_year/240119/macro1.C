#include <iostream>
#include <vector>

#include "TCanvas.h"
#include "TH1D.h"
#include "TList.h"
#include "TRandom.h"
#include "TString.h"

void macro1() {
  TString histName = "histo";
  TH1* histo[4];

  std::vector<double> mu{2.5, 4.5, 6.5, 8.5};

  TList* list = new TList();

  TCanvas* canvas = new TCanvas();
  canvas->Divide(2, 2);

  for (int j{}; j < 4; ++j) {
    histo[j] = new TH1D{histName + j, histName + j, 1000, 0, 10};
    histo[j]->GetXaxis()->SetTitle("x variable");
    histo[j]->GetYaxis()->SetTitle("entries");

    auto mean = mu[j];
    auto stddev = mean / 10.;

    for (int i{}; i < 1e6; ++i) {
      auto x = gRandom->Gaus(mean, stddev);
      histo[j]->Fill(x);
    }

    list->Add(histo[j]);

    canvas->cd(j + 1);

    auto current_histo = (TH1*)list->At(j);
    current_histo->Draw();

    auto histo_mean = current_histo->GetMean();
    auto histo_mean_err = current_histo->GetMeanError();
    auto histo_rms = current_histo->GetRMS();
    auto histo_rms_err = current_histo->GetRMSError();

    std::cout << "HISTOGRAM " << j << ": " << '\n'
              << "Mean: " << histo_mean << " +- " << histo_mean_err << '\n'
              << "RMS: " << histo_rms << " +- " << histo_rms_err << '\n';
  }
}