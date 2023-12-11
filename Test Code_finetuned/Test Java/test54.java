public class ThreadfinDragonfishEntity extends AnimatedGeoEntity<ThreadfinDragonfishEntity> {

    public static final Identifier FLANK_TEXTURE = new Identifier("deep_trenches:textures/entity/threadfin_dragonfish/flank.png");
    public static final Identifier LURE_TEXTURE = new Identifier("deep_trenches:textures/entity/threadfin_dragonfish/lure.png");
    public static final Identifier ANIMATION_FILE_LOCATION = new Identifier("deep_trenches:animations/threadfin_dragonfish.json");

    public ThreadfinDragonfishEntity(EntityType<? extends AnimatedGeoEntity<ThreadfinDragonfishEntity>> type, World world) {
        super(type, world);
    }

    @Override
    public Identifier getAnimationFileLocation(ThreadfinDragonfishEntity animatable) {
        return ANIMATION_FILE_LOCATION;
    }
}