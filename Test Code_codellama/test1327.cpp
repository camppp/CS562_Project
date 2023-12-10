void Sruba::krec(double kat) {
    kat_obrotu_sruby += kat;
    if (kat_obrotu_sruby >= 360 || kat_obrotu_sruby <= -360) {
        kat_obrotu_sruby = 0;
        std::cout << "Screw has completed a full rotation" << std::endl;
    }
}
