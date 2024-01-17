#include "TF1.h"
#include "TH1F.h"

// Define a step PDF
double pdfFunc(double* xx, double* par) {
  double x = xx[0];

  if (0 <= x && x < 5) {
    return x / 5;
  } else {
    return 1;
  }
}

void macro() {
  TH1F* histo = new TH1F{"histo", "Histogram", 100, 0, 10};
  TF1* pdf = new TF1{"pdf", pdfFunc, 0, 10, 0};

  histo->FillRandom("pdf", 1e5);

  histo->Draw();
}