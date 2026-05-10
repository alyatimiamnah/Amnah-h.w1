 #include "style.h"

void sigeffpurity() {

  SetGlobalStyle();

  // =========================
  // OPEN FILE
  // =========================
  TFile *file = TFile::Open("mlpHiggs.root");

  // =========================
  // GET TREES
  // =========================
  TTree *sig = (TTree*)file->Get("sig_filtered");
  TTree *bg  = (TTree*)file->Get("bg_filtered");

  // =========================
  // TOTAL EVENTS
  // =========================
  int Ns = sig->GetEntries();
  int Nb = bg->GetEntries();

  // =========================
  // VARIABLE
  // =========================
  float sig_acolin, bg_acolin;

  sig->SetBranchAddress("acolin", &sig_acolin);
  bg->SetBranchAddress("acolin", &bg_acolin);

  // =========================
  // QUESTION (0):
  // Define three graphs using TGraphErrors:
  //   - g_eff  (efficiency)
  //   - g_pur  (purity)
  //   - g_prod (eff × purity)
  // =========================
  TGraphErrors *g_eff  = new TGraphErrors();
  TGraphErrors *g_pur  = new TGraphErrors();
  TGraphErrors *g_prod = new TGraphErrors();



  // =========================
  // LOOP OVER THRESHOLDS
  // =========================
  for (int t = 80; t <= 200; t++) {

    int count_sig = 0;
    int count_bg  = 0;

    // =========================
    // SIGNAL LOOP
    // =========================
    for (int i = 0; i < Ns; i++) {
      sig->GetEntry(i);
      if (sig_acolin >= t) count_sig++;
    }

    // =========================
    // BACKGROUND LOOP
    // =========================
    for (int i = 0; i < Nb; i++) {
      bg->GetEntry(i);
      if (bg_acolin >= t) count_bg++;
    }

    // =========================
    // QUESTION (1):
    // Define:
    //   efficiency
    //   purity
    //   product
    // =========================
    double efficiency = (double)count_sig / Ns;

    double purity = (double)count_sig / (count_sig + count_bg);

    double product = efficiency * purity;


    // =========================
    // QUESTION (2):
    // Compute binomial errors for:
    //   efficiency
    //   purity
    // =========================
    double eff_err = sqrt(efficiency * (1 - efficiency) / Ns);

    double pur_err = sqrt(purity * (1 - purity) / (count_sig + count_bg));



    // =========================
    // QUESTION (3):
    // Get index p from graph
    // =========================

    int p = g_eff->GetN();

    // =========================
    // QUESTION (4):
    // Fill ALL graphs with points and errors:
    //   g_eff  → (t, efficiency)
    //   g_pur  → (t, purity)
    //   g_prod → (t, product)
    // =========================
      g_eff->SetPoint(p, t, efficiency);


       g_eff->SetPointError(p, 0, eff_err);


       g_pur->SetPoint(p, t, purity);
    g_pur->SetPointError(p, 0, pur_err);


    g_prod->SetPoint(p, t, product);
    g_prod->SetPointError(p, 0, 0);

  }

  // =========================
  // STYLE (given)
  // =========================
  g_eff->SetLineColor(kBlue);
  g_eff->SetMarkerColor(kBlue);
  g_eff->SetMarkerStyle(20);

  g_pur->SetLineColor(kRed);
  g_pur->SetMarkerColor(kRed);
  g_pur->SetMarkerStyle(21);

  g_prod->SetLineColor(kGreen+2);
  g_prod->SetMarkerColor(kGreen+2);
  g_prod->SetMarkerStyle(22);

  g_eff->SetTitle("Efficiency, Purity, and Optimization;Acolinearity Cut;Efficiency");

  // =========================
  // CANVAS
  // =========================
  TCanvas *c = new TCanvas("c","",800,600);
  SetCanvasStyle(c);

  // =========================
  // QUESTION (5):
  // Draw all graphs on same canvas
  // =========================


  g_eff->Draw("ALP");
  g_pur->Draw("LP SAME");
  g_prod->Draw("LP SAME");



  // =========================
  // QUESTION (6):
  // Create legend:
  //   Efficiency
  //   Purity
  //   Efficiency × Purity
  // =========================
  TLegend *leg = CreateLegend();

  leg->AddEntry(g_eff, "Efficiency", "lp");
  leg->AddEntry(g_pur, "Purity", "lp");
  leg->AddEntry(g_prod, "Efficiency x Purity", "lp");

  leg->Draw();


  // =========================
  // QUESTION (7):
  // Save plot as:
  //   "eff_purity_product.png"
  // =========================
  c->SaveAs("eff_purity_product.png");


}
