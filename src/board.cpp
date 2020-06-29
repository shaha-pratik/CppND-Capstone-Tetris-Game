#include "board.h"

Board::Board(Piece& piece, const std::size_t& screen_width,
             const std::size_t& screen_height)
    : piece_(piece),
      screen_height_(screen_height),
      screen_width_(screen_width) {
  InitBoard();
}

void Board::InitBoard() {
  for (int i = 0; i < BOARD_WIDTH; ++i)
    for (int j = 0; j < BOARD_HEIGHT; ++j) {
      board_[i][j] = 0;
    }
}

int Board::GetXPostionInPixel(int pos_x) const {
  return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) +
          (pos_x * BLOCK_SIZE));
}

int Board::GetYPositionInPixel(int pos_y) const {
  return (screen_height_ - (BLOCK_SIZE * BOARD_HEIGHT) + (pos_y * BLOCK_SIZE));
}

bool Board::IsBlockFree(int pos_x, int pos_y) const {
  return (board_[pos_x][pos_y] == int(BoardPixel::POS_FREE));
}

bool Board::IsMovementPossibleInBlock(int pos_x, int pos_y) const {
  for (int i = 0; i < PIECE_BLOCKS; ++i) {
    int board_x = pos_x + i;
    for (int j = 0; j < PIECE_BLOCKS; ++j) {
      int board_y = pos_y + j;
      if ((board_x < 0 || board_x > BOARD_WIDTH - 1 ||
           board_y > BOARD_HEIGHT - 1) &&
          (piece_.piece_[i][j] != 0)) {
        return false;
      }
      if (board_y >= 0 && piece_.piece_[i][j] != 0 &&
          !IsBlockFree(board_x, board_y)) {
        return false;
      }
    }
  }
  return true;
}

void Board::StorePieceInBoard(int pos_x, int pos_y) {
  for (int i = 0; i < PIECE_BLOCKS; ++i) {
    int board_x = pos_x + i;
    for (int j = 0; j < PIECE_BLOCKS; ++j) {
      int board_y = pos_y + j;
      if (piece_.piece_[i][j] != 0) {
        board_[board_x][board_y] = piece_.GetPieceType();
      }
    }
  }
}

int Board::DeletePossibleLines() {
  int n_lines_{0};
  for (int row = 0; row < BOARD_HEIGHT; ++row) {
    int col = 0;
    while (col < BOARD_WIDTH) {
      if (board_[col][row] == int(BoardPixel::POS_FREE)) {
        break;
      }
      col++;
    }
    if (col == BOARD_WIDTH) {
      DeleteLine(row);
      n_lines_ += 1;
    }
  }
  return n_lines_;
}

bool Board::IsGameOver() const {
  for (int i = 0; i < BOARD_WIDTH; ++i) {
    if (board_[i][0] != int(BoardPixel::POS_FREE)) {
      return true;
    }
  }
  return false;
}

void Board::DeleteLine(int pos_y) {
  for (int j = pos_y; j > 0; --j) {
    for (int i = 0; i < BOARD_WIDTH; ++i) {
      board_[i][j] = board_[i][j - 1];
    }
  }
}

void Board::UpdateCurrentPiece(const Piece& piece) { piece_ = piece; }

void Board::ClearBoard() { InitBoard(); }
