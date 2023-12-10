#pragma omp teams
#pragma omp distribute parallel for simd private(i), shared(i) // expected-error {{private variable cannot be shared}} expected-note {{defined as private}}
  for(int k = 0 ; k < n ; k++) {
    acc++;
  }
