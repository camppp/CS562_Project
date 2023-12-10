python
def handlePawnMoves(game_state, defenses, piece_attacks, ep_square):
    moves = []  # List to store the valid pawn moves

    for square, piece in game_state.board.items():
        if piece.color == game_state.current_player and piece.type == 'pawn':
            i = square.index
            value = piece_attacks[piece]

            # Regular pawn moves
            if game_state.board[i + piece.direction] == 0:
                addPawnMove(moves, piece, i, i + piece.direction, 0, value, False)

                # Double pawn move from starting position
                if piece.is_starting_position(i) and game_state.board[i + 2 * piece.direction] == 0:
                    addPawnMove(moves, piece, i, i + 2 * piece.direction, BITS_PAWN_START, value, False)

            # Pawn captures
            for j in [i - 1, i + 1]:
                if game_state.board[j] != 0 and game_state.board[j].color != piece.color:
                    addPawnMove(moves, piece, i, j, 0, piece_attacks[game_state.board[j]], False)

            # En passant
            if square == ep_square:
                addPawnMove(moves, piece, i, ep_square, BITS_EN_PASSANT, value, False)

            # Pawn promotions
            if piece.is_promotion_rank(i + piece.direction):
                for promotion_type in ['queen', 'rook', 'bishop', 'knight']:
                    addPawnMove(moves, piece, i, i + piece.direction, BITS_PROMOTION, piece_attacks[promotion_type], promotion_type)

    return moves
