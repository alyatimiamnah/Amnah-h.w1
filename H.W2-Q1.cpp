 #include "style.h"

void gaussianfit_acolin(){

  SetGlobalStyle();

  // =========================
  // OPEN FILE
  // =========================
  TFile *file = TFile::Open("mlpHiggs.root");

  // =========================
  // QUESTION (0):
  // Get the SIGNAL tree "sig_filtered"
  // =========================
  TTree *sig_tree = (TTree*)file->Get("sig_filtered");



  // =========================
  // VARIABLE
  // =========================
  float sig_acolin = 0;

  // =========================
  // QUESTION (1):
  // Set branch address for "acolin"
  // =========================

  sig_tree->SetBranchAddress("acolin",&sig_acolin);



  // =========================
  // HISTOGRAM
  // =========================
  TH1F *h = new TH1F("h","Signal acolin",50,0,3);

  // =========================
  // QUESTION (2):
  // Fill histogram using loop over sig_tree
  // =========================
  for(int i=0; i<sig_tree->GetEntries(); i++)
    {

    sig_tree->GetEntry(i);

    h->Fill(sig_acolin);

                   }



  // =========================
  // CANVAS
  // =========================
  TCanvas *c = new TCanvas("c","Gaussian Fit (acolin)",800,600);
  SetCanvasStyle(c);

  // =========================
  // STYLE HISTOGRAM
  // =========================
  SetHistogramStyle(h);

  // =========================
  // QUESTION (3):
  // Set axis labels:
  //   X-axis → "Acolinearity"
  //   Y-axis → "Events"
  // =========================
         h->GetXaxis()->SetTitle("Acolinearity");

         h->GetYaxis()->SetTitle("Events");



  // =========================
  // DRAW HISTOGRAM
  // =========================
  h->Draw("HIST");

  // =========================
  // QUESTION (4):
  // Create Gaussian function and fit histogram
  // Hint: choose a reasonable fit range

  TF1 *g = new TF1("g","gaus",0,3);

            h->Fit(g,"R");

         g->SetLineColor(kRed);

         g->Draw("SAME");




  // =========================
  // QUESTION (5):
  // Extract:
  //   mean
  //   sigma
  //   mean error
  //   sigma error
  // =========================
           double mean = g->GetParameter(1);

           double sigma = g->GetParameter(2);

           double mean_err = g->GetParError(1);

           double sigma_err = g->GetParError(2);


  // =========================
  // QUESTION (6):
  // Create legend and display results

  //
  // Hint:  leg->AddEntry((TObject*)0,
  //      Form("#mu = %.3f #pm %.3f", mean, mean_err), "");
  //

  // =========================

           TLegend *leg = CreateLegend();

           leg->AddEntry(h,"Signal","l");

           leg->AddEntry(g,"Gaussian Fit","l");

           leg->AddEntry((TObject*)0,
                         Form("#mu = %.3f #pm %.3f",mean,mean_err),"");

                                  leg->AddEntry((TObject*)0,
                                                Form("#sigma = %.3f #pm %.3f",sigma,sigma_err),"");
                    leg->Draw();


  // =========================
  // QUESTION (7):
  // Save the canvas as:
  //   "acolin_gaussian_fit.png"
  // =========================

           c->SaveAs("acolin_gaussian_fit.png");
