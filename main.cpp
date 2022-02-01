#include <iostream>

   char check(char a[][3], char b) {
    char tempo [3][3];
    for (int i = 0; i < 3; i++) {
        for (int t = 0; t < 3; t++){
            tempo[i][t] = b;
        }
    }
       if ((tempo[0][0] == a[0][0] && tempo[1][0] == a[1][0] && tempo[2][0] == a[2][0])
           || (tempo[0][1] == a[0][1] && tempo[1][1] == a[1][1] && tempo[2][1] == a[2][1])
           || (tempo[0][2] == a[0][2] && tempo[1][2] == a[1][2] && tempo[2][2] == a[2][2])) {
           return b;
       }
       else if ((tempo[0][0] == a[0][0] && tempo[0][1] == a[0][1] && tempo[0][2] == a[0][2])
                || (tempo[1][0] == a[1][0] && tempo[1][1] == a[1][1] && tempo[1][2] == a[1][2])
                || (tempo[2][0] == a[2][0] && tempo[2][1] == a[2][1] && tempo[2][2] == a[2][2])) {
           return b;
       }
       else if (tempo[0][0] == a[0][0] && tempo[1][1] == a[1][1] && tempo[2][2] == a[2][2]) {
           return b;
       }
       else if (tempo[2][0] == a[2][0] && tempo[1][1] == a[1][1] && tempo[0][2] == a[0][2]) {
           return b;
       }

      int count = 0;
       for (int i = 0; i < 3; i++){
           for (int j = 0; j < 3; j++) {
               if (a[i][j] != ' ') {
                   count++;
               }

           }
       }

       if (count == 9) {
           return 'D';
       }


    return ' ';
}

   int main() {
        int x, y;
        char sym;
        char tic_tac[3][3]{{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};

        for (int total = 0; total < 10; total++) {
            do {
                std::cout << "Enter coordinates x & y:\nCoordinate x:";
                std::cin >> x;
                std::cout << "Coordinate y:";
                std::cin >> y;
                std::cout << "Enter symbol O or X:\n";
                std::cin >> sym;
            } while ((sym != 88 && sym != 79) || (y < 0 || y > 3) || (x < 0 || x > 3) || tic_tac[y][x] != ' ');
            tic_tac[y][x] = sym;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << tic_tac[i][j];
                    if (j < 2) {
                        std::cout << "|";
                    }
                }
                std::cout << std::endl;
                if (i < 2) {
                    std::cout << "------\n";
                }
            }

            if (check(tic_tac, sym) != ' ' && check(tic_tac, sym) != 'D') {
                std::cout << "\n" << check(tic_tac, sym) << " Winner!!!";
                break;
            }
            else if (check(tic_tac, sym) == 'D') {
                std::cout << "Draw!";
                break;
            }


        }

}

