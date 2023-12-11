$(document).ready(function() {
    $('.like-button').click(function(e) {
        e.preventDefault();
        var commentId = $(this).attr('id').replace('_like', '');
        var likeButton = $('#' + commentId + '_like');
        var likes = $('#' + commentId + '_likes');

        $.ajax({
            url: '/comments/' + commentId + '/like',
            type: 'POST',
            data: {_token: '{{ csrf_token() }}', commentId: commentId},
            success: function(response) {
                if (response.status === 'liked') {
                    likeButton.html('Unlike');
                } else {
                    likeButton.html('Like');
                }
                likes.html(response.likes);
            },
            error: function(xhr, status, error) {
                console.log(error);
            }
        });
    });
});