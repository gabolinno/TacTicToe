# TacTicToe

When starting the game you can choose between two options - 
X and O (X for you to start first and O - to be second).
The empty board is displayed when you choose your symbol.
To make a move you have to enter two digits separated by space
or enter - every digit must be between 1 and 3.
After every move the board is updating.
The computer move is calculated by the Minimax algorithm.

# Example Game: 


Enter X to be first and O otherwise: X
Let's begin the game!
Player 1 (X)(YOU)  -  Player 2 (O)(Computer)


     |     |
     |     |
_____|_____|_____
     |     |
     |     |
_____|_____|_____
     |     |
     |     |
     |     |

Enter your move (two digits between 1 and 3): 1 1
     |     |
  X  |     |
_____|_____|_____
     |     |
     |     |
_____|_____|_____
     |     |
     |     |
     |     |

Computer's move: 2 2
     |     |
  X  |     |
_____|_____|_____
     |     |
     |  O  |
_____|_____|_____
     |     |
     |     |
     |     |

Enter your move (two digits between 1 and 3): 3 1
     |     |
  X  |     |
_____|_____|_____
     |     |
     |  O  |
_____|_____|_____
     |     |
  X  |     |
     |     |

Computer's move: 2 1
     |     |
  X  |     |
_____|_____|_____
     |     |
  O  |  O  |
_____|_____|_____
     |     |
  X  |     |
     |     |

Enter your move (two digits between 1 and 3): 2 3
     |     |
  X  |     |
_____|_____|_____
     |     |
  O  |  O  |  X
_____|_____|_____
     |     |
  X  |     |
     |     |

Computer's move: 1 2
     |     |
  X  |  O  |
_____|_____|_____
     |     |
  O  |  O  |  X
_____|_____|_____
     |     |
  X  |     |
     |     |

Enter your move (two digits between 1 and 3): 3 2
     |     |
  X  |  O  |
_____|_____|_____
     |     |
  O  |  O  |  X
_____|_____|_____
     |     |
  X  |  X  |
     |     |

Computer's move: 3 3
     |     |
  X  |  O  |
_____|_____|_____
     |     |
  O  |  O  |  X
_____|_____|_____
     |     |
  X  |  X  |  O
     |     |

Enter your move (two digits between 1 and 3): 1 3
     |     |
  X  |  O  |  X
_____|_____|_____
     |     |
  O  |  O  |  X
_____|_____|_____
     |     |
  X  |  X  |  O
     |     |

     |     |
  X  |  O  |  X
_____|_____|_____
     |     |
  O  |  O  |  X
_____|_____|_____
     |     |
  X  |  X  |  O
     |     |

-------------------------
Good game! It was a draw!
-------------------------