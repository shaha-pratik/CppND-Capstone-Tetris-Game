#include "game.h"

Game::Game(Renderer& renderer)
    : renderer_(renderer),
      engine(device()),
      random_shape(0, 6),
      random_rotation(0, 7),
      next_position_x_(10),
      next_position_y_(0),
      piece_{Piece()},
      next_piece_{Piece()} {
  screen_height = 480;
  Init();
}

void Game::Init() {
  piece_type_ = random_shape(engine);
  piece_rotation_ = random_rotation(engine);
  piece_ = Piece(piece_type_, rotation_value[piece_rotation_]);

  next_piece_type_ = random_shape(engine);
  next_piece_rotation_ = random_rotation(engine);
  next_piece_ = Piece(next_piece_type_, rotation_value[next_piece_rotation_]);

  board_ = Board(piece_, 0, screen_height);

  position_x_ = (BOARD_WIDTH / 2) + piece_.GetInitialXPosition();
  position_y_ = piece_.GetInitialYPosition();
}

void Game::GenerateNewPiece() {
  piece_ = next_piece_;
  board_.UpdateCurrentPiece(piece_);

  position_x_ = (BOARD_WIDTH / 2) + piece_.GetInitialXPosition();
  position_y_ = piece_.GetInitialYPosition();

  next_piece_type_ = random_shape(engine);
  next_piece_rotation_ = random_rotation(engine);

  next_piece_ = Piece(next_piece_type_, rotation_value[next_piece_rotation_]);
}

void Game::DrawPiece(int pX, int pY, const Piece& pPiece) {
  int xPosInPixels = board_.GetXPostionInPixel(pX);
  int yPosInPixels = board_.GetYPositionInPixel(pY);

  for (int i = 0; i < PIECE_BLOCKS; i++) {
    for (int j = 0; j < PIECE_BLOCKS; j++) {
      if (pPiece.piece_[i][j] != 0)
        renderer_.DrawBlock(xPosInPixels + i * BLOCK_SIZE,
                            yPosInPixels + j * BLOCK_SIZE, BLOCK_SIZE - 1,
                            BLOCK_SIZE - 1);
    }
  }
}

void Game::DrawBoard() {
  int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
  int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
  int mY = screen_height - (BLOCK_SIZE * BOARD_HEIGHT);

  renderer_.DrawBlock(mX1 - BOARD_LINE_WIDTH, mY, BOARD_LINE_WIDTH,
                      screen_height - 1);
  renderer_.DrawBlock(mX2, mY, BOARD_LINE_WIDTH, screen_height - 1);
  renderer_.DrawBlock(mX1, screen_height, BLOCK_SIZE * BOARD_WIDTH,
                      BOARD_LINE_WIDTH);

  mX1++;

  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      if (!board_.IsBlockFree(i, j)) {
        renderer_.DrawBlock(mX1 + i * BLOCK_SIZE, mY + j * BLOCK_SIZE,
                            BLOCK_SIZE - 1, BLOCK_SIZE - 1);
      }
    }
  }
}

void Game::DrawScene() {
  renderer_.ClearScreen();
  DrawBoard();
  DrawPiece(position_x_, position_y_, piece_);
  DrawPiece(next_position_x_, next_position_y_, next_piece_);

  renderer_.UpdateScreen();
}

bool Game::RestartGame() {
  bool response_{};
  int response = renderer_.MessageBox();
  if (response) {
    board_.ClearBoard();
    response_ = true;
  } else {
    response_ = false;
  }
  return response_;
}

void Game::Run(Controller& controller,
               const std::size_t& target_frame_duration) {
  bool running = true;
  game_score_ = 0;
  unsigned long time1 = SDL_GetTicks();

  while (running) {
    DrawScene();

    int key = controller.HandleInput(running);

    switch (key) {
      case (SDLK_d): {
        if (board_.IsMovementPossibleInBlock(position_x_ + 1, position_y_)) {
          position_x_++;
        }
        break;
      }
      case (SDLK_a): {
        if (board_.IsMovementPossibleInBlock(position_x_ - 1, position_y_)) {
          position_x_--;
        }
        break;
      }
      case (SDLK_s): {
        if (board_.IsMovementPossibleInBlock(position_x_, position_y_ + 1)) {
          position_y_++;
        }
        break;
      }
      case (SDLK_SPACE): {
        while (board_.IsMovementPossibleInBlock(position_x_, position_y_)) {
          position_y_++;
        }

        board_.StorePieceInBoard(position_x_, position_y_ - 1);
        game_score_ += (10 * board_.DeletePossibleLines());

        if (board_.IsGameOver()) {
          game_score_ = 0;
          if (!RestartGame()) {
            running = false;
            continue;
          };
          std::cout << "Game has finished.\n";
          std::cout << "Score: " << GetScore() << std::endl;
        }

        GenerateNewPiece();
        break;
      }
      case (SDLK_q): {
        piece_.RotatePiece(rotation_value[2]);
        if (board_.IsMovementPossibleInBlock(position_x_, position_y_)) {
          board_.piece_ = piece_;
        }
        break;
      }
      case (SDLK_e): {
        piece_.RotatePiece(rotation_value[4]);
        board_.piece_ = piece_;
        break;
      }
    }

    unsigned long time2 = SDL_GetTicks();
    if ((time2 - time1) > target_frame_duration) {
      if (board_.IsMovementPossibleInBlock(position_x_, position_y_ + 1)) {
        position_y_++;
      } else {
        board_.StorePieceInBoard(position_x_, position_y_);
        game_score_ += (10 * board_.DeletePossibleLines());

        if (board_.IsGameOver()) {
          if (!RestartGame()) {
            running = false;
            continue;
          }
          game_score_ = 0;
          std::cout << "Game has finished.\n";
          std::cout << "Score: " << GetScore() << std::endl;
        }

        GenerateNewPiece();
      }

      time1 = SDL_GetTicks();
    }
  }
}

int Game::GetScore() const { return game_score_; }