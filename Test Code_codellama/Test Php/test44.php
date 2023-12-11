function generateProfileImage($user, $theme) {
  $src = '';
  $class = '';

  if ($theme === 'girl') {
    $src = asset('theme_src/images/faces/girl.png');
    $class = 'img-lg rounded-circle mb-2';
  } else {
    $src = asset('theme_src/profile_pics/' . $user->Avatar->filename);
    $class = 'img-lg rounded-circle mb-2';
  }

  return '<img src="' . $src . '" class="' . $class . '" alt="Profile image">';
}