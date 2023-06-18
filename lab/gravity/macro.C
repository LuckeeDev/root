#include "TAxis.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraph.h"
#include "TROOT.h"
#include "TStyle.h"

void setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(111);
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}

void gravity(Int_t config) {
  Int_t ref = 0;  // riferimento per la posizione di equilibrio
  // Instance of the graph
  std::string filename;

  if (config == 1) {
    filename = "gravity-config1.dat";
  } else if (config == 2) {
    filename = "gravity-config2.dat";
  } else {
    std::cout << "You must call the function with either 1 or 2 as parameter."
              << '\n';
    return;
  }

  TGraph *graph = new TGraph(filename.c_str());
  // file da cui prendere i dati, in default con due colonne di dati double, se
  // volessi anche gli errori, dovrei usare la classe TGraphErrors
  graph->SetTitle("Grafico iniziale;Tempo - t (s);Posizione - x (cm)");

  // Make esthetetically better
  graph->GetXaxis()->SetTitleOffset(1.3);
  graph->SetMarkerStyle(kFullCircle);
  graph->SetMarkerColor(kBlue);
  graph->SetMarkerSize(1);

  // Define a fit function
  TF1 *f = new TF1("f", "([0]*sin(x*[1]+[2]))*exp(-x/[3])+[4]+[5]*x", 0, 1500);

  // inizializzo i parametri a dei valori ragionevoli per una buona convergenza
  // del fit (importante, con molti parametri). Non devono essere precisi, la
  // tolleranza è ampia, ma non devono neanche essere troppo distanti dai valori
  // cercati.

  // [0] è l'ampiezza, quindi valore ragionevole 1.5 (cm)
  f->SetParameter(0, 1.5);
  // [1] è connesso all'inverso del periodo, quindi circa 2*pi/220 s
  f->SetParameter(1, 6.28 / 220.);
  // [2] è la fase: il grafico non è a 0 per t=0, ha un po' di offset, ma
  // assumiamo 0, il fit non è particolarmente sensibile
  f->SetParameter(2, 0);
  // [3] è la costate di decadimento (presa dai dati dell'anno scorso)
  f->SetParameter(3, 600);
  // [4] è l'intercetta della baseline, si stima dal grafico
  f->SetParameter(4, 28.2);
  // [5] è la pendenza della baseline (input molto approssimato, il fit non è
  // particolarmente sensibile)
  f->SetParameter(5, 0.1);

  f->SetLineColor(kRed);
  f->SetLineStyle(2);

  TCanvas *myCanvas = new TCanvas("myCanvas", "", 50, 50, 1200, 500);
  myCanvas->Divide(2, 1);
  myCanvas->cd(1);
  graph->Draw("APE");
  // Fit it to the graph and draw it
  graph->Fit(f, "", "", 0, 1500);

  TF1 *baseline = new TF1("baseline", "[0]+[1]*x", 0, 1500);
  // Grafico la baseline (è una retta con parametri ai parametri [4],[5] della
  // funzione totale
  baseline->SetParameter(0, f->GetParameter(4));
  baseline->SetParameter(1, f->GetParameter(5));
  baseline->Draw("same");
  baseline->SetLineColor(kGreen);
  myCanvas->cd(2);

  // nuovo grafico con deriva della baseline sottratta (ref=0 intercetta finale,
  // ref=1 intercetta iniziale)
  Int_t nPoints = graph->GetN();
  Double_t *xVal = new Double_t[nPoints];
  Double_t *yVal = new Double_t[nPoints];
  Double_t *yValCorr = new Double_t[nPoints];
  xVal = graph->GetX();
  yVal = graph->GetY();
  Double_t start = baseline->Eval(xVal[0]);
  Double_t end = baseline->Eval(xVal[nPoints - 1]);
  if (ref)
    for (Int_t i = 0; i < nPoints; i++)
      yValCorr[i] = yVal[i] - xVal[i] * baseline->GetParameter(1);
  else
    for (Int_t i = 0; i < nPoints; i++)
      yValCorr[i] =
          yVal[i] - xVal[i] * baseline->GetParameter(1) + (end - start);
  TGraph *graphCorr = new TGraph(nPoints, xVal, yValCorr);

  // Make esthetetically better
  graphCorr->GetXaxis()->SetTitleOffset(1.3);
  graphCorr->SetMarkerStyle(kFullCircle);
  graphCorr->SetMarkerColor(kBlue);
  graphCorr->SetMarkerSize(1);

  graphCorr->SetTitle("Grafico corretto;Tempo - t (s); Posizione - x (cm)");
  graphCorr->Draw("APE");
  TF1 *fCorr = new TF1("fCorr", "f", 0, 1500);
  fCorr->SetLineColor(kRed);
  fCorr->SetLineStyle(2);
  // Fit it to the graph and draw it
  graphCorr->Fit(fCorr, "", "", 0, 1500);

  TF1 *baselineCorr = new TF1("baselineCorr", "[0]+[1]*x", 0, 1500);
  // Grafico la nuova baseline (è una retta con parametri ai parametri [4],[5]
  // della funzione totale dopo la correzione
  baselineCorr->SetParameter(0, fCorr->GetParameter(4));
  baselineCorr->SetParameter(1, fCorr->GetParameter(5));
  baselineCorr->Draw("same");
  baselineCorr->SetLineColor(kGreen);
  std::cout << "Baseline:  " << fCorr->GetParameter(4) << " +/- "
            << fCorr->GetParError(4) << '\n';
}
