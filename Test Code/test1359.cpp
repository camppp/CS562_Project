python
def customSampler(playlist, maxDuration):
    remaining_duration = maxDuration
    sampled_songs = []
    favorites = []

    for song, duration, favorite in playlist:
        if favorite:
            favorites.append((song, duration))
        else:
            sampled_songs.append((song, duration))

    sampled_songs.sort(key=lambda x: x[1])  # Sort by duration

    for song, duration in sampled_songs:
        if remaining_duration - duration >= 0:
            sampled_songs.remove((song, duration))
            remaining_duration -= duration

    for song, duration in favorites:
        if remaining_duration - duration >= 0:
            sampled_songs.append((song, duration))
            remaining_duration -= duration

    return [song for song, _ in sampled_songs]
