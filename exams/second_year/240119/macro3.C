#include "TBenchmark.h"
#include "TF1.h"
#include "TH1F.h"

double pdfFunc(double *xx, double *par) {
  double x = xx[0];
  if (0 <= x && x < 1) {
    return 0.2;
  } else {
    return x / 5.;
  }
}

void macro3() {
  TH1F *histo = new TH1F{"histo", "Histogram", 100, 0, 5};
  TF1 *pdf = new TF1{"pdf", pdfFunc, 0, 5, 0};

  gBenchmark->Start("FillRandom");
  histo->FillRandom("pdf", 1e6);
  gBenchmark->Show("FillRandom");
}