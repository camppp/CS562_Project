Image::Format ToggleAlphaChannel(Image& img) {
	switch (img.GetFormat()) {
	case Image::RGB:
		img.SetFormat(Image::RGBA);
		break;
	case Image::RGBA:
		img.SetFormat(Image::RGB);
		break;
	case Image::Grayscale:
		img.SetFormat(Image::GrayscaleA);
		break;
	case Image::GrayscaleA:
		img.SetFormat(Image::Grayscale);
		break;
	default:
		break;
	}
	return img.GetFormat();
}
