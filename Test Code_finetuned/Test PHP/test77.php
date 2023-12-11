function generateProfileImage($user, $theme) {
    if ($theme == "girl") {
        $src = "{{ asset('theme_src/images/faces/girl.png') }}";
    } else {
        $src = "{{ asset('theme_src/profile_pics/'.$user->Avatar->filename) }}";
    }
    $class = "img-lg rounded-circle mb-2";
    $alt = "Profile Image";

    return "<img src='$src' class='$class' alt='$alt'>";
}