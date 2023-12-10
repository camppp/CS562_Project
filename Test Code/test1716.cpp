// Create and fill histograms
TH1F *energyBeforeSubtraction = new TH1F("energyBeforeSubtraction", "Energy Distribution Before Time-Random Subtraction", 100, 0, 100);
TH1F *energyAfterSubtraction = new TH1F("energyAfterSubtraction", "Energy Distribution After Time-Random Subtraction", 100, 0, 100);

// Fill histograms with sample data
for (int i = 0; i < 1000; i++) {
    double energy = generateEnergy();  // Replace with actual energy generation function
    energyBeforeSubtraction->Fill(energy);
    
    // Perform time-random subtraction
    double subtractedEnergy = performTimeRandomSubtraction(energy);  // Replace with actual subtraction function
    energyAfterSubtraction->Fill(subtractedEnergy);
}

// Save histograms to the output file
out_file->cd("TimeRandomSubtracted");
energyBeforeSubtraction->Write();
energyAfterSubtraction->Write();
out_file->Close();
