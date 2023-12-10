double mu2 = E / (1.0 + v);
double lam = v * mu2 / (1.0 - 2.0 * v);
double mu = 0.50 * mu2;

D(0,0) = D(1,1) = D(2,2) = mu2;
D(0,1) = D(1,0) = D(0,2) = D(2,0) = D(1,2) = D(2,1) = lam;
