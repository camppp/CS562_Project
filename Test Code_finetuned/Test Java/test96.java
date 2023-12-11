protected void onLightSourceRemove(LightSource l) {
    if (this.image!= null) {
        this.image.removeLightSource(l);
    }
}